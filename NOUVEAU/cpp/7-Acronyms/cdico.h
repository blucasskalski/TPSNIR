#ifndef CDICO_H
#define CDICO_H

#include <ostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "cdicobase.h"
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class CDicoBase;

class CDico : CDicoBase
{
    string path;
    vector<CAcro> acronyms;

public:
    CDico(const string &path = 0) : CDicoBase(path) {}
    virtual int size() const { return acronyms.size(); }
    virtual CAcro &acro(int index)
    {
        vector<CAcro>::iterator acro2 = acronyms.begin();
        advance(acro2, index - 1);
        return *acro2;
    };
    virtual void voidaddDef(string acro, const CDef &cdef){};
    virtual void sort(){};
};
#endif