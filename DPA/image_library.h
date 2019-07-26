#ifndef IMAGE_LIBRARY_H
#define IMAGE_LIBRARY_H

#include <opencv2/highgui/highgui.hpp>
#include <vector>

#include <iostream>
#include <QObject>
#include <QFileInfo>
#include <QDateTime>


namespace img_lib
{
    struct ImageData
    {
        QString ImageName;
        QString ImageType;
        cv::String ImagePath;
        QDate ImageDate;        //http://doc.qt.io/archives/qt-4.8/qdate.html #toString
        QDateTime LastModified;
    };
}

bool compareByDate(const img_lib::ImageData &a, const img_lib::ImageData &b);

class Image_Library
{
public:
    Image_Library();

    void build_img_library(QString ImagePath, bool SingleImage, bool Subfolder);
    std::vector<img_lib::ImageData> allImages;

private:



};

#endif // IMAGE_LIBRARY_H
