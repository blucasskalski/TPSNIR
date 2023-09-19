/********************************************************************************
** Form generated from reading UI file 'dlgfileindexer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGFILEINDEXER_H
#define UI_DLGFILEINDEXER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgFileIndexer
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labDir;
    QLineEdit *edtDir;
    QPushButton *pbuDir;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labExt;
    QComboBox *cbxExt;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbuSearch;
    QTableWidget *tblFiles;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *labFiles;
    QLCDNumber *lcdFiles;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdSize;
    QRadioButton *rbuMega;
    QRadioButton *rbugiga;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbuSave;
    QPushButton *pbuQuit;

    void setupUi(QDialog *dlgFileIndexer)
    {
        if (dlgFileIndexer->objectName().isEmpty())
            dlgFileIndexer->setObjectName(QString::fromUtf8("dlgFileIndexer"));
        dlgFileIndexer->resize(572, 492);
        gridLayout = new QGridLayout(dlgFileIndexer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labDir = new QLabel(dlgFileIndexer);
        labDir->setObjectName(QString::fromUtf8("labDir"));

        horizontalLayout->addWidget(labDir);

        edtDir = new QLineEdit(dlgFileIndexer);
        edtDir->setObjectName(QString::fromUtf8("edtDir"));

        horizontalLayout->addWidget(edtDir);

        pbuDir = new QPushButton(dlgFileIndexer);
        pbuDir->setObjectName(QString::fromUtf8("pbuDir"));
        pbuDir->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(pbuDir);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labExt = new QLabel(dlgFileIndexer);
        labExt->setObjectName(QString::fromUtf8("labExt"));

        horizontalLayout_2->addWidget(labExt);

        cbxExt = new QComboBox(dlgFileIndexer);
        cbxExt->addItem(QString());
        cbxExt->addItem(QString());
        cbxExt->addItem(QString());
        cbxExt->setObjectName(QString::fromUtf8("cbxExt"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbxExt->sizePolicy().hasHeightForWidth());
        cbxExt->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(cbxExt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pbuSearch = new QPushButton(dlgFileIndexer);
        pbuSearch->setObjectName(QString::fromUtf8("pbuSearch"));

        horizontalLayout_2->addWidget(pbuSearch);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        tblFiles = new QTableWidget(dlgFileIndexer);
        tblFiles->setObjectName(QString::fromUtf8("tblFiles"));
        tblFiles->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblFiles->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(tblFiles, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labFiles = new QLabel(dlgFileIndexer);
        labFiles->setObjectName(QString::fromUtf8("labFiles"));

        verticalLayout->addWidget(labFiles);

        lcdFiles = new QLCDNumber(dlgFileIndexer);
        lcdFiles->setObjectName(QString::fromUtf8("lcdFiles"));

        verticalLayout->addWidget(lcdFiles);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox = new QGroupBox(dlgFileIndexer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lcdSize = new QLCDNumber(groupBox);
        lcdSize->setObjectName(QString::fromUtf8("lcdSize"));

        gridLayout_2->addWidget(lcdSize, 0, 0, 1, 1);

        rbuMega = new QRadioButton(groupBox);
        rbuMega->setObjectName(QString::fromUtf8("rbuMega"));

        gridLayout_2->addWidget(rbuMega, 0, 1, 1, 1);

        rbugiga = new QRadioButton(groupBox);
        rbugiga->setObjectName(QString::fromUtf8("rbugiga"));

        gridLayout_2->addWidget(rbugiga, 0, 2, 1, 1);


        horizontalLayout_5->addWidget(groupBox);


        horizontalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pbuSave = new QPushButton(dlgFileIndexer);
        pbuSave->setObjectName(QString::fromUtf8("pbuSave"));

        verticalLayout_2->addWidget(pbuSave);

        pbuQuit = new QPushButton(dlgFileIndexer);
        pbuQuit->setObjectName(QString::fromUtf8("pbuQuit"));

        verticalLayout_2->addWidget(pbuQuit);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

#if QT_CONFIG(shortcut)
        labDir->setBuddy(edtDir);
        labExt->setBuddy(cbxExt);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(pbuSave, pbuQuit);
        QWidget::setTabOrder(pbuQuit, edtDir);
        QWidget::setTabOrder(edtDir, pbuDir);
        QWidget::setTabOrder(pbuDir, cbxExt);
        QWidget::setTabOrder(cbxExt, pbuSearch);
        QWidget::setTabOrder(pbuSearch, rbuMega);
        QWidget::setTabOrder(rbuMega, rbugiga);
        QWidget::setTabOrder(rbugiga, tblFiles);

        retranslateUi(dlgFileIndexer);
        QObject::connect(pbuSearch, &QPushButton::clicked, tblFiles, qOverload<>(&QTableWidget::clear));
        QObject::connect(pbuQuit, &QPushButton::clicked, dlgFileIndexer, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(dlgFileIndexer);
    } // setupUi

    void retranslateUi(QDialog *dlgFileIndexer)
    {
        dlgFileIndexer->setWindowTitle(QCoreApplication::translate("dlgFileIndexer", "Dialog", nullptr));
        labDir->setText(QCoreApplication::translate("dlgFileIndexer", "&Racine :", nullptr));
        pbuDir->setText(QCoreApplication::translate("dlgFileIndexer", "...", nullptr));
        labExt->setText(QCoreApplication::translate("dlgFileIndexer", "&Extension :", nullptr));
        cbxExt->setItemText(0, QCoreApplication::translate("dlgFileIndexer", "mp3", nullptr));
        cbxExt->setItemText(1, QCoreApplication::translate("dlgFileIndexer", "mp4", nullptr));
        cbxExt->setItemText(2, QCoreApplication::translate("dlgFileIndexer", "avi", nullptr));

        pbuSearch->setText(QCoreApplication::translate("dlgFileIndexer", "Chercher", nullptr));
        labFiles->setText(QCoreApplication::translate("dlgFileIndexer", "Fichiers :", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dlgFileIndexer", "taille totale", nullptr));
        rbuMega->setText(QCoreApplication::translate("dlgFileIndexer", "&Mo", nullptr));
        rbugiga->setText(QCoreApplication::translate("dlgFileIndexer", "&Go", nullptr));
        pbuSave->setText(QCoreApplication::translate("dlgFileIndexer", "&Sauvegarder", nullptr));
        pbuQuit->setText(QCoreApplication::translate("dlgFileIndexer", "&Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlgFileIndexer: public Ui_dlgFileIndexer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGFILEINDEXER_H
