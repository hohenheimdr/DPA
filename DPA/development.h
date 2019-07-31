#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

#include <QDialog>
#include <QWidget>
#include <QDesktopWidget>
#include <QFileInfo>
#include <QDateTime>
#include <algorithm>

#include "dpa_image.h"
#include "config.h"
#include "image_library.h"


namespace Ui {
class Development;
}

class Development : public QDialog
{
    Q_OBJECT

public:
    explicit Development(QWidget *parent = 0);
    ~Development();

    void setImageLibrary(Image_Library &ImageLibrary);

private slots:
    void on_btn_exit_clicked();
    void on_btn_next_clicked();
    void on_btn_back_clicked();
    void on_comboBox_start_Date_currentIndexChanged(int index);
    void on_comboBox_end_Date_currentIndexChanged(int index);
    void on_chkBox_inc_dec_clicked();

private:
    Ui::Development *ui;

    DPA_Image Img_n1, Img_n2;

    Image_Library img_list; //noch zu img_list umbenennen!!!!

    unsigned int index_n1, index_n2;

    void getImages();
    cv::Mat calcDeltaGreen(cv::Mat &Green1, cv::Mat &Green2);
    cv::Mat addChangeToOrg(cv::Mat ImageEnd, cv::Mat ImgDeltaGreen);
    void showImages();
};

#endif // DEVELOPMENT_H
