#ifndef CMYDRAFT_H
#define CMYDRAFT_H
#include "cdraft.h"
#include "cvector.h"
#include <string>

class CVector;

class CMydraft : public CDraft {
public:
  CMydraft();
  CMydraft(const CMydraft &) = default;
  CMydraft(int w = 640, int h = 480) : CDraft(w, h) {}
  void draw(bool grad = false) { CDraft::draw(grad); }
  void draw(const CVector &v);

private:
};

#endif // !CMYDRAFT_H
