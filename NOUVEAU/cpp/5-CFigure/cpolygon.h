// cpolygon.h
#ifndef CPOLYGON_H
#define CPOLYGON_H
#include "cfigure.h"
#include "cdraft.h"

class CDraft;
class CPolygon : public CFigure
{
    CPoint *ppts;
    int num;

protected:
    void setPoints(int nbPts, CPoint *pts);

public:
    CPolygon()
        : CFigure(), ppts(NULL), num(0) {}
    CPolygon(CPoint pos, int nbPts = 0, CPoint *pts = NULL)
        : CFigure(pos)
    {
        setPoints(nbPts, pts);
    }
    ~CPolygon() { delete[] ppts; }
	virtual std::string draw() { return "CPolygon::draw()"; }
    virtual void draw(CDraft &dr) const;
    virtual double area() const {return 0;}
    virtual std::string className() const {return "CPolygon";}
};

#endif