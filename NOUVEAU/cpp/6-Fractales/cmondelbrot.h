//cmondelbrot.h
#ifndef CMONDELBROT_H
#define CMONDELBROT_H

#include <complex>
#include "cjulia.h"
using namespace std;

class CMondelbrot : public CJulia
{
    int nMax;
    //void init(const complex<double> &Z);

public:
    CMondelbrot(int nMax);
};
#endif