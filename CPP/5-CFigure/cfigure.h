// cfigure.h

#ifndef CFIGURE_H
#define CFIGURE_H

#include "cpoint.h"
#include <string>

class CFigure {
	CPoint	pos ;
	bool	visible ;
	
  public :
  	CFigure() : pos(0,0), visible(false) {}
  	CFigure(const CPoint& p, bool v = false ) : pos(p), visible(v) {}

  	double getX() const { return pos.getX() ; }
  	double getY() const { return pos.getY() ; }
  	CPoint getPos() const { return pos ; }
  	bool isVisible() const { return visible ; }

	void setX(double x ) { pos.setX(x) ; }
	void setY(double y ) { pos.setY(y) ; }
	void setPos(const CPoint& p ) { pos = p ; } 
	void setVisible(bool v ) { visible = v ; }
	
	virtual std::string draw() { return "CFigure::draw()" ; }
	
	virtual double area() const = 0 ;
	virtual std::string className() const = 0 ;

	int color = 0;
	int getColor() const { return this->color; }	
	void setColor(int color) { this->color = color; }
} ;

#endif

