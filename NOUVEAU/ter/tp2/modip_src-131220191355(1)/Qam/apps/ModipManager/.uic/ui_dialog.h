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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbuAbout;
    QTextEdit *edtDialog;
    QVBoxLayout *verticalLayout;
    QPushButton *pbuNew;
    QLabel *labHost;
    QLineEdit *edtHost;
    QHBoxLayout *horizontalLayout;
    QLabel *labPort;
    QLineEdit *edtPort;
    QPushButton *pbuConnect;
    QSpacerItem *verticalSpacer;
    QPushButton *pbuReset;
    QPushButton *pbuReadAll;
    QPushButton *pbuRead;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pbuQuit;
    QTabWidget *tabWidget;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(804, 551);
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

        edtDialog = new QTextEdit(Dialog);
        edtDialog->setObjectName(QStringLiteral("edtDialog"));
        edtDialog->setMinimumSize(QSize(0, 100));
        edtDialog->setMaximumSize(QSize(16777215, 100));
        edtDialog->setReadOnly(true);

        gridLayout->addWidget(edtDialog, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbuNew = new QPushButton(Dialog);
        pbuNew->setObjectName(QStringLiteral("pbuNew"));

        verticalLayout->addWidget(pbuNew);

        labHost = new QLabel(Dialog);
        labHost->setObjectName(QStringLiteral("labHost"));
        labHost->setMaximumSize(QSize(115, 16777215));

        verticalLayout->addWidget(labHost);

        edtHost = new QLineEdit(Dialog);
        edtHost->setObjectName(QStringLiteral("edtHost"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edtHost->sizePolicy().hasHeightForWidth());
        edtHost->setSizePolicy(sizePolicy);
        edtHost->setMinimumSize(QSize(115, 0));
        edtHost->setMaximumSize(QSize(115, 16777215));

        verticalLayout->addWidget(edtHost);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(-1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labPort = new QLabel(Dialog);
        labPort->setObjectName(QStringLiteral("labPort"));
        labPort->setMinimumSize(QSize(40, 0));
        labPort->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(labPort);

        edtPort = new QLineEdit(Dialog);
        edtPort->setObjectName(QStringLiteral("edtPort"));
        sizePolicy.setHeightForWidth(edtPort->sizePolicy().hasHeightForWidth());
        edtPort->setSizePolicy(sizePolicy);
        edtPort->setMinimumSize(QSize(65, 0));
        edtPort->setMaximumSize(QSize(65, 16777215));
        edtPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(edtPort);


        verticalLayout->addLayout(horizontalLayout);

        pbuConnect = new QPushButton(Dialog);
        pbuConnect->setObjectName(QStringLiteral("pbuConnect"));

        verticalLayout->addWidget(pbuConnect);

        verticalSpacer = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbuReset = new QPushButton(Dialog);
        pbuReset->setObjectName(QStringLiteral("pbuReset"));

        verticalLayout->addWidget(pbuReset);

        pbuReadAll = new QPushButton(Dialog);
        pbuReadAll->setObjectName(QStringLiteral("pbuReadAll"));

        verticalLayout->addWidget(pbuReadAll);

        pbuRead = new QPushButton(Dialog);
        pbuRead->setObjectName(QStringLiteral("pbuRead"));

        verticalLayout->addWidget(pbuRead);

        verticalSpacer_2 = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pbuQuit = new QPushButton(Dialog);
        pbuQuit->setObjectName(QStringLiteral("pbuQuit"));

        verticalLayout->addWidget(pbuQuit);


        gridLayout->addLayout(verticalLayout, 0, 2, 2, 1);

        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabsClosable(true);

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(Dialog);
        QObject::connect(pbuQuit, SIGNAL(clicked()), Dialog, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
#ifndef QT_NO_TOOLTIP
        pbuAbout->setToolTip(QApplication::translate("Dialog", "About...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbuAbout->setText(QString());
        pbuNew->setText(QApplication::translate("Dialog", "New...", Q_NULLPTR));
        labHost->setText(QApplication::translate("Dialog", "Host :", Q_NULLPTR));
        edtHost->setText(QString());
        labPort->setText(QApplication::translate("Dialog", "Port :", Q_NULLPTR));
        edtPort->setText(QApplication::translate("Dialog", "502", Q_NULLPTR));
        pbuConnect->setText(QApplication::translate("Dialog", "Connect", Q_NULLPTR));
        pbuReset->setText(QApplication::translate("Dialog", "Reset all", Q_NULLPTR));
        pbuReadAll->setText(QApplication::translate("Dialog", "Update all", Q_NULLPTR));
        pbuRead->setText(QApplication::translate("Dialog", "Update\n"
"selection", Q_NULLPTR));
        pbuQuit->setText(QApplication::translate("Dialog", "Quit", Q_NULLPTR));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
