// cpoint.h

#ifndef CPOINT_H
#define CPOINT_H

#include <iostream>
#include <string>

class CPoint {

  double x;
  double y;

public:
  CPoint() : x(0), y(0) {}
  CPoint(double x, double y) { set(x, y); }
  CPoint(const CPoint &p) { set(p.x, p.y); }

  double getX() const { return x; }
  double getY() const { return y; }
  void setX(double x) { this->x = x; }
  void setY(double y) { this->y = y; }
  void set(double x, double y) {
    this->x = x;
    this->y = y;
  }

  bool isNull() const { return (x == 0) && (y == 0); }
  std::string asString() const;

  CPoint &operator+=(const CPoint &p);
  CPoint &operator*=(double v);
  bool operator==(const CPoint &p);
  bool operator!=(const CPoint &p);

  friend std::ostream &operator<<(std::ostream &s, const CPoint &p);
};

#endif
