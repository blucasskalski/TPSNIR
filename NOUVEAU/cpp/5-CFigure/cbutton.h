// cbutton.h

#ifndef CBUTTON_H
#define CBUTTON_H

#include "clabel.h"
#include "crectangle.h"
#include <string>
class CDraft;

class CButton : public CLabel, public CRectangle
{

public:
	CButton(const CPoint &pos, double w, double h, const std::string &s)
		: CLabel(s), CRectangle(w, h)
	{
		setPos(pos);
	}

	virtual std::string draw() { return CRectangle::draw() + " + " + CLabel::draw(); }
	virtual double area() const { return CRectangle::area(); }
	virtual std::string className() const { return "CButton"; }
	virtual void draw(CDraft &dr) const
	{
		if (!isVisible())
			return;
		CPoint pts[4];
		pts[0].set(CRectangle::getX(), CRectangle::getY());
		pts[1].set(CRectangle::getXEnd(), CRectangle::getY());
		pts[2].set(CRectangle::getXEnd(), CRectangle::getYEnd());
		pts[3].set(CRectangle::getX(), CRectangle::getYEnd());
		dr.poly(CRectangle::getPos(), 4, pts, CRectangle::getColor(), CRectangle::isFill());
		dr.text((CRectangle)*this, CLabel::getText());
	};
};

#endif
