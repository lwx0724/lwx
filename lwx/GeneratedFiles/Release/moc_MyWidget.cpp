/****************************************************************************
** Meta object code from reading C++ file 'MyWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyWidget_t {
    QByteArrayData data[21];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyWidget_t qt_meta_stringdata_MyWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyWidget"
QT_MOC_LITERAL(1, 9, 12), // "textInfoSend"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "index"
QT_MOC_LITERAL(4, 29, 20), // "infoRecvChangeButton"
QT_MOC_LITERAL(5, 50, 4), // "int&"
QT_MOC_LITERAL(6, 55, 1), // "a"
QT_MOC_LITERAL(7, 57, 1), // "b"
QT_MOC_LITERAL(8, 59, 15), // "infoRecvParpare"
QT_MOC_LITERAL(9, 75, 13), // "emitTextInfo0"
QT_MOC_LITERAL(10, 89, 13), // "emitTextInfo1"
QT_MOC_LITERAL(11, 103, 13), // "emitTextInfo2"
QT_MOC_LITERAL(12, 117, 13), // "emitTextInfo3"
QT_MOC_LITERAL(13, 131, 13), // "emitTextInfo4"
QT_MOC_LITERAL(14, 145, 22), // "infoRecvBigButtonState"
QT_MOC_LITERAL(15, 168, 14), // "infoRecvGapNum"
QT_MOC_LITERAL(16, 183, 3), // "gap"
QT_MOC_LITERAL(17, 187, 19), // "infoRecvTextMessage"
QT_MOC_LITERAL(18, 207, 1), // "n"
QT_MOC_LITERAL(19, 209, 7), // "double*"
QT_MOC_LITERAL(20, 217, 5) // "value"

    },
    "MyWidget\0textInfoSend\0\0index\0"
    "infoRecvChangeButton\0int&\0a\0b\0"
    "infoRecvParpare\0emitTextInfo0\0"
    "emitTextInfo1\0emitTextInfo2\0emitTextInfo3\0"
    "emitTextInfo4\0infoRecvBigButtonState\0"
    "infoRecvGapNum\0gap\0infoRecvTextMessage\0"
    "n\0double*\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   72,    2, 0x0a /* Public */,
       8,    1,   77,    2, 0x0a /* Public */,
       9,    0,   80,    2, 0x0a /* Public */,
      10,    0,   81,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,
      13,    0,   84,    2, 0x0a /* Public */,
      14,    1,   85,    2, 0x0a /* Public */,
      15,    1,   88,    2, 0x0a /* Public */,
      17,    2,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 19,   18,   20,

       0        // eod
};

void MyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyWidget *_t = static_cast<MyWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textInfoSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->infoRecvChangeButton((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->infoRecvParpare((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->emitTextInfo0(); break;
        case 4: _t->emitTextInfo1(); break;
        case 5: _t->emitTextInfo2(); break;
        case 6: _t->emitTextInfo3(); break;
        case 7: _t->emitTextInfo4(); break;
        case 8: _t->infoRecvBigButtonState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->infoRecvGapNum((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->infoRecvTextMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyWidget::textInfoSend)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget.data,
      qt_meta_data_MyWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget.stringdata0))
        return static_cast<void*>(const_cast< MyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MyWidget::textInfoSend(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
