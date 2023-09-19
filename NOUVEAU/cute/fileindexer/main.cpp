#include <QApplication>
#include "dlgfileindexer.h"
int main(int argc, char* argv[] )
{
    QApplication app(argc, argv ) ;
    dlgFileIndexer dlg ;
    dlg.setWindowTitle("Indexeur de fichiers") ;
    dlg.show() ;
    return app.exec() ;
}
