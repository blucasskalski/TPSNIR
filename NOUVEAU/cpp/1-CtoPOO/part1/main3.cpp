#include "cdate.h"
#include <iostream>
using namespace std ;

int main(int argc, char** argv)
{
  CDate cdate1;
  cdate1.setdate(14, JUL, 1789);
  CDate cdate2(11, SEP, 2001);
  //
  cdate2.setMonth(OCT);
  cdate2.setYear(2011);
  //
  cout << cdate1.printdate() << endl;
  cout << cdate2.printdate() << endl;
  cout << cdate1.printlongdate() << endl;
  cout << cdate2.printlongdate() << endl;
  return 0;
}
