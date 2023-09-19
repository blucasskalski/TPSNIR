/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			mainwindow.cpp
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
#endif

#include "mainwindow.h"
#include "dlgsearch.h"

MainWindow::MainWindow(QWidget* parent ) : QMainWindow(parent ) 
{
	setupUi(this) ;
	dlgSearch = new DlgSearch( editor,  this ) ;
	readSettings() ;
	createActions() ;
	setupMenus() ;
	setupToolBars() ;

    connect( editor->document(), SIGNAL( contentsChanged() ),
			 this, 				 SLOT( documentWasModified() ) ) ;
	connect( editor, SIGNAL( cursorPositionChanged() ), 
			 this, 	 SLOT( cursorPosition() ) ) ;
	setCurrentFile("") ;

    currentFont.setFamily("Courier") ;
    currentFont.setFixedPitch(true) ;
    currentFont.setPointSize(12) ;

    currentBkColor = QColor(228,255,221) ;

    setupStatusBar() ;
    setupEditor() ;

    connect( colorSelector, SIGNAL( clicked() ), this, SLOT( setupEditorBkColor() ) ) ;
    connect( fontSelector, SIGNAL( clicked() ), this, SLOT( setupEditorFont() ) ) ;

    search
}

// --- Actions, menus, barres d'outils, ligne d'état :	MainActions.cpp
// --- Gestion des fichiers, chargement, sauvegarde :	MainFiles.cpp
// --- Editeur, position curseur, recherche, remplace :	MainEditor.cpp

// --- Gestion de la configuration courante

void MainWindow::readSettings()
{
#ifdef Q_OS_MAC
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "demo_editor" ) ;
#else
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "Qam", "demo_editor" ) ;
#endif

    QPoint	pos = settings.value("MainWindow/pos", QPoint(10,10) ).toPoint() ;
	QSize	size = settings.value("MainWindow/size", QSize(640,480) ).toSize() ;
	resize( size ) ;
	move( pos ) ;

    currentDir = settings.value("Files/lastDir", QDir::homePath() ).toString() ;
}

void MainWindow::writeSettings()
{
#ifdef Q_OS_MAC
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "qam.fr", "demo_editor" ) ;
#else
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, "Qam", "demo_editor" ) ;
#endif

    settings.setValue("MainWindow/pos", pos() ) ;
    settings.setValue("MainWindow/size", size() ) ;
    settings.setValue("Files/lastDir", currentDir ) ;
}

// --- Fermeture de l'application

void MainWindow::closeEvent( QCloseEvent* event )
{
	if ( maybeSave() ) {
		writeSettings() ;
		event->accept() ;
		return ;
	}
	event->ignore() ;
}

// --- Aide

void MainWindow::help()
{
}

#define ABOUTMESSAGE \
    "<p><b>DemoEditor version %1</b>" \
	"<p>Exemple d'éditeur de texte" \
    "<p>Copyright (c)2009-2022 Alain Menu " \
	"<a href=\"mailto:alain.menu@ac-creteil.fr\">alain.menu@ac-creteil.fr</a>"

#define	VERSION "3.1 (Qt5.14.x)"

void MainWindow::about()
{
	 QMessageBox::information(this,
		tr("A propos..."),
		QString(ABOUTMESSAGE).arg(VERSION) ) ;
}
