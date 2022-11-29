#include "csquare.h"

void CSquare::draw(CDraft &dr) const {
  if (!isVisible())
    return;
  CPoint tab[4]{CPoint(getX(), getY()), CPoint(getX(), getYEnd()),
                CPoint(getXEnd(), getYEnd()), CPoint(getXEnd(), getY())};
  dr.poly(getPos(), 4, tab, getColor(), getFill());
}
