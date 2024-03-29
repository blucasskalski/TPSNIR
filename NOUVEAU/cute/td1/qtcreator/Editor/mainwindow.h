#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenu* fileMenu;
    QAction* openAction;
    QAction* saveAction;
    QAction* quitAction;

    QMenu* editMenu;
    QAction* searchAction;

    QToolBar* fileToolBar;
    QToolBar* editToolBar;

private slots :

        void open();
        void on_saveAction_triggered();
        void search();


};
#endif // MAINWINDOW_H
