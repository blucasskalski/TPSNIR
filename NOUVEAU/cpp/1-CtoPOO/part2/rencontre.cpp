// g++ -Wall -o rencontre rencontre.cpp cdate.cpp tmonth.cpp cclubsportif.cpp cmembre.cpp 

#include "cmembre.h"
#include "cclubsportif.h"
#include "cmatch.h"
#include "cdate.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    CDate dateMatch;
    dateMatch.setdate(22, OCT, 2021);
    CMembre membre1("Thomas", "Verhnes", CDate(19, MAR, 2002));
    CMembre membre2("Yohann", "Raimbault", CDate(18, SEP, 2002));
    CClubSportif Club;
    Club.ajoute(membre1);
    Club.ajoute(membre2);
    Club.liste();
    CMatch match(membre1, membre2, dateMatch);
    match.printMatch();
   
    return 0;
}