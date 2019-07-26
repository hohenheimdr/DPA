#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "save_window.h"
#include "edit_image.h"
#include "dpa_image.h"
#include "config.h"
#include "development.h"
#include "gt_mask_vs_binary_img.h"
#include "image_library.h"
#include "analyse_binary_img.h"

#include <QDesktopWidget>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>
#include <QPixmap>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include <QGraphicsOpacityEffect>

namespace Ui {
class main_window;
}

class main_window : public QWidget
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = 0);

    ~main_window();

private slots:

    void on_btn_Quit_clicked();
    void on_btn_OpenImage_clicked();
    void on_btn_edit_image_clicked();
    void on_btn_save_clicked();
    void on_btn_reset_clicked();
    void on_btn_development_clicked();

//------ Buttons --------------------------------------
///----- ExG ------------------------------------------
    void on_rdbtn_exg_positiv_clicked();
    void on_rdbtn_exg_otsu_clicked();
    void on_rdbtn_exg_manual_clicked();
    void on_sBox_exg_man_thresh_valueChanged(int arg1);

///----- ExR ------------------------------------------
    void on_rdbtn_exr_positiv_clicked();
    void on_rdbtn_exr_otsu_clicked();
    void on_rdbtn_exr_manual_clicked();
    void on_sBox_exr_man_thresh_valueChanged(int arg1);

///----- ExGR ------------------------------------------
    void on_rdbtn_exgr_positiv_clicked();
    void on_rdbtn_exgr_otsu_clicked();
    void on_rdbtn_exgr_manual_clicked();
    void on_sBox_exgr_man_thresh_valueChanged(int arg1);

///----- Filter ------------------------------------------
    void on_rdbtn_filter_hsv_clicked();
    void on_rdbtn_filter_cielab_clicked();
    void on_chkB_filter_addExG_stateChanged(int arg1);
    void on_chkB_filter_addExR_stateChanged(int arg1);
    void on_sBox_min1_valueChanged(int arg1);
    void on_sBox_max1_valueChanged(int arg1);
    void on_sBox_min2_valueChanged(int arg1);
    void on_sBox_max2_valueChanged(int arg1);
    void on_sBox_min3_valueChanged(int arg1);
    void on_sBox_max3_valueChanged(int arg1);

    void on_chkB_exg_invert_clicked();
    void on_chkB_exr_invert_clicked();
    void on_chkB_exgr_invert_clicked();
    void on_chkB_filter_invert_clicked();

    void on_rdbtn_auto_filter_on_toggled(bool checked);

    void on_comboBox_img_list_currentIndexChanged(int index);
    void on_btn_Analyse_BinaryImg_clicked();
    void on_btn_back_clicked();
    void on_btn_next_clicked();
    void on_slider_opacity_exg_valueChanged(int value);
    void on_slider_opacity_exr_valueChanged(int value);
    void on_slider_opacity_exgr_valueChanged(int value);
    void on_slider_opacity_filter_valueChanged(int value);

    void on_btn_save_filter_binary_clicked();
    void on_chkB_zoom_filter_toggled(bool checked);
    void on_tabWidget_main_currentChanged(int index);
    void on_btn_gtMask_vs_binaryImg_clicked();    

    void on_rdbtn_auto_filter_off_toggled(bool checked);

    void on_rdbtn_auto_filter_method_MeanStdDev_toggled(bool checked);

    void on_rdbtn_auto_filter_method_Quantile_toggled(bool checked);

    void on_sBox_plant_quantil_valueChanged(double arg1);

    void on_sBox_soil_quantil_valueChanged(double arg1);

    void on_sBox_Sigma_valueChanged(int arg1);

    void on_rdbtn_ExG_ExR_Filter_toggled(bool checked);


    void on_rdbtn_ExG_Filter_toggled(bool checked);

    void on_rdbtn_ExGR_Filter_toggled(bool checked);

private:
    Ui::main_window *ui;

    DPA_Image ImgSample1;
    save_window* savewindow;
    EditImage* editImage;
    Development* development;
    GTMvsBimg* GTMask_vs_BinaryImg;
    Analyse_Binary_Img* analyse_binary_img;

    QGraphicsOpacityEffect *effect_opacity;

    Image_Library img_list;  //Class-Object of Image_Library
    unsigned int indexOfCurrentImage;
    void get_ALL_by_tab();
    void get_orignal_image();
    void get_exg_data();
    void get_exr_data();
    void get_exgr_data();
    void get_filter_data();
    void get_histogram();
    void get_auto_filter();
    qreal trans_opacity(int value);

    QLabel *zoom_img;
    QScrollArea *scrollarea;
    QWidget *central;

};

#endif // MAIN_WINDOW_H
