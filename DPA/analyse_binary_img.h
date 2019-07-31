#ifndef ANALYSE_BINARY_IMG_H
#define ANALYSE_BINARY_IMG_H


#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

#include <fstream>

#include "image_library.h"
#include "config.h"

namespace Ui {
class Analyse_Binary_Img;
}

class Analyse_Binary_Img : public QDialog
{
    Q_OBJECT

public:
    explicit Analyse_Binary_Img(QWidget *parent = 0);
    ~Analyse_Binary_Img();

private slots:
   // void on_buttonBox_accepted();
    void on_btn_OpenImage_clicked();
    void on_comboBox_img_list_currentIndexChanged(int index);
    void on_btn_next_clicked();
    void on_btn_back_clicked();
    void on_btn_ok_cancel_accepted();
    void on_rdbtn_single_clicked();
    void on_rdbtn_batch_clicked();

    void on_chkB_BlackPix_Coverage_toggled(bool checked);

private:
    Ui::Analyse_Binary_Img *ui;

    Image_Library img_list;
    cv::Mat image;
    unsigned int indexOfCurrentImage;

    enum kindOfProcessing{single, batch} processing;
    std::ofstream csv_file;

    QString BlackPixel_Label;
    QString WhitePixel_Label;

    void loadImage();
    int TotalNumberOfPixels, BlackPixel, WhitePixel;
    std::string Convert_float2string(float number);
    const std::string currentDateTime();
};

#endif // ANALYSE_BINARY_IMG_H
