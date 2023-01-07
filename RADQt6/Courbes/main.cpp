#include "cvue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CVue w;
    w.setWindowTitle("Bézier & B-Spline");
    w.show();
    return a.exec();
}
