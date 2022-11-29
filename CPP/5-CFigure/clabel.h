// clabel.h

#ifndef CLABEL_H
#define CLABEL_H

#include "cdraft.h"
#include "cfigure.h"
#include "crectangle.h"
#include <string>
class CLabel : virtual public CFigure {

  std::string text;

public:
  CLabel(const std::string &s) : text(s) {}

  virtual std::string draw() { return "CLabel::draw()"; }

  virtual double area() const { return 0; /* todo */ }
  virtual std::string className() const { return "CLabel"; }

  std::string getText() const { return text; }
  void draw(CDraft &dr) const;
};

#endif
