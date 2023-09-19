// clozenge.h

#ifndef CLOZENGE_H
#define CLOZENGE_H

#include "crectangle.h"
class CDraft;

class CLozenge : public CRectangle
{

public:
	CLozenge(double width, double height) : CRectangle(width, height) {}

	std::string draw() { return "CLozenge::draw()"; }
	virtual std::string className() const { return "CLozenge"; }
	virtual void draw(CDraft &dr) const
	{
		CPoint pts[4];
		pts[0].set(getX(), getY() + ((getYEnd() - getY()) / 2));
		pts[1].set(getXEnd() - ((getXEnd() - getX()) / 2), getY());
		pts[2].set(getXEnd(), (getYEnd() - ((getYEnd() - getY()) / 2)));
		pts[3].set(getX() + ((getXEnd() - getX()) / 2), getYEnd());

		if (!isVisible())
			return;
		dr.poly(getPos(), 4, pts, getColor(), isFill());
	};
};

#endif
