#include "dpa_image.h"

DPA_Image::DPA_Image()  //constructor
{
    //Variablen mit Standartwerten füllen....

    cv::Mat tempImg(100, 100, CV_8UC3, cv::Scalar(43,90,139));
    cv::putText(tempImg,
                "Empty",
                cv::Point(10,50), // Coordinates
                cv::FONT_HERSHEY_COMPLEX_SMALL, // Font
                1.0, // Scale. 2.0 = 2x bigger
                cv::Scalar(0,100,0), // Color (34,139,34)
                1, // Thickness
                CV_AA); // Anti-alias

    Image = tempImg.clone();
}

DPA_Image::~DPA_Image() //destructor
{
    //destroy anything
}

std::string Convert(int number)
{
    std::stringstream ss;
    ss<<number;
    return ss.str();
}

void DPA_Image::calc_Img_Brightness()
{
    cv::Mat tmpImg[3];   //destination array
    cv::split(Image,tmpImg);//split source

    //Relative_luminance
    rel_luminance = cv::mean(0.2126 * tmpImg[2] + 0.7152 * tmpImg[1] + 0.0722 * tmpImg[0])[0];

    //Brightness

    //brightness = cv::mean(std::sqrt(0.299 * tmpImg[2]*tmpImg[2] + 0.587 * tmpImg[1]*tmpImg[1] + 0.114 * tmpImg[0]*tmpImg[0]),2)[0];

    //L_luminance of CieLab
    cv::Mat tmpLab;
    cv::cvtColor(Image, tmpLab, cv::COLOR_BGR2Lab);
    cv::split(tmpLab,tmpImg);//split source
    L_luminance = cv::mean(tmpImg[0])[0];
}


void DPA_Image::readImage(QString ImagePath)
{
    QFileInfo check_file(ImagePath);
    // check if file exists and if yes: Is it really a file and no directory?
    if(check_file.exists() && check_file.isFile())
    {
        Image = cv::imread(ImagePath.toStdString());

        struct stat attrib;
        stat(ImagePath.toStdString().c_str(), &attrib);
        tm *filetime = gmtime(&(attrib.st_mtime));

        date_pic_taken = Convert(filetime->tm_mday) + "." + Convert(filetime->tm_mon+1) + "." + Convert(filetime->tm_year+ 1900);
        calc_Img_Brightness();
    }
}
void DPA_Image::setImage(cv::Mat inputImage)
{
   Image = inputImage.clone();
}

cv::Mat DPA_Image::get_OriginalImage()
{
    return Image.clone();
}

DPA_Image::ImageValues DPA_Image::get_Image_Values(kindOfMethod Method, kindOfThresh Thresh, int ThresholdValue, bool invert)
{
    DPA_Image::ImageValues output;

    cv::Mat imgBlue, imgGreen, imgRed, imgResult;

    int TotalNumberOfPixels, BlackPixel, WhitePixel;

    std::vector<cv::Mat> channels;
    split(Image, channels);

    imgBlue = channels[0];
    imgGreen = channels[1];
    imgRed = channels[2];

    switch (Method)
    {
    case ExG:
        imgResult = ((2 * imgGreen - imgBlue - imgRed)/(imgGreen + imgBlue + imgRed))*255;
        //imgResult = (2 * imgGreen - imgBlue - imgRed) //old and wrong??
        break;
    case ExR:
        imgResult = ((1.4 * imgRed - imgGreen)/(imgGreen + imgBlue + imgRed))*255;
        //imgResult = (1.4 * imgRed - imgGreen); //old and wrong??
        break;
    case ExGR:
        imgResult = ((2 * imgGreen - imgBlue - imgRed)/(imgGreen + imgBlue + imgRed))*255 - ((1.4 * imgRed - imgGreen)/(imgGreen + imgBlue + imgRed))*255;
        //imgResult = (2 * imgGreen - imgBlue - imgRed) - (1.4 * imgRed - imgGreen); //old and wrong??
        break;

    default:
        break;
    }

    cv::Scalar mean_value = cv::mean(imgResult);
    output.Mean = mean_value[0];
    cv::cvtColor(imgResult,output.Grey,cv::COLOR_GRAY2BGR);


    switch (Thresh)
    {
    case PositivThresh:
        cv::threshold(imgResult,imgResult,0, 255, cv::THRESH_BINARY);
        break;
    case OtsuThresh:
        cv::threshold(imgResult,imgResult,0, 255, cv::THRESH_BINARY+cv::THRESH_OTSU);
        break;
    case ManualThresh:
        cv::threshold(imgResult,imgResult,ThresholdValue, 255, cv::THRESH_BINARY);
        break;
    default:
        break;
    }

    if(invert)
    {
        imgResult = cv::Scalar::all(255)-imgResult;
    }

    cv::cvtColor(imgResult,output.Binary,cv::COLOR_GRAY2BGR);

    TotalNumberOfPixels = imgResult.rows * imgResult.cols;
    BlackPixel = TotalNumberOfPixels - cv::countNonZero(imgResult);
    WhitePixel = TotalNumberOfPixels - BlackPixel;

    cv::cvtColor(imgResult,imgResult,cv::COLOR_GRAY2BGR);
    cv::bitwise_and(Image, imgResult, output.Color);

    output.Coverage = 100.0/TotalNumberOfPixels*WhitePixel;
    output.Soil = 100.0 - output.Coverage;

    output.date_pic_taken = date_pic_taken;
    output.rel_luminance = rel_luminance;
    output.L_luminance = L_luminance;

    return output;
}

//-------------------------with Filter!!-----------------------------------------

DPA_Image::ImageValues DPA_Image::get_Image_Values(kindOfColorSpace ColorSpace, int min1, int max1, int min2, int max2, int min3, int max3, colorChangeType ColorChange, bool invert)
{
    DPA_Image::ImageValues output;

    cv::Mat imgBlue, imgGreen, imgRed, imgResult;

    int TotalNumberOfPixels, BlackPixel, WhitePixel;

    std::vector<cv::Mat> channels, combChannels;
    split(Image, channels);

    imgBlue = channels [0];
    imgGreen = channels [1];
    imgRed = channels [2];

    switch (ColorChange)
    {
    case addExG:
        imgGreen += ((2 * imgGreen - imgBlue - imgRed)/(imgGreen + imgBlue + imgRed))*255;
        //imgGreen += (2 * imgGreen - imgBlue - imgRed); //old and wrong??
        break;
    case addExR:
        imgRed += ((1.4 * imgRed - imgGreen)/(imgGreen + imgBlue + imgRed))*255;
        //imgRed += (1.4 * imgRed - imgGreen); //old and wrong??
        break;
    case addExGnExR:
        imgGreen += ((2 * imgGreen - imgBlue - imgRed)/(imgGreen + imgBlue + imgRed))*255;
        imgRed += ((1.4 * imgRed - imgGreen)/(imgGreen + imgBlue + imgRed))*255;
        //imgGreen += (2 * imgGreen - imgBlue - imgRed); //old and wrong??
        //imgRed += (1.4 * imgRed - imgGreen); //old and wrong??
        break;
    case addNon:
        break;
    default:
        break;
    }

    combChannels.push_back(imgBlue);
    combChannels.push_back(imgGreen);
    combChannels.push_back(imgRed);

    cv::merge(combChannels, imgResult);

    output.Grey = imgResult.clone();

    switch (ColorSpace)
    {
    case CieLab:
        cv::cvtColor(imgResult, imgResult, cv::COLOR_BGR2Lab);
        cv::inRange(imgResult,cv::Scalar(min1,min2,min3), cv::Scalar(max1,max2,max3),imgResult);
        break;

    case HSV:
        cv::cvtColor(imgResult, imgResult, cv::COLOR_BGR2HSV);
        cv::inRange(imgResult,cv::Scalar(min1,min2,min3), cv::Scalar(max1,max2,max3),imgResult);
        break;
    default:
        break;
    }

    if(invert)
    {
        imgResult = cv::Scalar::all(255)-imgResult;
    }

    cv::cvtColor(imgResult,output.Binary,cv::COLOR_GRAY2BGR);

    TotalNumberOfPixels = imgResult.rows * imgResult.cols;
    BlackPixel = TotalNumberOfPixels - countNonZero(imgResult);
    WhitePixel = TotalNumberOfPixels - BlackPixel;

    cv::cvtColor(imgResult,imgResult,cv::COLOR_GRAY2BGR);
    cv::bitwise_and(Image, imgResult, output.Color);

    output.Coverage = 100.0/TotalNumberOfPixels*WhitePixel;
    output.Soil = 100.0 - output.Coverage;

    output.date_pic_taken = date_pic_taken;
    output.rel_luminance = rel_luminance;
    output.L_luminance = L_luminance;

    return output;
}

//-------------------------with Auto Filter!!-----------------------------------------

DPA_Image::ImageValues DPA_Image::get_Image_Values(kindOfColorSpace ColorSpace, filter_settings FilterSettings,  colorChangeType ColorChange, bool invert)
{
    ImageValues output;
    ImageAnalyse FilterParam = analyse_img(FilterSettings);

    cv::Mat imgBlue, imgGreen, imgRed, imgResult;

    int TotalNumberOfPixels, BlackPixel, WhitePixel;

    std::vector<cv::Mat> channels, combChannels;
    split(Image, channels);

    imgBlue = channels [0];
    imgGreen = channels [1];
    imgRed = channels [2];

    switch (ColorChange)
    {
    case addExG:
        imgGreen += ((2 * imgGreen - imgBlue - imgRed)/(imgGreen + imgBlue + imgRed))*255;
        //imgGreen += (2 * imgGreen - imgBlue - imgRed); //old and wrong??
        break;
    case addExR:
        imgRed += ((1.4 * imgRed - imgGreen)/(imgGreen + imgBlue + imgRed))*255;
        //imgRed += (1.4 * imgRed - imgGreen); //old and wrong??
        break;
    case addExGnExR:
        imgGreen += ((2 * imgGreen - imgBlue - imgRed)/(imgGreen + imgBlue + imgRed))*255;
        imgRed += ((1.4 * imgRed - imgGreen)/(imgGreen + imgBlue + imgRed))*255;
        //imgGreen += (2 * imgGreen - imgBlue - imgRed); //old and wrong??
        //imgRed += (1.4 * imgRed - imgGreen); //old and wrong??
        break;
    case addNon:
        break;
    default:
        break;
    }

    combChannels.push_back(imgBlue);
    combChannels.push_back(imgGreen);
    combChannels.push_back(imgRed);

    cv::merge(combChannels, imgResult);

    output.Grey = imgResult.clone();


    switch (ColorSpace)
    {
    case CieLab:
        cv::cvtColor(imgResult, imgResult, cv::COLOR_BGR2Lab);
        cv::inRange(imgResult,cv::Scalar(0, std::round(FilterParam.thresh_Lab.a), 0), cv::Scalar(255, 255, 255),imgResult);
        break;

    case HSV:
        cv::cvtColor(imgResult, imgResult, cv::COLOR_BGR2HSV);
        cv::inRange(imgResult,cv::Scalar(0, 0, 0), cv::Scalar(std::round(FilterParam.thresh_HSV.H), 255, 255),imgResult);
        break;
    default:
        break;
    }

    if(invert)
    {
        imgResult = cv::Scalar::all(255)-imgResult;
    }

    cv::cvtColor(imgResult,output.Binary,cv::COLOR_GRAY2BGR);

    TotalNumberOfPixels = imgResult.rows * imgResult.cols;
    BlackPixel = TotalNumberOfPixels - countNonZero(imgResult);
    WhitePixel = TotalNumberOfPixels - BlackPixel;

    cv::cvtColor(imgResult,imgResult,cv::COLOR_GRAY2BGR);
    cv::bitwise_and(Image, imgResult, output.Color);

    output.Coverage = 100.0/TotalNumberOfPixels*WhitePixel;
    output.Soil = 100.0 - output.Coverage;

    output.date_pic_taken = date_pic_taken;
    output.rel_luminance = rel_luminance;
    output.L_luminance = L_luminance;

    return output;
}


void DPA_Image::clipImg(int x, int y, int width, int height)
{
    int Xmax = Image.cols;
    int	Ymax = Image.rows;
    int	FoI_X = 0;
    int	FoI_Y = 0;
    int	FoI_Height = Ymax;
    int	FoI_Width = Xmax;

    cv::Mat tempImage;

    FoI_X = x;
    FoI_Y = y;
    FoI_Width = width;
    FoI_Height = height;

        tempImage = Image.clone();

        // check Size of Field of Interest

        if(FoI_X >= Xmax)
        {
            FoI_X = Xmax -1;
        }
        if(FoI_X+FoI_Width > Xmax)
        {
            FoI_Width = Xmax-FoI_X;
        }
        if(FoI_Y >= Ymax)
        {
            FoI_Y = Ymax -1;
        }
        if(FoI_Y+FoI_Height > Ymax)
        {
            FoI_Height = Ymax-FoI_Y;
        }
        // check Size of Field of Interest ------ end

        Image = Image(cv::Rect(FoI_X,FoI_Y,FoI_Width,FoI_Height));
        calc_Img_Brightness();
}

void DPA_Image::rotateImg(double angle)
{
    cv::Mat org_img, new_img;

    org_img = Image.clone();

    if(angle > 0)
    {
        cv::Point2f center(Image.cols/2.0, Image.rows/2.0);
        new_img = cv::getRotationMatrix2D(center, -angle, 1.0);

        // determine bounding rectangle
        cv::Rect bbox = cv::RotatedRect(center,Image.size(), angle).boundingRect();
        // adjust transformation matrix
        new_img.at<double>(0,2) += bbox.width/2.0 - center.x;
        new_img.at<double>(1,2) += bbox.height/2.0 - center.y;

        cv::warpAffine(org_img,org_img,new_img, bbox.size());//Image.size());

    }

    Image = org_img;
}

cv::Mat DPA_Image::set_LabColor(int ColorNum)
{

    //not used yet!!!!
}

cv::Mat DPA_Image::set_HSVColorTable()
{
    cv::Mat src = Image.clone();

    cv::cvtColor(src, src, cv::COLOR_BGR2HSV);

    cv::Mat tmpImg[3];	//destination array
    cv::split(src,tmpImg);//split source


    double mean_s = cv::mean(tmpImg[1])[0];
    double mean_v = cv::mean(tmpImg[2])[0];

    int hight = 1,
            range = 720;

    double h = 0.0,
            s = mean_s, //200.0,
            v = mean_v; //255.0;

    cv::Mat ColorTable(hight, range, CV_8UC3, cv::Scalar(0.0, 0.0, 0.0)),
            output;

    cv::cvtColor(ColorTable, ColorTable, cv::COLOR_BGR2HSV);

    for(int i=0; i<720; i++)
    {
        h=i/2;
        ColorTable.at<cv::Vec3b>(cv::Point(i, 0))[0] = (h /360*179);
        ColorTable.at<cv::Vec3b>(cv::Point(i, 0))[1] = (s);
        ColorTable.at<cv::Vec3b>(cv::Point(i, 0))[2] = (v);
    }

    for(int i=0; i<400; i++)
    {
        output.push_back(ColorTable);
    }

    cv::cvtColor(output, output, cv::COLOR_HSV2BGR);

    return output;
}

cv::Mat DPA_Image::get_HistOfColor_HSV()
{
    cv::Mat src = Image.clone();

    cv::Mat hist = calc_histogram(src, HSV, true, 0, 0);

    // Draw the histograms
    int histSize = 180;
    int hist_w = 720;
    int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );

    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255) );

    // Normalize the result to [ 0, histImage.rows ]
    cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

    // Draw for each channel
    for( int i = 1; i < histSize; i++ )
    {
        cv::line( histImage,
                  cv::Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ),
                  cv::Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
                  cv::Scalar( 0, 0, 0), 2, 8, 0  );
    }

    cv::bitwise_and(set_HSVColorTable(), histImage, histImage);

    return histImage;
}

cv::Mat DPA_Image::set_LabColorTable(int Lab_channel)
{
    cv::Mat src = Image.clone();

    cv::cvtColor(src, src, cv::COLOR_BGR2Lab);

    cv::Mat tmpImg[3];	//destination array
    cv::split(src,tmpImg);//split source


    double mean_L = cv::mean(tmpImg[0])[0];

    int hight = 1,
            range = 512;

    double L = mean_L, //50.0
            a = 127.5,
            b = 127.5;

    cv::Mat ColorTable(hight, range, CV_8UC3, cv::Scalar(0.0, 0.0, 0.0)),
            output;

    cv::cvtColor(ColorTable, ColorTable, cv::COLOR_BGR2HSV);

    for(int i=0; i<512; i++)
    {
        switch (Lab_channel)
        {
        case 0: L=i/2;  break;
        case 1: a=i/2;  break;
        case 2: b=i/2;  break;
        default:        break;
        }

        ColorTable.at<cv::Vec3b>(cv::Point(i, 0))[0] = (L);
        ColorTable.at<cv::Vec3b>(cv::Point(i, 0))[1] = (a);
        ColorTable.at<cv::Vec3b>(cv::Point(i, 0))[2] = (b);
    }

    for(int i=0; i<200; i++)
    {
        output.push_back(ColorTable);
    }

    cv::cvtColor(output, output, cv::COLOR_Lab2BGR);

    return output;
}

cv::Mat DPA_Image::get_HistOfColor_Lab(int Lab_channel)
{
    cv::Mat src = Image.clone();

    cv::Mat hist = calc_histogram(src, CieLab, true, Lab_channel, 0);

    // Draw the histograms
    int histSize = 256;
    int hist_w = 512;
    int hist_h = 200;
    int bin_w = cvRound( (double) hist_w/histSize );

    cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255) );

    // Normalize the result to [ 0, histImage.rows ]
    cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

    // Draw for each channel
    for( int i = 1; i < histSize; i++ )
    {
        cv::line( histImage,
                  cv::Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ),
                  cv::Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
                  cv::Scalar( 0, 0, 0), 2, 8, 0  );
    }

    cv::bitwise_and(set_LabColorTable(Lab_channel), histImage, histImage);

    return histImage;
}

cv::Mat DPA_Image::calc_histogram(cv::Mat src, kindOfColorSpace ColorSpace, bool convert, int channel, int NumOfBlackPixToDelete)
{
    cv::Mat tempImg;

    // Establish the number of bins
    int histSize;
    // Set the ranges ( for HSV / LAB Channel) )
    float range[2];

    switch (ColorSpace)
    {
    case HSV:
        if(convert){cv::cvtColor(src,tempImg,cv::COLOR_BGR2HSV);} else{tempImg = src;}
        histSize = 180;
        range[0] = 0;
        range[1] = 179;

        break;
    case CieLab:
        if(convert){cv::cvtColor(src,tempImg,cv::COLOR_BGR2Lab);} else{tempImg = src;}
        histSize = 256;
        range[0] = 0;
        range[1] = 255;
        break;

    default:
        break;
    }

    std::vector<cv::Mat> planes;
    cv::split(tempImg, planes);

    const float* histRange = { range };

    bool uniform = true;
    bool accumulate = false;

    cv::Mat hist;

    // Compute the histograms:
    cv::calcHist(&planes[channel], 1, 0, cv::Mat(), hist, 1, &histSize, &histRange, uniform, accumulate );

    switch (ColorSpace)
    {
    case HSV:
        hist.at<float>(0) -= NumOfBlackPixToDelete;
        break;
    case CieLab:
        hist.at<float>(128) -= NumOfBlackPixToDelete;
        break;

    default:
        break;
    }

    return hist;
}

std::vector<cv::Mat> DPA_Image::get_histograms()
{
    std::vector<cv::Mat> output; // H_hist, S_hist, V_hist, L_hist, a_hist, b_hist

    cv::Mat src = Image.clone();

    output.push_back(calc_histogram(src, HSV, true, 0, 0));
    output.push_back(calc_histogram(src, HSV, true, 1, 0));
    output.push_back(calc_histogram(src, HSV, true, 2, 0));

    output.push_back(calc_histogram(src, CieLab, true, 0, 0));
    output.push_back(calc_histogram(src, CieLab, true, 1, 0));
    output.push_back(calc_histogram(src, CieLab, true, 2, 0));

    return output;
}

DPA_Image::ImageAnalyse DPA_Image::analyse_img(filter_settings FilterSettings)
{

    ImageAnalyse output;

    double H_plant, S_plant, V_plant, H_soil, S_soil, V_soil;
    double L_plant, a_plant, b_plant, L_soil, a_soil, b_soil;
    int TotalNumberOfPixels, BlackPixel;

    cv::Scalar StdDev, Mean;

    cv::Mat src, imgResult, Mask, ColSpace_img;

    src = Image.clone();

    cv::Mat CH_array[3];   //destination channel array
    cv::split(src,CH_array);    //split source

    switch (FilterSettings.MaskMethod)
    {
    case ExG_ExR_Mask:
        Mask = ((2 * CH_array[1] - CH_array[0] - CH_array[2])/(CH_array[1] + CH_array[0] + CH_array[2]))*255; //ExG
        //Mask = (2 * CH_array[1] - CH_array[0] - CH_array[2]); //ExG //old and wrong??
        cv::threshold(Mask,Mask,0, 255, cv::THRESH_BINARY+cv::THRESH_OTSU); //build binary Mask
        break;
    case ExG_Mask:
        Mask = ((2 * CH_array[1] - CH_array[0] - CH_array[2])/(CH_array[1] + CH_array[0] + CH_array[2]))*255; //ExG
        //Mask = (2 * CH_array[1] - CH_array[0] - CH_array[2]); //ExG //old and wrong??
        cv::threshold(Mask,Mask,0, 255, cv::THRESH_BINARY+cv::THRESH_OTSU); //build binary Mask
        break;
    case ExGR_Mask:
        Mask = ((2 * CH_array[1] - CH_array[0] - CH_array[2])/(CH_array[1] + CH_array[0] + CH_array[2]))*255
                - ((1.4 * CH_array[2] - CH_array[1])/(CH_array[1] + CH_array[0] + CH_array[2]))*255; //ExGR
        //Mask = (2 * CH_array[1] - CH_array[0] - CH_array[2]) - (1.4 * CH_array[2] - CH_array[1]); //ExGR //old and wrong??
        cv::threshold(Mask,Mask,0, 255, cv::THRESH_BINARY);
        break;
    default:
        break;
    }

    //--------------------------calc "total number of Pixel" for Histogram correction (calc hist counts also black Pixel of Mask)
    TotalNumberOfPixels = src.rows * src.cols;
    BlackPixel = TotalNumberOfPixels - cv::countNonZero(Mask);
    //----------------------------------------------------------------------------------------------------------------------------

    cv::cvtColor(src,ColSpace_img,cv::COLOR_BGR2HSV);
    cv::meanStdDev(ColSpace_img, Mean, StdDev, Mask);

    cv::cvtColor(Mask,imgResult,cv::COLOR_GRAY2BGR);
    cv::bitwise_and(src, imgResult, imgResult);
    cv::cvtColor(imgResult,imgResult,cv::COLOR_BGR2HSV);
    output.hist_plant_soil[0] = calc_histogram(imgResult, HSV, false, 0, BlackPixel);

    H_plant = Mean[0] - StdDev[0] * FilterSettings.Sigma;    //attention
    S_plant = Mean[1] - StdDev[1] * FilterSettings.Sigma;    //Values in Scale of 8 bit (0-255)
    V_plant = Mean[2] - StdDev[2] * FilterSettings.Sigma;    //instead of H(0-179) or H(1-360)

    output.thresh_HSV.mean_plant_H = Mean[0];
    output.thresh_HSV.mean_plant_S = Mean[1];
    output.thresh_HSV.mean_plant_V = Mean[2];
    output.thresh_HSV.stddev_plant_H = StdDev[0];
    output.thresh_HSV.stddev_plant_S = StdDev[1];
    output.thresh_HSV.stddev_plant_V = StdDev[2];
    output.thresh_HSV.quantil_plant_H = quantilMat(output.hist_plant_soil[0], 180, FilterSettings.plant_quantil);

    cv::cvtColor(src,ColSpace_img,cv::COLOR_BGR2Lab);
    cv::meanStdDev(ColSpace_img, Mean, StdDev, Mask);

    cv::cvtColor(Mask,imgResult,cv::COLOR_GRAY2BGR);
    cv::bitwise_and(src, imgResult, imgResult);
    cv::cvtColor(imgResult,imgResult,cv::COLOR_BGR2Lab);
    output.hist_plant_soil[1] = calc_histogram(imgResult, CieLab, false, 1, BlackPixel);

    L_plant = Mean[0] + StdDev[0] * FilterSettings.Sigma;    //attention
    a_plant = Mean[1] + StdDev[1] * FilterSettings.Sigma;    //Values in Scale of 8 bit (0-255)
    b_plant = Mean[2] + StdDev[2] * FilterSettings.Sigma;    //instead of L(0-100) a(-127-127) b(-127-127)

    output.thresh_Lab.mean_plant_L = Mean[0];
    output.thresh_Lab.mean_plant_a = Mean[1];
    output.thresh_Lab.mean_plant_b = Mean[2];
    output.thresh_Lab.stddev_plant_L = StdDev[0] ;
    output.thresh_Lab.stddev_plant_a = StdDev[1];
    output.thresh_Lab.stddev_plant_b = StdDev[2];
    output.thresh_Lab.quantil_plant_a = quantilMat(output.hist_plant_soil[1], 256, FilterSettings.plant_quantil);


    //-------------------Mean_soil------------------------------------------------

    switch (FilterSettings.MaskMethod)
    {
    case ExG_ExR_Mask:
        Mask = ((1.4 * CH_array[2] - CH_array[1])/(CH_array[1] + CH_array[0] + CH_array[2]))*255;	//ExR
        //Mask = (1.4 * CH_array[2] - CH_array[1]);	//ExR //old and wrong??
        cv::threshold(Mask,Mask,0, 255, cv::THRESH_BINARY+cv::THRESH_OTSU); //build binary Mask
        break;
    case ExG_Mask:        
        Mask = cv::Scalar::all(255)-Mask; //invertiert!!!
        break;
    case ExGR_Mask:        
        Mask = cv::Scalar::all(255)-Mask; //invertiert!!!
        break;
    default:
        break;
    }

    //--------------------------calc "total number of Pixel" for Histogram correction (calc hist counts also black Pixel of Mask)
    TotalNumberOfPixels = src.rows * src.cols;
    BlackPixel = TotalNumberOfPixels - cv::countNonZero(Mask);
    //----------------------------------------------------------------------------------------------------------------------------

    cv::cvtColor(src,ColSpace_img,cv::COLOR_BGR2HSV);
    cv::meanStdDev(ColSpace_img, Mean, StdDev, Mask);

    cv::cvtColor(Mask,imgResult,cv::COLOR_GRAY2BGR);
    cv::bitwise_and(src, imgResult, imgResult);
    cv::cvtColor(imgResult,imgResult,cv::COLOR_BGR2HSV);
    output.hist_plant_soil[2] = calc_histogram(imgResult, HSV, false, 0, BlackPixel);

    H_soil = Mean[0] + StdDev[0] * FilterSettings.Sigma;  //attention
    S_soil = Mean[1] + StdDev[1] * FilterSettings.Sigma;  //Values in Scale of 8 bit (0-255)
    V_soil = Mean[2] + StdDev[2] * FilterSettings.Sigma;  //instead of H(0-179) or H(1-360)

    output.thresh_HSV.mean_soil_H = Mean[0];
    output.thresh_HSV.mean_soil_S = Mean[1];
    output.thresh_HSV.mean_soil_V = Mean[2];
    output.thresh_HSV.stddev_soil_H = StdDev[0];
    output.thresh_HSV.stddev_soil_S = StdDev[1];
    output.thresh_HSV.stddev_soil_V = StdDev[2];
    output.thresh_HSV.quantil_soil_H = quantilMat(output.hist_plant_soil[2], 180, FilterSettings.soil_quantil);

    cv::cvtColor(src,ColSpace_img,cv::COLOR_BGR2Lab);
    cv::meanStdDev(ColSpace_img, Mean, StdDev, Mask);

    cv::cvtColor(Mask,imgResult,cv::COLOR_GRAY2BGR);
    cv::bitwise_and(src, imgResult, imgResult);
    cv::cvtColor(imgResult,imgResult,cv::COLOR_BGR2Lab);
    output.hist_plant_soil[3] = calc_histogram(imgResult, CieLab, false, 1, BlackPixel);

    L_soil = Mean[0] - StdDev[0] * FilterSettings.Sigma;  //attention
    a_soil = Mean[1] - StdDev[1] * FilterSettings.Sigma;  //Values in Scale of 8 bit (0-255)
    b_soil = Mean[2] - StdDev[2] * FilterSettings.Sigma;  //instead of L(0-100) a(-127-127) b(-127-127)

    output.thresh_Lab.mean_soil_L = Mean[0];
    output.thresh_Lab.mean_soil_a = Mean[1];
    output.thresh_Lab.mean_soil_b = Mean[2];
    output.thresh_Lab.stddev_soil_L = StdDev[0];
    output.thresh_Lab.stddev_soil_a = StdDev[1];
    output.thresh_Lab.stddev_soil_b = StdDev[2];
    output.thresh_Lab.quantil_soil_a = quantilMat(output.hist_plant_soil[3], 256, FilterSettings.soil_quantil);

    //----------Output---------------------------------
    switch (FilterSettings.AutoMethod)
    {

    case MeanStdDev_Filter:
        output.thresh_HSV.H = (H_plant + H_soil)/2;
        output.thresh_HSV.S = (S_plant + S_soil)/2;
        output.thresh_HSV.V = (V_plant + V_soil)/2;
        output.thresh_Lab.L = (L_plant + L_soil)/2;
        output.thresh_Lab.a = (a_plant + a_soil)/2;
        output.thresh_Lab.b = (b_plant + b_soil)/2;
        break;

    case Quantile_Filter:
        output.thresh_HSV.H = (output.thresh_HSV.quantil_plant_H + output.thresh_HSV.quantil_soil_H)/2;
        output.thresh_HSV.S = (S_plant + S_soil)/2;
        output.thresh_HSV.V = (V_plant + V_soil)/2;
        output.thresh_Lab.L = (L_plant + L_soil)/2;
        output.thresh_Lab.a = (output.thresh_Lab.quantil_plant_a + output.thresh_Lab.quantil_soil_a)/2;
        output.thresh_Lab.b = (b_plant + b_soil)/2;
        break;
    default:
        break;
    }

    return output;
}


double DPA_Image::quantilMat(cv::Mat hist, int nVals, double quantil)
{

    float numOfPix;
    for(int i=0; i<hist.rows; i++)
    {
        numOfPix += hist.at<float>(i);
    }

// COMPUTE CUMULATIVE DISTRIBUTION FUNCTION (CDF)------------------------------------
    cv::Mat cdf;
    hist.copyTo(cdf);
    for (int i = 1; i <= nVals-1; i++)
    {
        cdf.at<float>(i) += cdf.at<float>(i - 1);
    }

    cdf /= numOfPix;

// COMPUTE quantil-----------------------------------------------------------------------
    double quantilVal;
    for (int i = 0; i <= nVals-1; i++)
    {
        if (cdf.at<float>(i) >= quantil)
        {
            quantilVal = i;  break;
        }
    }
    return quantilVal;
}
