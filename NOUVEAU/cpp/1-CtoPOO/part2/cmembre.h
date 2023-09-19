#ifndef CMEMBRE_H
#define CMEMBRE_H
#include "tmonth.h"
#include "cdate.h"
#include <string>
#include <ostream>
using namespace std;
class CMembre
{
private:
  std::string nom;
  std::string prenom;
  std::string dateNaiss = "1er janvier 1900";
  std::string membre;
  CDate dateNaiss2;

public:
  CMembre() { _default(dateNaiss); }
  CMembre(std::string nom, std::string prenom, std::string dateNaiss)
  {
    set(nom, prenom, dateNaiss);
  }
  CMembre(std::string nom, std::string prenom)
  {
    nom_et_prenom(nom, prenom, dateNaiss);
  }
  CMembre(std::string nom, std::string prenom, CDate dateNaiss2)
  {
    set2(nom, prenom, dateNaiss2);
  }
  void _default(std::string dateNaiss);
  void nom_et_prenom(std::string nom, std::string prenom, std::string dateNaiss);
  void set(std::string nom, std::string prenom, std::string dateNaiss);
  void set2(std::string nom, std::string prenom, CDate dateNaiss2);
  void setNom(std::string nom);
  void setPrenom(std::string prenom);
  void setIdentity(std::string nom, std::string prenom);
  std::string getMembre(CMembre membre);
  std::string printmembre() const;
};
#endif
