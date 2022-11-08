#include "cclub.h"
#include <cstdio>
#include <iostream>

using namespace std;

CMembre *membres[NMAX];
int ajoute();

// int main(int argc, char **argv) {
// initialisation et déclaration du tableau membres
// for (int i = 0; i < NMAX; ++i)
//   membres[i] = 0;
// initialisation des membres dans le tableau
// CMembre membre1;
// membre1.set("Tournelle", "Marie", CDate(1, AVR, 2000));
//
// int res = ajoute(membre1);
void init() {
  cout << "init?" << '\n';
  membres[0]->set("Jean", "Valjean", CDate(1, FEV, 1993));
  membres[1]->set("Marie", "Helene", CDate(14, AOU, 1987));
  cout << "init." << '\n';
  ajoute();
}

int ajoute() {
  // recherche du premier i libre
  int iLibre = 0;
  while (membres[iLibre] != 0) {
    if (iLibre > 100) {
      iLibre = -1;
    } else {
      iLibre++;
    }
  }
  if (iLibre == -1)
    cout << "Aucune place libre" << '\n';
  else
    printf("Place trouvée\n");
  cout << "Index retenu : " << iLibre << '\n';
  return true;
}
