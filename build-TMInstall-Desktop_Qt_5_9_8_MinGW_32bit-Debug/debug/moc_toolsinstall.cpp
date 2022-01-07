/****************************************************************************
** Meta object code from reading C++ file 'toolsinstall.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TMInstall/toolsinstall.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolsinstall.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToolsInstall_t {
    QByteArrayData data[12];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolsInstall_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolsInstall_t qt_meta_stringdata_ToolsInstall = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ToolsInstall"
QT_MOC_LITERAL(1, 13, 10), // "print_test"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "createFileDialog1"
QT_MOC_LITERAL(4, 43, 17), // "createFileDialog2"
QT_MOC_LITERAL(5, 61, 11), // "confirmSlot"
QT_MOC_LITERAL(6, 73, 20), // "updateCheckStateMaya"
QT_MOC_LITERAL(7, 94, 7), // "checked"
QT_MOC_LITERAL(8, 102, 19), // "updateCheckStateMax"
QT_MOC_LITERAL(9, 122, 19), // "updateCheckStateHou"
QT_MOC_LITERAL(10, 142, 19), // "updateCheckStateMap"
QT_MOC_LITERAL(11, 162, 21) // "updateCheckStateUnmap"

    },
    "ToolsInstall\0print_test\0\0createFileDialog1\0"
    "createFileDialog2\0confirmSlot\0"
    "updateCheckStateMaya\0checked\0"
    "updateCheckStateMax\0updateCheckStateHou\0"
    "updateCheckStateMap\0updateCheckStateUnmap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolsInstall[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      11,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void ToolsInstall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolsInstall *_t = static_cast<ToolsInstall *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->print_test(); break;
        case 1: _t->createFileDialog1(); break;
        case 2: _t->createFileDialog2(); break;
        case 3: _t->confirmSlot(); break;
        case 4: _t->updateCheckStateMaya((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->updateCheckStateMax((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->updateCheckStateHou((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->updateCheckStateMap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->updateCheckStateUnmap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ToolsInstall::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ToolsInstall.data,
      qt_meta_data_ToolsInstall,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ToolsInstall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolsInstall::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolsInstall.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ToolsInstall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
