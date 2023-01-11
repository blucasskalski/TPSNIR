/********************************************************************************
** Form generated from reading UI file 'cvue.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
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
    QVBoxLayout *verticalLayout;
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
            CVue->setObjectName("CVue");
        CVue->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CVue->sizePolicy().hasHeightForWidth());
        CVue->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CVue);
        gridLayout->setObjectName("gridLayout");
        labCourbe = new QLabel(CVue);
        labCourbe->setObjectName("labCourbe");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labCourbe->sizePolicy().hasHeightForWidth());
        labCourbe->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labCourbe, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        labPos = new QLabel(CVue);
        labPos->setObjectName("labPos");

        verticalLayout->addWidget(labPos);

        labPoints = new QLabel(CVue);
        labPoints->setObjectName("labPoints");

        verticalLayout->addWidget(labPoints);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        rbuBezier = new QRadioButton(CVue);
        rbuBezier->setObjectName("rbuBezier");
        rbuBezier->setChecked(true);

        verticalLayout->addWidget(rbuBezier);

        rbuBSpline = new QRadioButton(CVue);
        rbuBSpline->setObjectName("rbuBSpline");

        verticalLayout->addWidget(rbuBSpline);

        chkFormGen = new QCheckBox(CVue);
        chkFormGen->setObjectName("chkFormGen");

        verticalLayout->addWidget(chkFormGen);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pbuEffacer = new QPushButton(CVue);
        pbuEffacer->setObjectName("pbuEffacer");

        verticalLayout->addWidget(pbuEffacer);

        pbuImprimer = new QPushButton(CVue);
        pbuImprimer->setObjectName("pbuImprimer");

        verticalLayout->addWidget(pbuImprimer);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pbuQuitter = new QPushButton(CVue);
        pbuQuitter->setObjectName("pbuQuitter");

        verticalLayout->addWidget(pbuQuitter);


        gridLayout->addLayout(verticalLayout, 0, 1, 2, 1);

        frmCourbe = new QFrame(CVue);
        frmCourbe->setObjectName("frmCourbe");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frmCourbe->sizePolicy().hasHeightForWidth());
        frmCourbe->setSizePolicy(sizePolicy2);
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
        labPos->setText(QCoreApplication::translate("CVue", "0, 0", nullptr));
        labPoints->setText(QCoreApplication::translate("CVue", "0 points", nullptr));
        rbuBezier->setText(QCoreApplication::translate("CVue", "B\303\251zier", nullptr));
        rbuBSpline->setText(QCoreApplication::translate("CVue", "B-Spline", nullptr));
        chkFormGen->setText(QCoreApplication::translate("CVue", "F. G\303\251n\303\251rale", nullptr));
        pbuEffacer->setText(QCoreApplication::translate("CVue", "Effacer", nullptr));
        pbuImprimer->setText(QCoreApplication::translate("CVue", "Imprimer...", nullptr));
        pbuQuitter->setText(QCoreApplication::translate("CVue", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CVue: public Ui_CVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVUE_H
