// main.cpp
#include <QApplication>
#include <QQuickView>
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QQuickView *view = new QQuickView();
    view->setSource(QUrl::fromLocalFile("hello.qml"));
    view->show();
    return app.exec();
}