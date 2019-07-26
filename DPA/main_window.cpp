#include "main_window.h"
#include "ui_main_window.h"

main_window::main_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_window)
{
    ui->setupUi(this);

    //--------------Fullscreen Image---QWidget------------------------------------------------
    scrollarea = new QScrollArea;
    central = new QWidget;
    zoom_img = new QLabel(central);
    scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollarea->setWidgetResizable(true);
    scrollarea->setWidget(zoom_img);
    scrollarea->setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint); //No Close-Button in the Window_Title_Bar

    scrollarea->setGeometry(this->geometry());
    //--------------Fullscreen Image---QWidget-------------------------end--------------------

    indexOfCurrentImage = 0;

    ui->sBox_exg_man_thresh->hide();
    ui->sBox_exr_man_thresh->hide();
    ui->sBox_exgr_man_thresh->hide();
    ui->lbl_exg_thresh_range->hide();
    ui->lbl_exr_thresh_range->hide();
    ui->lbl_exgr_thresh_range->hide();
    ui->lbl_filter_h_l->setText("H");
    ui->lbl_filter_s_a->setText("S");
    ui->lbl_filter_v_b->setText("V");
    ui->btn_reset->hide();
    ui->btn_edit_image->hide();
    ui->btn_save->hide();
    ui->btn_development->hide();
    ui->comboBox_img_list->hide();
    ui->btn_back->hide();
    ui->btn_next->hide();
    ui->label_2->hide();

    ui->txtBrw_min1->hide();
    ui->txtBrw_min2->hide();
    ui->txtBrw_min3->hide();
    ui->txtBrw_max1->hide();
    ui->txtBrw_max2->hide();
    ui->txtBrw_max3->hide();

    ui->tabWidget_main->setTabEnabled(1 , false);   //tab_info
    ui->tabWidget_main->setTabEnabled(2 , false);   //tab_hist
    ui->tabWidget_main->setTabEnabled(3 , false);   //tab_exg
    ui->tabWidget_main->setTabEnabled(4 , false);   //tab_exr
    ui->tabWidget_main->setTabEnabled(5 , false);   //tab_exgr
    ui->tabWidget_main->setTabEnabled(6 , false);   //tab_filter


//------------define config--------------------------

    config::ExG.Threshold = DPA_Image::PositivThresh;
    config::ExG.Threshold_Value = 0;
    config::ExR.Threshold = DPA_Image::PositivThresh;
    config::ExR.Threshold_Value = 0;
    config::ExGR.Threshold = DPA_Image::PositivThresh;
    config::ExGR.Threshold_Value = 0;
    config::Filter.ColorSpace = DPA_Image::HSV;
    config::Filter.ColorChangeType = DPA_Image::addNon;
    config::Filter.max1 = 255;
    config::Filter.max2 = 255;
    config::Filter.max3 = 255;
    config::Filter.min1 = 0;
    config::Filter.min2 = 0;
    config::Filter.min3 = 0;
    config::Filter.FilterSettings.AutoMethod = DPA_Image::MeanStdDev_Filter;
    config::Filter.FilterSettings.MaskMethod = DPA_Image::ExG_ExR_Mask;
    config::Filter.FilterSettings.plant_quantil = 0.5;
    config::Filter.FilterSettings.soil_quantil = 0.5;
    config::Filter.FilterSettings.Sigma = 1;
    config::ImgEditing.crop.x = 0;
    config::ImgEditing.crop.y = 0;
    config::ImgEditing.crop.width = 0;
    config::ImgEditing.crop.height = 0;
    config::ImgEditing.edited = false;
    config::ImgEditing.rotate.angle = 0;
}

main_window::~main_window()
{
    delete ui;
}

//------------ General Buttons-------------------------- -----------------------------------------------

void main_window::on_btn_Quit_clicked()
{
    exit(-2);
}

void main_window::on_btn_OpenImage_clicked()
{
   QString tmpPath = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                                    "/home/driehle/Masterarbeit/MA-Datensatz", tr("Image Files (*.png *.jpg *.bmp *.tif)"));

    if(tmpPath != NULL)
    {
        QMessageBox::StandardButton reply;
        bool Subfolder = false;
        bool SingleImage = true;

        reply = QMessageBox::question(this, "Single Image?", "Would you like to load all images in this folder?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            SingleImage = false;

            reply = QMessageBox::question(this, "loading images", "Would you like to include subfolders?", QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes){Subfolder = true;}
        }

        img_list.build_img_library(tmpPath, SingleImage, Subfolder);

        ImgSample1.readImage(tmpPath);

        config::ImgEditing.crop.width = ImgSample1.get_OriginalImage().cols;
        config::ImgEditing.crop.height = ImgSample1.get_OriginalImage().rows;

        for(int i=ui->comboBox_img_list->count(); i>0; i--)
        {
            ui->comboBox_img_list->removeItem(i);
        }
        //add Image_Library to comboBox_img_list
        ui->comboBox_img_list->setItemText(0,img_list.allImages[0].ImageDate.toString() + "   " + img_list.allImages[0].ImageName);

        for(unsigned int i=1; i < img_list.allImages.size(); i++)
        {
            ui->comboBox_img_list->addItem(img_list.allImages[i].ImageDate.toString() + "   " + img_list.allImages[i].ImageName);

            //get index of the current loaded image
            if(tmpPath == QString::fromStdString(img_list.allImages[i].ImagePath))
            {
                indexOfCurrentImage = i;
            }
        }

        ui->comboBox_img_list->setCurrentIndex(indexOfCurrentImage);

        get_ALL_by_tab();

        ui->btn_edit_image->show();
        ui->btn_save->show();
        //ui->btn_development->show();
        ui->comboBox_img_list->show();
        ui->btn_back->show();
        ui->btn_next->show();
        ui->tabWidget_main->setTabEnabled(1 , true);   //tab_info
        ui->tabWidget_main->setTabEnabled(2 , true);   //tab_hist
        ui->tabWidget_main->setTabEnabled(3 , true);   //tab_exg
        ui->tabWidget_main->setTabEnabled(4 , true);   //tab_exr
        ui->tabWidget_main->setTabEnabled(5 , true);   //tab_exgr
        ui->tabWidget_main->setTabEnabled(6 , true);   //tab_filter
    }
}

void main_window::on_comboBox_img_list_currentIndexChanged(int index)
{
    indexOfCurrentImage = index;

    ImgSample1.readImage(QString::fromStdString(img_list.allImages[indexOfCurrentImage].ImagePath));

    if(config::ImgEditing.edited == true)
    {
        ImgSample1.rotateImg(config::ImgEditing.rotate.angle);
        ImgSample1.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);
    }

    get_ALL_by_tab();
}

void main_window::on_btn_next_clicked()
{
    if(indexOfCurrentImage < img_list.allImages.size()-1) // -1 cause imgIndex is starting from 0, Size ist starting from 1
    {
        indexOfCurrentImage++;
        ui->comboBox_img_list->setCurrentIndex(indexOfCurrentImage);
    }
}

void main_window::on_btn_back_clicked()
{
    if(indexOfCurrentImage > 0)
    {
        indexOfCurrentImage--;
        ui->comboBox_img_list->setCurrentIndex(indexOfCurrentImage);
    }
}


void main_window::on_btn_edit_image_clicked()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::information(this, "Attention", "If you want to edit images, make sure they are all the same size. Otherwise, cropping will not fit all images!", QMessageBox::Ok);

    editImage = new EditImage();
    editImage->setImagePath(QString::fromStdString(img_list.allImages[indexOfCurrentImage].ImagePath));
    editImage->exec();

    config::ImgEditing.edited = true;

    ImgSample1.readImage(QString::fromStdString(img_list.allImages[indexOfCurrentImage].ImagePath));
    ImgSample1.rotateImg(config::ImgEditing.rotate.angle);
    ImgSample1.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);

    get_ALL_by_tab();

    ui->btn_edit_image->hide();
    ui->btn_reset->show();
}

void main_window::on_btn_reset_clicked()
{
   ImgSample1.readImage(QString::fromStdString(img_list.allImages[indexOfCurrentImage].ImagePath));

    config::ImgEditing.edited = false;
    config::ImgEditing.crop.x = 0;
    config::ImgEditing.crop.y = 0;
    config::ImgEditing.crop.width = ImgSample1.get_OriginalImage().cols;
    config::ImgEditing.crop.height = ImgSample1.get_OriginalImage().rows;
    config::ImgEditing.rotate.angle = 0;

    get_ALL_by_tab();

    ui->btn_edit_image->show();
    ui->btn_reset->hide();
}

void main_window::on_btn_save_clicked()
{
    savewindow = new save_window();
    savewindow->setImageLibrary(img_list, indexOfCurrentImage);
    savewindow->adjustSize();
    savewindow->move(QApplication::desktop()->screen()->rect().center() - savewindow->rect().center());
    savewindow->exec();
}

void main_window::on_btn_development_clicked()
{
    development = new Development();
    development->setImageLibrary(img_list);
    development->adjustSize();
    development->move(QApplication::desktop()->screen()->rect().center() - development->rect().center());
    development->exec();
}

void main_window::on_btn_gtMask_vs_binaryImg_clicked()
{
    GTMask_vs_BinaryImg = new GTMvsBimg();
    GTMask_vs_BinaryImg->move(QApplication::desktop()->screen()->rect().center() - GTMask_vs_BinaryImg->rect().center());
    GTMask_vs_BinaryImg->exec();
}

void main_window::on_btn_Analyse_BinaryImg_clicked()
{
    analyse_binary_img = new Analyse_Binary_Img();
    analyse_binary_img->move(QApplication::desktop()->screen()->rect().center() - analyse_binary_img->rect().center());
    analyse_binary_img->exec();
}

//------------ General Functions-------------------------- -----------------------------------------------

void main_window::get_ALL_by_tab()
{
    switch (ui->tabWidget_main->currentIndex())
    {
    case 0: get_orignal_image();    break;
    case 1:                         break;
    case 2: get_histogram();        break;
    case 3: get_exg_data();         break;
    case 4: get_exr_data();         break;
    case 5: get_exgr_data();        break;
    case 6: get_filter_data();      break;
    default:                        break;
    }
}

void main_window::get_orignal_image()
{
    cv::Mat img;

    img = ImgSample1.get_OriginalImage();
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    ui->lbl_org_img->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_org_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_org_img_1->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_org_img_1->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_org_img_2->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                                 .scaled(ui->lbl_org_img_2->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_org_img_3->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                                 .scaled(ui->lbl_org_img_2->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->lbl_org_img_4->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                                 .scaled(ui->lbl_org_img_2->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));


    ui->txtBrw_Info->setText("Image Name: " + img_list.allImages[indexOfCurrentImage].ImageName + "\n");
    ui->txtBrw_Info->append( "Image Type: " + img_list.allImages[indexOfCurrentImage].ImageType + "\n");
    ui->txtBrw_Info->append( "Image Path: " + QString::fromStdString(img_list.allImages[indexOfCurrentImage].ImagePath) + "\n");
    ui->txtBrw_Info->append( "Last Modification: " + img_list.allImages[indexOfCurrentImage].LastModified.toString());
}

void main_window::get_exg_data()
{
    DPA_Image::ImageValues imgValues;

    imgValues = ImgSample1.get_Image_Values(config::ExG.Method, config::ExG.Threshold, config::ExG.Threshold_Value, ui->chkB_exg_invert->isChecked());

    cv::cvtColor(imgValues.Grey, imgValues.Grey, cv::COLOR_BGR2RGB);
    ui->lbl_exg_grey_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Grey.data,imgValues.Grey.cols,imgValues.Grey.rows,imgValues.Grey.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_exg_grey_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Binary, imgValues.Binary, cv::COLOR_BGR2RGB);
    ui->lbl_exg_binary_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Binary.data,imgValues.Binary.cols,imgValues.Binary.rows,imgValues.Binary.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_exg_binary_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Color, imgValues.Color, cv::COLOR_BGR2RGB);
    ui->lbl_exg_color_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Color.data,imgValues.Color.cols,imgValues.Color.rows,imgValues.Color.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_exg_color_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    ui->txtBrw_ExG->setText("coverage: " + QString::number(imgValues.Coverage) + " %");
    ui->txtBrw_ExG->append( "soil:    " + QString::number(imgValues.Soil) + " %");
    ui->txtBrw_ExG->append( "gray_mean:    " + QString::number(imgValues.Mean));
    ui->txtBrw_ExG->append( "rel. luminance: " + QString::number(imgValues.rel_luminance));
    ui->txtBrw_ExG->append( "L luminance: " + QString::number(imgValues.L_luminance));
}

void main_window::get_exr_data()
{
    DPA_Image::ImageValues imgValues;

    imgValues = ImgSample1.get_Image_Values(config::ExR.Method, config::ExR.Threshold, config::ExR.Threshold_Value, ui->chkB_exr_invert->isChecked());

    cv::cvtColor(imgValues.Grey, imgValues.Grey, cv::COLOR_BGR2RGB);
    ui->lbl_exr_grey_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Grey.data,imgValues.Grey.cols,imgValues.Grey.rows,imgValues.Grey.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_exr_grey_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Binary, imgValues.Binary, cv::COLOR_BGR2RGB);
    ui->lbl_exr_binary_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Binary.data,imgValues.Binary.cols,imgValues.Binary.rows,imgValues.Binary.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_exr_binary_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Color, imgValues.Color, cv::COLOR_BGR2RGB);
    ui->lbl_exr_color_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Color.data,imgValues.Color.cols,imgValues.Color.rows,imgValues.Color.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_exr_color_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    ui->txtBrw_ExR->setText("soil:     " + QString::number(imgValues.Coverage) + " %");
    ui->txtBrw_ExR->append( "coverage: " + QString::number(imgValues.Soil) + " %");
    ui->txtBrw_ExR->append( "gray_mean:     " + QString::number(imgValues.Mean));
    ui->txtBrw_ExR->append( "rel. luminance: " + QString::number(imgValues.rel_luminance));
    ui->txtBrw_ExR->append( "L luminance: " + QString::number(imgValues.L_luminance));
}

void main_window::get_exgr_data()
{
    DPA_Image::ImageValues imgValues;

    imgValues = ImgSample1.get_Image_Values(config::ExGR.Method, config::ExGR.Threshold, config::ExGR.Threshold_Value, ui->chkB_exgr_invert->isChecked());

    cv::cvtColor(imgValues.Grey, imgValues.Grey, cv::COLOR_BGR2RGB);
    ui->lbl_exgr_grey_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Grey.data,imgValues.Grey.cols,imgValues.Grey.rows,imgValues.Grey.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_exgr_grey_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Binary, imgValues.Binary, cv::COLOR_BGR2RGB);
    ui->lbl_exgr_binary_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Binary.data,imgValues.Binary.cols,imgValues.Binary.rows,imgValues.Binary.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_exgr_binary_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Color, imgValues.Color, cv::COLOR_BGR2RGB);
    ui->lbl_exgr_color_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Color.data,imgValues.Color.cols,imgValues.Color.rows,imgValues.Color.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_exgr_color_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    ui->txtBrw_ExGR->setText("coverage: " + QString::number(imgValues.Coverage) + " %");
    ui->txtBrw_ExGR->append( "soil:    " + QString::number(imgValues.Soil) + " %");
    ui->txtBrw_ExGR->append( "gray_mean:    " + QString::number(imgValues.Mean));
    ui->txtBrw_ExGR->append( "rel. luminance: " + QString::number(imgValues.rel_luminance));
    ui->txtBrw_ExGR->append( "L luminance: " + QString::number(imgValues.L_luminance));
}

void main_window::get_filter_data()
{
    DPA_Image::ImageValues imgValues;

    if(ui->rdbtn_auto_filter_on->isChecked())
    {
        get_auto_filter();
        imgValues = ImgSample1.get_Image_Values(config::Filter.ColorSpace,
                                            config::Filter.FilterSettings,
                                            config::Filter.ColorChangeType,
                                            ui->chkB_filter_invert->isChecked());
    }else
    {
        imgValues = ImgSample1.get_Image_Values(config::Filter.ColorSpace,
                                            config::Filter.min1, config::Filter.max1,
                                            config::Filter.min2, config::Filter.max2,
                                            config::Filter.min3, config::Filter.max3,
                                            config::Filter.ColorChangeType,
                                            ui->chkB_filter_invert->isChecked());
    }



    cv::cvtColor(imgValues.Grey, imgValues.Grey, cv::COLOR_BGR2RGB);
    ui->lbl_filter_processedColor_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Grey.data,imgValues.Grey.cols,imgValues.Grey.rows,imgValues.Grey.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_filter_processedColor_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Binary, imgValues.Binary, cv::COLOR_BGR2RGB);
    ui->lbl_filter_binary_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Binary.data,imgValues.Binary.cols,imgValues.Binary.rows,imgValues.Binary.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_filter_binary_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    cv::cvtColor(imgValues.Color, imgValues.Color, cv::COLOR_BGR2RGB);
    ui->lbl_filter_color_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Color.data,imgValues.Color.cols,imgValues.Color.rows,imgValues.Color.step,QImage::Format_RGB888))
                               .scaled(ui->lbl_filter_color_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    ui->txtBrw_filter->setText("Black Pixels: " + QString::number(imgValues.Soil) + " %");
    ui->txtBrw_filter->append( "Rest:    " + QString::number(imgValues.Coverage) + " %");
    ui->txtBrw_filter->append( "rel. luminance: " + QString::number(imgValues.rel_luminance));
    ui->txtBrw_filter->append( "L luminance: " + QString::number(imgValues.L_luminance));

    if(ui->chkB_zoom_filter->isChecked())
    {
        zoom_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Color.data,imgValues.Color.cols,imgValues.Color.rows,imgValues.Color.step,QImage::Format_RGB888)));
    }

}

void main_window::get_histogram()
{
    cv::Mat tempImg;

    tempImg = ImgSample1.get_HistOfColor_HSV();

    cv::cvtColor(tempImg, tempImg, cv::COLOR_BGR2RGB);
    ui->lbl_hist_hue_img->setPixmap(QPixmap::fromImage(QImage(tempImg.data,tempImg.cols,tempImg.rows,tempImg.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_hist_hue_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    //----------CieLab "L"-------------------------------------------------------------
    tempImg = ImgSample1.get_HistOfColor_Lab(0);

    cv::cvtColor(tempImg, tempImg, cv::COLOR_BGR2RGB);
    ui->lbl_hist_L_img->setPixmap(QPixmap::fromImage(QImage(tempImg.data,tempImg.cols,tempImg.rows,tempImg.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_hist_hue_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    //----------CieLab "a"-------------------------------------------------------------
    tempImg = ImgSample1.get_HistOfColor_Lab(1);

    cv::cvtColor(tempImg, tempImg, cv::COLOR_BGR2RGB);
    ui->lbl_hist_a_img->setPixmap(QPixmap::fromImage(QImage(tempImg.data,tempImg.cols,tempImg.rows,tempImg.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_hist_hue_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    //----------CieLab "b"-------------------------------------------------------------
    tempImg = ImgSample1.get_HistOfColor_Lab(2);

    cv::cvtColor(tempImg, tempImg, cv::COLOR_BGR2RGB);
    ui->lbl_hist_b_img->setPixmap(QPixmap::fromImage(QImage(tempImg.data,tempImg.cols,tempImg.rows,tempImg.step,QImage::Format_RGB888))
                           .scaled(ui->lbl_hist_hue_img->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

qreal main_window::trans_opacity(int value)
{
    qreal opacity;

    switch(value)
    {
        case 10: opacity = 0.0;  break;
        case 9: opacity = 0.1;  break;
        case 8: opacity = 0.2;  break;
        case 7: opacity = 0.3;  break;
        case 6: opacity = 0.4;  break;
        case 5: opacity = 0.5;  break;
        case 4: opacity = 0.6;  break;
        case 3: opacity = 0.7;  break;
        case 2: opacity = 0.8;  break;
        case 1: opacity = 0.9;  break;
        case 0: opacity = 1.0; break;
    }
    return opacity;
}

//--------- Individual Funktions & Write Settings to Config (Global Variable)---------------------

///-------- ExG --------------------------------------------------------------------

void main_window::on_rdbtn_exg_positiv_clicked()
{   
    config::ExG.Threshold = DPA_Image::PositivThresh;
    get_exg_data();
}

void main_window::on_rdbtn_exg_otsu_clicked()
{
    config::ExG.Threshold = DPA_Image::OtsuThresh;
    get_exg_data();
}

void main_window::on_rdbtn_exg_manual_clicked()
{
    config::ExG.Threshold = DPA_Image::ManualThresh;
    get_exg_data();
}

void main_window::on_sBox_exg_man_thresh_valueChanged(int arg1)
{
    config::ExG.Threshold_Value = arg1;
    get_exg_data();
}

void main_window::on_chkB_exg_invert_clicked()
{
    get_exg_data();
}

void main_window::on_slider_opacity_exg_valueChanged(int value)
{
    QGraphicsOpacityEffect *effect_opacity = new QGraphicsOpacityEffect;
    ui->lbl_exg_binary_img->setGraphicsEffect(effect_opacity);

    effect_opacity->setOpacity(trans_opacity(value));
}

///-------- ExR --------------------------------------------------------------------

void main_window::on_rdbtn_exr_positiv_clicked()
{
    config::ExR.Threshold = DPA_Image::PositivThresh;
    get_exr_data();
}

void main_window::on_rdbtn_exr_otsu_clicked()
{
    config::ExR.Threshold = DPA_Image::OtsuThresh;
    get_exr_data();
}

void main_window::on_rdbtn_exr_manual_clicked()
{
    config::ExR.Threshold = DPA_Image::ManualThresh;
    get_exr_data();
}

void main_window::on_sBox_exr_man_thresh_valueChanged(int arg1)
{
    config::ExR.Threshold_Value = arg1;
    get_exr_data();
}

void main_window::on_chkB_exr_invert_clicked()
{
    get_exr_data();
}

void main_window::on_slider_opacity_exr_valueChanged(int value)
{
    QGraphicsOpacityEffect *effect_opacity = new QGraphicsOpacityEffect;
    ui->lbl_exr_binary_img->setGraphicsEffect(effect_opacity);

    effect_opacity->setOpacity(trans_opacity(value));
}

///-------- ExGR --------------------------------------------------------------------

void main_window::on_rdbtn_exgr_positiv_clicked()
{
    config::ExGR.Threshold = DPA_Image::PositivThresh;
    get_exgr_data();
}

void main_window::on_rdbtn_exgr_otsu_clicked()
{
    config::ExGR.Threshold = DPA_Image::OtsuThresh;
    get_exgr_data();
}

void main_window::on_rdbtn_exgr_manual_clicked()
{
    config::ExGR.Threshold = DPA_Image::ManualThresh;
    get_exgr_data();
}

void main_window::on_sBox_exgr_man_thresh_valueChanged(int arg1)
{
    config::ExGR.Threshold_Value = arg1;
    get_exgr_data();
}

void main_window::on_chkB_exgr_invert_clicked()
{
    get_exgr_data();
}

void main_window::on_slider_opacity_exgr_valueChanged(int value)
{
    QGraphicsOpacityEffect *effect_opacity = new QGraphicsOpacityEffect;
    ui->lbl_exgr_binary_img->setGraphicsEffect(effect_opacity);

    effect_opacity->setOpacity(trans_opacity(value));
}

///-------- Filter --------------------------------------------------------------------

void main_window::on_rdbtn_filter_hsv_clicked()
{
    config::Filter.ColorSpace = DPA_Image::HSV;
    ui->lbl_filter_h_l->setText("H");
    ui->sBox_min1->setMinimum(0);
    ui->sBox_min1->setMaximum(255);
    ui->sBox_min1->setValue(0);
    ui->sBox_max1->setMinimum(0);
    ui->sBox_max1->setMaximum(255);
    ui->sBox_max1->setValue(255);

    ui->lbl_filter_s_a->setText("S");
    ui->sBox_min2->setMinimum(0);
    ui->sBox_min2->setMaximum(255);
    ui->sBox_min2->setValue(0);
    ui->sBox_max2->setMinimum(0);
    ui->sBox_max2->setMaximum(255);
    ui->sBox_max2->setValue(255);

    ui->lbl_filter_v_b->setText("V");
    ui->sBox_min3->setMinimum(0);
    ui->sBox_min3->setMaximum(255);
    ui->sBox_min3->setValue(0);
    ui->sBox_max3->setMinimum(0);
    ui->sBox_max3->setMaximum(255);
    ui->sBox_max3->setValue(255);

    get_filter_data();
}

void main_window::on_rdbtn_filter_cielab_clicked()
{
    config::Filter.ColorSpace = DPA_Image::CieLab;
    ui->lbl_filter_h_l->setText("L");
    ui->sBox_min1->setMinimum(0);
    ui->sBox_min1->setMaximum(255);
    ui->sBox_min1->setValue(0);
    ui->sBox_max1->setMinimum(0);
    ui->sBox_max1->setMaximum(255);
    ui->sBox_max1->setValue(255);

    ui->lbl_filter_s_a->setText("a");
    ui->sBox_min2->setMinimum(-127);
    ui->sBox_min2->setMaximum(127);
    ui->sBox_min2->setValue(-127);
    ui->sBox_max2->setMinimum(-127);
    ui->sBox_max2->setMaximum(127);
    ui->sBox_max2->setValue(127);

    ui->lbl_filter_v_b->setText("b");
    ui->sBox_min3->setMinimum(-127);
    ui->sBox_min3->setMaximum(127);
    ui->sBox_min3->setValue(-127);
    ui->sBox_max3->setMinimum(-127);
    ui->sBox_max3->setMaximum(127);
    ui->sBox_max3->setValue(127);

    get_filter_data();
}

void main_window::on_chkB_filter_addExG_stateChanged(int arg1)
{
    if(arg1 == 0) //not checked
    {
        switch(config::Filter.ColorChangeType)
        {
        case DPA_Image::addExG:     config::Filter.ColorChangeType = DPA_Image::addNon;     break;
        case DPA_Image::addExGnExR: config::Filter.ColorChangeType = DPA_Image::addExR;     break;
        default:                                                                            break;
        }
    }
    else //is ckecked
    {
        switch(config::Filter.ColorChangeType)
        {
        case DPA_Image::addNon:     config::Filter.ColorChangeType = DPA_Image::addExG;     break;
        case DPA_Image::addExR:     config::Filter.ColorChangeType = DPA_Image::addExGnExR; break;
        default:                                                                            break;
        }
    }

    get_filter_data();
}

void main_window::on_chkB_filter_addExR_stateChanged(int arg1)
{
    if(arg1 == 0) //not checked
    {
        switch(config::Filter.ColorChangeType)
        {
        case DPA_Image::addExR:     config::Filter.ColorChangeType = DPA_Image::addNon;     break;
        case DPA_Image::addExGnExR: config::Filter.ColorChangeType = DPA_Image::addExG;     break;
        default:                                                                            break;
        }
    }
    else //is ckecked
    {
        switch(config::Filter.ColorChangeType)
        {
        case DPA_Image::addNon:     config::Filter.ColorChangeType = DPA_Image::addExR;     break;
        case DPA_Image::addExG:     config::Filter.ColorChangeType = DPA_Image::addExGnExR; break;
        default:                                                                            break;
        }
    }

    get_filter_data();
}

void main_window::on_sBox_min1_valueChanged(int arg1)
{
    config::Filter.min1 = arg1;

    get_filter_data();
}

void main_window::on_sBox_max1_valueChanged(int arg1)
{
    config::Filter.max1 = arg1;

    get_filter_data();
}

void main_window::on_sBox_min2_valueChanged(int arg1)
{
    if(config::Filter.ColorSpace == DPA_Image::CieLab)
    {            
        config::Filter.min2 = arg1 + 128;
    }
    else
    {
        config::Filter.min2 = arg1;
    }

    get_filter_data();
}

void main_window::on_sBox_max2_valueChanged(int arg1)
{
    if(config::Filter.ColorSpace == DPA_Image::CieLab)
    {            
        config::Filter.max2 = arg1 + 128;
    }
    else
    {
        config::Filter.max2 = arg1;
    }

    get_filter_data();
}

void main_window::on_sBox_min3_valueChanged(int arg1)
{
    if(config::Filter.ColorSpace == DPA_Image::CieLab)
    {            
        config::Filter.min3 = arg1 + 128;
    }
    else
    {
        config::Filter.min3 = arg1;
    }

    get_filter_data();
}

void main_window::on_sBox_max3_valueChanged(int arg1)
{
    if(config::Filter.ColorSpace == DPA_Image::CieLab)
    {         
        config::Filter.max3 = arg1 + 128;
    }
    else
    {
        config::Filter.max3 = arg1;
    }

    get_filter_data();
}

void main_window::on_slider_opacity_filter_valueChanged(int value)
{
    QGraphicsOpacityEffect *effect_opacity = new QGraphicsOpacityEffect;
    ui->lbl_filter_binary_img->setGraphicsEffect(effect_opacity);

    effect_opacity->setOpacity(trans_opacity(value));
}

void main_window::on_chkB_filter_invert_clicked()
{
    get_filter_data();
}



void main_window::on_btn_save_filter_binary_clicked()
{
    DPA_Image::ImageValues imgValues;

    imgValues = ImgSample1.get_Image_Values(config::Filter.ColorSpace,
                                        config::Filter.min1, config::Filter.max1,
                                        config::Filter.min2, config::Filter.max2,
                                        config::Filter.min3, config::Filter.max3,
                                        config::Filter.ColorChangeType,
                                        ui->chkB_filter_invert->isChecked());

    cv::imwrite("/home/driehle/Masks/" + img_list.allImages[indexOfCurrentImage].ImageName.toStdString() + "_mask.png", imgValues.Binary);

///Globalen Workspace über menu definieren... Analyse Ordner oder so..------------------------------------------------------------------------------------------
}

void main_window::on_chkB_zoom_filter_toggled(bool checked)
{
    if(checked)
    {
        DPA_Image::ImageValues imgValues;

        imgValues = ImgSample1.get_Image_Values(config::Filter.ColorSpace,
                                            config::Filter.min1, config::Filter.max1,
                                            config::Filter.min2, config::Filter.max2,
                                            config::Filter.min3, config::Filter.max3,
                                            config::Filter.ColorChangeType,
                                            ui->chkB_filter_invert->isChecked());

        cv::cvtColor(imgValues.Color, imgValues.Color, cv::COLOR_BGR2RGB);

        zoom_img->setPixmap(QPixmap::fromImage(QImage(imgValues.Color.data,imgValues.Color.cols,imgValues.Color.rows,imgValues.Color.step,QImage::Format_RGB888)));

        scrollarea->move(QApplication::desktop()->screen()->rect().center().x()+5,
                         QApplication::desktop()->screen()->rect().center().y() - scrollarea->rect().height()/2);

        this->move(QApplication::desktop()->screen()->rect().center().x() - this->rect().width()-5,
                   QApplication::desktop()->screen()->rect().center().y() - this->rect().height()/2);

        scrollarea->show();
    }
    else
    {
        scrollarea->close();
        this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    }
}

void main_window::get_auto_filter()
{
    DPA_Image::ImageAnalyse img_Data;

    img_Data = ImgSample1.analyse_img(config::Filter.FilterSettings);

    switch(config::Filter.ColorSpace)
    {
        case DPA_Image::HSV:        

            ui->txtBrw_min1->setText("0");
            ui->txtBrw_max1->setText(QString::number(std::round(img_Data.thresh_HSV.H)));
            ui->txtBrw_min2->setText("0");
            ui->txtBrw_max2->setText("255");
            ui->txtBrw_min3->setText("0");
            ui->txtBrw_max3->setText("255");
        break;

        case DPA_Image::CieLab:
            ui->txtBrw_min1->setText("0");
            ui->txtBrw_max1->setText("255");
            ui->txtBrw_min2->setText(QString::number(std::round(img_Data.thresh_Lab.a-128)));
            ui->txtBrw_max2->setText("127");
            ui->txtBrw_min3->setText("-127");
            ui->txtBrw_max3->setText("127");
        break;

        default:
        break;
    }
}

void main_window::on_tabWidget_main_currentChanged(int index)
{
    get_ALL_by_tab();
}

void main_window::on_rdbtn_auto_filter_on_toggled(bool checked)
{
    if(checked)
    {
        ui->txtBrw_min1->show();
        ui->txtBrw_min2->show();
        ui->txtBrw_min3->show();
        ui->txtBrw_max1->show();
        ui->txtBrw_max2->show();
        ui->txtBrw_max3->show();

        ui->sBox_min1->hide();
        ui->sBox_min2->hide();
        ui->sBox_min3->hide();
        ui->sBox_max1->hide();
        ui->sBox_max2->hide();
        ui->sBox_max3->hide();

        get_filter_data();
    }
}

void main_window::on_rdbtn_auto_filter_off_toggled(bool checked)
{
    if(checked)
    {
        ui->txtBrw_min1->hide();
        ui->txtBrw_min2->hide();
        ui->txtBrw_min3->hide();
        ui->txtBrw_max1->hide();
        ui->txtBrw_max2->hide();
        ui->txtBrw_max3->hide();

        ui->sBox_min1->show();
        ui->sBox_min2->show();
        ui->sBox_min3->show();
        ui->sBox_max1->show();
        ui->sBox_max2->show();
        ui->sBox_max3->show();

        ui->rdbtn_filter_hsv->setChecked(true);
        config::Filter.ColorSpace = DPA_Image::HSV;
        ui->lbl_filter_h_l->setText("H");
        ui->sBox_min1->setMinimum(0);
        ui->sBox_min1->setMaximum(255);
        ui->sBox_min1->setValue(0);
        ui->sBox_max1->setMinimum(0);
        ui->sBox_max1->setMaximum(255);
        ui->sBox_max1->setValue(255);

        ui->lbl_filter_s_a->setText("S");
        ui->sBox_min2->setMinimum(0);
        ui->sBox_min2->setMaximum(255);
        ui->sBox_min2->setValue(0);
        ui->sBox_max2->setMinimum(0);
        ui->sBox_max2->setMaximum(255);
        ui->sBox_max2->setValue(255);

        ui->lbl_filter_v_b->setText("V");
        ui->sBox_min3->setMinimum(0);
        ui->sBox_min3->setMaximum(255);
        ui->sBox_min3->setValue(0);
        ui->sBox_max3->setMinimum(0);
        ui->sBox_max3->setMaximum(255);
        ui->sBox_max3->setValue(255);

        get_filter_data();
    }
}

void main_window::on_rdbtn_auto_filter_method_MeanStdDev_toggled(bool checked)
{
    if(checked)
    {
        config::Filter.FilterSettings.AutoMethod = DPA_Image::kindOfAutoFilter::MeanStdDev_Filter;
        get_filter_data();
    }
}

void main_window::on_rdbtn_auto_filter_method_Quantile_toggled(bool checked)
{
    if(checked)
    {
        config::Filter.FilterSettings.AutoMethod = DPA_Image::kindOfAutoFilter::Quantile_Filter;
        get_filter_data();
    }
}

void main_window::on_sBox_plant_quantil_valueChanged(double arg1)
{
    config::Filter.FilterSettings.plant_quantil = arg1;
    get_filter_data();
}

void main_window::on_sBox_soil_quantil_valueChanged(double arg1)
{
    config::Filter.FilterSettings.soil_quantil = arg1;
    get_filter_data();
}

void main_window::on_sBox_Sigma_valueChanged(int arg1)
{
    config::Filter.FilterSettings.Sigma = arg1;
    get_filter_data();
}

void main_window::on_rdbtn_ExG_ExR_Filter_toggled(bool checked)
{
    if(checked)
    {
        config::Filter.FilterSettings.MaskMethod = DPA_Image::ExG_ExR_Mask;
        get_filter_data();
    }
}

void main_window::on_rdbtn_ExG_Filter_toggled(bool checked)
{
    if(checked)
    {
        config::Filter.FilterSettings.MaskMethod = DPA_Image::ExG_Mask;
        get_filter_data();
    }
}

void main_window::on_rdbtn_ExGR_Filter_toggled(bool checked)
{
    if(checked)
    {
        config::Filter.FilterSettings.MaskMethod = DPA_Image::ExGR_Mask;
        get_filter_data();
    }
}
