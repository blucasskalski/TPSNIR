#include "cbezier.h"

CBezier::CBezier(QObject *parent)
    : QObject{parent}, resolution(400){
}

double CBezier::puiss(double x, int n ) {
    double resultat = 1;
    while (n) {
        if (n & 1)
            resultat *= x;
        x *= x;
        n >>= 1;
    }
    return resultat;
}

double CBezier::fact(int n) {
    double resultat = 1;
    while (n) {
        resultat *= n--;
    }
    return resultat;
}

double CBezier::cnk(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

void CBezier::casParticulier(QPainter& paint, QList<QPoint>& pts ){
    paint.save() ;
    paint.setPen( QPen(Qt::darkGreen, 2 ) ) ; // sélection d’un crayon

    QPoint ptAct, ptPrec = pts[0] ;
    int n = pts.size() - 1 ; // ordre de la courbe

    for ( int i = 0 ; i <= resolution ; i++ ) {
        double t = i / (double)resolution ; // variation de 0 à 1
        double x = 0.0 , y = 0.0 ;
        double a, b, c, d ;

        switch( n ) {
        case 1 : // équation (1)
            a = 1 - t ;
            b = t ;
            x = pts[0].x() * a + pts[1].x() * b ;
            y = pts[0].y() * a + pts[1].y() * b ;
            break ;
        case 2 : // équation (2)
            a = puiss(1 - t, 2 ) ;
            b = 2 * t * ( 1 - t ) ;
            c = puiss(t, 2 ) ;
            x = pts[0].x() * a + pts[1].x() * b + pts[2].x() * c ;
            y = pts[0].y() * a + pts[1].y() * b + pts[2].y() * c ;
            break ;
        default : // équation (3)
            a = puiss(1 - t, 3 ) ;
            b = 3 * t * puiss(1 - t, 2 ) ;
            c = 3 * puiss(t, 2 ) * ( 1 - t ) ;
            d = puiss(t, 3 ) ;
            x = pts[0].x() * a + pts[1].x() * b + pts[2].x() * c + pts[3].x() * d ;
            y = pts[0].y() * a + pts[1].y() * b + pts[2].y() * c + pts[3].y() * d ;
            break ;
        }
        ptAct.setX( (int)x ) ;
        ptAct.setY( (int)y ) ;
        paint.drawPoint(ptAct ) ;
        paint.drawLine(ptPrec, ptAct ) ;
        ptPrec = ptAct ;
    }
    paint.restore() ;
}

void CBezier::formuleGenerale(QPainter& paint, QList<QPoint>& pts ){
    paint.save() ;
    paint.setPen( QPen(Qt::darkGreen, 2 ) ) ; // sélection d’un crayon

    QPoint ptAct, ptPrec = pts[0] ;
    int n = pts.size() - 1 ; // ordre de la courbe

    for ( int i = 0 ; i <= resolution ; i++ ) {
        double t = i / (double)resolution ; // variation de 0 à 1

        QList<QPoint> list;
        list = pts;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= (n - j); k++) {
                list[k].setX((1 - t) * list[k].x() + t * list[k + 1].x());
                list[k].setY((1 - t) * list[k].y() + t * list[k + 1].y());
            }
        }

        ptAct = list[0];
        paint.drawPoint(ptAct);
        paint.drawLine(ptPrec, ptAct);
        ptPrec = ptAct;
    }
    paint.restore() ;
}

void CBezier::traceCourbe(QPainter& paint, QList<QPoint>& points, bool formGen ){
    if (formGen) {
     formuleGenerale(paint, points);
     } else {
     casParticulier(paint, points);
     }
}
