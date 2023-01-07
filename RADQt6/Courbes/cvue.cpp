#include "cvue.h"
#include "ui_cvue.h"

CVue::CVue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CVue)
{
    ui->setupUi(this);

    //courbe->setParent(ui->frmCourbe);
    courbe = new CCourbe(ui->frmCourbe);
    connect(courbe, &CCourbe::posChange, this, &CVue::majInfo);
    connect(ui->pbuEffacer, &QPushButton::clicked, courbe, &CCourbe::raz);
    connect(ui->rbuBezier, SIGNAL(clicked()), this, SLOT(changeTypeCourbe()));
    connect(ui->rbuBSpline, SIGNAL(clicked()), this, SLOT(changeTypeCourbe()));
    connect(ui->chkFormGen, SIGNAL(clicked()), this, SLOT(changeTypeCourbe()));
    ui->rbuBezier->setChecked(true);
    ui->rbuBSpline->setChecked(false);
    ui->labCourbe->setText(courbe->typeCourbe());
}

void CVue::resizeEvent(QResizeEvent* event){
    courbe->resize(ui->frmCourbe->size());
}

void CVue::majInfo(QPoint point, int nbPoints ){
    QString s ;
    s = QString("%1 , %2").arg( point.x() ).arg( point.y() ) ;
    ui->labPos->setText( s ) ;
    s = QString("%1 point").arg( nbPoints ) ;
    if ( nbPoints ) s += "s" ;
    ui->labPoints->setText( s ) ;
}

void CVue::changeTypeCourbe(){
    courbe->changeTypeCourbe(ui->rbuBezier->isChecked(), ui->chkFormGen->isChecked());
    ui->labCourbe->setText(courbe->typeCourbe());
}

CVue::~CVue()
{
    delete ui;
}
