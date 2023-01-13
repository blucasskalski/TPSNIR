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

void CBSpline::fonctionGenerale(QPainter& paint, QList<QPoint>& pts) {
    paint.save();
    paint.setPen(QPen(Qt::darkGreen, 2));

    int n = pts.size(); // nombre de points de contrôle
    int k = 3; // degré de la courbe
    double t; // paramètre de la courbe

    std::vector<double> knots(n + k + 1);
    for (int i = 0; i < n + k + 1; ++i) {
        if (i < k) {
            knots[i] = 0;
        } else if (i > n) {
            knots[i] = n - k + 2;
        } else {
            knots[i] = i - k + 1;
        }
    }
    // tableau pour stocker les points intermédiaires
    QList<QPoint> interPoints(n + k + 1);

    for (int i = 0; i <= resolution; i++) {
        t = i / (double)resolution;
        // calcul des points intermédiaires
        for (int j = 0; j < n; j++) {
            interPoints[j + k] = pts[j];
        }
        for (int r = 1; r <= k; r++) {
            for (int j = k - r; j < n; j++) {
                double a = (t - knots[j]) / (knots[j + r + 1 - k] - knots[j]);
                interPoints[j] = interPoints[j].x() * (1 - a) + interPoints[j + 1].x() * a;
                interPoints[j].setY(interPoints[j].y() * (1 - a) + interPoints[j + 1].y() * a);
            }
        }
        // dessin de la courbe
        paint.drawPoint(interPoints[k - 1]);
        if (i > 0) {
            paint.drawLine(interPoints[k - 1], interPoints[k - 2]);
        }
    }
    paint.restore();
}
