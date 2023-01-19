#include "cclubsportif.h"
#include <ctime>
#include <random>

int main() {
  CClubSportif club("Echecs Club");
  std::mt19937 rng(time(nullptr));
  std::uniform_int_distribution<int> day_dist(1, 28);
  std::uniform_int_distribution<int> year_dist(1970, 2005);

  for (int i = 0; i < 10; i++) {
    std::string nom = "Membre" + std::to_string(i);
    std::string prenom = "Prenom" + std::to_string(i);
    int jour = day_dist(rng);
    TMonth mois = AOU;
    int annee = year_dist(rng);
    CDate dateNaiss(jour, mois, annee);
    CMembre membre(nom, prenom, dateNaiss);
    club.ajoute(membre);
  }
  club.liste();
  return 0;
}
