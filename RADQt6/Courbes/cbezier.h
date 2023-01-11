#ifndef CBEZIER_H
#define CBEZIER_H

#include <QObject>
#include <QPainter>
#include <QList>

class CBezier : public QObject{
    Q_OBJECT
protected:
    int resolution;
    double puiss(double x, int n );
    double fact(int n );
    double cnk(int n, int k );
    virtual void casParticulier(QPainter& paint, QList<QPoint>& pts ) ;
    virtual void formuleGenerale(QPainter& paint, QList<QPoint>& pts ) ;
public:
    explicit CBezier(QObject *parent = nullptr);
    void traceCourbe(QPainter&, QList<QPoint>&, bool);

signals:

};

#endif // CBEZIER_H
