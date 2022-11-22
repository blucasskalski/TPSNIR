#ifndef CDEF_H
#define CDEF_H
#include <string>
using namespace std;
class CDef {
  static string cl[];

public:
  CDef() {}

  CDef(const string &definition, int langue = 0) {}

  CDef(const CDef &cdef) {}

  ~CDef() {}

  static string CodLang(int langue) {

    int i = 0;

    while (!cl[i].empty()) {

      if (i == langue)
        return cl[i];

      i++;
    }

    return cl[i];
  }
};
//                     0     1     2     3     4     5     6
string CDef::cl[] = {"EN", "FR", "DE", "SP", "IT", "JP", "RU", ""};
#endif
