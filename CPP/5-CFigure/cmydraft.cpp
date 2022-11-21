#include "cmydraft.h"
#include "cdraft.h"

void CMydraft::draw(const CVector &v) {
  if (!v.isVisible())
    return;
  line(v.getPos(), v.getEnd(), v.getColor());
}

void CMydraft::draw(const CRectangle &r) {
  if (!v.isVisible())
    return;
}
