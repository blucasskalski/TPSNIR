/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			mainfiles.cpp
 |
 |	Projet :		DemoEditor - classe MainWindow
 |	Sujet :     	Programme de démonstration RAD Qt
 |
 |  Auteur :		Alain Menu
 |	Version :		3.0 (Qt5.3.x)
 |	Création :		2009
 |	Mise à jour :	27/10/2014
 |
 |	Fabrication :	Qt5 OpenSource
 + ------------------------------------------------------------------------- */
/*
 |	Copyright 2009-2014 Alain Menu <alain.menu@ac-creteil.fr>
 |
 |  This file is part of "DemoEditor project"
 |
 |  This program is free software ;  you can  redistribute it and/or  modify it
 |  under the terms of the  GNU General Public License as published by the Free
 |  Software Foundation ; either version 2 of the License, or  (at your option)
 |  any later version.
 |
 |  This program is distributed in the hope that it will be useful, but WITHOUT
 |  ANY WARRANTY ; without even the  implied  warranty  of  MERCHANTABILITY  or
 |  FITNESS FOR  A PARTICULAR PURPOSE. See the  GNU General Public License  for
 |  more details < http://www.gnu.org/licenses/gpl.txt >.
 + ------------------------------------------------------------------------- */

#include <QtGui>

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#include <QPrinter>
#include <QPrintDialog>
#endif

#include "mainwindow.h"

// --- Création d'un document vierge

void MainWindow::newFile()				// slot
{
	if ( maybeSave() ) {
		editor->clear() ;
		setCurrentFile("") ;
	}
}

// --- Sauvegarde du document courant

bool MainWindow::saveFile()				// slot
{
	if ( currentFile.isEmpty() )	
			return saveAsFile() ;
	else	return save( currentFile ) ;
}

bool MainWindow::saveAsFile()			// slot
{
	QString fileName = QFileDialog::getSaveFileName( 
		this,
		tr("Enregistrer sous..."),
		currentDir,
		tr("Tous les fichiers (*.*)") ) ;
	if ( fileName.isEmpty() ) 
			return false ;
	else	return save( fileName ) ;
}

bool MainWindow::maybeSave()
{
	if ( ! editor->document()->isModified() )	return true ;
	
	int res = QMessageBox::warning( this, tr("Confirmation"),
		tr("Le document a été modifié.\n"
		   "Voulez-vous sauvegarder les changements ?"),
		tr("Oui"), tr("Non"), tr("Annuler"), 0, 2 ) ;
		
	if ( res == 0 )	return saveFile() ;
	if ( res == 2 )	return false ;
	return true ;
}

void MainWindow::documentWasModified()	// slot
{
	setWindowModified( true ) ;		// '*' dans barre de titre
	saveAct->setEnabled( editor->document()->isModified() ) ;
	saveAsAct->setEnabled( ! editor->document()->isEmpty() ) ;
}

bool MainWindow::save( const QString& fileName )
{
	QFile	file( fileName ) ;
	
	bool res = file.open( QFile::WriteOnly | QFile::Text ) ;
	if ( !res ) {
		QMessageBox::critical( this, tr("Erreur"),
			tr("Impossible d'écrire le fichier %1 :\n%2")
			.arg( fileName )
			.arg( file.errorString() ),
			tr("Fermer") ) ;
		return false ;
	}
	QTextStream	out( &file ) ;
	QApplication::setOverrideCursor( Qt::WaitCursor ) ;
	out << editor->toPlainText() ;
	QApplication::restoreOverrideCursor() ;
	setCurrentFile( fileName ) ;
	currentDir = QFileInfo( fileName ).absolutePath() ;
	statusBar()->showMessage( tr("Sauvegarde ok !"), 2000 ) ;
	return true ;
}

// --- Chargement d'un fichier source

void MainWindow::openFile()				// slot
{
	if ( maybeSave() ) {
		QString	fileName = QFileDialog::getOpenFileName( 
			this,
			tr("Ouvrir..."), 
			currentDir,
			tr("Tous les fichiers (*.*)") ) ;
		if ( !fileName.isEmpty() )	load( fileName ) ;
	}
}

void MainWindow::load( const QString& fileName )
{
	QFile	file( fileName ) ;
	
	bool res = file.open( QFile::ReadOnly | QFile::Text ) ;
	if ( !res ) {
		QMessageBox::critical( this, tr("Erreur"),
			tr("Impossible de lire le fichier %1 :\n%2")
			.arg( fileName )
			.arg( file.errorString() ),
			tr("Fermer") ) ;
		return ;
	}
	QTextStream	in( &file ) ;
	QApplication::setOverrideCursor( Qt::WaitCursor ) ;
	editor->setPlainText( in.readAll() ) ;
	QApplication::restoreOverrideCursor() ;
	setCurrentFile( fileName ) ;
	currentDir = QFileInfo( fileName ).absolutePath() ;
	statusBar()->showMessage( tr("Lecture ok !"), 2000 ) ;
}

void MainWindow::setCurrentFile( const QString& fileName )
{
	currentFile = fileName ;
	editor->document()->setModified( false ) ;
	setWindowModified( false ) ;
	
	QString shownName ;
	if ( currentFile.isEmpty() ) 
			shownName = tr("sansnom.txt") ;
	else	shownName = QFileInfo( currentFile ).fileName() ;
	
    setWindowTitle( tr("DemoEditor - %1[*]").arg(shownName) ) ;

	saveAct->setEnabled( editor->document()->isModified() ) ;
	saveAsAct->setEnabled( ! editor->document()->isEmpty() ) ;
}

// --- Impression du document courant

void MainWindow::printFile()
{
	QTextDocument*	document = editor->document() ;
	QPrinter 		printer ;

    QPrintDialog*	dlg = new QPrintDialog( &printer, this ) ;
    if ( dlg->exec() != QDialog::Accepted ) return;

    QFont font ;
    font.setFamily("Courier") ;
    font.setFixedPitch(true) ;
    font.setPointSize(9) ;
    document->setDefaultFont(font) ;

	document->print( &printer ) ;
}
