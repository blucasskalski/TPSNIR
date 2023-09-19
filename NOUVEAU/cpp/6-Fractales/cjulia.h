// cjulia.h

#ifndef CJULIA_H
#define CJULIA_H

#include <complex>
using namespace std;

class CJulia
{
	int nMax; // nombre d'itérations

protected:
	complex<double> Zn;
	complex<double> C;
	double x1, y1, x2, y2; // plan complexe initial
	bool julia = false;

public:
	CJulia(int nMax = 200, double a = 0.0, double b = 0.0);
	virtual ~CJulia() {}

	double left() const { return x1; }
	double right() const { return x2; }
	double bottom() const { return y1; }
	double top() const { return y2; }

	int dot(double x, double y, double xMin = 0, double xMax = 0, double yMin = 0, double yMax = 0);

protected:
	virtual void init(const complex<double> &Z);
};

#endif
