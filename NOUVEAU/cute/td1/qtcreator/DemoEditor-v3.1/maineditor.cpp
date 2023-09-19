/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			maineditor.cpp
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
#include <QInputDialog>

#include "mainwindow.h"
#include "dlgsearch.h"

void MainWindow::cursorPosition()		// slot
{
	QTextCursor	curs = editor->textCursor() ;
	QTextBlock	block = curs.block() ;
	QTextBlock	begin = editor->document()->begin() ;
	int x = curs.position() - block.position() ;
	int y = 0 ;
	while ( begin != block ) { begin = begin.next() ; y++ ; }
	cursorPos->setText( QString("%1 : %2").arg( x + 1 ).arg( y + 1 ) ) ;
}

void MainWindow::cursorAtLine()			// slot
{
	int	 max = 0 ;	// nombre courant de lignes
	QTextBlock	begin = editor->document()->begin() ;
	QTextBlock	end   = editor->document()->end() ;
	while ( begin != end ) { begin = begin.next() ; max++ ; }
	
	bool ok ;

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    int  i = QInputDialog::getInteger( this, tr("Aller à la ligne..."), "", 1, 1, max, 1, &ok ) ;
#else
    int  i = QInputDialog::getInt( this, tr("Aller à la ligne..."), "", 1, 1, max, 1, &ok ) ;
#endif

    if ( !ok ) return ;

	QTextBlock	block = editor->document()->begin() ;
	while ( --i )	block = block.next() ;
	QTextCursor	curs( block ) ;
	curs.select( QTextCursor::LineUnderCursor ) ;	// sélection de la ligne
	editor->setTextCursor( curs ) ;
	editor->ensureCursorVisible() ;
	cursorPosition() ;
}

void MainWindow::search()				// slot
{
	if ( !dlgSearch->select() ) return ;
	next() ;
}

void MainWindow::replace()				// slot
{
	if ( !dlgSearch->select(true) )	return ;
	next() ;
}

void MainWindow::next()					// slot
{
	if ( ! dlgSearch->next() ) {}
	cursorPosition() ;
}

void MainWindow::previous()				// slot
{
	if ( ! dlgSearch->previous() ) {}
	cursorPosition() ;
}

void MainWindow::setupEditor()
{
	QPalette	palette ;
    palette.setColor( QPalette::Base, currentBkColor ) ;
    editor->setPalette( palette ) ;

    editor->document()->setDefaultFont( currentFont ) ;
    QTextCharFormat	format ;
    format.setFont( currentFont ) ;
    editor->setCurrentCharFormat( format ) ;
    editor->setLineWrapMode( QTextEdit::NoWrap ) ;
}

void MainWindow::clipboardDataChanged()	// slot
{
	pasteAct->setEnabled( !QApplication::clipboard()->text().isEmpty() ) ;
}
