/****************************************************************************
** Meta object code from reading C++ file 'tutorialCartoon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tutorialCartoon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tutorialCartoon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tutorialCartoon_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tutorialCartoon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tutorialCartoon_t qt_meta_stringdata_tutorialCartoon = {
    {
QT_MOC_LITERAL(0, 0, 15), // "tutorialCartoon"
QT_MOC_LITERAL(1, 16, 15), // "infoRecvCartoon"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "int&"
QT_MOC_LITERAL(4, 38, 5) // "index"

    },
    "tutorialCartoon\0infoRecvCartoon\0\0int&\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tutorialCartoon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void tutorialCartoon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tutorialCartoon *_t = static_cast<tutorialCartoon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->infoRecvCartoon((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject tutorialCartoon::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_tutorialCartoon.data,
      qt_meta_data_tutorialCartoon,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tutorialCartoon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tutorialCartoon::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tutorialCartoon.stringdata0))
        return static_cast<void*>(const_cast< tutorialCartoon*>(this));
    return QLabel::qt_metacast(_clname);
}

int tutorialCartoon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
