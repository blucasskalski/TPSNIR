/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DemoEditor-v3.1/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 7), // "newFile"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 8), // "openFile"
QT_MOC_LITERAL(29, 8), // "saveFile"
QT_MOC_LITERAL(38, 10), // "saveAsFile"
QT_MOC_LITERAL(49, 9), // "printFile"
QT_MOC_LITERAL(59, 19), // "documentWasModified"
QT_MOC_LITERAL(79, 20), // "clipboardDataChanged"
QT_MOC_LITERAL(100, 14), // "cursorPosition"
QT_MOC_LITERAL(115, 12), // "cursorAtLine"
QT_MOC_LITERAL(128, 6), // "search"
QT_MOC_LITERAL(135, 7), // "replace"
QT_MOC_LITERAL(143, 4), // "next"
QT_MOC_LITERAL(148, 8), // "previous"
QT_MOC_LITERAL(157, 4), // "help"
QT_MOC_LITERAL(162, 5), // "about"
QT_MOC_LITERAL(168, 18), // "setupEditorBkColor"
QT_MOC_LITERAL(187, 15) // "setupEditorFont"

    },
    "MainWindow\0newFile\0\0openFile\0saveFile\0"
    "saveAsFile\0printFile\0documentWasModified\0"
    "clipboardDataChanged\0cursorPosition\0"
    "cursorAtLine\0search\0replace\0next\0"
    "previous\0help\0about\0setupEditorBkColor\0"
    "setupEditorFont"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x0a,    1 /* Public */,
       3,    0,  117,    2, 0x0a,    2 /* Public */,
       4,    0,  118,    2, 0x0a,    3 /* Public */,
       5,    0,  119,    2, 0x0a,    4 /* Public */,
       6,    0,  120,    2, 0x0a,    5 /* Public */,
       7,    0,  121,    2, 0x0a,    6 /* Public */,
       8,    0,  122,    2, 0x0a,    7 /* Public */,
       9,    0,  123,    2, 0x0a,    8 /* Public */,
      10,    0,  124,    2, 0x0a,    9 /* Public */,
      11,    0,  125,    2, 0x0a,   10 /* Public */,
      12,    0,  126,    2, 0x0a,   11 /* Public */,
      13,    0,  127,    2, 0x0a,   12 /* Public */,
      14,    0,  128,    2, 0x0a,   13 /* Public */,
      15,    0,  129,    2, 0x0a,   14 /* Public */,
      16,    0,  130,    2, 0x0a,   15 /* Public */,
      17,    0,  131,    2, 0x08,   16 /* Private */,
      18,    0,  132,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->openFile(); break;
        case 2: { bool _r = _t->saveFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->saveAsFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->printFile(); break;
        case 5: _t->documentWasModified(); break;
        case 6: _t->clipboardDataChanged(); break;
        case 7: _t->cursorPosition(); break;
        case 8: _t->cursorAtLine(); break;
        case 9: _t->search(); break;
        case 10: _t->replace(); break;
        case 11: _t->next(); break;
        case 12: _t->previous(); break;
        case 13: _t->help(); break;
        case 14: _t->about(); break;
        case 15: _t->setupEditorBkColor(); break;
        case 16: _t->setupEditorFont(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
