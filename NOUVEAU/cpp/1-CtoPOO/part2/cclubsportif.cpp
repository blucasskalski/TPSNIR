#include "cclubsportif.h"
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

bool CClubSportif::ajoute(const CMembre &membre)
{
    int ilibre = 0;
    int i = 0;
    for (i = 0; i < NMAX; i++)
    {
        if (membres[i] == 0)
        {
            ilibre = i;
            membres[ilibre] = new CMembre(membre);
            break;
        }
    }
/*     cout << "libre :" << ilibre << endl;
    while (i >= 0)
    {
        cout << "return :" << membres[i]->printmembre() << endl;
        i--;
    } */
}

void CClubSportif::liste()
{
    int num = 1;
    cout << "Affcihage des membres..." << endl;
     for (int i = 0; i < NMAX; i++)
    {
        if(membres[i] != 0)
        {
             cout << "N°" << num << " " << membres[i]->printmembre() << endl;
             num++;
        }
    }
}

void CClubSportif::nettoyage()
{
    cout << "Nettoyage des membres..." << endl;
    for(int i = 0; i < NMAX; i++)
    {
        membres[i] = 0;
    }
}