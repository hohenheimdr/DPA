#ifndef GT_MASK_VS_BINARY_IMG_H
#define GT_MASK_VS_BINARY_IMG_H

#include <QDialog>
#include <QWidget>
#include <QDesktopWidget>
#include <QFileInfo>



#include <QMessageBox>

#include "dpa_image.h"
#include "config.h"
#include "image_library.h"
#include <fstream>

//GT_MASK_VS_BINARY_IMG ==> comparison between Groundtruth-Image and Binary-Result-Image

namespace Ui {
class GTMvsBimg;
}

class GTMvsBimg : public QDialog
{
    Q_OBJECT

public:
    explicit GTMvsBimg(QWidget *parent = 0);
    ~GTMvsBimg();


private slots:    
    void on_btn_exit_clicked();
    void on_btn_next_clicked();
    void on_btn_back_clicked();

    void on_chkB_invert_clicked(bool checked);


    void on_btn_save_csv_clicked();

private:
    Ui::GTMvsBimg *ui;

    Image_Library GT_Mask_list, Binary_Img_list;
    DPA_Image GT_Mask, Binary_Img;

    const std::string currentDateTime();

    float coverage_gtMask, coverage_binaryImg, tooLess, tooMuch;

    std::string Convert_float2string(float number);
    std::ofstream csv_file;

    bool invert;

    unsigned int index_GT_Mask, index_Binary_Img;

    void showImages();
    void getImages();
    float calcCoverage(cv::Mat image, bool converted);
    cv::Mat calcDifference(cv::Mat Img1, cv::Mat Img2, bool to_Less_Much);
    cv::Mat addDiffToGTMask(cv::Mat ImgGTMask, cv::Mat ImgToLessDiff, cv::Mat ImgToMuchDiff);
};

#endif // GT_MASK_VS_BINARY_IMG_H
