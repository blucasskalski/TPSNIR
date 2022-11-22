// clozenge.h

#ifndef CLOZENGE_H
#define CLOZENGE_H

#include "crectangle.h"

class CLozenge : public CRectangle {

public:
  CLozenge(double width, double height) : CRectangle(width, height) {}

  std::string draw() { return "CLozenge::draw()"; }
  void draw(CDraft &dr) const {}

  virtual std::string className() const { return "CLozenge"; }
};

#endif
