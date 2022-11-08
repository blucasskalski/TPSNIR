#include "CMembre.h"
#include "cdate.h"
#include <cstdio>
#include <iostream>

using namespace std;

int spot_libre_membre();
CMembre *membres[NMAX];

int main(int argc, char **argv) {
  // initialisation et déclaration du tableau membres
  for (int i = 0; i < NMAX; ++i)
    membres[i] = 0;
  int iLibre;
  iLibre = spot_libre_membre();
  if (iLibre == -1)
    cout << "Aucune place libre" << '\n';
  else
    printf("Place trouvée\n");
  cout << "Index retenu : " << iLibre << '\n';
  return 0;
}

int spot_libre_membre() {
  int idx = 0;
  while (membres[idx] != 0) {
    if (idx > 100) {
      idx = -1;
    } else {
      idx++;
    }
  }

  return idx;
}
