#include "CMembre.h"

std::string CMembre::getNOM() const { return (std::string)nom; }

void CMembre::setNOM(std::string nom) {
  // if(/*blabla*/)

  this->nom = (std::string)nom;
}

/////////////////////////

std::string CMembre::getPRENOM() const { return (std::string)prenom; }

void CMembre::setPRENOM(std::string prenom) {
  // if (/*Blabla*/)
  this->prenom = (std::string)prenom;
}

///////////////////////

CDate CMembre::getDATENAISS() const { return (CDate)dateNaiss; }

void CMembre::setDATENAISS(CDate dateNaiss) {
  // if (/*Blabla*/)
  this->dateNaiss = (CDate)dateNaiss;
}

void CMembre::set(std::string nom, std::string prenom, CDate dateNaiss) {
  this->nom = (std::string)nom;
  this->prenom = (std::string)prenom;
  this->dateNaiss = (CDate)dateNaiss;
}

std::string CMembre::print() const {
  std::ostringstream oss;

  oss << nom << ' ';
  oss << prenom << ", né(e) le ";
  oss << dateNaiss;
  return oss.str();
}

std::string CMembre::printlong() const {
  std::ostringstream oss;

  oss << std::setfill('0');
  oss << std::setw(2) << nom << " ";
  oss << std::setw(2) << prenom << " ";
  oss << std::setw(4) << dateNaiss;
  return oss.str();
}

std::ostream &operator<<(std::ostream &s, const CMembre &date) {
  s << date.print();
  return s;
}
