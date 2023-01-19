#include "cmembre.h"
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
  CMembre membre1("Marie", "Tournelle", CDate(1, SEP, 2004));
  cout << membre1.print() << endl;
  cout << membre1.printLong() << endl;
  return 0;
}
