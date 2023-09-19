#ifndef CMEMBRE_H
#define CMEMBRE_H
#include "tmonth.h"
#include "cdate.h"
#include <string>
#include <ostream>

class CMembre {
private:
  std::string nom;
  std::string prenom;
  std::string dateNaiss = "1er janvier 1900";
  public :
  CMembre() { _default(dateNaiss); }
  CMembre(std::string nom, std::string prenom, std::string dateNaiss)
  {
    set(nom, prenom, dateNaiss) ;
  }
  CMembre(std::string nom, std::string prenom)
  {
    nom_et_prenom(nom, prenom, dateNaiss);
  }

  void _default(std::string dateNaiss);
  void nom_et_prenom(std::string nom, std::string prenom, std::string dateNaiss);
  void set(std::string nom, std::string prenom, std::string dateNaiss) ;
  void setNom(std::string nom);
  void setPrenom(std::string prenom);
  void setIdentity(std::string nom, std::string prenom);
  std::string printmembre() const ;
} ;
#endif
