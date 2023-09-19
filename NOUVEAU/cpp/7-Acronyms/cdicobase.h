#ifndef CDICOBASE_H
#define CDICOBASE_H
#include "cdef.h"
#include <iostream>
#include <fstream>
using namespace std;
class CAcro;
class CDicoBase
{
    string path;
    fstream stream;

public:
    CDicoBase(const string &path = 0)
    {
        this->path = path;
        stream.open(this->path.c_str(), ios::in);
    }
    virtual ~CDicoBase()
    {
        if (stream)
            stream.close();
    }
    bool isOpen() const { return stream.is_open(); }

    bool load()
    {
        if (!isOpen()) return false;
            string line, acro;
            while(getline(stream, line)){
                size_t pos = line.rfind('\r');
                if(pos != string::npos) line.replace(pos, 1, "\0");
                if(line[0] == '*'){
                    line.erase(0,1);
                    acro = line;
                }
                if(line[0] == '+'){
                    int cod = line[1] - '0';
                    line.erase(0,3);
                    addDef(acro, CDef(line,cod));
                }
            }
            return true;
    }

    virtual int size() const = 0;
    virtual CAcro & acro(int index) = 0;
    virtual void voidaddDef(string acro, const CDef &cdef) = 0;
    virtual void sort() = 0;
};
#endif