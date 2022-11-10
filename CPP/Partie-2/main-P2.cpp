#include "crvba.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  CRvba couleur1;
  CRvba couleur2(115, 157, 172);

  // fixer couleur1 à cyan
  couleur1.set(0, 255, 255);
  // afficher les 4 valeurs de couleur1
  cout << couleur1.print() << endl;
  // afficher les 4 valeurs de couleur2
  cout << couleur2.printlong() << endl;
  return 0;
}
