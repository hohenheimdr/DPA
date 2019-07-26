#include "development.h"
#include "ui_development.h"

Development::Development(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Development)
{
    ui->setupUi(this);

    index_n1 = 0;
    index_n2 = 1;
}

Development::~Development()
{
    delete ui;
}

void Development::on_btn_exit_clicked()
{
    this->close();
}

void Development::setImageLibrary(Image_Library &ImageLibrary)
{
    img_list = ImageLibrary;

    for(unsigned int i=0; i < img_list.allImages.size(); i++)
    {
        ui->comboBox_start_Date->addItem(img_list.allImages[i].ImageDate.toString() + "   " + img_list.allImages[i].ImageName);
        ui->comboBox_end_Date->addItem(img_list.allImages[i].ImageDate.toString() + "   " + img_list.allImages[i].ImageName);
    }

    ui->comboBox_start_Date->setCurrentIndex(0);
    ui->comboBox_end_Date->setCurrentIndex(1);

    getImages();
    showImages();
}

void Development::getImages()
{
    Img_n1.readImage(QString::fromStdString(img_list.allImages[index_n1].ImagePath));
    Img_n1.rotateImg(config::ImgEditing.rotate.angle);
    Img_n1.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);

    Img_n2.readImage(QString::fromStdString(img_list.allImages[index_n2].ImagePath));
    Img_n2.rotateImg(config::ImgEditing.rotate.angle);
    Img_n2.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);
}

cv::Mat Development::calcDeltaGreen(cv::Mat& Green1, cv::Mat& Green2)
{
    cv::Mat deltaGreen;

    if(ui->chkBox_inc_dec->isChecked())
    {
        deltaGreen = Green2 - Green1;
    }
    else
    {
        deltaGreen = Green1 - Green2;
    }

    return deltaGreen;
}

void Development::showImages()
{
    cv::Mat img_grey1, img_grey2, img_rgb;

//----Gn1---------------------------------------------------------------------------------

    img_grey1 = Img_n1.get_Image_Values(config::ExG.Method, config::ExG.Threshold, config::ExG.Threshold_Value, false).Grey;

    ui->lbl_Gn1->setGeometry(10, 10, 480, 320);
    cv::cvtColor(img_grey1, img_rgb, cv::COLOR_BGR2RGB);
    ui->lbl_Gn1->setPixmap(QPixmap::fromImage(QImage(img_rgb.data,img_rgb.cols,img_rgb.rows,img_rgb.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_Gn1->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_Gn1->adjustSize();

//----Gn2---------------------------------------------------------------------------------

    img_grey2 = Img_n2.get_Image_Values(config::ExG.Method, config::ExG.Threshold, config::ExG.Threshold_Value, false).Grey;

    ui->lbl_Gn2->setGeometry(10, 10, 480, 320);
    cv::cvtColor(img_grey2, img_rgb, cv::COLOR_BGR2RGB);
    ui->lbl_Gn2->setPixmap(QPixmap::fromImage(QImage(img_rgb.data,img_rgb.cols,img_rgb.rows,img_rgb.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_Gn2->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_Gn2->adjustSize();

//----dG----------------------------------------------------------------------------------

    img_rgb = calcDeltaGreen(img_grey1, img_grey2);
    cv::cvtColor(img_rgb, img_rgb, cv::COLOR_BGR2RGB);

    ui->lbl_dG->setGeometry(10, 10, 480, 320);
    ui->lbl_dG->setPixmap(QPixmap::fromImage(QImage(img_rgb.data,img_rgb.cols,img_rgb.rows,img_rgb.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_dG->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_dG->adjustSize();

//----img Start----------------------------------------------------------------------------------

    img_rgb = Img_n1.get_OriginalImage();
    cv::cvtColor(img_rgb, img_rgb, cv::COLOR_BGR2RGB);

    ui->lbl_img_start->setGeometry(10, 10, 480, 320);
    ui->lbl_img_start->setPixmap(QPixmap::fromImage(QImage(img_rgb.data,img_rgb.cols,img_rgb.rows,img_rgb.step,QImage::Format_RGB888))
                                   .scaled(ui->lbl_img_start->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_img_start->adjustSize();

//----img End----------------------------------------------------------------------------------

    img_rgb = Img_n2.get_OriginalImage();
    cv::cvtColor(img_rgb, img_rgb, cv::COLOR_BGR2RGB);

    ui->lbl_img_end->setGeometry(10, 10, 480, 320);
    ui->lbl_img_end->setPixmap(QPixmap::fromImage(QImage(img_rgb.data,img_rgb.cols,img_rgb.rows,img_rgb.step,QImage::Format_RGB888))
                                   .scaled(ui->lbl_img_end->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_img_end->adjustSize();

//----Img End + dG----------------------------------------------------------------------------------

    img_rgb = addChangeToOrg(Img_n2.get_OriginalImage(), calcDeltaGreen(img_grey1, img_grey2));
    cv::cvtColor(img_rgb, img_rgb, cv::COLOR_BGR2RGB);

    ui->lbl_img_end_dg->setGeometry(10, 10, 480, 320);
    ui->lbl_img_end_dg->setPixmap(QPixmap::fromImage(QImage(img_rgb.data,img_rgb.cols,img_rgb.rows,img_rgb.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_img_end_dg->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_img_end_dg->adjustSize();

//----Positions --------------------------------------------------------------------------

    //----- Gn1 --------------------------------------------------------------------------

    ui->lbl_Gn1->move(10,
                      10);

    //----- dG  --------------------------------------------------------------------------

    ui->lbl_dG->move(ui->lbl_Gn1->pos().x() + ui->lbl_Gn1->width() + 5,
                      ui->lbl_Gn1->pos().y());

    //----- Gn2 --------------------------------------------------------------------------

    ui->lbl_Gn2->move(ui->lbl_dG->pos().x() + ui->lbl_dG->width() + 5,
                      ui->lbl_dG->pos().y());

    //----- Img Start --------------------------------------------------------------------------

    ui->lbl_img_start->move(ui->lbl_Gn1->pos().x(),
                      ui->lbl_Gn1->pos().y()+ui->lbl_Gn1->size().height() + 5);

    //----- Img End --------------------------------------------------------------------------

    ui->lbl_img_end->move(ui->lbl_Gn2->pos().x(),
                      ui->lbl_Gn2->pos().y()+ui->lbl_Gn2->size().height() + 5);

    //----- Img End + dG--------------------------------------------------------------------------

    ui->lbl_img_end_dg->move(ui->lbl_dG->pos().x(),
                             ui->lbl_dG->pos().y()+ui->lbl_dG->size().height() + 5);

//----Position Buttons--------------------------------------------------------------------

    this->adjustSize();

    ui->groupBox->move(this->size().width() / 2 - ui->groupBox->width() / 2,
                       ui->lbl_img_end_dg->pos().y()+ui->lbl_img_end_dg->size().height() + 5);

    ui->chkBox_inc_dec->move(ui->groupBox->pos().x()+ui->groupBox->size().width() + 10,
                       ui->groupBox->pos().y() + ui->groupBox->size().height() /2);

//----Set Text on Label----------------------------------------------------------------------------

    ui->lbl_info_1->setText(QString::number(index_n1+1) + " to " + QString::number(index_n2+1));
    ui->lbl_info_2->setText(QString::number(img_list.allImages.size()) + " Images");

    this->adjustSize();

    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
}

void Development::on_btn_next_clicked()
{
    if(index_n2 < img_list.allImages.size()-2) // -1 cause imgIndex is starting from 0, Size ist starting from 1
    {
        index_n1++;
        ui->comboBox_start_Date->setCurrentIndex(index_n1);

        index_n2++;
        ui->comboBox_end_Date->setCurrentIndex(index_n2);
    }

    getImages();
    showImages();    
}

void Development::on_btn_back_clicked()
{  
    if(index_n1 > 1)
    {
        index_n1--;
        ui->comboBox_start_Date->setCurrentIndex(index_n1);

        index_n2--;
        ui->comboBox_end_Date->setCurrentIndex(index_n2);
    }

    getImages();
    showImages();
}

cv::Mat Development::addChangeToOrg(cv::Mat ImageEnd, cv::Mat ImgDeltaGreen)
{
    cv::Mat imgBlue, imgGreen, imgRed, imgResult;

    std::vector<cv::Mat> channels, combChannels;
    split(ImageEnd, channels);

    imgBlue = channels [0];
    imgGreen = channels [1];
    imgRed = channels [2];

    cv::cvtColor(ImgDeltaGreen, ImgDeltaGreen, cv::COLOR_BGR2GRAY);

    imgRed += (ImgDeltaGreen*2);

    combChannels.push_back(imgBlue);
    combChannels.push_back(imgGreen);
    combChannels.push_back(imgRed);

    cv::merge(combChannels, imgResult);

    return imgResult;

}

void Development::on_comboBox_start_Date_currentIndexChanged(int index)
{
    index_n1 = index;
    getImages();
    showImages();
}

void Development::on_comboBox_end_Date_currentIndexChanged(int index)
{
    index_n2 = index;
    getImages();
    showImages();
}

void Development::on_chkBox_inc_dec_clicked()
{
    getImages();
    showImages();
}
