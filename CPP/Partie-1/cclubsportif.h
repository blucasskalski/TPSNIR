#include "cmembre.h"
#include <iostream>
#include <string>

const int NMAX = 100;

class CMembre;

class CClubSportif {
private:
  std::string nomClub;
  CMembre *membres[NMAX];

public:
  // Constructeur
  CClubSportif(std::string nomClub);

  // Destructeur
  ~CClubSportif();

  // Méthode pour ajouter un membre
  bool ajoute(const CMembre &membre);

  // Méthode pour afficher la liste des membres
  void liste();
};
