// cvector.h

#ifndef CVECTOR_H
#define CVECTOR_H

#include "cfigure.h"
#include <cmath>

class CVector : virtual public CFigure {
protected:
  double dx;
  double dy;

public:
  CVector(const CPoint &e1, const CPoint &e2) : CFigure(e1) {
    dx = e2.getX() - getX();
    dy = e2.getY() - getY();
  }
  CVector(double x, double y) : dx(x), dy(y) {}

  double getXEnd() const { return getX() + dx; }
  double getYEnd() const { return getY() + dy; }
  CPoint getEnd() const;
  double getLength() const;

  virtual std::string draw() { return "CVector::draw()"; }

  void draw(CDraft &dr) const;

  virtual double area() const { return std::fabs(dx * dy); }
  virtual std::string className() const { return "CVector"; }
};

#endif
