#include "crectangle.h"
#include "cmydraft.h"
#include "cvector.h"
#include <iostream>
#include "xamgraph.h"
#include <string>
using namespace std;

void CMyDraft::draw(const CVector &v)
{
    if (!v.isVisible())
        return;
    line(v.getPos(), v.getEnd(), v.getColor());
}

void CMyDraft::draw(const CRectangle &r)
{
    CPoint pts[4];
    pts[0].set(r.getX(), r.getY());
    pts[1].set(r.getXEnd(), r.getY());
    pts[2].set(r.getXEnd(), r.getYEnd());
    pts[3].set(r.getX(), r.getYEnd());

    if (!r.isVisible())
        return;
    poly(r.getPos(), 4, pts, r.getColor(), r.isFill());
}

void CMyDraft::draw(const CLozenge &l)
{
    CPoint pts[4];
    pts[0].set(l.getX(), l.getY() + ((l.getYEnd() - l.getY()) / 2));
    pts[1].set(l.getXEnd() - ((l.getXEnd() - l.getX()) / 2), l.getY());
    pts[2].set(l.getXEnd(), l.getYEnd() - ((l.getYEnd() - l.getY()) / 2));
    pts[3].set(l.getX() + ((l.getXEnd() - l.getX()) / 2), l.getYEnd());

    if (!l.isVisible())
        return;
    poly(l.getPos(), 4, pts, l.getColor(), l.isFill());
}

void CMyDraft::draw(const CLabel &a)
{
    if (!a.isVisible())
        return;
    text(a.getPos(), a.getText(), a.getColor());   
}

void CMyDraft::draw(const CButton &b)
{
    if (!b.isVisible())
        return;
    CPoint pts[4];
    pts[0].set(b.CRectangle::getX(), b.CRectangle::getY());
    pts[1].set(b.CRectangle::getXEnd(), b.CRectangle::getY());
    pts[2].set(b.CRectangle::getXEnd(), b.CRectangle::getYEnd());
    pts[3].set(b.CRectangle::getX(), b.CRectangle::getYEnd());
    poly(b.CRectangle::getPos(), 4, pts, b.CRectangle::getColor(), b.CRectangle::isFill());
    text((CRectangle)b, b.CLabel::getText());
}