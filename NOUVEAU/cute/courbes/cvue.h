#ifndef CVUE_H
#define CVUE_H

#include <QWidget>
#include "ccourbe.h"
class CCourbe;

QT_BEGIN_NAMESPACE
namespace Ui { class CVue; }
QT_END_NAMESPACE

class CVue : public QWidget
{
    Q_OBJECT
    CCourbe* courbe;

public:
    CVue(QWidget *parent = nullptr);
    ~CVue();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::CVue *ui;

private slots:
    void majInfo(QPoint, int);
    void changeTypeCourbe();

};
#endif // CVUE_H
