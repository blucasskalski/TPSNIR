/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[18];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 11), // "sockReceive"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "frame"
QT_MOC_LITERAL(4, 26, 8), // "sockInfo"
QT_MOC_LITERAL(5, 35, 3), // "msg"
QT_MOC_LITERAL(6, 39, 17), // "on_rbuTcp_toggled"
QT_MOC_LITERAL(7, 57, 7), // "checked"
QT_MOC_LITERAL(8, 65, 21), // "on_pbuConnect_clicked"
QT_MOC_LITERAL(9, 87, 24), // "on_chkMbapTiAuto_toggled"
QT_MOC_LITERAL(10, 112, 25), // "on_chkMbapLenAuto_toggled"
QT_MOC_LITERAL(11, 138, 34), // "on_cbxPduFunct_currentIndexCh..."
QT_MOC_LITERAL(12, 173, 5), // "index"
QT_MOC_LITERAL(13, 179, 24), // "on_rbuPduAddrDec_toggled"
QT_MOC_LITERAL(14, 204, 26), // "on_rbuPduNumberDec_toggled"
QT_MOC_LITERAL(15, 231, 25), // "on_rbuPduValueDec_toggled"
QT_MOC_LITERAL(16, 257, 18), // "on_pbuSend_clicked"
QT_MOC_LITERAL(17, 276, 19) // "on_pbuAbout_clicked"

    },
    "Dialog\0sockReceive\0\0frame\0sockInfo\0"
    "msg\0on_rbuTcp_toggled\0checked\0"
    "on_pbuConnect_clicked\0on_chkMbapTiAuto_toggled\0"
    "on_chkMbapLenAuto_toggled\0"
    "on_cbxPduFunct_currentIndexChanged\0"
    "index\0on_rbuPduAddrDec_toggled\0"
    "on_rbuPduNumberDec_toggled\0"
    "on_rbuPduValueDec_toggled\0on_pbuSend_clicked\0"
    "on_pbuAbout_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       6,    1,   80,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      11,    1,   90,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sockReceive((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->sockInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_rbuTcp_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_pbuConnect_clicked(); break;
        case 4: _t->on_chkMbapTiAuto_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_chkMbapLenAuto_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_cbxPduFunct_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_rbuPduAddrDec_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_rbuPduNumberDec_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_rbuPduValueDec_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_pbuSend_clicked(); break;
        case 11: _t->on_pbuAbout_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
