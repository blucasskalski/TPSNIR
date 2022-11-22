// main.cpp

#include "cbutton.h"
#include "cdraft.h"
#include "cfigure.h"
#include "clozenge.h"
#include "cmydraft.h"
#include "crectangle.h"
#include "csquare.h"
#include "cvector.h"
#include <iostream>
#include <string>

using namespace std;

class CVector;
class CRectangle;
class CLabel;

int main(int argc, char **argv) {
  // Traitement de l'option '-v' (ligne de commandes)

  if (argc > 1) {
    string opt(*++argv);
    if (opt == "-v")
      CDraft::setVerbose(true);
  }

  // Construction de l'espace graphique
  CMydraft draft(800, 600);
  draft.setX(400);
  draft.setY(300);
  draft.setScale(40);
  draft.draw(true);

  // CVector v1
  CVector v1(CPoint(1.5, 2), CPoint(7.2, 5));
  v1.setColor(XAM_LIGHT_RED);
  v1.setVisible(true);

  // CRectangle r1
  CRectangle r1(5.0, 2.5);
  r1.setX(-6.0);
  r1.setY(4.5);
  r1.setVisible(true);
  r1.setFill(true);
  r1.setColor(XAM_LIGHT_BLUE);

  // CSquare s1
  CSquare s1(3);
  s1.setPos(CPoint(2.4, 1));
  s1.setVisible(true);
  s1.setColor(XAM_DARK_MAGENTA);
  s1.setFill(false);

  //
  CLozenge l1(3.0, 1.4);
  l1.setX(-9.0);
  l1.setY(-4.5);
  l1.setVisible(true);
  l1.setFill(true);
  l1.setColor(XAM_CYAN);

  CLabel L1("MY_CLABEL1");
  L1.setColor(XAM_DARK_GREEN);
  L1.setPos(CPoint(-8, -2));
  L1.setVisible(true);

  CButton b1(CPoint(5.5, -5.2), 4, 1, "MY_CBUTTON1");
  // CButton b1(CPoint(4.0, 1.0), 5.5, -5.2, "MY_CBUTTON1");
  b1.setPos(CPoint(5.5, -5.2));
  b1.setFill(true);
  b1.setColor(XAM_LAVENDER);
  b1.setVisible(true);

  draft.draw(v1);
  draft.draw(r1);
  draft.draw(s1);
  draft.draw(l1);
  draft.draw(L1);
  draft.draw(b1);

  CFigure *figure[6];
  figure[0] = new CVector(4, -1.6);
  figure[0]->setPos(CPoint(-5, -4));
  figure[0]->setColor(XAM_RED);
  figure[0]->setVisible(true);

  figure[0]->draw(draft);

  figure[1] = new CRectangle(1.0, 3.14);
  figure[1]->setPos(CPoint(-8.5, 2));
  figure[1]->setColor(XAM_BLUE);
  figure[1]->setVisible(true);
  figure[1]->setFill(true);

  figure[1]->draw(draft);

  figure[4] = new CLabel("MY_CLABEL2");
  figure[4]->setColor(XAM_GREEN);
  figure[4]->setPos(CPoint(-6.5, 2.0));
  figure[4]->setVisible(true);

  figure[4]->draw(draft);

  draft.updateScreen();
  draft.draw(v1);
  draft.run();

  return 0;
}
