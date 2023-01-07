#ifndef CVUE_H
#define CVUE_H

#include <QWidget>
#include "ccourbe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CVue; }
QT_END_NAMESPACE

class CCourbe;

class CVue : public QWidget
{
    Q_OBJECT

public:
    CVue(QWidget *parent = nullptr);
    ~CVue();

private:
    Ui::CVue *ui;
    CCourbe* courbe;
protected:
    void resizeEvent(QResizeEvent* event) override;
private slots:
    void majInfo(QPoint, int);
    void changeTypeCourbe();
};
#endif // CVUE_H
