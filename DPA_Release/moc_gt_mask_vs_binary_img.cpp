/****************************************************************************
** Meta object code from reading C++ file 'gt_mask_vs_binary_img.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DPA/gt_mask_vs_binary_img.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gt_mask_vs_binary_img.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GTMvsBimg_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GTMvsBimg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GTMvsBimg_t qt_meta_stringdata_GTMvsBimg = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GTMvsBimg"
QT_MOC_LITERAL(1, 10, 19), // "on_btn_exit_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "on_btn_next_clicked"
QT_MOC_LITERAL(4, 51, 19), // "on_btn_back_clicked"
QT_MOC_LITERAL(5, 71, 22), // "on_chkB_invert_clicked"
QT_MOC_LITERAL(6, 94, 7), // "checked"
QT_MOC_LITERAL(7, 102, 23) // "on_btn_save_csv_clicked"

    },
    "GTMvsBimg\0on_btn_exit_clicked\0\0"
    "on_btn_next_clicked\0on_btn_back_clicked\0"
    "on_chkB_invert_clicked\0checked\0"
    "on_btn_save_csv_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GTMvsBimg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

       0        // eod
};

void GTMvsBimg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GTMvsBimg *_t = static_cast<GTMvsBimg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_exit_clicked(); break;
        case 1: _t->on_btn_next_clicked(); break;
        case 2: _t->on_btn_back_clicked(); break;
        case 3: _t->on_chkB_invert_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_btn_save_csv_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject GTMvsBimg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GTMvsBimg.data,
      qt_meta_data_GTMvsBimg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GTMvsBimg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GTMvsBimg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GTMvsBimg.stringdata0))
        return static_cast<void*>(const_cast< GTMvsBimg*>(this));
    return QDialog::qt_metacast(_clname);
}

int GTMvsBimg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
