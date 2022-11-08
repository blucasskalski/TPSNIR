/*------------------------------------------------------------------------
 *  Nom         :   CMembre.h
 *  Type        :   INTERFACE
 *  Sujet       :   Definition de la classe CMembre
 *
 *  Auteur      :   Sonny ESNAULT
 *  Version     :   0.1
 *  Creation    :   19/10/2022
 *
 *  Fabrication :
 *------------------------------------------------------------------------
 */

#ifndef CMEMBRE_H
#define CMEMBRE_H
#include "cdate.h"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class CMembre {

private:
  CDate dateNaiss;
  std::string nom;
  std::string prenom;

public:
  CMembre() { set("?", "?", CDate(1, JAN, 1900)); }
  CMembre(std::string nom, std::string prenom, CDate dateNaiss) {
    set(nom, prenom, dateNaiss);
  }

  std::string print() const;

  std::string printlong() const;

  std::string getNOM() const;
  void setNOM(std::string nom);

  std::string getPRENOM() const;
  void setPRENOM(std::string prenom);

  CDate getDATENAISS() const;
  void setDATENAISS(CDate dateNaiss);

  void set(std::string nom, std::string prenom, CDate dateNaiss);
};

std::ostream &operator<<(std::ostream &s, const CMembre &date);

#endif
