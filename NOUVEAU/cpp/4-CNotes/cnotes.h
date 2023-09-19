#ifndef CNOTES_H
#define CNOTES_H
#include <iostream>

using namespace std;

class CElem;
typedef CElem *pElem;
class CElem
{
public:
    double note;
    pElem suiv;
};

class CNotes
{
    pElem prem, dern;
    int nbElem;
    int indice_current;

public:
    CNotes(double n = -1)
        : prem(NULL), dern(NULL), nbElem(0)
    {
        if (n != -1)
            Ajoute(n);
    }
    CNotes(const CNotes &cn)
    {
        Ajoute(cn);
    }
    ~CNotes();
    CNotes &operator+=(double v);
    CNotes &operator[](int indice);
    CNotes &operator=(double v);
    CNotes &operator+(double v);
    CNotes &operator+=(const CNotes &cn);
    CNotes &operator+(const CNotes& cn);
    int nbNotes() const { return nbElem; }
    void Ajoute(double v);
    void Ajoute(const CNotes &cn);
    double Moyenne() const;
    string print();
};
#endif