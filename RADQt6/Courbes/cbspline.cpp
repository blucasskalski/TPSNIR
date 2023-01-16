#include "cbspline.h"

CBSpline::CBSpline(QObject *parent) : CBezier(parent), resolution(100){
    //...
}

void CBSpline::casParticulier(QPainter& paint, QList<QPoint>& pts)
{
    paint.save();
    paint.setPen(QPen(Qt::darkRed, 2));
    QPoint ptAct, ptPrec = pts[0];
    int n = pts.size() - 1; // ordre de la courbe
    for (int i = 0; i <= resolution; i++) {
        if(n ==2){
            double t = i / (double)resolution; // variation de 0 à 1
            double x = 0.0, y = 0.0;
            double a, b, c;
            a = (1 - t) * (1 - t);
            b = 2 * t * (1 - t);
            c = t * t;
            x = (pts[0].x() * a) + (pts[1].x() * b) + (pts[2].x() * c);
            y = (pts[0].y() * a) + (pts[1].y() * b) + (pts[2].y() * c);
            ptAct.setX((int)x);
            ptAct.setY((int)y);
            paint.drawPoint(ptAct);
            paint.drawLine(ptPrec, ptAct);
            ptPrec = ptAct;
        }
    }
    paint.restore();
}

void CBSpline::formuleGenerale(QPainter& paint, QList<QPoint>& pts) {
    //...
}
