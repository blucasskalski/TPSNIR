#include "dlgfileindexer.h"
#include "ui_dlgfileindexer.h"
#include <QtGui>

dlgFileIndexer::dlgFileIndexer(QWidget *parent)
    : QDialog(parent), ui(new Ui::dlgFileIndexer)
{
    setupUi(this);
    totalMega = 0.0 ;

    pbuSave->setEnabled( false ) ;
    lcdSize->setSegmentStyle( QLCDNumber::Flat ) ;
    lcdSize->setDigitCount( 6 ) ;
    lcdFiles->setSegmentStyle( QLCDNumber::Flat ) ;
    edtDir->setText( QDir::homePath() ) ;
    initTable() ;
    connect( rbuMega, SIGNAL( toggled(bool) ), this, SLOT( changeUnit(bool) ) ) ;
//    connect( pbuDir, SIGNAL( clicked() ), this, SLOT( getDir() ) ) ;
    connect( pbuSearch,SIGNAL( clicked() ), this, SLOT( search() ) ) ;
//    connect( pbuSave, SIGNAL( clicked() ), this, SLOT( save() ) ) ;
//    connect( tblFiles, SIGNAL( cellDoubleClicked(int,int) ), this, SLOT( openItem(int,int) ) ) ;
}

void dlgFileIndexer::initTable()
{
tblFiles->clear() ;
tblFiles->setColumnCount( 3 ) ;
tblFiles->setColumnWidth (0, 300 ) ;
tblFiles->setColumnWidth (1, 80 ) ;
tblFiles->setColumnWidth (2, 300 ) ;
tblFiles->verticalHeader()->setVisible( false ) ;
tblFiles->setAlternatingRowColors( true ) ;
QStringList titles ;
titles << "Nom" << "Taille (ko)" << "Chemin relatif" ;
tblFiles->setHorizontalHeaderLabels( titles ) ;
tblFiles->setSelectionMode( QAbstractItemView::SingleSelection ) ;
tblFiles->setSelectionBehavior( QAbstractItemView::SelectRows ) ;
}

dlgFileIndexer::~dlgFileIndexer()
{
    delete ui;
}

void dlgFileIndexer::changeUnit(bool mega )
{
    lcdSize->display( mega ? totalMega : totalMega / 1024 ) ;
}

int dlgFileIndexer::tree(QDir& base )
{
    QList<QFileInfo>
    fList = base.entryInfoList() ;
    if ( !fList.isEmpty() ) {
        QList<QFileInfo>::Iterator it ;
        QFileInfo fInfo ;
        it = fList.begin() ;
        while ( it != fList.end() ) {
            fInfo = *it ;
            ++it ;
            if(fInfo.fileName() == ".") continue;
            if(fInfo.fileName() == "..") continue;
            if(fInfo.isSymLink()) continue;
            if(fInfo.isDir())
            {
                QDir dir = fInfo.absoluteFilePath();
                tree(dir);
                continue;
            }
            if(fInfo.suffix() == suffix)
            {
                lcdFiles->display(lcdFiles->intValue()+1);
                lcdFiles->repaint();
            }
        }
        return 0;
    }
    return -1;
}

void dlgFileIndexer::search()
{
    totalMega = 0.0 ;
    lcdSize->display( 0 ) ;
    tblFiles->setRowCount(0) ;
    lcdFiles->display(0) ;
    initTable() ;
    QApplication::setOverrideCursor( Qt::WaitCursor ) ;
    baseDir = edtDir->text() ;
    suffix = cbxExt->currentText() ;
    tree( baseDir ) ;
    QApplication::restoreOverrideCursor() ;
    pbuSave->setEnabled( true ) ;
}
