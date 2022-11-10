#define NMAX 100

#ifndef CCLUB_H
#define CCLUB_H
#include "CMembre.h"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

void init();
bool ajoute(const CMembre &membre);
void list();

// class CClubSportif {
// private:
//   std::string nom;
//   // public:
// };

class CClubSportif {
public:
  std::string nom;

private:
};

#endif
