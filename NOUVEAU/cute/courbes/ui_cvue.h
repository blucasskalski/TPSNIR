/********************************************************************************
** Form generated from reading UI file 'cvue.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CVUE_H
#define UI_CVUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CVue
{
public:
    QGridLayout *gridLayout;
    QLabel *labCourbe;
    QVBoxLayout *verticalLayout_3;
    QLabel *labPos;
    QLabel *labPoints;
    QSpacerItem *verticalSpacer;
    QRadioButton *rbuBezier;
    QRadioButton *rbuBSpline;
    QCheckBox *chkFormGen;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pbuEffacer;
    QPushButton *pbuImprimer;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pbuQuitter;
    QFrame *frmCourbe;

    void setupUi(QWidget *CVue)
    {
        if (CVue->objectName().isEmpty())
            CVue->setObjectName(QString::fromUtf8("CVue"));
        CVue->resize(573, 441);
        gridLayout = new QGridLayout(CVue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labCourbe = new QLabel(CVue);
        labCourbe->setObjectName(QString::fromUtf8("labCourbe"));

        gridLayout->addWidget(labCourbe, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labPos = new QLabel(CVue);
        labPos->setObjectName(QString::fromUtf8("labPos"));

        verticalLayout_3->addWidget(labPos);

        labPoints = new QLabel(CVue);
        labPoints->setObjectName(QString::fromUtf8("labPoints"));

        verticalLayout_3->addWidget(labPoints);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        rbuBezier = new QRadioButton(CVue);
        rbuBezier->setObjectName(QString::fromUtf8("rbuBezier"));
        rbuBezier->setChecked(true);

        verticalLayout_3->addWidget(rbuBezier);

        rbuBSpline = new QRadioButton(CVue);
        rbuBSpline->setObjectName(QString::fromUtf8("rbuBSpline"));

        verticalLayout_3->addWidget(rbuBSpline);

        chkFormGen = new QCheckBox(CVue);
        chkFormGen->setObjectName(QString::fromUtf8("chkFormGen"));

        verticalLayout_3->addWidget(chkFormGen);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        pbuEffacer = new QPushButton(CVue);
        pbuEffacer->setObjectName(QString::fromUtf8("pbuEffacer"));

        verticalLayout_3->addWidget(pbuEffacer);

        pbuImprimer = new QPushButton(CVue);
        pbuImprimer->setObjectName(QString::fromUtf8("pbuImprimer"));

        verticalLayout_3->addWidget(pbuImprimer);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        pbuQuitter = new QPushButton(CVue);
        pbuQuitter->setObjectName(QString::fromUtf8("pbuQuitter"));

        verticalLayout_3->addWidget(pbuQuitter);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 2, 1);

        frmCourbe = new QFrame(CVue);
        frmCourbe->setObjectName(QString::fromUtf8("frmCourbe"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmCourbe->sizePolicy().hasHeightForWidth());
        frmCourbe->setSizePolicy(sizePolicy);
        frmCourbe->setMinimumSize(QSize(470, 470));
        frmCourbe->setFrameShape(QFrame::StyledPanel);
        frmCourbe->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frmCourbe, 1, 0, 1, 1);


        retranslateUi(CVue);
        QObject::connect(pbuQuitter, &QPushButton::clicked, CVue, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(CVue);
    } // setupUi

    void retranslateUi(QWidget *CVue)
    {
        CVue->setWindowTitle(QCoreApplication::translate("CVue", "CVue", nullptr));
        labCourbe->setText(QCoreApplication::translate("CVue", "TextLabel", nullptr));
        labPos->setText(QCoreApplication::translate("CVue", "TextLabel", nullptr));
        labPoints->setText(QCoreApplication::translate("CVue", "TextLabel", nullptr));
        rbuBezier->setText(QCoreApplication::translate("CVue", "&B\303\251zier", nullptr));
        rbuBSpline->setText(QCoreApplication::translate("CVue", "B-&Spline", nullptr));
        chkFormGen->setText(QCoreApplication::translate("CVue", "Formule &G\303\251n\303\251rale", nullptr));
        pbuEffacer->setText(QCoreApplication::translate("CVue", "&Effacer", nullptr));
        pbuImprimer->setText(QCoreApplication::translate("CVue", "&Imprimer", nullptr));
        pbuQuitter->setText(QCoreApplication::translate("CVue", "&Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CVue: public Ui_CVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVUE_H
