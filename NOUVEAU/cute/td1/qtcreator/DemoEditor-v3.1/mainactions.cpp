/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			mainaction.cpp
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

void MainWindow::createActions()
{
	// actions 'fichier'
	
	newAct = new QAction( QIcon(":/images/filenew.png"), tr("&Nouveau"), this ) ;
	newAct->setShortcut( tr("Ctrl+N") ) ;
	newAct->setStatusTip( tr("Création d'un nouveau fichier") ) ;
	connect( newAct, SIGNAL( triggered() ), this, SLOT( newFile() ) ) ;
	
	openAct = new QAction( QIcon(":/images/fileopen.png"), tr("&Ouvrir..."), this ) ;
	openAct->setShortcut( tr("Ctrl+O") ) ;
	openAct->setStatusTip( tr("Ouverture d'un fichier") ) ;
	connect( openAct, SIGNAL( triggered() ), this, SLOT( openFile() ) ) ;

	saveAct = new QAction( QIcon(":/images/filesave.png"), tr("&Sauvegarder"), this ) ;
	saveAct->setShortcut( tr("Ctrl+S") ) ;
	saveAct->setStatusTip( tr("Sauvegarde du document") ) ;
	connect( saveAct, SIGNAL( triggered() ), this, SLOT( saveFile() ) ) ;

	saveAsAct = new QAction( tr("&Sauvegarder sous..."), this ) ;
	saveAsAct->setStatusTip( tr("Sauvegarde du document sous un nouveau nom") ) ;
	connect( saveAsAct, SIGNAL( triggered() ), this, SLOT( saveAsFile() ) ) ;

	printAct = new QAction( QIcon(":/images/fileprint.png"), tr("Im&primer"), this ) ;
	printAct->setShortcut( tr("Ctrl+P") ) ;
	printAct->setStatusTip( tr("Impression du document") ) ;
	connect( printAct, SIGNAL( triggered() ), this, SLOT( printFile() ) ) ;

	exitAct = new QAction( QIcon(":/images/fileexit.png"), tr("&Quitter"), this ) ;
	exitAct->setShortcut( tr("Ctrl+Q") ) ;
	exitAct->setStatusTip( tr("Quitter l'application") ) ;
	connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) ) ;

	saveAct->setEnabled( false ) ;
	saveAsAct->setEnabled( false ) ;

	// actions 'édition'
	
	undoAct = new QAction( QIcon(":/images/editundo.png"), tr("Annuler"), this ) ;
	undoAct->setShortcut( tr("Ctrl+Z") ) ;
	undoAct->setStatusTip( tr("Annuler la dernière action") ) ;
	connect( undoAct, SIGNAL( triggered() ), editor->document(), SLOT( undo() ) ) ;

	redoAct = new QAction( QIcon(":/images/editredo.png"), tr("Répéter"), this ) ;
	redoAct->setShortcut( tr("Ctrl+Y") ) ;
	redoAct->setStatusTip( tr("Répéter la dernière action") ) ;
	connect( redoAct, SIGNAL( triggered() ), editor->document(), SLOT( redo() ) ) ;

	cutAct = new QAction( QIcon(":/images/editcut.png"), tr("Couper"), this ) ;
	cutAct->setShortcut( tr("Ctrl+X") ) ;
	cutAct->setStatusTip( tr("Couper la sélection courante vers le presse-papier") ) ;
	connect( cutAct, SIGNAL( triggered() ), editor, SLOT( cut() ) ) ;

	copyAct = new QAction( QIcon(":/images/editcopy.png"), tr("Copier"), this ) ;
	copyAct->setShortcut( tr("Ctrl+C") ) ;
	copyAct->setStatusTip( tr("Copier la sélection courante vers le presse-papier") ) ;
	connect( copyAct, SIGNAL( triggered() ), editor, SLOT( copy() ) ) ;

	pasteAct = new QAction( QIcon(":/images/editpaste.png"), tr("Coller"), this ) ;
	pasteAct->setShortcut( tr("Ctrl+V") ) ;
	pasteAct->setStatusTip( tr("Coller le contenu du presse-papier") ) ;
	connect( pasteAct, SIGNAL( triggered() ), editor, SLOT( paste() ) ) ;

	selectAllAct = new QAction( tr("Sélectionner tout"), this ) ;
	selectAllAct->setShortcut( tr("Ctrl+A") ) ;
	selectAllAct->setStatusTip( tr("Sélectionner l'ensemble du document") ) ;
	connect( selectAllAct, SIGNAL( triggered() ), editor, SLOT( selectAll() ) ) ;
	
	cutAct->setEnabled( false ) ;
	connect( editor, SIGNAL( copyAvailable(bool) ), cutAct, SLOT( setEnabled(bool) ) ) ;
	copyAct->setEnabled( false ) ;
	connect( editor, SIGNAL( copyAvailable(bool) ), copyAct, SLOT( setEnabled(bool) ) ) ;
	pasteAct->setEnabled( !QApplication::clipboard()->text().isEmpty() ) ;
	connect( QApplication::clipboard(), SIGNAL( dataChanged() ), this, SLOT( clipboardDataChanged() ) ) ;
	
	// actions 'recherche'
	
	searchAct = new QAction( QIcon(":/images/search.png"), tr("Rechercher..."), this ) ;
	searchAct->setShortcut( tr("Ctrl+F") ) ;
	searchAct->setStatusTip( tr("Recherche d'occurrences dans le texte") ) ;
	connect( searchAct, SIGNAL( triggered() ), this, SLOT( search() ) ) ;

	toNextAct = new QAction( QIcon(":/images/next.png"), tr("Rechercher le suivant"), this ) ;
	toNextAct->setShortcut( tr("F3") ) ;
	toNextAct->setStatusTip( tr("Recherche de l'occurrence suivante") ) ;
	connect( toNextAct, SIGNAL( triggered() ), this, SLOT( next() ) ) ;

	toPreviousAct = new QAction( QIcon(":/images/previous.png"), tr("Rechercher le précédent"), this ) ;
	toPreviousAct->setShortcut( tr("Shift+F3") ) ;
	toPreviousAct->setStatusTip( tr("Recherche de l'occurrence précédente") ) ;
	connect( toPreviousAct, SIGNAL( triggered() ), this, SLOT( previous() ) ) ;

	replaceAct = new QAction( QIcon(":/images/replace.png"), tr("Remplacer..."), this ) ;
	replaceAct->setShortcut( tr("Ctrl+R") ) ;
	replaceAct->setStatusTip( tr("Remplacement d'occurrences dans le texte") ) ;
	connect( replaceAct, SIGNAL( triggered() ), this, SLOT( replace() ) ) ;

	toLineAct = new QAction( QIcon(":/images/searchline.png"), tr("Aller à la ligne..."), this ) ;
	toLineAct->setShortcut( tr("Ctrl+G") ) ;
	toLineAct->setStatusTip( tr("Positionner le curseur sur une ligne précise") ) ;
	connect( toLineAct, SIGNAL( triggered() ), this, SLOT( cursorAtLine() ) ) ;
	
	// actions 'aide'
	
	helpAct =  new QAction( QIcon(":/images/help.png"), tr("Aide..."), this ) ;
	helpAct->setShortcut( tr("F1") ) ;
	helpAct->setStatusTip( tr("Utilisation de l'application...") ) ;
	connect( helpAct, SIGNAL( triggered() ), this, SLOT( help() ) ) ;

	helpAct->setEnabled( false ) ;

	aboutAct = new QAction( tr("A propos..."), this ) ;
	aboutAct->setStatusTip( tr("A propos de l'application...") ) ;
	connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) ) ;
}

void MainWindow::setupMenus()
{
	// menu 'fichier'
	
	fileMenu = menuBar()->addMenu( tr("&Fichier") ) ;
	fileMenu->addAction( newAct ) ;
	fileMenu->addAction( openAct ) ;
	fileMenu->addAction( saveAct ) ;
	fileMenu->addAction( saveAsAct ) ;
	fileMenu->addSeparator() ;
	fileMenu->addAction( printAct ) ;
	fileMenu->addSeparator() ;
	fileMenu->addAction( exitAct ) ;

	// menu 'édition'
	
	editMenu = menuBar()->addMenu( tr("&Edition") ) ;
	editMenu->addAction( undoAct ) ;
	editMenu->addAction( redoAct ) ;
	editMenu->addAction( cutAct ) ;
	editMenu->addAction( copyAct ) ;
	editMenu->addAction( pasteAct ) ;
	editMenu->addSeparator() ;
	editMenu->addAction( selectAllAct ) ;

	// menu 'recherche'
	
	searchMenu = menuBar()->addMenu( tr("&Recherche") ) ;	
	searchMenu->addAction( searchAct ) ;
	searchMenu->addAction( toNextAct ) ;
	searchMenu->addAction( toPreviousAct ) ;
	searchMenu->addAction( replaceAct ) ;
	searchMenu->addSeparator() ;
	searchMenu->addAction( toLineAct ) ;

	// menu 'aide'

	helpMenu = menuBar()->addMenu( tr("&Aide") ) ;
	helpMenu->addAction( helpAct ) ;
	helpMenu->addAction( aboutAct ) ;
}

void MainWindow::setupToolBars()
{
	// barre d'outils 'fichier'
	
	fileToolBar = addToolBar( tr("Fichier") ) ;
	fileToolBar->addAction( newAct ) ;
	fileToolBar->addAction( openAct ) ;
	fileToolBar->addAction( saveAct ) ;
	fileToolBar->addAction( printAct ) ;

	// barre d'outils 'édition'
	
	editToolBar = addToolBar( tr("Edition") ) ;
	editToolBar->addAction( undoAct ) ;
	editToolBar->addAction( redoAct ) ;
	editToolBar->addAction( cutAct ) ;
	editToolBar->addAction( copyAct ) ;
	editToolBar->addAction( pasteAct ) ;
	
	// barre d'outils 'recherche'
	
	searchToolBar = addToolBar( tr("Recherche") ) ;
	searchToolBar->addAction( searchAct ) ;
	searchToolBar->addAction( toNextAct ) ;
	searchToolBar->addAction( toPreviousAct ) ;
	searchToolBar->addAction( replaceAct ) ;
	searchToolBar->addAction( toLineAct ) ;
}

// configuration de la barre d'état

void MainWindow::setupStatusBar()
{
	statusBar()->showMessage( tr("Prêt") ) ;
	
	cursorPos = new QLabel("1 : 1") ;
	cursorPos->setMinimumWidth( 60 ) ;
    cursorPos->setFrameShape( QFrame::Box ) ;
    cursorPos->setFrameShadow( QFrame::Raised ) ;
	cursorPos->setAlignment( Qt::AlignCenter ) ;
    statusBar()->addPermanentWidget( cursorPos ) ;

    QLabel* spacer1 = new QLabel(" ") ;
    statusBar()->addPermanentWidget( spacer1 ) ;

    colorSelector = new QPushButton("") ;

    QString bkcolor = QString("background-color: rgb(%1,%2,%3)")
                        .arg(currentBkColor.red())
                        .arg(currentBkColor.green())
                        .arg(currentBkColor.blue()) ;
    colorSelector->setStyleSheet(bkcolor) ;

    colorSelector->setToolTip("Couleur de fond...") ;
    colorSelector->setMaximumWidth( 20 ) ;
    colorSelector->setMaximumHeight( 16 ) ;
    statusBar()->addPermanentWidget( colorSelector ) ;

    QLabel* spacer2 = new QLabel(" ") ;
    statusBar()->addPermanentWidget( spacer2 ) ;

    fontSelector = new QPushButton("*") ;
    fontSelector->setToolTip("Police de caractères...") ;
    fontSelector->setMaximumWidth( 20 ) ;
    fontSelector->setMaximumHeight( 16 ) ;
    statusBar()->addPermanentWidget( fontSelector ) ;
}

// sélection de la couleur de fond

void MainWindow::setupEditorBkColor()   // slot
{
    QColor color = QColorDialog::getColor(currentBkColor, this ) ;
    if ( color.isValid() ) {
        currentBkColor = color ;
        QString bkcolor = QString("background-color: rgb(%1,%2,%3)")
                            .arg(currentBkColor.red())
                            .arg(currentBkColor.green())
                            .arg(currentBkColor.blue()) ;
        colorSelector->setStyleSheet(bkcolor) ;
        setupEditor() ;
    }
}

// sélection de la police de caractères

void MainWindow::setupEditorFont()      // slot
{
    bool ok ;
    QFont font = QFontDialog::getFont( &ok, currentFont, this ) ;
    if ( ok ) {
        currentFont = font ;
        setupEditor() ;
        editor->setPlainText( editor->toPlainText() ) ;
    }
}
