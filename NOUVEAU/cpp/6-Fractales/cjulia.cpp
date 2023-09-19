// cjulia.cpp

#include "cjulia.h"
#include "cvue.h"
#include <iostream>
#include <math.h>

CJulia::CJulia(int n, double a, double b) : nMax(n)
{
	x1 = -2.;
	x2 = 2.;
	y1 = 1.5;
	y2 = -1.5;
	C = complex<double>(a, b);
	julia = true;
}

int CJulia::dot(double x, double y, double xMin, double xMax, double yMin, double yMax)
{

	int zoomx = 800 / (x2 - x1);
	int zoomy = 600 / (y1 - y2);
	complex<double> Z;
	if (julia) //Ensemble de Julia
	{
		//C = -0.0519,0.688 ; C = 0.285,0.01; C = -1 ; C = -0.1134,0.8606 ; C = 0.32,0.0043 ; C = -0.25
		//	C = complex<double> (0.285,0.01);
		Z = complex<double>(x / zoomx + x1, y / zoomy + y2);
	}
	else //Ensemble de Mandelbrot
	{
		C = complex<double>(x / zoomx + x1, y / zoomy + y2);
		Z = complex<double>(0, 0);
	}
	init(Z);
	for (int n = 0; n < nMax; n++)
	{
		complex<double> Z(real(Zn) * real(Zn) - imag(Zn) * imag(Zn) + real(C), 2 * real(Zn) * imag(Zn) + imag(C));
		if (norm(Z) > 4)
			return n;
		Zn = Z;
	}
	return 0;
}

void CJulia::init(const complex<double> &Z)
{
	Zn = Z;
}
