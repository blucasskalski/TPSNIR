#include "cclubsportif.h"

// Constructeur
CClubSportif::CClubSportif(std::string nomClub) : nomClub(nomClub) {
  for (int i = 0; i < NMAX; i++) {
    membres[i] = nullptr;
  }
}

// Destructeur
CClubSportif::~CClubSportif() {
  for (int i = 0; i < NMAX; i++) {
    if (membres[i] != nullptr) {
      delete membres[i];
    }
  }
}

// Méthode pour ajouter un membre
bool CClubSportif::ajoute(const CMembre &membre) {
  for (int i = 0; i < NMAX; i++) {
    if (membres[i] == nullptr) {
      membres[i] = new CMembre(membre);
      return true;
    }
  }
  std::cout << "Impossible d'ajouter le membre, le club est complet."
            << std::endl;
  return false;
}

// Méthode pour afficher la liste des membres
void CClubSportif::liste() {
  std::cout << "Liste des membres du club " << nomClub << " :" << std::endl;
  for (int i = 0; i < NMAX; i++) {
    if (membres[i] != nullptr) {
      std::cout << membres[i]->printLong() << std::endl;
    }
  }
}
