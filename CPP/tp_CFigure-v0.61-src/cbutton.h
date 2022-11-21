// cbutton.h

#ifndef CBUTTON_H
#define CBUTTON_H

#include "clabel.h"
#include "crectangle.h"
#include <string>

class CButton : public CLabel, public CRectangle {

public:
  CButton(const CPoint &pos, double w, double h, const std::string &s)
      : CLabel(s), CRectangle(w, h) {
    setPos(pos);
  }

  virtual std::string draw() {
    return CRectangle::draw() + " + " + CLabel::draw();
  }
  void draw(CDraft &dr) const {}

  virtual double area() const { return CRectangle::area(); }
  virtual std::string className() const { return "CButton"; }
};

#endif
