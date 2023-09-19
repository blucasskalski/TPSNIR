#include "cmembre.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    CDate cdatedefault;
    cdatedefault.setdate(1, JAN, 1900);
    string cdate1 = cdatedefault.printlongdate();
    CMembre membre1("Tournelle", "Marie", CDate(1, AVR, 2000));
    CMembre cmembre2("nom1", "prenom1", cdate1);
    cout << membre1.printmembre() << endl;
    
    return 0;
}