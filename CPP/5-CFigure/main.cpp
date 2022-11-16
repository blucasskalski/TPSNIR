// main.cpp

#include "cmydraft.h"
#include "cvector.h"
#include <iostream>
#include <string>

using namespace std;

class CVector;

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

  CVector v1(CPoint(1.5, 2), CPoint(7.2, 5));
  v1.setColor(XAM_LIGHT_RED);
  v1.setVisible(true);
  draft.draw(v1);

  draft.updateScreen();
  draft.run();

  return 0;
}
