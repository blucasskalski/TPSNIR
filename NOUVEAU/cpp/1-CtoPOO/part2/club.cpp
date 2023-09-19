// g++ -Wall -o rencontre rencontre.cpp cdate.cpp tmonth.cpp cclubsportif.cpp cmembre.cpp 
#include "cmembre.h"
#include "cclubsportif.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    CDate cdatedefault;
    cdatedefault.setdate(1, JAN, 1900);
    string cdate1 = cdatedefault.printlongdate();
    CMembre membre1("Tournelle", "Marie", CDate(1, AVR, 2000));
    CMembre membre2("nom1", "prenom1", cdate1);
    CMembre membre3("yo", "lo", CDate(1, AVR, 2000));
    CMembre membre4("comment", "tu", CDate(1, AVR, 2000));
    CMembre membre5("vas", "et", CDate(1, AVR, 2000));
    CMembre membre6("toi", "oui", CDate(1, AVR, 2000));
    CMembre membre7("non", "ou", CDate(1, AVR, 2000));
    CMembre membre8("pas", "wesh", CDate(1, AVR, 2000));
    CMembre membre9("alors", "nous", CDate(1, AVR, 2000));
    CMembre membre10("avons", "toujours", CDate(1, AVR, 2000));
    CMembre membre11("bonjour", "salut", CDate(1, AVR, 2000));
    cout << membre1.printmembre() << endl;
    CClubSportif Club;
    Club.ajoute(membre1);
    Club.ajoute(membre2);
    Club.ajoute(membre3);
    Club.ajoute(membre4);
    Club.ajoute(membre5);
    Club.ajoute(membre6);
    Club.ajoute(membre7);
    Club.ajoute(membre8);
    Club.ajoute(membre9);
    Club.ajoute(membre10);
    Club.ajoute(membre11);
    Club.liste();
    Club.nettoyage();
    Club.liste();
    
    return 0;
}