#include "cmembre.h"
#include "cdate.h"
#include <sstream>
#include <iomanip>

void CMembre::set(std::string nom, std::string prenom, std::string dateNaiss)
{
  this->nom=nom;

  this->prenom=prenom;

  this->dateNaiss=dateNaiss;
}

void CMembre::setNom(std::string nom)
{
  this->nom=nom;
}

void CMembre::setPrenom(std::string prenom)
{
  this->prenom=prenom;
}

void CMembre::setIdentity(std::string nom, std::string prenom)
{
  setNom(nom);
  setPrenom(prenom);
}

void CMembre::_default(std::string dateNaiss)
{
  set("?", "?", dateNaiss) ;
}

void CMembre::nom_et_prenom(std::string nom, std::string prenom, std::string dateNaiss)
{
  set(nom, prenom, "1er janvier 1900");
}

std::string CMembre::printmembre() const
{
  std::ostringstream oss;
  oss << std::setfill(' ');
  oss << std::setw(1) << nom << ' ';
  oss << std::setw(1) << prenom << ' ';
  oss << std::setw(0) << dateNaiss;
  return oss.str();
}
