#include "clabel.h"

void CLabel::draw(CDraft &dr) const {
  if (!isVisible())
    return;
  dr.text(getPos(), getText(), getColor());
}
