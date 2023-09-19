// ccircle.h
#ifndef CCIRCLE_H
#define CCIRCLE_H
#include "cpolygon.h"
#include "cdraft.h"
#define _USE_MATH_DEFINES
#include <cmath>

class CDraft;
class CCircle : public CPolygon
{
    CPoint pos;
    int rayon;
    CPoint *pts;
    int nbpts;

public:
    CCircle()
        : CPolygon(), pos(0, 0), rayon(0), pts(NULL), nbpts(0) {}
    CCircle(CPoint pos, int rayon, int nbpts = 12)
        : CPolygon(pos)
    {
        this->nbpts = nbpts;
        this->rayon = rayon;
    }
    ~CCircle()
    {
        if (pts != NULL)
            delete[] pts;
    }

    virtual void draw(CDraft &dr)
    {
        pts = NULL;
        pts = new CPoint[nbpts];
        for (int i = 0; i < nbpts; i++)
        {
            pts[i] = CPoint(getX() + rayon * cos(((2 * M_PI) / (nbpts)) * (i + 1)), getY() + rayon * sin(((2 * M_PI) / (nbpts)) * (i + 1)));
        }
        CPolygon::setPoints(nbpts, pts);
        CPolygon::draw(dr);
    }
};
#endif