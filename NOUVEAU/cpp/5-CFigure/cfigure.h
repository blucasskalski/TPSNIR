// cfigure.h

#ifndef CFIGURE_H
#define CFIGURE_H
#include "cpoint.h"
#include <string>
#include "cdraft.h"
class CDraft;

class CFigure
{
	CPoint pos;
	bool visible;
	int color;
	bool fill;

public:
	CFigure() : pos(0, 0), visible(false), color(0), fill(false)  {}
	CFigure(const CPoint &p, bool v = false, int c = 0) : pos(p), visible(v), color(c){}

	double getX() const { return pos.getX(); }
	double getY() const { return pos.getY(); }
	CPoint getPos() const { return pos; }
	bool isVisible() const { return visible; }

	void setX(double x) { pos.setX(x); }
	void setY(double y) { pos.setY(y); }
	void setPos(const CPoint &p) { pos = p; }
	void setVisible(bool v) { visible = v; }

	virtual std::string draw() { return "CFigure::draw()"; }
	virtual double area() const = 0;
	virtual std::string className() const = 0;
	virtual void draw(CDraft& dr ) const = 0 ;
	int getColor() const { return color; }
	void setColor(int c) { color = c; }

	void setFill(bool v) { fill = v; }
	bool isFill() const { return fill; }

};

#endif
