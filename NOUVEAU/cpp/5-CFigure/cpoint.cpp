// cpoint.cpp

#include "cpoint.h"
#include <sstream>

std::string CPoint::asString() const
{
	std::ostringstream	oss ;
	oss << '(' << x << ',' << y << ')' ;
	return oss.str() ;
}

CPoint&	CPoint::operator +=(const CPoint& p )
{
	set( x + p.x, y + p.y ) ;
	return *this ;
}

CPoint& CPoint::operator *=(double v )
{
	set( x * v, y * v ) ;
	return *this ;
}

bool CPoint::operator ==(const CPoint& p )
{
	return ( x == p.x )&&( y == p.y ) ;
}

bool CPoint::operator !=(const CPoint& p )
{
	return !( *this == p ) ;
}

std::ostream& operator <<(std::ostream& s, const CPoint& p )
{
	s << p.asString() ;
	return s ;
}

