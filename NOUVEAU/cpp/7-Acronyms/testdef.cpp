#include "cdef.h"
#include "cacro.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    CDef def("Internet Protocol", 0);
    cout << def.print();

    CDef def2("Intelligent Peripheral", 0);
    cout << def2.print();

    CDef def3;
    def3.setLang(0);
    def3.setDef("In My Opinion");
    cout << def3.print() << endl;

    CAcro cacro("IP");
    cacro.addDef(def);
    cacro.addDef(def2);
    cout << cacro.print();

    CAcro cacro2("IMO");
    cacro2.addDef(def3);
    cout << cacro2.print();
}