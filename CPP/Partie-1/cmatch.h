#include "cclubsportif.h"

using namespace std;

class CMatch {
private:
  CDate date;
  CMembre *adversaire1;
  CMembre *adversaire2;

public:
  CMatch(CDate date, CMembre *adversaire1, CMembre *adversaire2);

  string print();
};
