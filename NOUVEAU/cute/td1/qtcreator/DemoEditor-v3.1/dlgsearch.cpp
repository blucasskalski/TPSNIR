/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			dlgsearch.cpp
 |
 |	Projet :		DemoEditor - classe DLgSearch
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

#include "dlgsearch.h"

DlgSearch::DlgSearch(QTextEdit* editor, QWidget* parent ) : QDialog(parent )
{
	setupUi(this) ;
	this->editor = editor ;
	cursor = new QTextCursor( editor->document() ) ;
    flags &= 0 ;
}

int DlgSearch::select(bool replace )
{
	modeReplace = replace ;
	setWindowTitle( replace ? tr("Remplacer...") : tr("Rechercher...") ) ;
	labReplace->setVisible( replace ) ;
	cbxReplace->setVisible( replace ) ;
	
	cbxSearch->clear() ;
	cbxSearch->addItems( searchList ) ;
	
	if ( ! exec() )	return false ;
	
	QString	s = cbxSearch->currentText() ;
	if ( !searchList.contains( s ) )	searchList << s ;
	searchList.sort() ;
	currentSearch = s ;

	if ( replace ) {
		s = cbxReplace->currentText() ;
		if ( !replaceList.contains( s ) )	replaceList << s ;
		replaceList.sort() ;
		currentReplace = s ;
	}
	
    flags &= 0 ;
	if ( chkEntireDocument->isChecked() ) {
		cursor->movePosition( QTextCursor::Start ) ;
	}
	else {
		*cursor = editor->textCursor() ;
		if ( rbuBackward->isChecked() )		flags |= QTextDocument::FindBackward ;
	}
	if ( chkWholeWords->isChecked() )		flags |= QTextDocument::FindWholeWords ;
	if ( chkCaseSensitive->isChecked() )	flags |= QTextDocument::FindCaseSensitively ;
	
	return true ;
}

bool DlgSearch::next()
{
	if ( cursor->isNull() )	cursor->movePosition( QTextCursor::Start ) ;
		
	*cursor = editor->document()->find( currentSearch, *cursor, flags ) ;
	if ( !cursor->isNull() ) {
		editor->setTextCursor( *cursor ) ;
		if ( modeReplace ) {
			cursor->removeSelectedText() ;
			cursor->insertText( currentReplace ) ;
		}
		return true ;
	}
	return false ;
}

bool DlgSearch::previous()
{
	if ( cursor->isNull() )	cursor->movePosition( QTextCursor::End ) ;

	QTextDocument::FindFlags	flagsBack = flags ;
	if ( flagsBack & QTextDocument::FindBackward )
			flagsBack &= ~QTextDocument::FindBackward ;
	else	flagsBack |=  QTextDocument::FindBackward ;
	
	*cursor = editor->document()->find( currentSearch, *cursor, flagsBack ) ;
	if ( !cursor->isNull() ) {
		editor->setTextCursor( *cursor ) ;
		if ( modeReplace ) {
			cursor->removeSelectedText() ;
			cursor->insertText( currentReplace ) ;
		}
		return true ;
	}
	return false ;
}
