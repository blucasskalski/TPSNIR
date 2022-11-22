// csquare.h

#ifndef CSQUARE_H
#define CSQUARE_H

#include "cdraft.h"
#include "crectangle.h"

class CSquare : public CRectangle {

public:
  CSquare(double size) : CRectangle(size, size) {}

  std::string draw() { return "CSquare::draw()"; }

  virtual std::string className() const { return "CSquare"; }
  void draw(CDraft &dr) const {}
};

#endif
