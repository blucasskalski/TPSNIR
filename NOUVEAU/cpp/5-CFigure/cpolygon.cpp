#include "cpolygon.h"

void CPolygon::setPoints(int nbPts, CPoint *pts)
{
    num = nbPts;
    ppts = NULL;
    if (!nbPts)
        return;
    ppts = new CPoint[num];
    for (int i = 0; i < nbPts; i++)
        ppts[i] = *(pts + i);
}
void CPolygon::draw(CDraft &dr) const
{
    if (ppts == NULL)
        return;
    if (!isVisible())
        return;
                std::cout << getPos();

    dr.poly(getPos(), num, ppts, getColor(), isFill());
}
