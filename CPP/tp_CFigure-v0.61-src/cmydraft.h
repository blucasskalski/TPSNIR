#ifndef CMYDRAFT_H
#define CMYDRAFT_H
#include "cbutton.h"
#include "cdraft.h"
#include "clabel.h"
#include "clozenge.h"
#include "crectangle.h"
#include "csquare.h"
#include "cvector.h"
#include <string>

class CVector;
class CRectangle;

class CMydraft : public CDraft {
public:
  CMydraft();
  CMydraft(const CMydraft &) = default;
  CMydraft(int w = 640, int h = 480) : CDraft(w, h) {}
  void draw(bool grad = false) { CDraft::draw(grad); }
  void draw(const CVector &v);
  void draw(const CSquare &s);
  void draw(const CRectangle &r);
  void draw(const CLozenge &l);
  void draw(const CLabel &l);
  void draw(const CButton &b);
};

#endif // !CMYDRAFT_H
