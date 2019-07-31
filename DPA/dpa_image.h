#ifndef DPA_IMAGE_H
#define DPA_IMAGE_H

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

#include <QFileDialog>
#include <QObject>
#include <QFileInfo>
#include <sys/stat.h>
#include <ctime>
#include <math.h>

class DPA_Image
{
public:

private:
    cv::Mat Image;
    std::string date_pic_taken;
    float rel_luminance, brightness, L_luminance, mean_exg, mean_exr;   //L of CieLab

    double pi = 3.14159265359;

    void calc_Img_Brightness();
    cv::Mat set_HSVColorTable();
    cv::Mat set_LabColorTable(int Lab_channel);
    double quantilMat(cv::Mat hist, int nVals, double quantil);

    struct Thresh_HSV
    {
        float H,S,V;
        float mean_plant_H, mean_plant_S, mean_plant_V;
        float mean_soil_H, mean_soil_S, mean_soil_V;

        float stddev_plant_H, stddev_plant_S, stddev_plant_V;
        float stddev_soil_H, stddev_soil_S, stddev_soil_V;

        float quantil_plant_H, quantil_plant_S, quantil_plant_V;
        float quantil_soil_H, quantil_soil_S, quantil_soil_V;
    };
    struct Thresh_Lab
    {
        float L,a,b;
        float mean_plant_L, mean_plant_a, mean_plant_b;
        float mean_soil_L, mean_soil_a, mean_soil_b;

        float stddev_plant_L, stddev_plant_a, stddev_plant_b;
        float stddev_soil_L, stddev_soil_a, stddev_soil_b;

        float quantil_plant_L, quantil_plant_a, quantil_plant_b;
        float quantil_soil_L, quantil_soil_a, quantil_soil_b;
    };


public:

    enum kindOfThresh{PositivThresh, OtsuThresh, ManualThresh};
    enum kindOfMethod{ExG, ExR, ExGR};
    enum kindOfColorSpace{HSV, CieLab};
    enum colorChangeType{addExG, addExR, addExGnExR, addNon};
    enum kindOfAutoFilter{Manual_Filter, MeanStdDev_Filter, Quantile_Filter, Otsu_Filter};
    enum kindOfMaskMethod{ExG_ExR_Mask, ExG_Mask, ExGR_Mask};

    struct filter_settings
    {
        kindOfAutoFilter AutoMethod;
        kindOfMaskMethod MaskMethod;
        int Sigma;
        double plant_quantil, soil_quantil;
    };

    struct ImageValues
    {
        cv::Mat Grey, Binary, Color;
        float Coverage, Soil, Mean, rel_luminance, L_luminance, brightness, mean_exg, mean_exr;
        std::string date_pic_taken;
    };

    struct ImageAnalyse
    {
        cv::Mat hist_plant_soil[4]; //h_hist_plant, a_hist_plant, h_hist_soil, a_hist_soil

        Thresh_HSV thresh_HSV;
        Thresh_Lab thresh_Lab;
    };

// Original Image Functions

    void readImage(QString ImagePath);
    void setImage(cv::Mat inputImage);
    void clipImg(int x, int y, int width, int height);
    void rotateImg(double angle);
    cv::Mat get_OriginalImage();

//Method Funktions

    ImageValues get_Image_Values(kindOfMethod Method, kindOfThresh Thresh, int ThresholdValue, bool invert);
    ImageValues get_Image_Values(kindOfColorSpace ColorSpace, int min1, int max1, int min2, int max2, int min3, int max3, colorChangeType ColorChange, bool invert);
    ImageValues get_Image_Values(kindOfColorSpace ColorSpace, filter_settings FilterSettings,  colorChangeType ColorChange, bool invert);

    ImageAnalyse analyse_img(filter_settings FilterSettings);
    cv::Mat get_HistOfColor_HSV();
    cv::Mat get_HistOfColor_Lab(int Lab_channel);
    cv::Mat calc_histogram(cv::Mat src, kindOfColorSpace ColorSpace, bool convert, int channel, int NumOfBlackPixToDelete);
    std::vector<cv::Mat> get_histograms();


    cv::Mat set_LabColor(int ColorNum); //not used yet!


    DPA_Image();    //constructor
    ~DPA_Image();   //destructor
};

#endif // DPA_IMAGE_H
