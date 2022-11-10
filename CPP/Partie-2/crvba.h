/*------------------------------------------------------------------------
 *  Nom         :   Crvba.h
 *  Type        :   INTERFACE
 *  Sujet       :   Definition de la classe Crvba
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Creation    :   10/11/2022
 *------------------------------------------------------------------------
 */

#ifndef CRVBA_H
#define CRVBA_H
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
class CRvba {

private:
  int r, v, b, a;

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

  CRvba() { set(0, 0, 0); }
  CRvba(int r, int v, int b, int a = 255) { set(r, v, b, a); }

  void set(int r, int v, int b, int a = 255);
};

#endif
