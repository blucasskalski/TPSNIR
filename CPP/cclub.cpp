#include "cclub.h"
#include "CMembre.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

CMembre *membres[NMAX];
int iLibre;

bool ajoute(const CMembre &membre) {
  // recherche du premier i libre
  iLibre = 0;
  while (membres[iLibre]) {
    if (iLibre > 100) {
      iLibre = -1;
      break;
    } else {
      iLibre++;
    }
  }
  if (iLibre == -1) {
    cout << "Aucune place libre" << endl;
    return false;
  } else {
    cout << "Place trouvée" << endl;
    cout << "Index retenu : " << iLibre << endl;
  }
  cout << "Ajout du membre \"" << membre.getNOM() << ' ' << membre.getPRENOM();
  cout << "\" dans le tableau en tant que membre n°" << iLibre << endl;
  iLibre++;
  return true;
}

void init() {
  for (int i = 0; i < NMAX; ++i)
    membres[i] = 0;
  cout << "init?" << '\n';
  membres[0]->set("Jean", "Valjean", CDate(1, FEV, 1993));
  membres[1]->set("Marie", "Helene", CDate(14, AOU, 1987));
  cout << "init." << '\n';
}

void list() {
  for (int i = 0; i < iLibre; i++) {
    std::string nom = membres[iLibre]->getNOM();
    cout << "Nom: " << nom << endl;
  }
}
