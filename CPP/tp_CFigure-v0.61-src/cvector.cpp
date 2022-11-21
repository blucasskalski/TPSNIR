// cvector.cpp

#include "cvector.h"
#include <cmath>

CPoint CVector::getEnd() const
{
	return CPoint( getXEnd(), getYEnd() ) ;
}

double CVector::getLength() const
{
	return std::sqrt( dx * dx + dy * dy ) ;
}

void CVector::draw(CDraft &dr)const{
	if(!isVisible()) return;
	dr.line(getPos(), getEnd(), getColor());
}

