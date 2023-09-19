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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_3;
    QPushButton *pbuAbout;
    QGroupBox *grpIp;
    QHBoxLayout *horizontalLayout;
    QLabel *labServer;
    QLineEdit *edtAddress;
    QLabel *labPort;
    QLineEdit *edtPort;
    QSpacerItem *horizontalSpacer;
    QRadioButton *rbuTcp;
    QRadioButton *rbuUdp;
    QPushButton *pbuConnect;
    QGroupBox *grpMbap;
    QGridLayout *gridLayout_2;
    QLabel *labMbapTi;
    QLineEdit *edtMbapTi;
    QCheckBox *chkMbapTiAuto;
    QLabel *labMbapPi;
    QLineEdit *edtMbapPi;
    QLabel *labMbapLen;
    QLineEdit *edtMbapLen;
    QCheckBox *chkMbapLenAuto;
    QLabel *labMbapUi;
    QLineEdit *edtMbapUi;
    QGroupBox *grpPdu;
    QGridLayout *gridLayout;
    QLabel *labPduFunct;
    QComboBox *cbxPduFunct;
    QLabel *labPduAddr;
    QLineEdit *edtPduAddr;
    QRadioButton *rbuPduAddrDec;
    QRadioButton *rbuPduAddrHex;
    QLabel *labPduNumber;
    QLineEdit *edtPduNumber;
    QRadioButton *rbuPduNumberDec;
    QRadioButton *rbuPduNumberHex;
    QLabel *labPduValue;
    QLineEdit *edtPduValue;
    QRadioButton *rbuPduValueDec;
    QRadioButton *rbuPduValueHex;
    QLabel *labPduData;
    QLineEdit *edtPduData;
    QTextEdit *edtDialog;
    QPushButton *pbuSend;
    QSpacerItem *verticalSpacer;
    QPushButton *pbuClear;
    QPushButton *pbuQuit;
    QButtonGroup *grpRbuAddr;
    QButtonGroup *grpProto;
    QButtonGroup *grpRbuNumber;
    QButtonGroup *grpRbuValue;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(640, 480));
        Dialog->setMaximumSize(QSize(640, 480));
        gridLayout_3 = new QGridLayout(Dialog);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pbuAbout = new QPushButton(Dialog);
        pbuAbout->setObjectName(QStringLiteral("pbuAbout"));
        pbuAbout->setMinimumSize(QSize(60, 60));
        pbuAbout->setMaximumSize(QSize(60, 60));
        pbuAbout->setIconSize(QSize(60, 60));
        pbuAbout->setFlat(true);

        gridLayout_3->addWidget(pbuAbout, 0, 0, 1, 1);

        grpIp = new QGroupBox(Dialog);
        grpIp->setObjectName(QStringLiteral("grpIp"));
        horizontalLayout = new QHBoxLayout(grpIp);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labServer = new QLabel(grpIp);
        labServer->setObjectName(QStringLiteral("labServer"));

        horizontalLayout->addWidget(labServer);

        edtAddress = new QLineEdit(grpIp);
        edtAddress->setObjectName(QStringLiteral("edtAddress"));
        edtAddress->setMinimumSize(QSize(120, 0));
        edtAddress->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(edtAddress);

        labPort = new QLabel(grpIp);
        labPort->setObjectName(QStringLiteral("labPort"));

        horizontalLayout->addWidget(labPort);

        edtPort = new QLineEdit(grpIp);
        edtPort->setObjectName(QStringLiteral("edtPort"));
        edtPort->setMinimumSize(QSize(52, 0));
        edtPort->setMaximumSize(QSize(52, 16777215));
        edtPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(edtPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rbuTcp = new QRadioButton(grpIp);
        grpProto = new QButtonGroup(Dialog);
        grpProto->setObjectName(QStringLiteral("grpProto"));
        grpProto->addButton(rbuTcp);
        rbuTcp->setObjectName(QStringLiteral("rbuTcp"));
        rbuTcp->setChecked(true);

        horizontalLayout->addWidget(rbuTcp);

        rbuUdp = new QRadioButton(grpIp);
        grpProto->addButton(rbuUdp);
        rbuUdp->setObjectName(QStringLiteral("rbuUdp"));

        horizontalLayout->addWidget(rbuUdp);


        gridLayout_3->addWidget(grpIp, 0, 1, 1, 2);

        pbuConnect = new QPushButton(Dialog);
        pbuConnect->setObjectName(QStringLiteral("pbuConnect"));
        pbuConnect->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pbuConnect->setFont(font);
        pbuConnect->setAutoDefault(false);

        gridLayout_3->addWidget(pbuConnect, 0, 3, 1, 2);

        grpMbap = new QGroupBox(Dialog);
        grpMbap->setObjectName(QStringLiteral("grpMbap"));
        grpMbap->setMinimumSize(QSize(300, 156));
        grpMbap->setMaximumSize(QSize(300, 156));
        gridLayout_2 = new QGridLayout(grpMbap);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labMbapTi = new QLabel(grpMbap);
        labMbapTi->setObjectName(QStringLiteral("labMbapTi"));

        gridLayout_2->addWidget(labMbapTi, 0, 0, 1, 1);

        edtMbapTi = new QLineEdit(grpMbap);
        edtMbapTi->setObjectName(QStringLiteral("edtMbapTi"));
        edtMbapTi->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(edtMbapTi, 0, 1, 1, 1);

        chkMbapTiAuto = new QCheckBox(grpMbap);
        chkMbapTiAuto->setObjectName(QStringLiteral("chkMbapTiAuto"));
        chkMbapTiAuto->setChecked(true);

        gridLayout_2->addWidget(chkMbapTiAuto, 0, 2, 1, 1);

        labMbapPi = new QLabel(grpMbap);
        labMbapPi->setObjectName(QStringLiteral("labMbapPi"));

        gridLayout_2->addWidget(labMbapPi, 1, 0, 1, 1);

        edtMbapPi = new QLineEdit(grpMbap);
        edtMbapPi->setObjectName(QStringLiteral("edtMbapPi"));
        edtMbapPi->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(edtMbapPi, 1, 1, 1, 1);

        labMbapLen = new QLabel(grpMbap);
        labMbapLen->setObjectName(QStringLiteral("labMbapLen"));

        gridLayout_2->addWidget(labMbapLen, 2, 0, 1, 1);

        edtMbapLen = new QLineEdit(grpMbap);
        edtMbapLen->setObjectName(QStringLiteral("edtMbapLen"));
        edtMbapLen->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(edtMbapLen, 2, 1, 1, 1);

        chkMbapLenAuto = new QCheckBox(grpMbap);
        chkMbapLenAuto->setObjectName(QStringLiteral("chkMbapLenAuto"));
        chkMbapLenAuto->setChecked(true);

        gridLayout_2->addWidget(chkMbapLenAuto, 2, 2, 1, 1);

        labMbapUi = new QLabel(grpMbap);
        labMbapUi->setObjectName(QStringLiteral("labMbapUi"));

        gridLayout_2->addWidget(labMbapUi, 3, 0, 1, 1);

        edtMbapUi = new QLineEdit(grpMbap);
        edtMbapUi->setObjectName(QStringLiteral("edtMbapUi"));
        edtMbapUi->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(edtMbapUi, 3, 1, 1, 1);


        gridLayout_3->addWidget(grpMbap, 1, 0, 1, 2);

        grpPdu = new QGroupBox(Dialog);
        grpPdu->setObjectName(QStringLiteral("grpPdu"));
        grpPdu->setMinimumSize(QSize(310, 190));
        grpPdu->setMaximumSize(QSize(310, 190));
        gridLayout = new QGridLayout(grpPdu);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labPduFunct = new QLabel(grpPdu);
        labPduFunct->setObjectName(QStringLiteral("labPduFunct"));

        gridLayout->addWidget(labPduFunct, 0, 0, 1, 1);

        cbxPduFunct = new QComboBox(grpPdu);
        cbxPduFunct->setObjectName(QStringLiteral("cbxPduFunct"));
        cbxPduFunct->setMaxVisibleItems(6);

        gridLayout->addWidget(cbxPduFunct, 0, 1, 1, 3);

        labPduAddr = new QLabel(grpPdu);
        labPduAddr->setObjectName(QStringLiteral("labPduAddr"));

        gridLayout->addWidget(labPduAddr, 1, 0, 1, 1);

        edtPduAddr = new QLineEdit(grpPdu);
        edtPduAddr->setObjectName(QStringLiteral("edtPduAddr"));
        edtPduAddr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(edtPduAddr, 1, 1, 1, 1);

        rbuPduAddrDec = new QRadioButton(grpPdu);
        grpRbuAddr = new QButtonGroup(Dialog);
        grpRbuAddr->setObjectName(QStringLiteral("grpRbuAddr"));
        grpRbuAddr->addButton(rbuPduAddrDec);
        rbuPduAddrDec->setObjectName(QStringLiteral("rbuPduAddrDec"));
        rbuPduAddrDec->setChecked(true);

        gridLayout->addWidget(rbuPduAddrDec, 1, 2, 1, 1);

        rbuPduAddrHex = new QRadioButton(grpPdu);
        grpRbuAddr->addButton(rbuPduAddrHex);
        rbuPduAddrHex->setObjectName(QStringLiteral("rbuPduAddrHex"));

        gridLayout->addWidget(rbuPduAddrHex, 1, 3, 1, 1);

        labPduNumber = new QLabel(grpPdu);
        labPduNumber->setObjectName(QStringLiteral("labPduNumber"));

        gridLayout->addWidget(labPduNumber, 2, 0, 1, 1);

        edtPduNumber = new QLineEdit(grpPdu);
        edtPduNumber->setObjectName(QStringLiteral("edtPduNumber"));
        edtPduNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(edtPduNumber, 2, 1, 1, 1);

        rbuPduNumberDec = new QRadioButton(grpPdu);
        grpRbuNumber = new QButtonGroup(Dialog);
        grpRbuNumber->setObjectName(QStringLiteral("grpRbuNumber"));
        grpRbuNumber->addButton(rbuPduNumberDec);
        rbuPduNumberDec->setObjectName(QStringLiteral("rbuPduNumberDec"));
        rbuPduNumberDec->setChecked(true);

        gridLayout->addWidget(rbuPduNumberDec, 2, 2, 1, 1);

        rbuPduNumberHex = new QRadioButton(grpPdu);
        grpRbuNumber->addButton(rbuPduNumberHex);
        rbuPduNumberHex->setObjectName(QStringLiteral("rbuPduNumberHex"));

        gridLayout->addWidget(rbuPduNumberHex, 2, 3, 1, 1);

        labPduValue = new QLabel(grpPdu);
        labPduValue->setObjectName(QStringLiteral("labPduValue"));

        gridLayout->addWidget(labPduValue, 3, 0, 1, 1);

        edtPduValue = new QLineEdit(grpPdu);
        edtPduValue->setObjectName(QStringLiteral("edtPduValue"));
        edtPduValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(edtPduValue, 3, 1, 1, 1);

        rbuPduValueDec = new QRadioButton(grpPdu);
        grpRbuValue = new QButtonGroup(Dialog);
        grpRbuValue->setObjectName(QStringLiteral("grpRbuValue"));
        grpRbuValue->addButton(rbuPduValueDec);
        rbuPduValueDec->setObjectName(QStringLiteral("rbuPduValueDec"));

        gridLayout->addWidget(rbuPduValueDec, 3, 2, 1, 1);

        rbuPduValueHex = new QRadioButton(grpPdu);
        grpRbuValue->addButton(rbuPduValueHex);
        rbuPduValueHex->setObjectName(QStringLiteral("rbuPduValueHex"));
        rbuPduValueHex->setChecked(true);

        gridLayout->addWidget(rbuPduValueHex, 3, 3, 1, 1);

        labPduData = new QLabel(grpPdu);
        labPduData->setObjectName(QStringLiteral("labPduData"));

        gridLayout->addWidget(labPduData, 4, 0, 1, 1);

        edtPduData = new QLineEdit(grpPdu);
        edtPduData->setObjectName(QStringLiteral("edtPduData"));

        gridLayout->addWidget(edtPduData, 4, 1, 1, 3);


        gridLayout_3->addWidget(grpPdu, 1, 2, 1, 3);

        edtDialog = new QTextEdit(Dialog);
        edtDialog->setObjectName(QStringLiteral("edtDialog"));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier New"));
        font1.setPointSize(14);
        edtDialog->setFont(font1);
        edtDialog->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        edtDialog->setReadOnly(true);

        gridLayout_3->addWidget(edtDialog, 2, 0, 4, 4);

        pbuSend = new QPushButton(Dialog);
        pbuSend->setObjectName(QStringLiteral("pbuSend"));
        pbuSend->setFont(font);

        gridLayout_3->addWidget(pbuSend, 2, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 4, 1, 1);

        pbuClear = new QPushButton(Dialog);
        pbuClear->setObjectName(QStringLiteral("pbuClear"));
        pbuClear->setAutoDefault(false);

        gridLayout_3->addWidget(pbuClear, 4, 4, 1, 1);

        pbuQuit = new QPushButton(Dialog);
        pbuQuit->setObjectName(QStringLiteral("pbuQuit"));
        pbuQuit->setAutoDefault(false);

        gridLayout_3->addWidget(pbuQuit, 5, 4, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(pbuQuit, SIGNAL(clicked()), Dialog, SLOT(close()));
        QObject::connect(pbuClear, SIGNAL(clicked()), edtDialog, SLOT(clear()));

        cbxPduFunct->setCurrentIndex(2);
        pbuSend->setDefault(true);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
#ifndef QT_NO_TOOLTIP
        pbuAbout->setToolTip(QApplication::translate("Dialog", "About...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbuAbout->setText(QString());
        grpIp->setTitle(QApplication::translate("Dialog", "Internet Protocol", Q_NULLPTR));
        labServer->setText(QApplication::translate("Dialog", "Server :", Q_NULLPTR));
        edtAddress->setText(QApplication::translate("Dialog", "192.168.1.1", Q_NULLPTR));
        labPort->setText(QApplication::translate("Dialog", "Port :", Q_NULLPTR));
        edtPort->setText(QApplication::translate("Dialog", "502", Q_NULLPTR));
        rbuTcp->setText(QApplication::translate("Dialog", "TCP", Q_NULLPTR));
        rbuUdp->setText(QApplication::translate("Dialog", "UDP", Q_NULLPTR));
        pbuConnect->setText(QApplication::translate("Dialog", "Connect", Q_NULLPTR));
        grpMbap->setTitle(QApplication::translate("Dialog", "Modbus Application Protocol (MBAP)", Q_NULLPTR));
        labMbapTi->setText(QApplication::translate("Dialog", "Transaction Ident. (dec) :", Q_NULLPTR));
        edtMbapTi->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        chkMbapTiAuto->setText(QApplication::translate("Dialog", "Auto", Q_NULLPTR));
        labMbapPi->setText(QApplication::translate("Dialog", "Protocol Identifier (hex) :", Q_NULLPTR));
        edtMbapPi->setInputMask(QApplication::translate("Dialog", "HHHH", Q_NULLPTR));
        edtMbapPi->setText(QApplication::translate("Dialog", "0000", Q_NULLPTR));
        labMbapLen->setText(QApplication::translate("Dialog", "Length (dec) :", Q_NULLPTR));
        edtMbapLen->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        chkMbapLenAuto->setText(QApplication::translate("Dialog", "Auto", Q_NULLPTR));
        labMbapUi->setText(QApplication::translate("Dialog", "Unit Identifier (hex) :", Q_NULLPTR));
        edtMbapUi->setInputMask(QApplication::translate("Dialog", "HH", Q_NULLPTR));
        edtMbapUi->setText(QApplication::translate("Dialog", "FF", Q_NULLPTR));
        grpPdu->setTitle(QApplication::translate("Dialog", "Modbus Protocol Data Unit (PDU)", Q_NULLPTR));
        labPduFunct->setText(QApplication::translate("Dialog", "Function :", Q_NULLPTR));
        cbxPduFunct->clear();
        cbxPduFunct->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "1 - Read Coils", Q_NULLPTR)
         << QApplication::translate("Dialog", "2 - Read Discret Input", Q_NULLPTR)
         << QApplication::translate("Dialog", "3 - Read Holding Registers", Q_NULLPTR)
         << QApplication::translate("Dialog", "4 - Read Input Registers", Q_NULLPTR)
         << QApplication::translate("Dialog", "5 - Write Single Coil", Q_NULLPTR)
         << QApplication::translate("Dialog", "6 - Write Single Register", Q_NULLPTR)
         << QApplication::translate("Dialog", "15 - Write Multiple Coils", Q_NULLPTR)
         << QApplication::translate("Dialog", "16 - Write Multiple Registers", Q_NULLPTR)
        );
        labPduAddr->setText(QApplication::translate("Dialog", "Address :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        edtPduAddr->setToolTip(QApplication::translate("Dialog", "0 .. 9998 (270E)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        edtPduAddr->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        rbuPduAddrDec->setText(QApplication::translate("Dialog", "dec", Q_NULLPTR));
        rbuPduAddrHex->setText(QApplication::translate("Dialog", "hex", Q_NULLPTR));
        labPduNumber->setText(QApplication::translate("Dialog", "Number :", Q_NULLPTR));
        edtPduNumber->setText(QApplication::translate("Dialog", "1", Q_NULLPTR));
        rbuPduNumberDec->setText(QApplication::translate("Dialog", "dec", Q_NULLPTR));
        rbuPduNumberHex->setText(QApplication::translate("Dialog", "hex", Q_NULLPTR));
        labPduValue->setText(QApplication::translate("Dialog", "Value :", Q_NULLPTR));
        edtPduValue->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        rbuPduValueDec->setText(QApplication::translate("Dialog", "dec", Q_NULLPTR));
        rbuPduValueHex->setText(QApplication::translate("Dialog", "hex", Q_NULLPTR));
        labPduData->setText(QApplication::translate("Dialog", "Data (hex) :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        edtPduData->setToolTip(QApplication::translate("Dialog", "format HH HH HH...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbuSend->setText(QApplication::translate("Dialog", "Send", Q_NULLPTR));
        pbuClear->setText(QApplication::translate("Dialog", "Clear", Q_NULLPTR));
        pbuQuit->setText(QApplication::translate("Dialog", "Quit", Q_NULLPTR));
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
