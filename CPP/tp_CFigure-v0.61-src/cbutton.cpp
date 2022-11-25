#include "cbutton.h"

void CButton::draw(CDraft &dr) const {
  if (!isVisible())
    return;
  CRectangle r(getXEnd() - getX(), getYEnd() - getY() * 0.75);
  CPoint tab[4]{CPoint(getX(), getY()), CPoint(getXEnd(), getY()),
                CPoint(getXEnd(), getYEnd()), CPoint(getX(), getYEnd())};
  dr.poly(getPos(), 4, tab, getColor(), isFill());

  r.setVisible(true);
  r.setPos(getPos());
  dr.text(r, getText());
}
