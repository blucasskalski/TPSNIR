#include "cdate.h"
class CMembre {
private:
  std::string nom;
  std::string prenom;
  CDate dateNaiss;

public:
  // Constructeurs
  CMembre();
  CMembre(std::string nom, std::string prenom);
  CMembre(std::string nom, std::string prenom, CDate dateNaiss);
  // Accesseurs en lecture et en écriture pour les attributs privés
  inline std::string getNom() const { return nom; }
  inline void setNom(std::string nom) { this->nom = nom; }

  inline std::string getPrenom() const { return prenom; }
  inline void setPrenom(std::string prenom) { this->prenom = prenom; }

  inline CDate getDateNaiss() const { return dateNaiss; }
  inline void setDateNaiss(CDate dateNaiss) { this->dateNaiss = dateNaiss; }

  // Méthode print() retournant les 3 attributs sous forme d’une unique chaîne
  std::string print();
  std::string printLong();
};
