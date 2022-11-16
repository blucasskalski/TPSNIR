#include "cmydraft.h"

void CMydraft::draw(const CVector &v) {
  if (!v.isVisible())
    return;
  line(v.getPos(), v.getEnd(), v.getColor());
}
