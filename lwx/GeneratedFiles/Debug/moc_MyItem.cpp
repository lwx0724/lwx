/****************************************************************************
** Meta object code from reading C++ file 'MyItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyItem_t {
    QByteArrayData data[22];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyItem_t qt_meta_stringdata_MyItem = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyItem"
QT_MOC_LITERAL(1, 7, 10), // "changeInfo"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "int&"
QT_MOC_LITERAL(4, 24, 1), // "a"
QT_MOC_LITERAL(5, 26, 1), // "b"
QT_MOC_LITERAL(6, 28, 13), // "changeCartoon"
QT_MOC_LITERAL(7, 42, 5), // "index"
QT_MOC_LITERAL(8, 48, 20), // "showCurrentBigButton"
QT_MOC_LITERAL(9, 69, 14), // "changViewRuler"
QT_MOC_LITERAL(10, 84, 3), // "gap"
QT_MOC_LITERAL(11, 88, 14), // "changeTextHint"
QT_MOC_LITERAL(12, 103, 1), // "n"
QT_MOC_LITERAL(13, 105, 7), // "double*"
QT_MOC_LITERAL(14, 113, 5), // "value"
QT_MOC_LITERAL(15, 119, 12), // "infoRecvMove"
QT_MOC_LITERAL(16, 132, 12), // "infoRecvDraw"
QT_MOC_LITERAL(17, 145, 16), // "infoRecvClearAll"
QT_MOC_LITERAL(18, 162, 14), // "infoRecvUpdata"
QT_MOC_LITERAL(19, 177, 13), // "infoRecvClear"
QT_MOC_LITERAL(20, 191, 14), // "infoRecvClear2"
QT_MOC_LITERAL(21, 206, 12) // "infoRecvText"

    },
    "MyItem\0changeInfo\0\0int&\0a\0b\0changeCartoon\0"
    "index\0showCurrentBigButton\0changViewRuler\0"
    "gap\0changeTextHint\0n\0double*\0value\0"
    "infoRecvMove\0infoRecvDraw\0infoRecvClearAll\0"
    "infoRecvUpdata\0infoRecvClear\0"
    "infoRecvClear2\0infoRecvText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       6,    1,   79,    2, 0x06 /* Public */,
       8,    1,   82,    2, 0x06 /* Public */,
       9,    1,   85,    2, 0x06 /* Public */,
      11,    2,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   93,    2, 0x0a /* Public */,
      16,    0,   94,    2, 0x0a /* Public */,
      17,    0,   95,    2, 0x0a /* Public */,
      18,    1,   96,    2, 0x0a /* Public */,
      19,    1,   99,    2, 0x0a /* Public */,
      20,    1,  102,    2, 0x0a /* Public */,
      21,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void MyItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyItem *_t = static_cast<MyItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeCartoon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->showCurrentBigButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changViewRuler((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->changeTextHint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2]))); break;
        case 5: _t->infoRecvMove(); break;
        case 6: _t->infoRecvDraw(); break;
        case 7: _t->infoRecvClearAll(); break;
        case 8: _t->infoRecvUpdata((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->infoRecvClear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->infoRecvClear2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->infoRecvText((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyItem::*_t)(int & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyItem::changeInfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyItem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyItem::changeCartoon)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyItem::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyItem::showCurrentBigButton)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyItem::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyItem::changViewRuler)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyItem::*_t)(int , double * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyItem::changeTextHint)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MyItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyItem.data,
      qt_meta_data_MyItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyItem.stringdata0))
        return static_cast<void*>(const_cast< MyItem*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< MyItem*>(this));
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< MyItem*>(this));
    return QObject::qt_metacast(_clname);
}

int MyItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MyItem::changeInfo(int & _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyItem::changeCartoon(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyItem::showCurrentBigButton(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyItem::changViewRuler(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyItem::changeTextHint(int _t1, double * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
