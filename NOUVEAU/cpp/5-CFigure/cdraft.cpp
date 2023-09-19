/* ----------------------------------------------------------------------------
 |	STS I.R.I.S.    Lycée La Fayette 0770920G
 + ----------------------------------------------------------------------------
 |
 |	Nom :			cdraft.cpp
 |
 |	Projet :		cfigure
 |	Sujet :     	illustration du cours "Langage C++" Part. 3
 |
 |  Auteur :		Alain Menu
 |	Version :		0.5
 |	Création :		nov 2005
 |	Mise à jour :	15/11/2017
 |
 |	Fabrication :	librairie XamGraph version SDL-2
 + ------------------------------------------------------------------------- */

#include "cdraft.h"
#include "crectangle.h"

#include <iostream>

bool CDraft::verbose = false ;

// Construction d'une zone de dessin de dimensions [ w x h ]  pixels

CDraft::CDraft(int w, int h ) : XamGraph( w, h, "TP CFigure" )
{
	org = CPoint(0, 0 ) ;
	scale = 1 ;

	clearScreen( XAM_WHITE ) ;

	if ( verbose )	std::cerr << "CDraft v0.61 (c)2007-2017 Alain Menu" << std::endl ;
	if ( verbose )	std::cerr << "- " << w << " x " << h << " pixels..." << std::endl ;
}

// Destruction de la zone graphique

CDraft::~CDraft()
{
	if ( verbose )	std::cerr << "Bye..." << std::endl ;
}

// Méthodes privées de conversion coord. réel / coord. pixels

void CDraft::moveTo(double x, double y)
{
	XamGraph::moveTo( (int)( org.getX() + getScale() * x ), (int)( org.getY() - getScale() * y ) ) ;
}

void CDraft::lineTo(double x, double y )
{
	XamGraph::lineTo( (int)( org.getX() + getScale() * x ), (int)( org.getY() - getScale() * y ) ) ;
}

// Méthode privée de tracé d'un point d'ancrage

void CDraft::anchor(CPoint p )
{
	setColor( XAM_BLACK ) ;

	circle(	(int)( org.getX() + getScale() * p.getX() ),
			(int)( org.getY() - getScale() * p.getY() ),
			5 ) ;
}

// méthodes publiques

void CDraft::draw( bool grad )
{
	setLineThickness( 1 ) ;
	setLineStyle( XAM_DASHED_LINE ) ;
	setColor( XAM_LIGHT_GRAY ) ;
	XamGraph::moveTo( (int)org.getX(), 0 ) ;
	XamGraph::lineTo( (int)org.getX(), maxY() ) ;
	XamGraph::moveTo( 0, (int)org.getY() ) ;
	XamGraph::lineTo( maxX(), (int)org.getY() ) ;

	if ( !grad ) return ;

	setLineStyle( XAM_SOLID_LINE ) ;
	for ( int i = (int)org.getX(), j = (int)org.getY() ; i > 0 ; i -= getScale() ) {
		XamGraph::moveTo( i, j - 4 ) ; lineRel( 0, 8 ) ;
	}
	for ( int i = (int)org.getX(), j = (int)org.getY() ; i < maxX() ; i += getScale() ) {
		XamGraph::moveTo( i, j - 4 ) ; lineRel( 0, 8 ) ;
	}
	for ( int j = (int)org.getY(), i = (int)org.getX() ; j > 0 ; j -= getScale() ) {
		XamGraph::moveTo( i - 4 , j ) ; lineRel( 8, 0 ) ;
	}
	for ( int j = (int)org.getY(), i = (int)org.getX() ; j < maxY() ; j += getScale() ) {
		XamGraph::moveTo( i - 4 , j ) ; lineRel( 8, 0 ) ;
	}
}

void CDraft::line(CPoint p1, CPoint p2, int color )
{
	setLineThickness( 2 ) ;
	setColor( color ) ;
	moveTo( p1.getX(), p1.getY() ) ;
	lineTo( p2.getX(), p2.getY() ) ;
	anchor( p1 ) ;
	if ( verbose )	std::cerr << "- Line() : " << p1 << std::endl ;
}

void CDraft::text(CPoint p, std::string s, int color )
{
	setTextAlignment( XAM_ALIGNMENT_LEFT ) ;
	setColor( color) ;

	int x = (int)( org.getX() + getScale() * p.getX() ) ;
	int y = (int)( org.getY() - getScale() * p.getY() ) ;

	textOut(x, y, (char *)s.c_str() ) ;
	anchor( p ) ;

	if ( verbose )	std::cerr << "- Text() : " << p << std::endl ;
}

void CDraft::text(CRectangle r, std::string s )
{
	setTextAlignment( XAM_ALIGNMENT_LEFT ) ;

	if ( r.isFill() )	setColor( XAM_BLACK ) ;
	else				setColor( r.getColor() ) ;

	int x = (int)( org.getX() + getScale() * r.getX() ) ;
	int y = (int)( org.getY() - getScale() * r.getY() ) ;

	double w = r.getXEnd() - r.getX() ;
	double h = r.getYEnd() - r.getY() ;
	x += (int)( w * getScale() - textWidth( (char *)s.c_str() ) ) / 2 ;
	y -= (int)( h * getScale() + textHeight() ) / 2 ;

	textOut(x, y, (char *)s.c_str() ) ;
	anchor( r.getPos() ) ;

	if ( verbose )	std::cerr << "- Text() : " << r.getPos() << std::endl ;
}

void CDraft::poly(CPoint p, int nbPts, CPoint* pts, int color, bool fill )
{
	int*	ptab = new int[ ( nbPts + 1 ) * 2 ] ;

	int i ;
	for ( i = 0 ; i < nbPts ; i++ ) {
		ptab[ 2*i ]     = (int)( org.getX() + getScale() * pts[i].getX() ) ;
		ptab[ 2*i + 1 ] = (int)( org.getY() - getScale() * pts[i].getY() ) ;
	}
	ptab[ 2*i ]     = (int)( org.getX() + getScale() * pts[0].getX() ) ;
	ptab[ 2*i + 1 ] = (int)( org.getY() - getScale() * pts[0].getY() ) ;

	setColor( color ) ;

	if ( fill )	filledPolygon(nbPts, ptab ) ;
	else		polygon(nbPts + 1, ptab ) ;

	delete [] ptab ;

	anchor( p ) ;
	if ( verbose )	std::cerr << "- Poly() : " << p << std::endl ;
}

