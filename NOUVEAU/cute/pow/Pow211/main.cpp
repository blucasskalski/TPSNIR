#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "pow211.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
    Pow211 pow211;
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("board", &pow211 ) ;
    engine.load(QUrl("../Pow211/main.qml"));
    return app.exec();
}
