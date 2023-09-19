// cvue.h

#ifndef CVUE_H
#define CVUE_H

#include <../XamGraph/src/xamgraph.h>

class CJulia;

class CVue : public XamGraph
{
	double xMin; // plan complexe initial
	double xMax;
	double yMin;
	double yMax;

	int mainColor; // couleur de base

	bool capture;
		// indicateur capture en cours
	int xBegin, yBegin; // coord. du rectangle de capture
	int xEnd, yEnd;
	int dot;
	CJulia *fractale; // objet fractal utilisé

public:

	CVue(int w, int h, CJulia *fractale);
	~CVue() {}

	bool isCapturing() { return capture; }
	void initCapture(int x, int y);
	void changeCapture(int x, int y);
	void stopCapture();

	void drawLogicalPosition(int x, int y);

private:
	void drawCapture();
	void drawFractal();

	double xLogical(int xPix) { return (xMax - xMin) / maxX() * xPix + xMin; }
	double yLogical(int yPix) { return (yMax - yMin) / maxY() * (maxY() - yPix) + yMin; }

	int scaledColor(int n);
};

#endif
