#ifndef DLGFILEINDEXER_H
#define DLGFILEINDEXER_H

#include "ui_dlgfileindexer.h"
#include <QDir>
#include <QDialog>

class dlgFileIndexer : public QDialog, private Ui::dlgFileIndexer
{
    Q_OBJECT

public:
    dlgFileIndexer(QWidget* parent = nullptr);
    ~dlgFileIndexer();

public slots :
    void changeUnit(bool ) ;
//    void getDir() ;
    void search() ;
//    void save() ;
//    void openItem(int, int ) ;
    int tree(QDir& base );


private :

    Ui::dlgFileIndexer *ui;
    double totalMega ;
    QDir baseDir ;
    QString suffix ;
    void initTable() ;
};
#endif // DLGFILEINDEXER_H
