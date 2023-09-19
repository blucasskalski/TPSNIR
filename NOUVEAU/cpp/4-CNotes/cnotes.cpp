#include "cnotes.h"
#include <string>
#include <sstream>
#include <iomanip>

CNotes::~CNotes()
{
    pElem p = prem;
    while (prem != NULL)
    {
        p = p->suiv;
        delete prem;
        prem = p;
    }
    prem = dern = NULL;
    nbElem = 0;
}

void CNotes::Ajoute(double v)
{
    pElem p = new CElem;
    p->note = v;
    p->suiv = NULL;
    if (prem == NULL)
        prem = dern = p;
    else
    {
        dern->suiv = p;
        dern = dern->suiv;
    }
    nbElem++;
}

void CNotes::Ajoute(const CNotes &cn)
{
    pElem c = cn.prem;
    for (int i = 0; i < cn.nbElem; i++)
    {
        Ajoute(c->note);
        c = c->suiv;
    }
}

double CNotes::Moyenne() const
{
    pElem p;
    p = prem;
    double moy;
    while (p != NULL)
    {
        moy += p->note;
        p = p->suiv;
    }
    return moy /= nbElem;
}
string CNotes::print()
{
    std::ostringstream oss;
    pElem p;
    p = prem;
    oss << std::setfill(' ');
    for (int i = 0; i < nbElem; i++)
    {
        if (p != NULL)
        {
            oss << "n°" << i << ' ' << p->note << ' ';
            p = p->suiv;
        }
    }
    oss << endl;
    return oss.str();
}
CNotes &CNotes::operator+(double v)
{
    Ajoute(v);
    return *this;
}

CNotes &CNotes::operator+(const CNotes& cn)
{
    Ajoute(cn);
    return *this;
}

CNotes &CNotes::operator=(double v)
{
    {
        // cout << "note : " << v << endl;
        pElem p = prem;
        for (int i = 0; i < indice_current; i++)
        {
            p = p->suiv;
        }
        Ajoute(v);
        return *this;
    }
}
CNotes &CNotes::operator[](int indice)
{
    pElem p = prem;
    for (int i = 0; i < indice; i++)
    {
        if (p->suiv == NULL && i + 1 < indice)
            Ajoute(0);

        p = p->suiv;
    }
    indice_current = indice;
    return *this;
}
CNotes &CNotes::operator+=(double v)
{
    Ajoute(v);
    return *this;
}
CNotes &CNotes::operator+=(const CNotes &cn)
{
    Ajoute(cn);
    return *this;
}