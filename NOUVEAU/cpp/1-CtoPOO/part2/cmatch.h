#ifndef CMATCH
#define CMATCH
#include "cclubsportif.h"
#include <string>
#include <iostream>
 
using namespace std;

class CMatch
{
private:
    CDate rencontre;
    CMembre *membre_rencontre[2];

public:
    CMatch(CMembre membre1, CMembre membre2, CDate rencontre0)
    {
        membre_rencontre[0] = new CMembre(membre1); 
        membre_rencontre[1] = new CMembre(membre2);
        rencontre = rencontre0;
        cout << "Création d'un match..." << endl;
    }
    void printMatch(/*CMembre &membre_rencontre, CDate rencontre*/)
    {
        cout << "La rencontre sportive aura lieu entre :" << endl;
        cout << membre_rencontre[0]->printmembre();
        cout << " et ";
        cout << membre_rencontre[1]->printmembre() << endl;
        cout << "La date de la rencontre sera le : ";
        cout << rencontre.printdate() << endl;
    }
};
#endif
