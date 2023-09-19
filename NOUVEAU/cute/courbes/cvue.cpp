#include "cvue.h"
#include "ui_cvue.h"
#include "ccourbe.h"

CVue::CVue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CVue)
{
    ui->setupUi(this);
    courbe = new CCourbe(ui->frmCourbe);
    ui->labPoints->setText("0 point") ;
    ui->labPos->setText("0 , 0") ;
    ui->labCourbe->setText(courbe->typeCourbe());
    connect( courbe, SIGNAL(posChange(QPoint,int)), this, SLOT( majInfo(QPoint,int) ) ) ;
    connect( ui->pbuEffacer, SIGNAL(clicked()), courbe, SLOT(raz()) ) ;
    connect( ui->rbuBezier, SIGNAL(toggled(bool)), this, SLOT(changeTypeCourbe() )) ;
    connect( ui->chkFormGen, SIGNAL(toggled(bool)), this, SLOT(changeTypeCourbe() )) ;
}

CVue::~CVue()
{
    delete ui;
}

void CVue::majInfo(QPoint point, int nbPoints )
{
    QString s ;
    s = QString("%1 , %2").arg( point.x() ).arg( point.y() ) ;
    ui->labPos->setText( s ) ;
    s = QString("%1 point").arg( nbPoints ) ;
    if ( nbPoints ) s += "s" ;
    ui->labPoints->setText( s ) ;
}

void CVue::resizeEvent(QResizeEvent *event)
{
    courbe->resize(ui->frmCourbe->width(), ui->frmCourbe->height());
}

void CVue::changeTypeCourbe()
{
    courbe->changeTypeCourbe(ui->rbuBezier->isChecked(), ui->chkFormGen->isChecked());
    ui->labCourbe->setText(courbe->typeCourbe());
}
