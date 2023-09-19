// cvue.cpp

#include "cvue.h"
#include "cjulia.h"
#include "iostream"
// constructeur
// par défaut, le repère complexe est initialisé avec le plan physique

CVue::CVue(int w, int h, CJulia *fractale)
	: XamGraph(w, h, "Julia & Mandelbrot"),
	  xMin(0),
	  xMax(w - 1),
	  yMin(h - 1),
	  yMax(0),
	  capture(false),
	  fractale(NULL)
{
	if (fractale != NULL)
	{
		this->fractale = fractale;
	}

	/*	xMin = fractale->left();
	xMax = fractale->right();
	yMin = fractale->top();
	yMax = fractale->bottom();
*/
	mainColor = stringToColor("#0080ff");

	clearScreen(XAM_WHITE);
	drawFractal();
}

// Début ou fin d'une capture rectangulaire pour zoom

void CVue::initCapture(int x, int y)
{

	if (!capture)
	{ // premier point
		capture = true;
		xBegin = x;
		yBegin = y;
		xEnd = x;
		yEnd = y;
		drawCapture();
	}
	else
	{ // deuxième point
		// dessin de la nouvelle fractale
		stopCapture();
		xMin = xLogical(xBegin);
		xMax = xLogical(xEnd);
		yMin = yLogical(yEnd);
		yMax = yLogical(yBegin);
		setDrawingArea(XAM_DRAWING_BITMAP);
		drawFractal();
		updateScreen();
		setDrawingArea(XAM_DRAWING_SCREEN);
		updateScreen();
	}
}

// Modification dynamique du rectangle de capture

void CVue::changeCapture(int x, int y)
{
	drawCapture();
	xEnd = x;
	yEnd = y;
	drawCapture();

	updateScreen();
}

// Annulation de la capture en cours

void CVue::stopCapture()
{
	drawFractal();
	updateScreen();
	capture = false;
}

// Dessin du rectangle de capture (mode XOR)

void CVue::drawCapture()
{
	setWriteMode(XAM_MODE_XOR);
	setColor(XAM_GREEN);

	int left = (xBegin < xEnd ? xBegin : xEnd);
	int top = (yBegin < yEnd ? yBegin : yEnd);
	int right = (xBegin < xEnd ? xEnd : xBegin);
	int bottom = (yBegin < yEnd ? yEnd : yBegin);

	rectangle(left, top, right - left, bottom - top);
	setWriteMode(XAM_MODE_COPY);

	updateScreen();
}

// Dessin point par point de la fractale
void CVue::drawFractal()
{
	string colors[16] = {"#E6E6FA", "#FFFF00", "#FF00FF", "#FF00OO", "#00FFFF", "#OOFF00", "#0000FF", "#800080", "#C0C0C0", "#800000", "#C000C0", "#8000OO", "#008080", "#008000", "#000080", "#FFA500"};
	if (fractale == NULL)
		return;

	for (int i = 0; i < maxX(); i++)
	{
		for (int j = 0; j < maxY(); j++)
		{
			dot = fractale->dot(xLogical(i), yLogical(j), xMin, xMax, yMin, yMax);
			//putPixel(i, j, stringToColor(colors[(dot % 16)].c_str()));
			//Uint32 v = ( 255 * ( dot % 32 + 1 ) / 33.0 );
			//putPixel(i, j, rgb(0,0,v));
			putPixel(i, j, scaledColor(dot));
		}
	}
	updateScreen();
}

// affiche position courante de la souris dans le repère complexe

void CVue::drawLogicalPosition(int x, int y)
{
	char buf[80];
	sprintf(buf, "[ %+15.10f ; %+15.10f ]", xLogical(x), yLogical(y));
	char buf2[10];
	sprintf((buf2), "%d ;", capture);
	setColor(XAM_WHITE);
	int posy = maxY() - textHeight() - 4;
	filledRectangle(0, posy, textWidth(buf) + 4, textHeight() + 4);
	setColor(XAM_BLACK);
	//textOut(2, posy + 2, buf);
	textOut(2, posy + 2, buf2);

	updateScreen();
}

// couleurs...
int c = 0;
int d = 0;
int CVue::scaledColor(int n)
{
	int COLOR_TABLE[] = {
		0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c,
		0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff,
		0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999,
		0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d,
		0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24,
		0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f,
		0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8,
		0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c,
		0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99,
		0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64,
		0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27,
		0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c,
		0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416,
		0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be,
		0xffe0, 0x9e66, 0x0000};
	int color = COLOR_TABLE[n];
	/*c++;
	if (c > 30000)
		c = 0, d++;
	if (d > 143)
		d = 0;*/
	/*int r = ((color >> 11) & 0x1F) << 3;
	int g = ((color >> 5) & 0x3F) << 2;
	int b = (color & 0x1F) << 3;
	return rgb(r, g, b);*/
	int r = (int)(red(mainColor) * (n % 17) / 16.0);
	int v = (int)(green(mainColor) * (n % 17) / 16.0);
	int b = (int)(blue(mainColor) * (n % 17) / 16.0);
	return rgb(r, v, b);
}
