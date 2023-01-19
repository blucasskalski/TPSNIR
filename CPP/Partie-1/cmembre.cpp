#include "cmembre.h"

std::string CMembre::print() {
  return nom + " " + prenom + " " + dateNaiss.print();
}

std::string CMembre::printLong() {
  return nom + " " + prenom + " né(e) le " + dateNaiss.printLong();
}

// Constructeur par défaut
CMembre::CMembre() : nom("?"), prenom("?"), dateNaiss(1, JAN, 1900) {}

// Constructeur acceptant nom et prénom en arguments
CMembre::CMembre(std::string nom, std::string prenom)
    : nom(nom), prenom(prenom), dateNaiss(1, JAN, 1900) {}

// Constructeur acceptant nom, prenom et dateNaiss en arguments
CMembre::CMembre(std::string nom, std::string prenom, CDate dateNaiss)
    : nom(nom), prenom(prenom), dateNaiss(dateNaiss) {}
