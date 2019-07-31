/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DPA/main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_main_window_t {
    QByteArrayData data[60];
    char stringdata0[1665];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_window_t qt_meta_stringdata_main_window = {
    {
QT_MOC_LITERAL(0, 0, 11), // "main_window"
QT_MOC_LITERAL(1, 12, 19), // "on_btn_Quit_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 24), // "on_btn_OpenImage_clicked"
QT_MOC_LITERAL(4, 58, 25), // "on_btn_edit_image_clicked"
QT_MOC_LITERAL(5, 84, 19), // "on_btn_save_clicked"
QT_MOC_LITERAL(6, 104, 20), // "on_btn_reset_clicked"
QT_MOC_LITERAL(7, 125, 26), // "on_btn_development_clicked"
QT_MOC_LITERAL(8, 152, 28), // "on_rdbtn_exg_positiv_clicked"
QT_MOC_LITERAL(9, 181, 25), // "on_rdbtn_exg_otsu_clicked"
QT_MOC_LITERAL(10, 207, 27), // "on_rdbtn_exg_manual_clicked"
QT_MOC_LITERAL(11, 235, 35), // "on_sBox_exg_man_thresh_valueC..."
QT_MOC_LITERAL(12, 271, 4), // "arg1"
QT_MOC_LITERAL(13, 276, 28), // "on_rdbtn_exr_positiv_clicked"
QT_MOC_LITERAL(14, 305, 25), // "on_rdbtn_exr_otsu_clicked"
QT_MOC_LITERAL(15, 331, 27), // "on_rdbtn_exr_manual_clicked"
QT_MOC_LITERAL(16, 359, 35), // "on_sBox_exr_man_thresh_valueC..."
QT_MOC_LITERAL(17, 395, 29), // "on_rdbtn_exgr_positiv_clicked"
QT_MOC_LITERAL(18, 425, 26), // "on_rdbtn_exgr_otsu_clicked"
QT_MOC_LITERAL(19, 452, 28), // "on_rdbtn_exgr_manual_clicked"
QT_MOC_LITERAL(20, 481, 36), // "on_sBox_exgr_man_thresh_value..."
QT_MOC_LITERAL(21, 518, 27), // "on_rdbtn_filter_hsv_clicked"
QT_MOC_LITERAL(22, 546, 30), // "on_rdbtn_filter_cielab_clicked"
QT_MOC_LITERAL(23, 577, 34), // "on_chkB_filter_addExG_stateCh..."
QT_MOC_LITERAL(24, 612, 34), // "on_chkB_filter_addExR_stateCh..."
QT_MOC_LITERAL(25, 647, 25), // "on_sBox_min1_valueChanged"
QT_MOC_LITERAL(26, 673, 25), // "on_sBox_max1_valueChanged"
QT_MOC_LITERAL(27, 699, 25), // "on_sBox_min2_valueChanged"
QT_MOC_LITERAL(28, 725, 25), // "on_sBox_max2_valueChanged"
QT_MOC_LITERAL(29, 751, 25), // "on_sBox_min3_valueChanged"
QT_MOC_LITERAL(30, 777, 25), // "on_sBox_max3_valueChanged"
QT_MOC_LITERAL(31, 803, 26), // "on_chkB_exg_invert_clicked"
QT_MOC_LITERAL(32, 830, 7), // "checked"
QT_MOC_LITERAL(33, 838, 26), // "on_chkB_exr_invert_clicked"
QT_MOC_LITERAL(34, 865, 27), // "on_chkB_exgr_invert_clicked"
QT_MOC_LITERAL(35, 893, 29), // "on_chkB_filter_invert_clicked"
QT_MOC_LITERAL(36, 923, 31), // "on_rdbtn_auto_filter_on_toggled"
QT_MOC_LITERAL(37, 955, 40), // "on_comboBox_img_list_currentI..."
QT_MOC_LITERAL(38, 996, 5), // "index"
QT_MOC_LITERAL(39, 1002, 32), // "on_btn_Analyse_BinaryImg_clicked"
QT_MOC_LITERAL(40, 1035, 19), // "on_btn_back_clicked"
QT_MOC_LITERAL(41, 1055, 19), // "on_btn_next_clicked"
QT_MOC_LITERAL(42, 1075, 34), // "on_slider_opacity_exg_valueCh..."
QT_MOC_LITERAL(43, 1110, 5), // "value"
QT_MOC_LITERAL(44, 1116, 34), // "on_slider_opacity_exr_valueCh..."
QT_MOC_LITERAL(45, 1151, 35), // "on_slider_opacity_exgr_valueC..."
QT_MOC_LITERAL(46, 1187, 37), // "on_slider_opacity_filter_valu..."
QT_MOC_LITERAL(47, 1225, 33), // "on_btn_save_filter_binary_cli..."
QT_MOC_LITERAL(48, 1259, 27), // "on_chkB_zoom_filter_toggled"
QT_MOC_LITERAL(49, 1287, 32), // "on_tabWidget_main_currentChanged"
QT_MOC_LITERAL(50, 1320, 34), // "on_btn_gtMask_vs_binaryImg_cl..."
QT_MOC_LITERAL(51, 1355, 32), // "on_rdbtn_auto_filter_off_toggled"
QT_MOC_LITERAL(52, 1388, 46), // "on_rdbtn_auto_filter_method_M..."
QT_MOC_LITERAL(53, 1435, 44), // "on_rdbtn_auto_filter_method_Q..."
QT_MOC_LITERAL(54, 1480, 34), // "on_sBox_plant_quantil_valueCh..."
QT_MOC_LITERAL(55, 1515, 33), // "on_sBox_soil_quantil_valueCha..."
QT_MOC_LITERAL(56, 1549, 26), // "on_sBox_Sigma_valueChanged"
QT_MOC_LITERAL(57, 1576, 31), // "on_rdbtn_ExG_ExR_Filter_toggled"
QT_MOC_LITERAL(58, 1608, 27), // "on_rdbtn_ExG_Filter_toggled"
QT_MOC_LITERAL(59, 1636, 28) // "on_rdbtn_ExGR_Filter_toggled"

    },
    "main_window\0on_btn_Quit_clicked\0\0"
    "on_btn_OpenImage_clicked\0"
    "on_btn_edit_image_clicked\0on_btn_save_clicked\0"
    "on_btn_reset_clicked\0on_btn_development_clicked\0"
    "on_rdbtn_exg_positiv_clicked\0"
    "on_rdbtn_exg_otsu_clicked\0"
    "on_rdbtn_exg_manual_clicked\0"
    "on_sBox_exg_man_thresh_valueChanged\0"
    "arg1\0on_rdbtn_exr_positiv_clicked\0"
    "on_rdbtn_exr_otsu_clicked\0"
    "on_rdbtn_exr_manual_clicked\0"
    "on_sBox_exr_man_thresh_valueChanged\0"
    "on_rdbtn_exgr_positiv_clicked\0"
    "on_rdbtn_exgr_otsu_clicked\0"
    "on_rdbtn_exgr_manual_clicked\0"
    "on_sBox_exgr_man_thresh_valueChanged\0"
    "on_rdbtn_filter_hsv_clicked\0"
    "on_rdbtn_filter_cielab_clicked\0"
    "on_chkB_filter_addExG_stateChanged\0"
    "on_chkB_filter_addExR_stateChanged\0"
    "on_sBox_min1_valueChanged\0"
    "on_sBox_max1_valueChanged\0"
    "on_sBox_min2_valueChanged\0"
    "on_sBox_max2_valueChanged\0"
    "on_sBox_min3_valueChanged\0"
    "on_sBox_max3_valueChanged\0"
    "on_chkB_exg_invert_clicked\0checked\0"
    "on_chkB_exr_invert_clicked\0"
    "on_chkB_exgr_invert_clicked\0"
    "on_chkB_filter_invert_clicked\0"
    "on_rdbtn_auto_filter_on_toggled\0"
    "on_comboBox_img_list_currentIndexChanged\0"
    "index\0on_btn_Analyse_BinaryImg_clicked\0"
    "on_btn_back_clicked\0on_btn_next_clicked\0"
    "on_slider_opacity_exg_valueChanged\0"
    "value\0on_slider_opacity_exr_valueChanged\0"
    "on_slider_opacity_exgr_valueChanged\0"
    "on_slider_opacity_filter_valueChanged\0"
    "on_btn_save_filter_binary_clicked\0"
    "on_chkB_zoom_filter_toggled\0"
    "on_tabWidget_main_currentChanged\0"
    "on_btn_gtMask_vs_binaryImg_clicked\0"
    "on_rdbtn_auto_filter_off_toggled\0"
    "on_rdbtn_auto_filter_method_MeanStdDev_toggled\0"
    "on_rdbtn_auto_filter_method_Quantile_toggled\0"
    "on_sBox_plant_quantil_valueChanged\0"
    "on_sBox_soil_quantil_valueChanged\0"
    "on_sBox_Sigma_valueChanged\0"
    "on_rdbtn_ExG_ExR_Filter_toggled\0"
    "on_rdbtn_ExG_Filter_toggled\0"
    "on_rdbtn_ExGR_Filter_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  284,    2, 0x08 /* Private */,
       3,    0,  285,    2, 0x08 /* Private */,
       4,    0,  286,    2, 0x08 /* Private */,
       5,    0,  287,    2, 0x08 /* Private */,
       6,    0,  288,    2, 0x08 /* Private */,
       7,    0,  289,    2, 0x08 /* Private */,
       8,    0,  290,    2, 0x08 /* Private */,
       9,    0,  291,    2, 0x08 /* Private */,
      10,    0,  292,    2, 0x08 /* Private */,
      11,    1,  293,    2, 0x08 /* Private */,
      13,    0,  296,    2, 0x08 /* Private */,
      14,    0,  297,    2, 0x08 /* Private */,
      15,    0,  298,    2, 0x08 /* Private */,
      16,    1,  299,    2, 0x08 /* Private */,
      17,    0,  302,    2, 0x08 /* Private */,
      18,    0,  303,    2, 0x08 /* Private */,
      19,    0,  304,    2, 0x08 /* Private */,
      20,    1,  305,    2, 0x08 /* Private */,
      21,    0,  308,    2, 0x08 /* Private */,
      22,    0,  309,    2, 0x08 /* Private */,
      23,    1,  310,    2, 0x08 /* Private */,
      24,    1,  313,    2, 0x08 /* Private */,
      25,    1,  316,    2, 0x08 /* Private */,
      26,    1,  319,    2, 0x08 /* Private */,
      27,    1,  322,    2, 0x08 /* Private */,
      28,    1,  325,    2, 0x08 /* Private */,
      29,    1,  328,    2, 0x08 /* Private */,
      30,    1,  331,    2, 0x08 /* Private */,
      31,    1,  334,    2, 0x08 /* Private */,
      33,    1,  337,    2, 0x08 /* Private */,
      34,    1,  340,    2, 0x08 /* Private */,
      35,    1,  343,    2, 0x08 /* Private */,
      36,    1,  346,    2, 0x08 /* Private */,
      37,    1,  349,    2, 0x08 /* Private */,
      39,    0,  352,    2, 0x08 /* Private */,
      40,    0,  353,    2, 0x08 /* Private */,
      41,    0,  354,    2, 0x08 /* Private */,
      42,    1,  355,    2, 0x08 /* Private */,
      44,    1,  358,    2, 0x08 /* Private */,
      45,    1,  361,    2, 0x08 /* Private */,
      46,    1,  364,    2, 0x08 /* Private */,
      47,    0,  367,    2, 0x08 /* Private */,
      48,    1,  368,    2, 0x08 /* Private */,
      49,    1,  371,    2, 0x08 /* Private */,
      50,    0,  374,    2, 0x08 /* Private */,
      51,    1,  375,    2, 0x08 /* Private */,
      52,    1,  378,    2, 0x08 /* Private */,
      53,    1,  381,    2, 0x08 /* Private */,
      54,    1,  384,    2, 0x08 /* Private */,
      55,    1,  387,    2, 0x08 /* Private */,
      56,    1,  390,    2, 0x08 /* Private */,
      57,    1,  393,    2, 0x08 /* Private */,
      58,    1,  396,    2, 0x08 /* Private */,
      59,    1,  399,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   32,

       0        // eod
};

void main_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        main_window *_t = static_cast<main_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_Quit_clicked(); break;
        case 1: _t->on_btn_OpenImage_clicked(); break;
        case 2: _t->on_btn_edit_image_clicked(); break;
        case 3: _t->on_btn_save_clicked(); break;
        case 4: _t->on_btn_reset_clicked(); break;
        case 5: _t->on_btn_development_clicked(); break;
        case 6: _t->on_rdbtn_exg_positiv_clicked(); break;
        case 7: _t->on_rdbtn_exg_otsu_clicked(); break;
        case 8: _t->on_rdbtn_exg_manual_clicked(); break;
        case 9: _t->on_sBox_exg_man_thresh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_rdbtn_exr_positiv_clicked(); break;
        case 11: _t->on_rdbtn_exr_otsu_clicked(); break;
        case 12: _t->on_rdbtn_exr_manual_clicked(); break;
        case 13: _t->on_sBox_exr_man_thresh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_rdbtn_exgr_positiv_clicked(); break;
        case 15: _t->on_rdbtn_exgr_otsu_clicked(); break;
        case 16: _t->on_rdbtn_exgr_manual_clicked(); break;
        case 17: _t->on_sBox_exgr_man_thresh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_rdbtn_filter_hsv_clicked(); break;
        case 19: _t->on_rdbtn_filter_cielab_clicked(); break;
        case 20: _t->on_chkB_filter_addExG_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_chkB_filter_addExR_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_sBox_min1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_sBox_max1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_sBox_min2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_sBox_max2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_sBox_min3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_sBox_max3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_chkB_exg_invert_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_chkB_exr_invert_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_chkB_exgr_invert_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_chkB_filter_invert_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_rdbtn_auto_filter_on_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_comboBox_img_list_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_btn_Analyse_BinaryImg_clicked(); break;
        case 35: _t->on_btn_back_clicked(); break;
        case 36: _t->on_btn_next_clicked(); break;
        case 37: _t->on_slider_opacity_exg_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_slider_opacity_exr_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_slider_opacity_exgr_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_slider_opacity_filter_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_btn_save_filter_binary_clicked(); break;
        case 42: _t->on_chkB_zoom_filter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_tabWidget_main_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_btn_gtMask_vs_binaryImg_clicked(); break;
        case 45: _t->on_rdbtn_auto_filter_off_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->on_rdbtn_auto_filter_method_MeanStdDev_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->on_rdbtn_auto_filter_method_Quantile_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->on_sBox_plant_quantil_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 49: _t->on_sBox_soil_quantil_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 50: _t->on_sBox_Sigma_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->on_rdbtn_ExG_ExR_Filter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 52: _t->on_rdbtn_ExG_Filter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->on_rdbtn_ExGR_Filter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject main_window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_main_window.data,
      qt_meta_data_main_window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *main_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_main_window.stringdata0))
        return static_cast<void*>(const_cast< main_window*>(this));
    return QWidget::qt_metacast(_clname);
}

int main_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 54;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
