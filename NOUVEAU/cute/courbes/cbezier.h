#ifndef CBEZIER_H
#define CBEZIER_H

#include <QObject>
#include <QPainter>

class CBezier : public QObject
{
    Q_OBJECT
protected:
    int resolution;
public:
    explicit CBezier(QObject *parent = nullptr);
    void traceCourbe(QPainter& paint, QList<QPoint>& points, bool formGen) ;

protected:
    virtual void casParticulier(QPainter& paint, QList<QPoint>& pts ) ;
    virtual void formuleGenerale(QPainter& paint, QList<QPoint>& pts ) ;
    double puiss(double x, int n);
    double fact(int n);
    double cnk(int n, int k);
signals:

};

#endif // CBEZIER_H
