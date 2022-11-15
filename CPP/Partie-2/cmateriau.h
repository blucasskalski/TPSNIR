/*------------------------------------------------------------------------
 *  Nom         :   CMateriau.h
 *  Type        :   INTERFACE
 *  Sujet       :   Definition de la classe CMateriau
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Creation    :   10/11/2022
 *------------------------------------------------------------------------
 */

#ifndef CMATERIAU_H
#define CMATERIAU_H
#include "crvba.h"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
class CMateriau {

private:
  std::string nom;
  CRvba ra, rd, rs; // float ra[4], rd[4], rs[4], b;
  float b;
  /* ra => Réflexion Ambiante -
   * rd => réflexion diffuse -
   * rs => réflexion spéculaire -
   * b => brillance */
public:
  std::string print() const;

  std::string printlong() const;

  int getR() const;
  void setR(int r);

  int getV() const;
  void setV(int v);

  int getB() const;
  void setB(int b);

  int getA() const;
  void setA(int a);

  CMateriau() {
    set("défaut", CRvba(0.2, 0.2, 0.2, 1.0), CRvba(0.8, 0.8, 0.8, 1.0),
        CRvba(0.0, 0.0, 0.0, 1.0), 0.0);
    // TODO Convertir floats vers entier 0..255
  }
  CMateriau(std::string nom, CRvba ra, CRvba rd, CRvba rs, float b) {
    set(nom, ra, rd, rs, b);
  }

  void set(std::string nom, CRvba ra, CRvba rd, CRvba rs, float b);
};

#endif
