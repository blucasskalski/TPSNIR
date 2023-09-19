// main.cpp

#include "cmydraft.h"
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	// Traitement de l'option '-v' (ligne de commandes)

	if (argc > 1)
	{
		string opt(*++argv);
		if (opt == "-v")
			CDraft::setVerbose(true);
	}
	// Construction de l'espace graphiqu

	CMyDraft draft(800, 600);
	draft.setX(400);
	draft.setY(300);
	draft.setScale(40);
	draft.draw(true);

	CVector v1(CPoint(1.5, 2), CPoint(7.2, 5));
	v1.setColor(XAM_LIGHT_RED);
	v1.setVisible(true);
	draft.draw(v1);

	CRectangle r1(5, 2.5);
	r1.setPos(CPoint(-6, 4.5));
	r1.setFill(true);
	r1.setColor(XAM_LIGHT_GREEN);
	r1.setVisible(true);
	draft.draw(r1);

	CLozenge l1(3, 1.4);
	l1.setPos(CPoint(-9, -4.5));
	l1.setFill(true);
	l1.setColor(XAM_CYAN);
	l1.setVisible(true);
	draft.draw(l1);

	CLabel a1("MY_CLABEL1");
	a1.setPos(CPoint(-8, -2));
	a1.setColor(XAM_DARK_GREEN);
	a1.setVisible(true);
	draft.draw(a1);

	CButton b(CPoint(5.5, -5.2), 4, 1, "MY_CBUTTON1");
	b.CRectangle::setColor(XAM_LAVENDER);
	b.CRectangle::setFill(true);
	b.setVisible(true);
	draft.draw(b);

	CSquare c(3);
	c.setPos(CPoint(2.4, 1));
	c.setColor(XAM_DARK_MAGENTA);
	c.setVisible(true);
	draft.draw(c);

	CFigure *figure[6];
	figure[0] = new CVector(4, -1.6);
	figure[0]->setPos(CPoint(-5, -4));
	figure[0]->setColor(XAM_RED);

	figure[1] = new CRectangle(1, 3.14);
	figure[1]->setPos(CPoint(-8.5, 2));
	figure[1]->setColor(XAM_BLUE);

	figure[2] = new CLozenge(4, 2.4);
	figure[2]->setPos(CPoint(0, 6));
	figure[2]->setColor(XAM_DARK_CYAN);

	figure[3] = new CLabel("MY_CLABEL2");
	figure[3]->setPos(CPoint(6.5, 2));
	figure[3]->setColor(XAM_GREEN);

	figure[4] = new CButton(CPoint(-8, 6.3), 5, 0.8, "MY_CBUTTON2");
	figure[4]->setColor(XAM_ORANGE);

	figure[5] = new CSquare(1.8);
	figure[5]->setPos(CPoint(-3, -0.5));
	figure[5]->setFill(true);
	figure[5]->setColor(XAM_VIOLET);

	for (unsigned i = 0; i < 6; i++)
	{
		if (figure != NULL)
		{
			figure[i]->setVisible(true);
			figure[i]->draw(draft);
		}
	}

	CPoint pts1[3] = {CPoint(-1, 0), CPoint(1, 1), CPoint(1, -1)};
	CPolygon poly1(CPoint(0, 0), 3, pts1);
	poly1.setVisible(true);
	poly1.setFill(false);
	poly1.setColor(XAM_BLACK);
	poly1.draw(draft);

	CPoint pts2[12] = {CPoint(2, -4), CPoint(3, -4), CPoint(3, -5), CPoint(4, -5), CPoint(4, -6),
					   CPoint(3, -6), CPoint(3, -7), CPoint(2, -7), CPoint(2, -6), CPoint(1, -6), CPoint(1, -5), CPoint(2, -5)};
	CPolygon poly2(CPoint(1, -4), 12, pts2);
	poly2.setVisible(true);
	poly2.setFill(true);
	poly2.setColor(XAM_GOLD);
	poly2.draw(draft);
	// coord : 1,-4
	// pts :2,-4 ; 3,-4 ; 3, -5 ; 4, -5; 4, -6 ; 3, -6 ; 3, -7 ; 2, -7 ; 2, -6 ; 1, -6 ; 1, -5 ; 2, -5 ;

	CCircle circle(CPoint(7.5, -3), 1.2, 30);
	circle.setFill(false);
	circle.setVisible(true);
	circle.setColor(XAM_PINK);
	circle.draw(draft);

	draft.updateScreen();
	draft.run();

	return 0;
}
