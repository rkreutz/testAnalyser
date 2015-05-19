/****************************************************************************
** Meta object code from reading C++ file 'testanalyser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testanalyser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testanalyser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestAnalyser_t {
    QByteArrayData data[16];
    char stringdata[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestAnalyser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestAnalyser_t qt_meta_stringdata_TestAnalyser = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 10),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 10),
QT_MOC_LITERAL(5, 47, 10),
QT_MOC_LITERAL(6, 58, 10),
QT_MOC_LITERAL(7, 69, 10),
QT_MOC_LITERAL(8, 80, 11),
QT_MOC_LITERAL(9, 92, 8),
QT_MOC_LITERAL(10, 101, 9),
QT_MOC_LITERAL(11, 111, 13),
QT_MOC_LITERAL(12, 125, 12),
QT_MOC_LITERAL(13, 138, 14),
QT_MOC_LITERAL(14, 153, 9),
QT_MOC_LITERAL(15, 163, 5)
    },
    "TestAnalyser\0setDevice1\0\0setDevice2\0"
    "setDevice3\0setDevice4\0setDevice5\0"
    "showCamera\0closeCamera\0startRec\0"
    "showFrame\0selectRegions\0resetRegions\0"
    "analyseRegions\0loadImage\0TESTE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestAnalyser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,

       0        // eod
};

void TestAnalyser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestAnalyser *_t = static_cast<TestAnalyser *>(_o);
        switch (_id) {
        case 0: _t->setDevice1(); break;
        case 1: _t->setDevice2(); break;
        case 2: _t->setDevice3(); break;
        case 3: _t->setDevice4(); break;
        case 4: _t->setDevice5(); break;
        case 5: _t->showCamera(); break;
        case 6: _t->closeCamera(); break;
        case 7: _t->startRec(); break;
        case 8: _t->showFrame(); break;
        case 9: _t->selectRegions(); break;
        case 10: _t->resetRegions(); break;
        case 11: _t->analyseRegions(); break;
        case 12: _t->loadImage(); break;
        case 13: _t->TESTE(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestAnalyser::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestAnalyser.data,
      qt_meta_data_TestAnalyser,  qt_static_metacall, 0, 0}
};


const QMetaObject *TestAnalyser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestAnalyser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestAnalyser.stringdata))
        return static_cast<void*>(const_cast< TestAnalyser*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestAnalyser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
