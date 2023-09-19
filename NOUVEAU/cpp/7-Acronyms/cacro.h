#ifndef CACRO_H
#define CACRO_H
#include "cacrobase.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
class CAcro : public CAcroBase
{
private:
    string acronyme;
    list<CDef> ldef;

public:
    CAcro() : acronyme("?") {}
    CAcro(string acro)
    {
        acronyme = acro;
    }
    CAcro(const CAcro &cacro)
    {
        acronyme = cacro.acronyme;
        ldef = cacro.ldef;
    }
    virtual string acro() const { return acronyme; }
    virtual int size() const { return ldef.size(); }
    virtual CDef &def(int index)
    {
        list<CDef>::iterator cdef2 = ldef.begin();
        advance(cdef2, index - 1);
        return *cdef2;
    };
    virtual void addDef(const CDef &def) { ldef.push_back(def);}

    string print()
    {
        std::ostringstream oss;
        oss << std::setfill('0');
        oss << "acronyme : " << acro() << endl;
        for(int i = 1; i <= size(); i++)
        {
            oss << "n°" << i << " : ";
            oss << def(i).print();
        }
        oss << endl;
        return oss.str();
    }
};
#endif