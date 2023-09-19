// clabel.h

#ifndef CLABEL_H
#define CLABEL_H

#include "cfigure.h"
#include "crectangle.h"
#include <string>
class CDraft;

class CLabel : virtual public CFigure
{

	std::string text; 

public:
	CLabel(const std::string &s) : text(s) {}

	virtual std::string draw() { return "CLabel::draw()"; }

	virtual double area() const { return 0; /* todo */ }
	virtual std::string className() const { return "CLabel"; }
	std::string getText() const { return text; }
	virtual void draw(CDraft &dr) const
	{
		if (!isVisible())
			return;
		dr.text(getPos(), getText(), getColor());
	};
};

#endif
