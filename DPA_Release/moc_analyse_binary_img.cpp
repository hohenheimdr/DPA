/****************************************************************************
** Meta object code from reading C++ file 'analyse_binary_img.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DPA/analyse_binary_img.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analyse_binary_img.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Analyse_Binary_Img_t {
    QByteArrayData data[12];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analyse_Binary_Img_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analyse_Binary_Img_t qt_meta_stringdata_Analyse_Binary_Img = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Analyse_Binary_Img"
QT_MOC_LITERAL(1, 19, 24), // "on_btn_OpenImage_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 40), // "on_comboBox_img_list_currentI..."
QT_MOC_LITERAL(4, 86, 5), // "index"
QT_MOC_LITERAL(5, 92, 19), // "on_btn_next_clicked"
QT_MOC_LITERAL(6, 112, 19), // "on_btn_back_clicked"
QT_MOC_LITERAL(7, 132, 25), // "on_btn_ok_cancel_accepted"
QT_MOC_LITERAL(8, 158, 23), // "on_rdbtn_single_clicked"
QT_MOC_LITERAL(9, 182, 22), // "on_rdbtn_batch_clicked"
QT_MOC_LITERAL(10, 205, 33), // "on_chkB_BlackPix_Coverage_tog..."
QT_MOC_LITERAL(11, 239, 7) // "checked"

    },
    "Analyse_Binary_Img\0on_btn_OpenImage_clicked\0"
    "\0on_comboBox_img_list_currentIndexChanged\0"
    "index\0on_btn_next_clicked\0on_btn_back_clicked\0"
    "on_btn_ok_cancel_accepted\0"
    "on_rdbtn_single_clicked\0on_rdbtn_batch_clicked\0"
    "on_chkB_BlackPix_Coverage_toggled\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analyse_Binary_Img[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void Analyse_Binary_Img::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Analyse_Binary_Img *_t = static_cast<Analyse_Binary_Img *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_OpenImage_clicked(); break;
        case 1: _t->on_comboBox_img_list_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btn_next_clicked(); break;
        case 3: _t->on_btn_back_clicked(); break;
        case 4: _t->on_btn_ok_cancel_accepted(); break;
        case 5: _t->on_rdbtn_single_clicked(); break;
        case 6: _t->on_rdbtn_batch_clicked(); break;
        case 7: _t->on_chkB_BlackPix_Coverage_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Analyse_Binary_Img::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Analyse_Binary_Img.data,
      qt_meta_data_Analyse_Binary_Img,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Analyse_Binary_Img::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analyse_Binary_Img::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Analyse_Binary_Img.stringdata0))
        return static_cast<void*>(const_cast< Analyse_Binary_Img*>(this));
    return QDialog::qt_metacast(_clname);
}

int Analyse_Binary_Img::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
