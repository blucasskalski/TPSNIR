#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QMenuBar>
#include <QStatusBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    openAction = new QAction( QIcon(":/images/fileopen.png") ,tr("&Ouvrir..."), this);
    openAction->setShortcut( tr("Ctrl+O"));
    openAction->setStatusTip( tr("Ouverture d'un fichier"));
    connect(openAction, SIGNAL(triggered() ), this, SLOT(open() ) );

    saveAction = new QAction( QIcon(":/images/filesave.png"),tr("&Sauvegarder"), this );
    saveAction -> setShortcut(tr ("CTRL+S") );
    saveAction -> setStatusTip(tr ("Sauvegarde du document"));
    saveAction -> setObjectName("saveAction");

    quitAction = new QAction( tr("&Quitter"), this);
    quitAction-> setShortcut( tr("CTRL+Q") );
    quitAction-> setStatusTip(tr ("Quitter l'application") );
    connect(quitAction, SIGNAL(triggered()), this,SLOT(close() ) );

    QMetaObject::connectSlotsByName(this);

    fileMenu = QMainWindow::menuBar()->addMenu( tr("&Fichier") );
    fileMenu-> addAction(openAction);
    fileMenu-> addAction(saveAction);
    fileMenu-> addSeparator();
    fileMenu-> addAction(quitAction);

    fileToolBar = addToolBar( tr("fichier") );
    fileToolBar-> addAction(openAction);
    fileToolBar-> addAction(saveAction);

    setWindowTitle("MyEditor");
    QMainWindow::statusBar()->showMessage(tr("prêt"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open(){

    std::cout<<"open clicked !"<< std::endl;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir..."), QDir::homePath(),tr("Fichiers texte (*.txt);; Autres fichiers (*.*)") );
    if(fileName.isEmpty() ) return;

    QFile file( fileName );

    if(! file.open(QFile::ReadOnly | QFile::Text)){

        QMessageBox::critical(this, tr("Erreur") , tr("Impossible de lire le fichier %1 :\n%2").arg( fileName ).arg(file.errorString()), tr("Fermer"));
        return;

    }

    QTextStream in(&file);
    editor->setPlainText(in.readAll());
    QMainWindow::statusBar()-> showMessage(tr("Lecture ok !"), 2000);
}

void MainWindow::on_saveAction_triggered(){
    std::cout<<"save clicked !" << std::endl;
}

void MainWindow::search(){
    std::cout<< "search clicked !" << std::endl;
}
