/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			mainwindow.h
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include ".uic/ui_mainwindow.h"
#include <QAction>
#include "search.h"

class DlgSearch ;
class QLabel ;
class QPushButton ;

class MainWindow : public QMainWindow , private Ui::MainWindow
{
	Q_OBJECT
	
  public :
	MainWindow(QWidget* parent = 0 ) ;

  protected :
	void closeEvent( QCloseEvent* event ) ;
	
  public slots :
	void newFile() ;
	void openFile() ;
	bool saveFile() ;
	bool saveAsFile() ;
	void printFile() ;
	void documentWasModified() ;
	void clipboardDataChanged() ;
	void cursorPosition() ;
	void cursorAtLine() ;
	void search() ;
	void replace() ;
	void next() ;
	void previous() ;
	void help() ;
	void about() ;
		
  private :
	void readSettings() ;
	void writeSettings() ;
	bool maybeSave() ;
	bool save( const QString& fileName ) ;
	void load( const QString& fileName ) ;
	void setCurrentFile( const QString& fileName ) ;
	void setupEditor() ;
	void createActions() ;
	void setupMenus() ;
	void setupToolBars() ;
	void setupStatusBar() ;

  private slots :
    void setupEditorBkColor() ;
    void setupEditorFont() ;

  private :
    QFont       currentFont ;
    QColor      currentBkColor ;
	QString		currentFile ;
	QString		currentDir ;
	QLabel*		cursorPos ;
    QPushButton*    fontSelector ;
    QPushButton*    colorSelector ;
	DlgSearch*	dlgSearch ;
	
	QAction*	newAct ;
	QAction*	openAct ;
	QAction*	saveAct ;
	QAction*	saveAsAct ;
	QAction*	printAct ;
	QAction*	exitAct ;
	
	QAction*	undoAct ;
	QAction*	redoAct ;
	QAction*	cutAct ;
	QAction*	copyAct ;
	QAction*	pasteAct ;
	QAction*	selectAllAct ;
	
	QAction*	searchAct ;
	QAction*	toNextAct ;
	QAction*	toPreviousAct ;
	QAction*	replaceAct ;
	QAction*	toLineAct ;

	QAction*	helpAct ;	
	QAction*	aboutAct ;

	QMenu*		fileMenu ;
	QMenu*		editMenu ;
	QMenu*		searchMenu ;
	QMenu*		helpMenu ;
	
	QToolBar*	fileToolBar ;
	QToolBar*	editToolBar ;
	QToolBar*	searchToolBar ;

private:
    Search*     searchDlg;
} ;

#endif
