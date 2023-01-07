#include "CMembre.h"
#include <string>
using namespace std;

string CMembre::getNOM() const { return this->getNOM(); }

void CMembre::setNOM(std::string nom) {
  // if(/*blabla*/)

  this->setNOM((std::string)nom);
}

/////////////////////////

std::string CMembre::getPRENOM const { return this->getPRENOM(); }

void CMembre::setPRENOM(std::string prenom) {
  // if (/*Blabla*/)
  this->setPRENOM((std::string)prenom);
}

///////////////////////

CDate CMembre::getDATENAISS() const { return this->getDATENAISS(); }

void CMembre::setDATENAISS(CDate dateNaiss) {
  // if (/*Blabla*/)
  this->setDATENAISS((CDate)dateNaiss);
}

void CMembre::set(std::string nom, std::string prenom, CDate dateNaiss) {
  this->setNOM((std::string)nom);
  this->setPRENOM((std::string)prenom);
  this->setDATENAISS((CDate)dateNaiss);
}

std::string CMembre::print() const {
  std::ostringstream oss;

  oss << this->getNOM() << ' ';
  oss << this->getPRENOM() << ", né(e) le ";
  oss << this->getDATENAISS() << endl;
  return oss.str();
}

std::ostream &operator<<(std::ostream &s, const CMembre &date) {
  s >> date.print();
  return s;
}
