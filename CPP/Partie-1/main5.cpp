#include "cclubsportif.h"
#include <ctime>
#include <random>

int main() {
  CClubSportif club("Lambda");
  std::default_random_engine alea;
  std::uniform_int_distribution<int> day_dist(1, 28);
  std::uniform_int_distribution<int> year_dist(1970, 2005);
  std::uniform_int_distribution<int> month_dist(1, 12);

  for (int i = 0; i < 10; i++) {
    std::string nom = "Membre" + std::to_string(i);
    std::string prenom = "Prenom" + std::to_string(i);
    int jour = day_dist(alea);
    TMonth mois = TMonth(month_dist(alea));
    int annee = year_dist(alea);
    CDate dateNaiss(jour, mois, annee);
    CMembre membre(nom, prenom, dateNaiss);
    club.ajoute(membre);
  }
  club.liste();
  return 0;
}
