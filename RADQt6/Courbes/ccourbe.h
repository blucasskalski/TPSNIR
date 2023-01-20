#ifndef CCOURBE_H
#define CCOURBE_H
#define LARGEURVUE 1000
#define HAUTEURVUE 1000
#define LX(X) ((int)((double)LARGEURVUE / width() * (X)))
#define LY(Y) ((int)((double)HAUTEURVUE / height() * (Y)))

#include "cbezier.h"
#include "cbspline.h"
#include <QMouseEvent>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QPrinter>
#include <QPrintDialog>

class CBSpline;

class CBezier;

class CCourbe : public QWidget {
  Q_OBJECT
public:
  explicit CCourbe(QWidget *parent = nullptr);
  ~CCourbe();
  enum Mode { Construction, Modification };
  void changeTypeCourbe(bool, bool);
  QString typeCourbe();
  void imprime();

private:
  QList<QPoint> points;
  QList<QPoint>::iterator itPoint;
  Mode mode;
  QRect poignee(const QPoint &point);
  void dessine(QPainter &paint, bool final = false);
  bool isBezier;
  bool isFormGen;
  CBezier *spline;
signals:
  void posChange(QPoint, int);

protected:
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
public slots:
  void raz();
};

#endif // CCOURBE_H
