#ifndef CCOURBE_H
#define CCOURBE_H
#define LARGEURVUE 1000
#define HAUTEURVUE 1000
#define LX(X) ( (int)( (double)LARGEURVUE / width() * (X) ) )
#define LY(Y) ( (int)( (double)HAUTEURVUE / height() * (Y) ) )
#include <QWidget>
#include "cbezier.h"

class CBezier ;

class CCourbe : public QWidget
{
    Q_OBJECT
public:
    explicit CCourbe(QWidget *parent = nullptr);
    ~CCourbe();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    enum Mode { Construction, Modification};
    void paintEvent(QPaintEvent* event);
    void dessine(QPainter& paint, bool final = false ) ;


private:
    Mode mode;
    bool isBezier;
    bool isFormGen;
    CBezier* spline;

signals:
    void posChange(QPoint, int);

private:
    QList<QPoint> points;
    QList<QPoint>::iterator itPoint;
    QRect poignee(const QPoint& point);

public slots:
    void raz();
    QString typeCourbe();
    void changeTypeCourbe(bool bezier, bool formGen);


};

#endif // CCOURBE_H
