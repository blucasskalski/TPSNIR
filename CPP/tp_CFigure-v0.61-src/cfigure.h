// cfigure.h

#ifndef CFIGURE_H
#define CFIGURE_H

#include "cdraft.h"
#include "cpoint.h"
#include <string>

class CDraft;

class CFigure {
private:
  CPoint pos;
  bool visible;
  bool fill;

public:
  CFigure() : pos(0, 0), visible(false) {}
  CFigure(const CPoint &p, bool v = false) : pos(p), visible(v), fill(false) {}

  double getX() const { return pos.getX(); }
  double getY() const { return pos.getY(); }
  CPoint getPos() const { return pos; }
  bool isVisible() const { return visible; }

  void setX(double x) { pos.setX(x); }
  void setY(double y) { pos.setY(y); }
  void setPos(const CPoint &p) { pos = p; }
  void setVisible(bool v) { visible = v; }

  virtual std::string draw() { return "CFigure::draw()"; }
  virtual void draw(CDraft &dr) const = 0;

  virtual double area() const = 0;
  virtual std::string className() const = 0;

  void setFill(bool v) { fill = v; }
  bool getFill() const { return fill; }

  int color = 0;
  int getColor() const { return this->color; }
  void setColor(int color) { this->color = color; }
};

#endif
