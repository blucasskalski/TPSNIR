#include "CMembre.h"
#include "cdate.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  char buffer[1024];
  CMembre membre1("Tournelle", "Marie", CDate(1, AVR, 2000));
  cout << membre1.print() << endl;
  cin >> buffer;
  membre1.setPRENOM(buffer);
  cout << membre1.print() << endl;
  return 0;
}
