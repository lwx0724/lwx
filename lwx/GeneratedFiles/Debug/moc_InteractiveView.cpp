/****************************************************************************
** Meta object code from reading C++ file 'InteractiveView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../InteractiveView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InteractiveView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InteractiveView_t {
    QByteArrayData data[8];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InteractiveView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InteractiveView_t qt_meta_stringdata_InteractiveView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "InteractiveView"
QT_MOC_LITERAL(1, 16, 6), // "zoomIn"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "zoomOut"
QT_MOC_LITERAL(4, 32, 4), // "zoom"
QT_MOC_LITERAL(5, 37, 11), // "scaleFactor"
QT_MOC_LITERAL(6, 49, 9), // "setGapNum"
QT_MOC_LITERAL(7, 59, 3) // "gap"

    },
    "InteractiveView\0zoomIn\0\0zoomOut\0zoom\0"
    "scaleFactor\0setGapNum\0gap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InteractiveView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Double,    7,

       0        // eod
};

void InteractiveView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InteractiveView *_t = static_cast<InteractiveView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->zoomIn(); break;
        case 1: _t->zoomOut(); break;
        case 2: _t->zoom((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->setGapNum((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject InteractiveView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_InteractiveView.data,
      qt_meta_data_InteractiveView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InteractiveView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InteractiveView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InteractiveView.stringdata0))
        return static_cast<void*>(const_cast< InteractiveView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int InteractiveView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE