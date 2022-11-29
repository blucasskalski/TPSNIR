#include "crectangle.h"

void CRectangle::draw(CDraft &dr) const {
  if (!isVisible())
    return;
  CPoint tab[4]{CPoint(CRectangle::getX(), CRectangle::getY()),
                CPoint(CRectangle::getX(), CRectangle::getYEnd()),
                CPoint(CRectangle::getXEnd(), CRectangle::getYEnd()),
                CPoint(CRectangle::getXEnd(), CRectangle::getY())};
  dr.poly(CPoint(CRectangle::getX(), CRectangle::getY()), 4, tab, getColor(),
          getFill());
}
