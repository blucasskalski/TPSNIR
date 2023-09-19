#include "ccourbe.h"
#include <QMouseEvent>
#include <QPainter>

CCourbe::CCourbe(QWidget *parent)
    : QWidget{parent}, isBezier(1), isFormGen(0)
{
setMouseTracking( true ) ;
mode = Construction;
spline = new CBezier(this) ;
}

CCourbe::~CCourbe()
{
    delete spline;
}

void CCourbe::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point;
    point.setX(LX(event->pos().x()));
    point.setY(LX(event->pos().y()));
    emit posChange(point, points.count());
}

void CCourbe::mousePressEvent(QMouseEvent *event)
{
    QPoint point;
    point.setX(LX(event->pos().x()));
    point.setY(LX(event->pos().y()));
    if(mode == Construction)
    {
        if(! points.isEmpty()) points.removeLast();
        points << point;
        if(event->button() == Qt::LeftButton)
        {
            points << point;
        }
        if ( event->button() == Qt::RightButton ) {
            itPoint = points.end() ;
            mode = Modification ;
        }
    }
    if ( mode == Modification ) {
        if ( event->button() == Qt::LeftButton ) {
            QList<QPoint>::iterator it ;
            for ( it = points.begin() ; it != points.end() ; ++it ) {
                if ( poignee( *it ).contains(point) ) itPoint = it ;
            }
        }
    }
    update() ;
    if ( points.isEmpty() ) return ;
    if ( mode == Construction ) {
        points.removeLast() ;
        points << point ;
    }
    if ( mode == Modification ) {
        if ( itPoint == points.end() ) return ;
        (*itPoint).setX( point.x() ) ;
        (*itPoint).setY( point.y() ) ;
    }
    update() ;
}


void CCourbe::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint point;
    point.setX(LX(event->pos().x()));
    point.setY(LX(event->pos().y()));
    if ( points.isEmpty() ) return ;
    if ( mode == Construction ) {
        points.removeLast() ;
        points << point ;
    }
    if ( mode == Modification ) {
        if ( itPoint == points.end() ) return ;
        (*itPoint).setX( point.x() ) ;
        (*itPoint).setY( point.y() ) ;
    }
    update() ;
}

QRect CCourbe::poignee(const QPoint& point)
{
    int size = 10;
    int x = point.x() - LX(size / 2);
    int y = point.y() - LY(size / 2);
    return QRect(x, y, size, size);
}

void CCourbe::paintEvent(QPaintEvent* event )
{
    Q_UNUSED(event) ;
    QPainter paint( this ) ;
    dessine( paint ) ;
}

void CCourbe::dessine(QPainter& paint, bool final)
{
    paint.save() ;
    paint.setWindow(0, 0, LARGEURVUE, HAUTEURVUE ) ;
    QList<QPoint>::iterator it ;
    QPoint pt ;
    if ( !final ) for ( it = points.begin() ; it != points.end() ; ++it ) {
        paint.setPen( Qt::SolidLine ) ;
        paint.setBrush( it == itPoint ? Qt::red : Qt::blue ) ;
        paint.drawRect( poignee(pt) ) ;
        paint.setPen( Qt::DotLine ) ;
        paint.setPen( Qt::lightGray ) ;
        if ( ! pt.isNull() ) paint.drawLine(pt, *it ) ;
        pt = *it ;
    }
    if(!points.isEmpty()) spline->traceCourbe(paint, points, isFormGen);
    paint.restore() ;
}

void CCourbe::raz()
{
    points.clear();
    mode = Construction;
    update();
    emit posChange(QPoint(0,0),0);
}

void CCourbe::changeTypeCourbe(bool bezier, bool formGen)
{
    isBezier = bezier;
    isFormGen = formGen;
}
QString CCourbe::typeCourbe()
{
    QString s;
    int type = 0;
    if(isBezier) type++;
    if(isFormGen) type+=2;
    switch(type)
    {
    case 0: //B-Spline
        s = QString(" courbe B-Spline (polynômes de Reisenfeld) - Cas particulier m = 2 ");
        break;
    case 1: //Bezier
        s = QString(" courbe de Bézier - Méthode des barycentres (sur 4 points max.)");
        break;
    case 2: //B-Spline + FormGen
        s = QString(" courbe B-Spline (polynômes de Reisenfeld) - Formule générale m = 3 ");
        break;
    case 3: //Bezier + FormGen
        s = QString("courbe de Bézier - Formule générale");
        break;
    }

    return s;

}
