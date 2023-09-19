#include "cmateriau.h"
#include <sstream>
#include <iomanip>
#include <iostream>

CRvba CMateriau::getAmbiante() const
{
    CRvba ambiante2;
    ambiante2.setRvba(this->ambiante[0], this->ambiante[1], this->ambiante[2], this->ambiante[3]);
    return ambiante2;
}
CRvba CMateriau::getDiffuse() const
{
    CRvba diffuse2;
    diffuse2.setRvba(this->diffuse[0], this->diffuse[1], this->diffuse[2], this->diffuse[3]);
    return diffuse2;
}

float CMateriau::getBrilliance() const
{
    return this->brilliance;
}

CRvba CMateriau::getSpeculaire() const
{
    CRvba speculaire2;
    speculaire2.setRvba(this->speculaire[0], this->speculaire[1], this->speculaire[2], this->speculaire[3]);
    return speculaire2;
}

void CMateriau::setNom(std::string nom)
{
    this->nom = nom;
}
void CMateriau::setAmbiante(CRvba ambiante)
{
    this->ambiante[0] = ambiante.getR();
    this->ambiante[1] = ambiante.getV();
    this->ambiante[2] = ambiante.getB();
    this->ambiante[3] = ambiante.getA();
}
void CMateriau::setDiffuse(CRvba diffuse)
{
    this->diffuse[0] = diffuse.getR();
    this->diffuse[1] = diffuse.getV();
    this->diffuse[2] = diffuse.getB();
    this->diffuse[3] = diffuse.getA();
}
void CMateriau::setSpeculaire(CRvba speculaire)
{
    this->speculaire[0] = speculaire.getR();
    this->speculaire[1] = speculaire.getV();
    this->speculaire[2] = speculaire.getB();
    this->speculaire[3] = speculaire.getA();
}
void CMateriau::setBrilliance(float brilliance)
{
    this->brilliance = brilliance;
}

void CMateriau::setAlpha(int alpha)
{
    this->speculaire[3] = alpha;
    this->diffuse[3] = alpha;
    this->ambiante[3] = alpha;
}

std::string CMateriau::printAmbiante() const
{
    std::ostringstream oss;
    oss << std::setfill('0');
    oss << "{" << ambiante[0] << "," << ambiante[1] << "," << ambiante[2] << "," << ambiante[3] << "}" << endl;
    return oss.str();
}
std::string CMateriau::printDiffuse() const
{
    std::ostringstream oss;
    oss << std::setfill('0');
    oss << "{" << diffuse[0] << "," << diffuse[1] << "," << diffuse[2] << "," << diffuse[3] << "}" << endl;
    return oss.str();
}
std::string CMateriau::printSpeculaire() const
{
    std::ostringstream oss;
    oss << std::setfill('0');
    oss << "{" << speculaire[0] << "," << speculaire[1] << "," << speculaire[2] << "," << speculaire[3] << "}" << endl;
    return oss.str();
}
std::string CMateriau::printMateriau() const
{
    std::ostringstream oss;
    oss << std::setfill('0');
    oss << "Couleur: " << nom << endl;
    oss << "Réflexion ambiante: " << CMateriau::printAmbiante();
    oss << "Réflexion diffuse: " << CMateriau::printDiffuse();
    oss << "Réflexion spéculaire: " << CMateriau::printSpeculaire();
    oss << "Brilliance: " << brilliance << endl;
    return oss.str();
}

float *CMateriau::rAmbiante() const
{
    return (float *)ambiante;
}
float *CMateriau::rDiffuse() const
{
    return (float *)diffuse;
}
float *CMateriau::rSpeculaire() const
{
    return (float *)speculaire;
}
float *CMateriau::Brilliance()
{
    return &brilliance;
}