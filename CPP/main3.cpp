/*--------------------------------------------------------------------------
 *  Nom         :   main3.cpp
 *  Type        :   APPLICATION
 *  Sujet       :   Programme de test de la classe CDate
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :   g++ -Wall -o test3 main3.cpp tmonth.cpp cdate.cpp
 *--------------------------------------------------------------------------
 */
#include "cdate.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv){
	CDate cdate1;

	cdate1.set(14, JUL, 1789);

	CDate cdate2(11, SEP, 2001);

	cdate2.setYear(2011);
	cdate2.setMonth(OCT);
	//Affichage Compressé
	cout << cdate1 << endl;
	cout << cdate2 << endl;
	//Affichage Long
	cout << cdate1.printLong() << endl;
	cout << cdate2.printLong() << endl;


	return 0;
}
