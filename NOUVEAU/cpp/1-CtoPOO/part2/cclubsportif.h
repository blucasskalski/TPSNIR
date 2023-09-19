#ifndef CCLUBSPORTIF
#define CCLUBSPORTIF
#include "tmonth.h"
#include "cdate.h"
#include "cmembre.h"
#include <string>
#include <ostream>
#define NMAX 100

using namespace std;

class CClubSportif
{
private:
    std::string membres2;
    CMembre *membres[NMAX];

public:
    CClubSportif()
    {
        for (int i = 0; i < NMAX; i++)
            membres[i] = 0;
    }

    bool ajoute(const CMembre &membre);
    void liste();
    void nettoyage();
};
#endif
