/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			main.cpp
 |
 |	Projet :		Fractales
 |	Sujet :     	fractales déterministes Julia & Mandelbrot
 |
 |  Auteur :		Alain Menu
 |	Version :		0.5
 |	Création :		09/03/2006
 |	Mise à jour :	07/10/2013
 |
 |	Fabrication :	librairie XamGraph version SDL-0.24 ou sup.
 + ------------------------------------------------------------------------- */

#include "cvue.h"
#include "cjulia.h"
#include "cmondelbrot.h"
#include <getopt.h>

#include <iostream>
using namespace std;

CVue *vue;
CJulia *fractale = NULL;

// intercepteurs d'événements liés à la souris

void mouseButtonDownHandler(int x, int y, int button)
{
	if (button == 1)
	{ // bouton gauche ?
		vue->initCapture(x, y);
	}

	if (button == 3)
	{ // bouton droit ?
		if (vue->isCapturing())
		{
			vue->stopCapture();
		}
	}
}

void mouseMoveHandler(int x, int y)
{
	if (vue->isCapturing())
	{
		vue->changeCapture(x, y);
	}
	vue->drawLogicalPosition(x, y);
}

// programme principal

int main(int argc, char *argv[])
{

	bool julia = false;
	int nMax = 200;
	double re = -0.1134;
	double im = 0.8606;
	cout << "Usage : " << argv[0] << "[-n <iter>] [-j [-r <re>] [-i <im>]]" << endl;
	int opt;
	while ((opt = getopt(argc, argv, "n:jr:i:")) != -1)
	{
		switch (opt)
		{
		case 'n':
			nMax = atoi(optarg);
			continue;
		case 'j':
			julia = true;
			continue;
		case 'r':
			re = atof(optarg);
			continue;
		case 'i':
			im = atof(optarg);
			continue;
		}
		break;
	}

	cout << "--> Ensemble de " << (julia ? "Julia" : "Mandelbrot") << endl;
	cout << "--> " << nMax << " Iterations" << endl;
	if (julia)
	{
		cout << "--> C = ( " << re << " , " << im << " )";
		cout << endl;
		fractale = new CJulia(nMax, re, im);
	}
	else
	{
		fractale = new CMondelbrot(nMax);
	}

	vue = new CVue(800, 600, fractale);
	vue->connectMouseButtonDownEvent(mouseButtonDownHandler);
	vue->connectMouseMotionEvent(mouseMoveHandler);
	vue->run();
	delete fractale;
	delete vue;
	return 0;
}
