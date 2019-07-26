#ifndef SAVE_WINDOW_H
#define SAVE_WINDOW_H

#include "dpa_image.h"
#include "config.h"
#include "image_library.h"

#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

#include <glob.h>
#include <fstream>
#include <ctime>

namespace Ui {
class save_window;
}

class save_window : public QDialog
{
    Q_OBJECT

public:
    explicit save_window(QWidget *parent = 0);
    ~save_window();

    void setImageLibrary(Image_Library &ImageLibrary, int current_index);

private slots:
    void on_btn_cancel_clicked();
    void on_btn_start_clicked();
    void on_rdbtn_single_clicked();
    void on_rdbtn_batch_clicked();
    void on_comboBox_img_list_currentIndexChanged(int index);

private:
    Ui::save_window *ui;

    Image_Library img_list;
    int indexOfCurrentImage; //Current image is the one you choose in Main_Window for single analysis

    QString targetFolder;
    int hundredpercent = 100;

    enum kindOfProcessing{single, batch} processing;

    DPA_Image SampleImage;

    std::ofstream csv_file;

    void saveImages(img_lib::ImageData img_data);
    void writeCSVFile(img_lib::ImageData img_data);
    void writeCSVFile_Threshold_Analysis(img_lib::ImageData img_data);
    void writeCSVFile_Histogram(img_lib::ImageData img_data);
    void writeCSVFile_Mean_StdDev_Quantil(img_lib::ImageData img_data);
    void set_progressbar(int current_number);
    void get_auto_filter();

    std::string Convert(float number);
    const std::string currentDateTime();
};

#endif // save_window_H
