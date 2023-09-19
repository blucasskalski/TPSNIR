#include "cjulia.h"
#include "cmondelbrot.h"
#include <iostream>

CMondelbrot::CMondelbrot(int nMax) : CJulia(nMax), nMax(nMax)
{
	x1 = -2.4;
	x2 = 1.2;
	y1 = 1.5;
	y2 = -1.5;
    //QUESTION 17 A FAIRE
	julia = false;
}