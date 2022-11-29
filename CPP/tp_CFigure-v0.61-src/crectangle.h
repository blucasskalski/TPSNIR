// crectangle.h

#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "cdraft.h"
#include "cvector.h"
#include <cmath>

class CDraft;

class CRectangle : public CVector {
private:
  bool fill;

public:
  CRectangle();
  CRectangle(double width, double height) : CVector(width, -height) {}

  void setFill(bool v) { fill = v; }
  bool isFill() const { return fill; }

  double getPerimeter() const { return 2 * (std::fabs(dx) + std::fabs(dy)); }

  virtual std::string draw() { return "CRectangle::draw()"; }
  void draw(CDraft &dr) const;

  virtual std::string className() const { return "CRectangle"; }
};

#endif
