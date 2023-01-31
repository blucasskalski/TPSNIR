#ifndef CBSPLINE_H
#define CBSPLINE_H

#include "cbezier.h"

class CBSpline : public CBezier {
  Q_OBJECT

public:
  explicit CBSpline(QObject *parent = nullptr);
  virtual void casParticulier(QPainter &paint, QList<QPoint> &pts) override;
  virtual void formuleGenerale(QPainter &paint, QList<QPoint> &pts) override;
  double bsplineBasis(int i, int k, double t);
  protected:
    int resolution;
  };

#endif // CBSPLINE_H
