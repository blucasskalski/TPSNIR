#include "cbspline.h"
#include <iostream>
using namespace std;

CBSpline::CBSpline(QObject *parent) : CBezier(parent), resolution(100) {
  //...
}

void CBSpline::casParticulier(QPainter &paint, QList<QPoint> &pts) {
  paint.save();
  paint.setPen(QPen(Qt::darkRed, 2));
  QPoint ptAct, ptPrec = pts[0];
  int n = pts.size() - 1; // ordre de la courbe

  for (int i = 0; i <= resolution; i++) {
    double t = i / (double)resolution; // variation de 0 à 1
    double x = 0.0, y = 0.0;
    double a, b, c;

    a = (1 - t) * pts[n - 1].x() + t * pts[n].x();
    b = (1 - t) * pts[n - 2].x() + t * pts[n - 1].x();
    c = (1 - t) * b + t * a;
    x = c;

    a = (1 - t) * pts[n - 1].y() + t * pts[n].y();
    b = (1 - t) * pts[n - 2].y() + t * pts[n - 1].y();
    c = (1 - t) * b + t * a;
    y = c;

    ptAct.setX((int)x);
    ptAct.setY((int)y);
    paint.drawPoint(ptAct);
    paint.drawLine(ptPrec, ptAct);
    ptPrec = ptAct;
  }
  paint.restore();
}

void CBSpline::formuleGenerale(QPainter &paint, QList<QPoint> &pts) {
 //CODE
}
