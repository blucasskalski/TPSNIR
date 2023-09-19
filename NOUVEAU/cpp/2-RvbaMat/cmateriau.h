#ifndef CMATERIAU
#define CMATERIAU
#include <string>
#include <iostream>
#include "crvba.h"

class CMateriau
{
private:
    std::string nom;
    float ambiante[4];
    float diffuse[4];
    float speculaire[4];
    float brilliance;
    int convert(int nombre)
    {
        if (nombre > 255)
            nombre = 255;
        else if (nombre < 0)
            nombre = 0;
        return (nombre / 255);
    }
    int undoConvert(int nombre)
    {
        if (nombre > 1)
            nombre = 1;
        else if (nombre < 0)
            nombre = 0;
        return (nombre * 255);
    }

public:
    CMateriau()
    {
        setNom("défault");
        setAmbiante(CRvba(0.2, 0.2, 0.2, 1.0));
        setDiffuse(CRvba(0.8, 0.8, 0.8, 1.0));
        setSpeculaire(CRvba(0.0, 0.0, 0.0, 1.0));
        setBrilliance(0);
    }
    CMateriau(std::string nom, CRvba ambiante, CRvba diffuse, CRvba speculaire, float brilliance = 0)
    {
        setNom(nom);
        setAmbiante(ambiante);
        setDiffuse(diffuse);
        setSpeculaire(speculaire);
        setBrilliance(brilliance);
    }
    CMateriau(const CMateriau &c)
    {
        setNom(c.getNom());
        setAmbiante(c.getAmbiante());
        setDiffuse(c.getDiffuse());
        setSpeculaire(c.getSpeculaire());
        setBrilliance(c.getBrilliance());
    }
    void setNom(std::string nom);
    void setAmbiante(CRvba ambiante);
    void setDiffuse(CRvba diffuse);
    void setSpeculaire(CRvba speculaire);
    void setBrilliance(float brilliance);
    void setAlpha(int alpha);
    CRvba getAmbiante() const;
    CRvba getDiffuse() const;
    CRvba getSpeculaire() const;
    float getBrilliance() const;
    float* rAmbiante() const;
    float* rDiffuse() const;
    float* rSpeculaire() const;
    float* Brilliance();
    std::string getNom() const { return nom; }
    std::string printMateriau() const;
    std::string printAmbiante() const;
    std::string printDiffuse() const;
    std::string printSpeculaire() const;
};
#endif