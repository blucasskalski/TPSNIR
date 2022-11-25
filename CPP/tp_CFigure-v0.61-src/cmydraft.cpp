#include "cmydraft.h"
#include "cbutton.h"
#include "cdraft.h"
#include "clabel.h"
#include "clozenge.h"
#include "cpoint.h"
#include "crectangle.h"
#include "csquare.h"

void CMydraft::draw(const CVector &v) {
  if (!v.isVisible())
    return;
  line(v.getPos(), v.getEnd(), v.getColor());
}

void CMydraft::draw(const CRectangle &r) {
  if (!r.isVisible())
    return;
  CPoint tab[4]{CPoint(r.getX(), r.getY()), CPoint(r.getX(), r.getYEnd()),
                CPoint(r.getXEnd(), r.getYEnd()),
                CPoint(r.getXEnd(), r.getY())};
  poly(CPoint(r.getX(), r.getY()), 4, tab, r.getColor(), r.isFill());
}

void CMydraft::draw(const CSquare &s) {
  if (!s.isVisible())
    return;
  CPoint tab[4]{CPoint(s.getX(), s.getY()), CPoint(s.getX(), s.getYEnd()),
                CPoint(s.getXEnd(), s.getYEnd()),
                CPoint(s.getXEnd(), s.getY())};
  poly(CPoint(s.getX(), s.getY()), 4, tab, s.getColor(), s.isFill());
}

void CMydraft::draw(const CLozenge &l) {
  if (!l.isVisible())
    return;
  CPoint tab[4]{CPoint(l.getX() + (l.getXEnd() - l.getX()) / 2, l.getY()),
                CPoint(l.getX(), l.getYEnd() - (l.getYEnd() - l.getY()) / 2),
                CPoint(l.getXEnd() - (l.getXEnd() - l.getX()) / 2, l.getYEnd()),
                CPoint(l.getXEnd(), l.getY() + (l.getYEnd() - l.getY()) / 2)};
  poly(CPoint(l.getX(), l.getY()), 4, tab, l.getColor(), l.isFill());
}

void CMydraft::draw(const CLabel &L) {
  if (!L.isVisible())
    return;
  CDraft::text(L.getPos(), L.getText(), L.getColor());
}

void CMydraft::draw(const CButton &b) {
  if (!b.isVisible())
    return;
  CRectangle r(b.getXEnd(), b.getYEnd());
  CPoint tab[4]{CPoint(b.getX(), b.getY()), CPoint(b.getXEnd(), b.getY()),
                CPoint(b.getXEnd(), b.getYEnd()),
                CPoint(b.getX(), b.getYEnd())};
  poly(b.getPos(), 4, tab, b.getColor(), b.isFill());

  r.setVisible(true);
  r.setPos(b.getPos());
  CDraft::text(b, b.getText());
}

void CVector::draw(CDraft &dr) const {
  if (!isVisible())
    return;
  dr.line(getPos(), getEnd(), getColor());
}

void CRectangle::draw(CDraft &dr) const {
  if (!isVisible())
    return;
  CPoint tab[4]{CPoint(CRectangle::getX(), CRectangle::getY()),
                CPoint(CRectangle::getX(), CRectangle::getYEnd()),
                CPoint(CRectangle::getXEnd(), CRectangle::getYEnd()),
                CPoint(CRectangle::getXEnd(), CRectangle::getY())};
  dr.poly(CPoint(CRectangle::getX(), CRectangle::getY()), 4, tab,
          CRectangle::getColor(), isFill());
}

void CLozenge::draw(CDraft &dr) const {
  if (!isVisible())
    return;
  CPoint tab[4]{
      CPoint(CLozenge::getX() + (CLozenge::getXEnd() - CLozenge::getX()) / 2,
             CLozenge::getY()),
      CPoint(CLozenge::getX(),
             CLozenge::getYEnd() -
                 (CLozenge::getYEnd() - CLozenge::getY()) / 2),
      CPoint(CLozenge::getXEnd() - (CLozenge::getXEnd() - CLozenge::getX()) / 2,
             CLozenge::getYEnd()),
      CPoint(CLozenge::getXEnd(),
             CLozenge::getY() + (CLozenge::getYEnd() - CLozenge::getY()) / 2)};
  dr.poly(CPoint(CLozenge::getPos()), 4, tab, CLozenge::getColor(),
          CLozenge::isFill());
}
