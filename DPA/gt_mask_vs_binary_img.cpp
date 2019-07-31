#include "gt_mask_vs_binary_img.h"
#include "ui_gt_mask_vs_binary_img.h"

GTMvsBimg::GTMvsBimg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GTMvsBimg)
{
    ui->setupUi(this);

    index_GT_Mask = 0;
    index_Binary_Img = 0;
    invert = false;

    QString tmpPath = QFileDialog::getOpenFileName(this, tr("Open GT_Mask Images"), "/home/driehle/Masterarbeit/MA-Datensatz", tr("Image Files (*.png *.jpg *.bmp *.tif)"));
    if(tmpPath != NULL)
    {
        GT_Mask_list.build_img_library(tmpPath,false,true);

        //add Image_Library to comboBox_img_list
        for(unsigned int i=0; i < GT_Mask_list.allImages.size(); i++)
        {
            //get index of the current loaded image
            if(tmpPath == QString::fromStdString(GT_Mask_list.allImages[i].ImagePath))
            {
                index_GT_Mask = i;
            }
        }
        ui->txtBrw_gtMask->setText(GT_Mask_list.allImages[index_GT_Mask].ImageName);

        tmpPath = QFileDialog::getOpenFileName(this, tr("Open Binary Images"), "/home/driehle/Masterarbeit/MA-Datensatz", tr("Image Files (*.png *.jpg *.bmp *.tif)"));
        if(tmpPath != NULL)
        {
            Binary_Img_list.build_img_library(tmpPath,false,true);

            //add Image_Library to comboBox_img_list
            for(unsigned int i=0; i < Binary_Img_list.allImages.size(); i++)
            {
                //get index of the current loaded image
                if(tmpPath == QString::fromStdString(Binary_Img_list.allImages[i].ImagePath))
                {
                    index_Binary_Img = i;
                }
            }
            ui->txtBrw_BinaryImg->setText(Binary_Img_list.allImages[index_Binary_Img].ImageName);

            getImages();
            showImages();
        }
    }

    if(GT_Mask_list.allImages.size() != Binary_Img_list.allImages.size())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, "Attention", "Numbers of Groundtruth-Masks and Binary-Result-Images are not the same!", QMessageBox::Ok);
    }
}

GTMvsBimg::~GTMvsBimg()
{
    delete ui;
}

const std::string GTMvsBimg::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d_%X", &tstruct);

    return buf;
}

std::string GTMvsBimg::Convert_float2string(float number)
{
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

void GTMvsBimg::on_btn_exit_clicked()
{
    this->close();
}

void GTMvsBimg::getImages()
{
    GT_Mask.readImage(QString::fromStdString(GT_Mask_list.allImages[index_GT_Mask].ImagePath));
    Binary_Img.readImage(QString::fromStdString(Binary_Img_list.allImages[index_Binary_Img].ImagePath));
}

cv::Mat GTMvsBimg::calcDifference(cv::Mat Img1, cv::Mat Img2, bool to_Less_Much)
{
    cv::Mat output;

    cv::cvtColor(Img1, Img1, cv::COLOR_RGB2GRAY);
    cv::cvtColor(Img2, Img2, cv::COLOR_RGB2GRAY);
    cv::threshold(Img1,Img1,0, 255, cv::THRESH_BINARY);
    cv::threshold(Img2,Img2,0, 255, cv::THRESH_BINARY);

    if(to_Less_Much){ output = Img1 - Img2; } //too less difference
    else{ output = Img2 - Img1; } //too much difference

    return output;
}

cv::Mat GTMvsBimg::addDiffToGTMask(cv::Mat ImgGTMask, cv::Mat ImgToLessDiff, cv::Mat ImgToMuchDiff)
{
    cv::Mat output;
    cv::Mat imgBlue, imgGreen, imgRed;

    cv::cvtColor(ImgGTMask, ImgGTMask, cv::COLOR_RGB2GRAY);
    cv::threshold(ImgGTMask,ImgGTMask,0, 255, cv::THRESH_BINARY);
    cv::cvtColor(ImgGTMask, ImgGTMask, cv::COLOR_GRAY2RGB);

    std::vector<cv::Mat> channels, combChannels;
    split(ImgGTMask, channels);

    imgBlue = channels[2]/2 + ImgToLessDiff;
    imgGreen = channels[1] - ImgToLessDiff;
    imgRed = channels[0]/2 + ImgToMuchDiff - ImgToLessDiff;

    combChannels.push_back(imgRed);
    combChannels.push_back(imgGreen);
    combChannels.push_back(imgBlue);

    cv::merge(combChannels, output);

    return output;

}

float GTMvsBimg::calcCoverage(cv::Mat Image, bool converted)
{
    if(converted != true)
    {
        cv::cvtColor(Image, Image, cv::COLOR_RGB2GRAY);
    }
    float TotalNumberOfPixels = Image.rows * Image.cols;
    float BlackPixel = TotalNumberOfPixels - countNonZero(Image);
    float WhitePixel = TotalNumberOfPixels - BlackPixel;


    return 100.0/TotalNumberOfPixels*WhitePixel;
}

void GTMvsBimg::showImages()
{
    cv::Mat img_GTMask, img_BinaryImg, img_difference;

//----GT_Mask----------------------------------------------------------------------------------

    img_GTMask = GT_Mask.get_OriginalImage();
    cv::cvtColor(img_GTMask, img_GTMask, cv::COLOR_BGR2RGB);

    if(invert)
    {
        cv::bitwise_not(img_GTMask,img_GTMask);
    }

    ui->lbl_gt_mask->setGeometry(10, 10, 480, 320);
    ui->lbl_gt_mask->setPixmap(QPixmap::fromImage(QImage(img_GTMask.data,img_GTMask.cols,img_GTMask.rows,img_GTMask.step,QImage::Format_RGB888))
                                   .scaled(ui->lbl_gt_mask->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_gt_mask->adjustSize();

//----Binary Image----------------------------------------------------------------------------------

    img_BinaryImg = Binary_Img.get_OriginalImage();
    cv::cvtColor(img_BinaryImg, img_BinaryImg, cv::COLOR_BGR2RGB);

    ui->lbl_binary_img->setGeometry(10, 10, 480, 320);
    ui->lbl_binary_img->setPixmap(QPixmap::fromImage(QImage(img_BinaryImg.data,img_BinaryImg.cols,img_BinaryImg.rows,img_BinaryImg.step,QImage::Format_RGB888))
                                   .scaled(ui->lbl_binary_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_binary_img->adjustSize();

//----Difference Result----------------------------------------------------------------------------------


    img_difference = addDiffToGTMask(img_GTMask, calcDifference(img_GTMask, img_BinaryImg, true), calcDifference(img_GTMask, img_BinaryImg, false));

    ui->lbl_diff_result->setGeometry(10, 10, 480, 320);
    ui->lbl_diff_result->setPixmap(QPixmap::fromImage(QImage(img_difference.data,img_difference.cols,img_difference.rows,img_difference.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_diff_result->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_diff_result->adjustSize();

//---------Result Values--------------------------------------------------------------------

    coverage_gtMask = calcCoverage(img_GTMask, false);
    ui->txtBrw_gtMask_result->setText("Coverage: " + QString::number(coverage_gtMask) + " %");

    coverage_binaryImg = calcCoverage(img_BinaryImg, false);
    ui->txtBrw_binaryImg_result->setText( "Coverage: " + QString::number(coverage_binaryImg) + " % \n");

    tooLess = calcCoverage(calcDifference(img_GTMask, img_BinaryImg, true), true);
    ui->txtBrw_binaryImg_result->append(  "too less: " + QString::number(tooLess) + " %");

    tooMuch = calcCoverage(calcDifference(img_GTMask, img_BinaryImg, false), true);
    ui->txtBrw_binaryImg_result->append(  "too much: " + QString::number(tooMuch) + " %");

//----Positions --------------------------------------------------------------------------

    //----- GT_Mask --------------------------------------------------------------------------

    ui->lbl_gt_mask->move(50,
                          50);

    //----- Difference Result--------------------------------------------------------------------------

    ui->lbl_diff_result->move(ui->lbl_gt_mask->pos().x() + ui->lbl_gt_mask->width() + 5,
                              ui->lbl_gt_mask->pos().y());

    //----- Binary Image --------------------------------------------------------------------------

    ui->lbl_binary_img->move(ui->lbl_diff_result->pos().x() + ui->lbl_diff_result->width() + 5,
                             ui->lbl_diff_result->pos().y());

//----Position Buttons--------------------------------------------------------------------

    ui->groupBox->move(ui->lbl_diff_result->pos().x() + ui->lbl_diff_result->size().width() / 2 - ui->groupBox->width() / 2,
                       ui->lbl_diff_result->pos().y()+ui->lbl_diff_result->size().height() + 5);

    ui->lbl_text_2->move(ui->lbl_gt_mask->pos().x() + ui->lbl_gt_mask->size().width() / 2 - ui->lbl_text_2->width() / 2,
                         ui->lbl_gt_mask->pos().y()-ui->lbl_text_2->size().height());

    ui->lbl_text_4->move(ui->lbl_diff_result->pos().x() + ui->lbl_diff_result->size().width() / 2 - ui->lbl_text_4->width() / 2,
                         ui->lbl_diff_result->pos().y()-ui->lbl_text_4->size().height());

    ui->lbl_text_3->move(ui->lbl_binary_img->pos().x() + ui->lbl_binary_img->size().width() / 2 - ui->lbl_text_3->width() / 2,
                         ui->lbl_binary_img->pos().y()-ui->lbl_text_3->size().height());

    this->adjustSize();

    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
}

void GTMvsBimg::on_btn_next_clicked()
{
    if(index_GT_Mask < GT_Mask_list.allImages.size()-1 && index_Binary_Img < Binary_Img_list.allImages.size()-1) // -1 cause imgIndex is starting from 0, Size ist starting from 1
    {
        index_GT_Mask++;
        ui->txtBrw_gtMask->setText(GT_Mask_list.allImages[index_GT_Mask].ImageName);

        index_Binary_Img++;
        ui->txtBrw_BinaryImg->setText(Binary_Img_list.allImages[index_Binary_Img].ImageName);
    }

    getImages();
    showImages();
}

void GTMvsBimg::on_btn_back_clicked()
{  
    if(index_GT_Mask > 0 && index_Binary_Img  > 0)
    {
        index_GT_Mask--;
        ui->txtBrw_gtMask->setText(GT_Mask_list.allImages[index_GT_Mask].ImageName);

        index_Binary_Img--;
        ui->txtBrw_BinaryImg->setText(Binary_Img_list.allImages[index_Binary_Img].ImageName);
    }

    getImages();
    showImages();
}

void GTMvsBimg::on_chkB_invert_clicked(bool checked)
{
    invert = checked;

    getImages();
    showImages();
}
void GTMvsBimg::on_btn_save_csv_clicked()
{
    if(GT_Mask_list.allImages.size() == Binary_Img_list.allImages.size())
    {
        cv::Mat img_GTMask, img_BinaryImg;

        QString targetFolder;

        targetFolder = (QFileDialog::getExistingDirectory(this, tr("Save to Directory..."),
                                                                 "/home/driehle/Masterarbeit/MA-Datensatz",
                                                                 QFileDialog::ShowDirsOnly
                                                                 | QFileDialog::DontResolveSymlinks));

        std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_gtMask_vs_BinaryImg" +".csv";//_" + currentDateTime() +".csv";
        csv_file.open(csv_file_name.c_str());
        csv_file << "gt_mask_name; binary_img_name; gt_mask; binary_img; too_less; too_much \n";


        for(int i=0; i<GT_Mask_list.allImages.size(); i++)
        {
            index_GT_Mask = i;
            index_Binary_Img = i;
            getImages();

            csv_file << GT_Mask_list.allImages[index_GT_Mask].ImageName.toStdString() + ";";
            csv_file << Binary_Img_list.allImages[index_Binary_Img].ImageName.toStdString() + ";";

            img_GTMask = GT_Mask.get_OriginalImage();
            cv::cvtColor(img_GTMask, img_GTMask, cv::COLOR_BGR2RGB);
            if(invert){ cv::bitwise_not(img_GTMask,img_GTMask); }

            img_BinaryImg = Binary_Img.get_OriginalImage();
            cv::cvtColor(img_BinaryImg, img_BinaryImg, cv::COLOR_BGR2RGB);

            csv_file << Convert_float2string(calcCoverage(img_GTMask, false)) + ";";
            csv_file << Convert_float2string(calcCoverage(img_BinaryImg, false)) + ";";
            csv_file << Convert_float2string(calcCoverage(calcDifference(img_GTMask, img_BinaryImg, true), true)) + ";";
            csv_file << Convert_float2string(calcCoverage(calcDifference(img_GTMask, img_BinaryImg, false), true)) + "\n";
        }

        csv_file.close();
    }
}
