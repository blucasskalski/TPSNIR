/********************************************************************************
** Form generated from reading UI file 'dlgsearch.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSEARCH_H
#define UI_DLGSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgSearch
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *cbxReplace;
    QComboBox *cbxSearch;
    QLabel *labReplace;
    QLabel *labSearch;
    QVBoxLayout *vboxLayout;
    QPushButton *pbuOk;
    QPushButton *pbuCancel;
    QSpacerItem *spacerItem;
    QGroupBox *grpDirection;
    QGridLayout *gridLayout1;
    QRadioButton *rbuBackward;
    QRadioButton *rbuForward;
    QGroupBox *grpOptions;
    QGridLayout *gridLayout2;
    QCheckBox *chkCaseSensitive;
    QCheckBox *chkEntireDocument;
    QCheckBox *chkWholeWords;
    QSpacerItem *spacerItem1;

    void setupUi(QDialog *DlgSearch)
    {
        if (DlgSearch->objectName().isEmpty())
            DlgSearch->setObjectName(QString::fromUtf8("DlgSearch"));
        DlgSearch->resize(400, 175);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgSearch->sizePolicy().hasHeightForWidth());
        DlgSearch->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(DlgSearch);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 190, 351, 33));
        gridLayout = new QGridLayout(DlgSearch);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(8, 8, 8, 8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbxReplace = new QComboBox(DlgSearch);
        cbxReplace->setObjectName(QString::fromUtf8("cbxReplace"));
        cbxReplace->setMinimumSize(QSize(180, 0));
        cbxReplace->setEditable(true);

        gridLayout->addWidget(cbxReplace, 1, 1, 1, 2);

        cbxSearch = new QComboBox(DlgSearch);
        cbxSearch->setObjectName(QString::fromUtf8("cbxSearch"));
        cbxSearch->setMinimumSize(QSize(180, 0));
        cbxSearch->setEditable(true);

        gridLayout->addWidget(cbxSearch, 0, 1, 1, 2);

        labReplace = new QLabel(DlgSearch);
        labReplace->setObjectName(QString::fromUtf8("labReplace"));
        labReplace->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(labReplace, 1, 0, 1, 1);

        labSearch = new QLabel(DlgSearch);
        labSearch->setObjectName(QString::fromUtf8("labSearch"));
        labSearch->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(labSearch, 0, 0, 1, 1);

        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        pbuOk = new QPushButton(DlgSearch);
        pbuOk->setObjectName(QString::fromUtf8("pbuOk"));
        pbuOk->setAutoDefault(true);

        vboxLayout->addWidget(pbuOk);

        pbuCancel = new QPushButton(DlgSearch);
        pbuCancel->setObjectName(QString::fromUtf8("pbuCancel"));

        vboxLayout->addWidget(pbuCancel);

        spacerItem = new QSpacerItem(20, 81, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        gridLayout->addLayout(vboxLayout, 0, 4, 3, 1);

        grpDirection = new QGroupBox(DlgSearch);
        grpDirection->setObjectName(QString::fromUtf8("grpDirection"));
        gridLayout1 = new QGridLayout(grpDirection);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
        gridLayout1->setContentsMargins(8, 8, 8, 8);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        rbuBackward = new QRadioButton(grpDirection);
        rbuBackward->setObjectName(QString::fromUtf8("rbuBackward"));

        gridLayout1->addWidget(rbuBackward, 1, 0, 1, 1);

        rbuForward = new QRadioButton(grpDirection);
        rbuForward->setObjectName(QString::fromUtf8("rbuForward"));
        rbuForward->setChecked(true);

        gridLayout1->addWidget(rbuForward, 0, 0, 1, 1);


        gridLayout->addWidget(grpDirection, 2, 2, 1, 1);

        grpOptions = new QGroupBox(DlgSearch);
        grpOptions->setObjectName(QString::fromUtf8("grpOptions"));
        gridLayout2 = new QGridLayout(grpOptions);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
        gridLayout2->setContentsMargins(8, 8, 8, 8);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        chkCaseSensitive = new QCheckBox(grpOptions);
        chkCaseSensitive->setObjectName(QString::fromUtf8("chkCaseSensitive"));

        gridLayout2->addWidget(chkCaseSensitive, 1, 0, 1, 1);

        chkEntireDocument = new QCheckBox(grpOptions);
        chkEntireDocument->setObjectName(QString::fromUtf8("chkEntireDocument"));

        gridLayout2->addWidget(chkEntireDocument, 2, 0, 1, 1);

        chkWholeWords = new QCheckBox(grpOptions);
        chkWholeWords->setObjectName(QString::fromUtf8("chkWholeWords"));

        gridLayout2->addWidget(chkWholeWords, 0, 0, 1, 1);


        gridLayout->addWidget(grpOptions, 2, 0, 1, 2);

        spacerItem1 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 0, 3, 1, 1);

#if QT_CONFIG(shortcut)
        labReplace->setBuddy(cbxReplace);
        labSearch->setBuddy(cbxSearch);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(pbuOk, pbuCancel);
        QWidget::setTabOrder(pbuCancel, cbxSearch);
        QWidget::setTabOrder(cbxSearch, cbxReplace);
        QWidget::setTabOrder(cbxReplace, chkWholeWords);
        QWidget::setTabOrder(chkWholeWords, chkCaseSensitive);
        QWidget::setTabOrder(chkCaseSensitive, chkEntireDocument);
        QWidget::setTabOrder(chkEntireDocument, rbuForward);
        QWidget::setTabOrder(rbuForward, rbuBackward);

        retranslateUi(DlgSearch);
        QObject::connect(pbuCancel, &QPushButton::clicked, DlgSearch, qOverload<>(&QDialog::reject));
        QObject::connect(pbuOk, &QPushButton::clicked, DlgSearch, qOverload<>(&QDialog::accept));
        QObject::connect(chkEntireDocument, &QCheckBox::clicked, grpDirection, &QGroupBox::setDisabled);

        pbuOk->setDefault(true);


        QMetaObject::connectSlotsByName(DlgSearch);
    } // setupUi

    void retranslateUi(QDialog *DlgSearch)
    {
        DlgSearch->setWindowTitle(QCoreApplication::translate("DlgSearch", "Rechercher...", nullptr));
        labReplace->setText(QCoreApplication::translate("DlgSearch", "Remplacer par :", nullptr));
        labSearch->setText(QCoreApplication::translate("DlgSearch", "&Texte :", nullptr));
        pbuOk->setText(QCoreApplication::translate("DlgSearch", "&Valider", nullptr));
        pbuCancel->setText(QCoreApplication::translate("DlgSearch", "&Annuler", nullptr));
        grpDirection->setTitle(QCoreApplication::translate("DlgSearch", "Direction", nullptr));
        rbuBackward->setText(QCoreApplication::translate("DlgSearch", "Vers l'arri\303\250re", nullptr));
        rbuForward->setText(QCoreApplication::translate("DlgSearch", "Vers l'avant", nullptr));
        grpOptions->setTitle(QCoreApplication::translate("DlgSearch", "Options", nullptr));
        chkCaseSensitive->setText(QCoreApplication::translate("DlgSearch", "Respecter la &Casse", nullptr));
        chkEntireDocument->setText(QCoreApplication::translate("DlgSearch", "&Tout le document", nullptr));
        chkWholeWords->setText(QCoreApplication::translate("DlgSearch", "&Mots entiers seulement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSearch: public Ui_DlgSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSEARCH_H
