#include "ccourbe.h"

CCourbe::CCourbe(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
    mode = Mode::Construction;
    spline = new CBezier(this);
}

CCourbe::~CCourbe(){
    delete spline;
}
void CCourbe::mouseMoveEvent(QMouseEvent* event)
{
    QPoint point;
    point.setX(LX(event->position().x()));
    point.setY(LY(event->position().y()));
    //emit posChange(point, 0);
    if (points.isEmpty()) return;
    if (mode == Construction) {
        points.removeLast();
        points << point;
    }
    if (mode == Modification) {
        if (itPoint == points.end()) return;
        (*itPoint).setX(point.x());
        (*itPoint).setY(point.y());
    }
    update();
    emit posChange(point, points.size());
}

void CCourbe::mousePressEvent(QMouseEvent* event){
    QPoint point;
    point.setX(LX(event->position().x()));
    point.setY(LY(event->position().y()));
    emit posChange(point, 0);
    if (mode == Construction) {
            if (!points.isEmpty()) points.removeLast();
            points << point;
            if (event->button() == Qt::LeftButton) {
                points << point;
            }
            if (event->button() == Qt::RightButton) {
                itPoint = points.end();
                mode = Modification;
            }
        }
        if (mode == Modification) {
            if (event->button() == Qt::LeftButton) {
                QList<QPoint>::iterator it;
                for (it = points.begin(); it != points.end(); ++it) {
                    if (poignee(*it).contains(point)) itPoint = it;
                }
            }
        }
        update();
}

void CCourbe::mouseReleaseEvent(QMouseEvent* event){
    QPoint point;
    point.setX(LX(event->position().x()));
    point.setY(LY(event->position().y()));
    emit posChange(point, 0);
    if (mode == Modification) {
            if (event->button() == Qt::LeftButton) {
                itPoint = points.end();
            }
        }
        update();
}

QRect CCourbe::poignee(const QPoint& point)
{
    int size = 10;
    int x = point.x() - LX(size / 2);
    int y = point.y() - LY(size / 2);
    return QRect(x, y, LX(size), LY(size));
}

void CCourbe::paintEvent(QPaintEvent* event){
    Q_UNUSED(event);
    QPainter paint(this);
    dessine(paint);
}

void CCourbe::dessine(QPainter& paint, bool final)
{
    paint.save();
    paint.setWindow(0, 0, LARGEURVUE, HAUTEURVUE);
    QList<QPoint>::iterator it;
    QPoint pt;
    if (!final)
        for (it = points.begin(); it != points.end(); ++it) {
            paint.setPen(Qt::SolidLine);
            paint.setBrush(it == itPoint ? Qt::red : Qt::blue);
            paint.drawRect(poignee(*it));
            paint.setPen(Qt::DotLine);
            paint.setPen(Qt::lightGray);
            if (!pt.isNull())
                paint.drawLine(pt, *it);
            pt = *it;
        }
    if(!points.isEmpty()){
                spline->traceCourbe(paint, points, isFormGen);
            }
    paint.restore();
}

void CCourbe::raz()
{
    points.clear();
    mode = Construction;
    update();
    emit posChange(QPoint(0,0), 0 );
}

void CCourbe::changeTypeCourbe(bool bezier, bool formGen){
    isBezier = bezier;
    isFormGen = formGen;

    delete spline ;
    if ( isBezier ) spline = new CBezier ;
    else spline = new CBSpline ;
    update() ;
}

QString CCourbe::typeCourbe(){
    QString s;

    if (isBezier) {
        s = "courbe de Bézier";
        if (isFormGen) {
            s += " - Formule générale";
        }
        else {
            s += " - Méthode des barycentres (sur 4 points max.)";
        }
    }
    else {
        s = "courbe B-Spline (polynômes de Reisenfeld)";
        if (isFormGen) {
            s += " - Formule générale m = 3";
        }
        else {
            s += " - Cas particulier m = 2";
        }
    }

    return s;
}

