/****************************************************************************
** Meta object code from reading C++ file 'ccourbe.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ccourbe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccourbe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CCourbe_t {
    const uint offsetsAndSize[16];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CCourbe_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CCourbe_t qt_meta_stringdata_CCourbe = {
    {
QT_MOC_LITERAL(0, 7), // "CCourbe"
QT_MOC_LITERAL(8, 9), // "posChange"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 3), // "raz"
QT_MOC_LITERAL(23, 10), // "typeCourbe"
QT_MOC_LITERAL(34, 16), // "changeTypeCourbe"
QT_MOC_LITERAL(51, 6), // "bezier"
QT_MOC_LITERAL(58, 7) // "formGen"

    },
    "CCourbe\0posChange\0\0raz\0typeCourbe\0"
    "changeTypeCourbe\0bezier\0formGen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CCourbe[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   43,    2, 0x0a,    4 /* Public */,
       4,    0,   44,    2, 0x0a,    5 /* Public */,
       5,    2,   45,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    6,    7,

       0        // eod
};

void CCourbe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CCourbe *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->posChange((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->raz(); break;
        case 2: { QString _r = _t->typeCourbe();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->changeTypeCourbe((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CCourbe::*)(QPoint , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CCourbe::posChange)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CCourbe::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CCourbe.offsetsAndSize,
    qt_meta_data_CCourbe,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CCourbe_t
, QtPrivate::TypeAndForceComplete<CCourbe, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *CCourbe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CCourbe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CCourbe.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CCourbe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CCourbe::posChange(QPoint _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
