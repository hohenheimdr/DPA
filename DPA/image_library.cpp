#include "image_library.h"

Image_Library::Image_Library()
{

}

bool compareByDate(const img_lib::ImageData &a, const img_lib::ImageData &b)
{
    //return a.ImageDate < b.ImageDate;
    //return a.LastModified < b.LastModified;
    return a.ImageName < b.ImageName;
}


void Image_Library::build_img_library(QString ImagePath, bool SingleImage, bool Subfolder)
{
    if(ImagePath != NULL)
    {
        allImages.clear();

        std::vector<cv::String> vecImagePath;
        QString sourceDirectory;

        if(SingleImage)
        {
            vecImagePath.push_back(ImagePath.toStdString());
        }else
        {
            QString::size_type p = ImagePath.lastIndexOf('/')+1;
            sourceDirectory = ImagePath.mid(0, p);
            p = ImagePath.lastIndexOf('.');
            sourceDirectory = sourceDirectory + '*' + ImagePath.mid(p, 4);
            cv::glob(sourceDirectory.toStdString(), vecImagePath, Subfolder);
        }

        QFileInfo fileInfo;

        for(unsigned int i = 0; i < vecImagePath.size(); i++)
        {
            fileInfo.setFile(QString::fromStdString(vecImagePath[i]));

            allImages.push_back({fileInfo.fileName(), fileInfo.suffix(), vecImagePath[i], fileInfo.lastModified().date(), fileInfo.lastModified()}); //date()
        }

        std::sort(allImages.begin(), allImages.end(), compareByDate);
    }
}
