/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			main.cpp
 |
 |	Projet :		DemoEditor - programme principal
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

#include <QApplication>
#include <QIcon>
#include "mainwindow.h"

int	main(int argc, char* argv[] )
{
	QApplication	app(argc, argv ) ;

#ifndef Q_OS_MAC
    app.setWindowIcon( QIcon("images/qam47.xpm") ) ;
#endif

    // widget principal et unique de l'application
	MainWindow*	mainWindow = new MainWindow ;
    mainWindow->setWindowTitle( "DemoEditor V3.1" ) ;

	// projection du widget	
	mainWindow->show() ;

	// boucle d'événements...
    return app.exec() ;
}
