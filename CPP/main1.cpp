/*--------------------------------------------------------------------------
 *  Nom         :   main1.cpp
 *  Type        :   APPLICATION
 *  Sujet       :   Programme de test de TMonth
 *
 *  Auteur      :   Bryan LUCAS SKALSKI
 *  Version     :   0.1
 *  Création    :   03/02/2022
 *
 *  Fabrication :   g++ -Wall -o test1 main1.cpp tmonth.cpp
 *--------------------------------------------------------------------------
 */
#include "tmonth.h"
#include <iostream>
using namespace std ;

int main(int argc, char** argv){
	for(TMonth m = JAN ; m <= DEC; m = (TMonth)(m+1)){
		cout << strMonth(m) << endl;
	}
	return 0;
}
