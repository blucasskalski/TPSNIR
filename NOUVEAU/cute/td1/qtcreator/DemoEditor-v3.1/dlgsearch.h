/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			dlgsearch.h
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

#ifndef	DLGSEARCH_H
#define	DLGSEARCH_H

#include ".uic/ui_dlgsearch.h"
#include <QTextEdit>
#include <QTextCursor>

class DlgSearch : public QDialog , private Ui::DlgSearch
{
	Q_OBJECT
	
  public :
	DlgSearch(QTextEdit* editor, QWidget* parent = 0 ) ;
	int 	select(bool replace = false ) ;
	bool	next() ;
	bool	previous() ;
	QString	current() { return currentSearch ; }
	
  private :
	QTextEdit*	editor ;					// document de travail
	QTextDocument::FindFlags	flags ;		// mode de recherche
	QTextCursor*	cursor ;				// curseur courant dans le document
	bool	modeReplace ;					// mode cherche/remplace
	QString	currentSearch ;					// chaîne recherchée courante
	QString currentReplace ;				// chaîne de remplacment courante
	QStringList	searchList ;				// liste des recherches
	QStringList	replaceList ;				// liste des remplacements
} ;

#endif
