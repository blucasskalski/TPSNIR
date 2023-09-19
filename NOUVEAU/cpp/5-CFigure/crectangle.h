// crectangle.h

#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "cvector.h"
#include <cmath>
class CDraft;

class CRectangle : public CVector
{
private:
	//bool fill;

public:
	CRectangle(double width, double height)
		: CVector(width, -height) /*fill(false)*/ {}

	/*void setFill(bool v) { fill = v; }
	bool isFill() const { return fill; }*/

	double getPerimeter() const
	{
		return 2 * (std::fabs(dx) + std::fabs(dy));
	}

	virtual std::string draw() { return "CRectangle::draw()"; }
	virtual std::string className() const { return "CRectangle"; }
	virtual void draw(CDraft &dr) const {
{
	CPoint pts[4];
    pts[0].set(getX(), getY());
    pts[1].set(getXEnd(), getY());
    pts[2].set(getXEnd(), getYEnd());
    pts[3].set(getX(), getYEnd());

    if (!isVisible())
        return;
    dr.poly(getPos(), 4, pts, getColor(), isFill());
}
};
};

#endif
