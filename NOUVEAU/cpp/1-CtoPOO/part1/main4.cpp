#include "cmembre.h"
#include "cdate.h"
#include <iostream>
using namespace std ;

int main(int argc, char** argv)
{
  CMembre cmembre1; //membre par default nom et prenom = "?" et date naissance default = "1er janvier 1900"
  //  cmembre1.set("laxenaire", "flavian", "2002");

  CDate cdatedefault;
  cdatedefault.setdate(1, JAN, 1900);
  string cdate1 = cdatedefault.printlongdate();
  CMembre cmembre2("nom1", "prenom1", cdate1); //membre acceptant nom et prenom en arguments et date naissance default

  //  cmembre2.setNom("Laxenaire");
  //  cmembre2.setPrenom("Jacques");

  cout << cmembre1.printmembre() << endl; //afficher le membre default
  cout << cmembre2.printmembre() << endl; //afficher le membre avec nom et prenom en arguments

  CMembre cmembre3("",""); //membre nom et prenom choisi par l'utilisateur
  string n, p ;
  int j, m, a;
  cout << "\033[32mnom et prenom (séparés par espaces) ? \033[0m" ;
  cin >> n >> p ;
  cmembre3.setIdentity(n,p);
  cout << cmembre3.printmembre() << endl;

  CMembre cmembre4("","","");
  CDate cdate3;
  cout << "\033[32mnom, prenom et date naissance (séparés par espaces) ? \033[0m" ;
  cin >> n >> p >> j >> m >> a;
  cmembre4.setIdentity(n,p);
  cdate3.setdate(j,(TMonth)m,a);
  cout << cmembre4.printmembre() << cdate3.printlongdate() << endl;
  return 0;
}

// g++ -Wall -o test4 cmembre.cpp main4.cpp cdate.cpp tmonth.cpp
