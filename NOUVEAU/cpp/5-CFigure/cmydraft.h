#ifndef CMYDRAFT_H
#define CMYDRAFT_H

#include "cdraft.h"
#include "cvector.h"
#include "clozenge.h"
#include "clabel.h"
#include "cbutton.h"
#include "csquare.h"
#include "cpolygon.h"
#include "ccircle.h"
// annonces de classes

class CVector;
class CLozenge;
class CLabel;
class CButton;
class CSquare;


class CMyDraft : public CDraft {

// classe CDraft : gestion d'une zone de dessin 2D
public :

    CMyDraft(int w = 640, int h = 480) : CDraft(w, h) {}
    void draw(bool grad = false) { CDraft::draw(grad); }
    void draw(const CVector& v ) ;
    void draw(const CRectangle& r ) ;
    void draw(const CLozenge& l ) ;
    void draw(const CLabel& a ) ;
    void draw(const CButton& b ) ;
};

#endif
