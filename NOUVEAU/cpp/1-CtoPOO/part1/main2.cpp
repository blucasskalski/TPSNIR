#include "tdate.h"
#include <iostream>
using namespace std ;
int main(int argc, char** argv )
{
  TDate tdate1 ;
  //setDate(&tdate1, 14, (TMonth) JUL, 1789 ) ;
  TDate tdate2 ;

  unsigned j, m, a ;
  cout << "jour, mois et année (séparés par espaces) ? " ;
  cin >> j >> m >> a ;
  setDate(&tdate2, j, (TMonth) m, a ) ;
  cout << "date 1 : " << tdate1.day << '/' ;
  cout << tdate1.month << '/' << tdate1.year << endl ;
  cout << "date 2 : " << tdate2.day << '/' ;
  cout << strMonth(tdate2.month) << '/' << tdate2.year << endl ;

  return 0 ;
}
