/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include "qammodbusmapviewer.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbuAbout;
    QVBoxLayout *verticalLayout;
    QPushButton *pbuLoad;
    QHBoxLayout *horizontalLayout;
    QLabel *labPort;
    QLineEdit *edtPort;
    QPushButton *pbuStart;
    QTextEdit *edtDialog;
    QamModbusMapViewer *mapView;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(827, 385);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pbuAbout = new QPushButton(Dialog);
        pbuAbout->setObjectName(QStringLiteral("pbuAbout"));
        pbuAbout->setMinimumSize(QSize(60, 60));
        pbuAbout->setMaximumSize(QSize(60, 60));
        pbuAbout->setIconSize(QSize(60, 60));
        pbuAbout->setFlat(true);

        gridLayout->addWidget(pbuAbout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbuLoad = new QPushButton(Dialog);
        pbuLoad->setObjectName(QStringLiteral("pbuLoad"));

        verticalLayout->addWidget(pbuLoad);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labPort = new QLabel(Dialog);
        labPort->setObjectName(QStringLiteral("labPort"));
        labPort->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(labPort);

        edtPort = new QLineEdit(Dialog);
        edtPort->setObjectName(QStringLiteral("edtPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edtPort->sizePolicy().hasHeightForWidth());
        edtPort->setSizePolicy(sizePolicy);
        edtPort->setMinimumSize(QSize(60, 0));
        edtPort->setMaximumSize(QSize(60, 16777215));
        edtPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(edtPort);


        verticalLayout->addLayout(horizontalLayout);

        pbuStart = new QPushButton(Dialog);
        pbuStart->setObjectName(QStringLiteral("pbuStart"));

        verticalLayout->addWidget(pbuStart);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        edtDialog = new QTextEdit(Dialog);
        edtDialog->setObjectName(QStringLiteral("edtDialog"));
        edtDialog->setMinimumSize(QSize(100, 100));
        edtDialog->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(edtDialog, 0, 2, 1, 1);

        mapView = new QamModbusMapViewer(Dialog);
        mapView->setObjectName(QStringLiteral("mapView"));

        gridLayout->addWidget(mapView, 1, 0, 1, 3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
#ifndef QT_NO_TOOLTIP
        pbuAbout->setToolTip(QApplication::translate("Dialog", "About...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbuAbout->setText(QString());
        pbuLoad->setText(QApplication::translate("Dialog", "Load conf.", Q_NULLPTR));
        labPort->setText(QApplication::translate("Dialog", "Port :", Q_NULLPTR));
        edtPort->setText(QApplication::translate("Dialog", "502", Q_NULLPTR));
        pbuStart->setText(QApplication::translate("Dialog", "Start", Q_NULLPTR));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
