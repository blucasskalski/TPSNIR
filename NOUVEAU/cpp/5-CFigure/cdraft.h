/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cdraft.h
 |
 |	Projet :		cfigure
 |	Sujet :     	illustration du cours "Langage C++" Part. 3
 |
 |  Auteur :		Alain Menu
 |	Version :		0.3
 |	Création :		nov 2005
 |	Mise à jour :	03/10/2013
 |
 |	Fabrication :	librairie XamGraph version SDL-0.2x ou sup. requise
 + ------------------------------------------------------------------------- */

#ifndef CDRAFT_H
#define CDRAFT_H

#include <xamgraph.h>
#include "cpoint.h"
#include <string>


// annonces de classes

class CRectangle ;

// classe CDraft : gestion d'une zone de dessin 2D

class CDraft : public XamGraph
{
	CPoint	org ;
	int		scale ;

	void moveTo(double x, double y ) ;
	void lineTo(double x, double y ) ;
	void anchor(CPoint p ) ;

	static bool verbose ;

  public :
	CDraft(int w = 640, int h = 480 ) ;
	~CDraft() ;

	static void setVerbose(bool v ) { verbose = v ; }

	int getX() const { return (int)org.getX() ; }	// origine du repère
	int getY() const { return (int)org.getY() ; }
	void setX(int v ) { org.setX( (double)v ) ; }
	void setY(int v ) { org.setY( (double)v ) ; }

	int getScale() const { return scale ; }			// échelle du repère
	void setScale(int v ) { scale = v ; }

	void draw(bool grad = false ) ;					// dessin du repère gradué

	// primitives de dessin

	void line(CPoint p1, CPoint p2, int color = XAM_BLACK ) ;
	void poly(CPoint p, int nbPts, CPoint* pts, int color = XAM_BLACK, bool fill = false ) ;
	void text(CPoint p, std::string s, int color = XAM_BLACK ) ;
	void text(CRectangle r, std::string s ) ;
} ;

#endif
