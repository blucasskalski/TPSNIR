/*--------------------------------------------------------------------------
 *  Nom         :   main2.cpp
 *  Type        :   APPLICATION
 *  Sujet       :   Programme de test de TDate
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :   g++ -Wall -o test2 tmonth.cpp tdate.cpp main2.cpp
 *--------------------------------------------------------------------------
 */
#include "tdate.h"
#include <iostream>
using namespace std;
void setDate(TDate* date, unsigned day, TMonth month, unsigned year);
int main(int argc, char** argv){
	TDate tdate1;
	setDate(&tdate1, 14, JUL, 1789 );
	TDate tdate2;

	unsigned j, m, a;
	cout << "jour, mois et année (séparés par espaces) ? ";
	cin >> j >> m >> a;

	setDay(&tdate2, j);
	setMonth(&tdate2, (TMonth)m);
	setYear(&tdate2, a);

	cout << "date 1 : " << tdate1.day << '/';
	cout << tdate1.month << '/' << tdate1.year << endl;
	cout << "date 2 : " << tdate2.day << '/';
	cout << strMonth(tdate2.month) << '/' << tdate2.year << endl;
	return 0;
}
