#include "save_window.h"
#include "ui_save_window.h"

save_window::save_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::save_window)
{
    ui->setupUi(this);

    indexOfCurrentImage = 0;

    ui->comboBox_img_list->show();
    ui->lbl_img->show();
    ui->progressBar->hide();

    processing = single;
}

save_window::~save_window()
{
    delete ui;
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string save_window::currentDateTime()
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

//convert float to std::string
std::string save_window::Convert(float number)
{
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

//get Image paths from host (main_window) when save_window is called. (current_index for single image processing)
void save_window::setImageLibrary(Image_Library &ImageLibrary, int current_index)
{
    img_list = ImageLibrary;

    //add Image_Library to comboBox_img_list
    for(unsigned int i=0; i < img_list.allImages.size(); i++)
    {
        ui->comboBox_img_list->addItem(img_list.allImages[i].ImageDate.toString() + "   " + img_list.allImages[i].ImageName);
    }

    indexOfCurrentImage = current_index;
    ui->comboBox_img_list->setCurrentIndex(indexOfCurrentImage);
}

void save_window::get_auto_filter()   // Löschen!!!! //Löschen!!! Überflüssig!!!
{
    DPA_Image::ImageAnalyse img_Data;

    img_Data = SampleImage.analyse_img(config::Filter.FilterSettings);

    switch(config::Filter.ColorSpace)
    {
        case DPA_Image::HSV:
            config::Filter.min1 = 0;
            config::Filter.max1 = std::round(img_Data.thresh_HSV.H);

            config::Filter.min2 = 0;
            config::Filter.max2 = 255;

            config::Filter.min3 = 0;
            config::Filter.max3 = 255;
        break;

        case DPA_Image::CieLab:
            config::Filter.min1 = 0;
            config::Filter.max1 = 255;

            config::Filter.min2 = std::round(img_Data.thresh_Lab.a);
            config::Filter.max2 = 255;

            config::Filter.min3 = 0;
            config::Filter.max3 = 255;
        break;

        default:
        break;
    }
}

void save_window::on_comboBox_img_list_currentIndexChanged(int index)
{
    indexOfCurrentImage = index;
}

void save_window::on_btn_cancel_clicked()
{
    this->close();
}

void save_window::on_rdbtn_single_clicked()
{
    processing = single;
}

void save_window::on_rdbtn_batch_clicked()
{
    processing = batch;
}

void save_window::set_progressbar(int current_number)
{
    ui->progressBar->setValue(current_number+1);
}

void save_window::saveImages(img_lib::ImageData img_data)
{
    DPA_Image::ImageValues imgValues;

    SampleImage.readImage(QString::fromStdString(img_data.ImagePath));
    if(config::ImgEditing.edited == true)
    {
        SampleImage.rotateImg(config::ImgEditing.rotate.angle);
        SampleImage.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);
    }

    if(ui->chkB_img_EditedImage->isChecked())
    {
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_EditedImage.png", SampleImage.get_OriginalImage());
    }
    if(ui->chkB_img_histogram->isChecked())
    {
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_Histogram.png", SampleImage.get_HistOfColor_HSV());
    }

//-ExG---------------------------------------------------------------------------------------------------------------------
    if(ui->chkB_img_exg_binary->isChecked())
    {
        imgValues = SampleImage.get_Image_Values(config::ExG.Method, config::ExG.Threshold, config::ExG.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExG_binary.png", imgValues.Binary);
    }
    if(ui->chkB_img_exg_color->isChecked())
    {
        imgValues = SampleImage.get_Image_Values(config::ExG.Method, config::ExG.Threshold, config::ExG.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExG_color.png", imgValues.Color);
    }

//-ExR---------------------------------------------------------------------------------------------------------------------
    if(ui->chkB_img_exr_binary->isChecked())
    {
        imgValues = SampleImage.get_Image_Values(config::ExR.Method, config::ExR.Threshold, config::ExR.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExR_binary.png", imgValues.Binary);
    }
    if(ui->chkB_img_exr_color->isChecked())
    {
        imgValues = SampleImage.get_Image_Values(config::ExR.Method, config::ExR.Threshold, config::ExR.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExR_color.png", imgValues.Color);
    }

//-ExGR---------------------------------------------------------------------------------------------------------------------
    if(ui->chkB_img_exgr_binary->isChecked())
    {
        imgValues = SampleImage.get_Image_Values(config::ExGR.Method, config::ExGR.Threshold, config::ExGR.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExGR_binary.png", imgValues.Binary);
    }
    if(ui->chkB_img_exgr_color->isChecked())
    {
        imgValues = SampleImage.get_Image_Values(config::ExGR.Method, config::ExGR.Threshold, config::ExGR.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExGR_color.png", imgValues.Color);
    }

//-Filter---------------------------------------------------------------------------------------------------------------------

    if(ui->chkB_img_filter_binary->isChecked() || ui->chkB_img_filter_color->isChecked())
    {


        if(ui->chkB_auto_filter->isChecked())
        {
            imgValues = SampleImage.get_Image_Values(config::Filter.ColorSpace,
                                                config::Filter.FilterSettings,
                                                config::Filter.ColorChangeType,
                                                true);
            ///Achtung!!!!  Achtung!!!!  Achtung!!!!  Achtung!!!!  Achtung!!!!  true -> false!!!  Binary Image is inverted
        }
        else
        {
            imgValues = SampleImage.get_Image_Values(config::Filter.ColorSpace,
                                                config::Filter.min1, config::Filter.max1,
                                                config::Filter.min2, config::Filter.max2,
                                                config::Filter.min3, config::Filter.max3,
                                                config::Filter.ColorChangeType,
                                                true);
        }

        if(ui->chkB_img_filter_binary->isChecked())
        {
            cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_Filter_binary.png", imgValues.Binary);
        }
        if(ui->chkB_img_filter_color->isChecked())
        {
            cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_Filter_color.png", imgValues.Color);
        }

    }


//-all Grey---------------------------------------------------------------------------------------------------------------------
    if(ui->chkB_img_all_grey->isChecked())
    {
        imgValues = SampleImage.get_Image_Values(config::ExG.Method, config::ExG.Threshold, config::ExG.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExG_Grey.png", imgValues.Grey);

        imgValues = SampleImage.get_Image_Values(config::ExR.Method, config::ExR.Threshold, config::ExR.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExR_Grey.png", imgValues.Grey);

        imgValues = SampleImage.get_Image_Values(config::ExGR.Method, config::ExGR.Threshold, config::ExGR.Threshold_Value, false);
        cv::imwrite(targetFolder.toStdString() + "/" + img_data.ImageName.toStdString() + "_ExGR_Grey.png", imgValues.Grey);
    }
}

void save_window::writeCSVFile(img_lib::ImageData img_data)
{
    DPA_Image::ImageValues imgValues;

    SampleImage.readImage(QString::fromStdString(img_data.ImagePath));
    if(config::ImgEditing.edited == true)
    {
        SampleImage.rotateImg(config::ImgEditing.rotate.angle);
        SampleImage.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);
    }

    //-ExG---------------------------------------------------------------------------------------------------------------------
        if(ui->chkB_result_exg->isChecked())
        {
            imgValues = SampleImage.get_Image_Values(config::ExG.Method, config::ExG.Threshold, config::ExG.Threshold_Value, false);
            csv_file << imgValues.date_pic_taken + ";";
            csv_file << img_data.ImageName.toStdString() + ";";
            csv_file << "ExG;";
            csv_file << Convert(imgValues.Coverage) + ";";
            csv_file << Convert(imgValues.Soil) + ";";
            csv_file << Convert(imgValues.rel_luminance) + ";";
            csv_file << Convert(imgValues.L_luminance) + ";";
            csv_file << Convert(imgValues.Mean) + "\n";
        }

    //-ExR---------------------------------------------------------------------------------------------------------------------
        if(ui->chkB_result_exr->isChecked())
        {
            imgValues = SampleImage.get_Image_Values(config::ExR.Method, config::ExR.Threshold, config::ExR.Threshold_Value, false);
            csv_file << imgValues.date_pic_taken + ";";
            csv_file << img_data.ImageName.toStdString() + ";";
            csv_file << "ExR;";
            csv_file << Convert(imgValues.Soil) + ";";
            csv_file << Convert(imgValues.Coverage) + ";";
            csv_file << Convert(imgValues.rel_luminance) + ";";
            csv_file << Convert(imgValues.L_luminance) + ";";
            csv_file << Convert(imgValues.Mean) + "\n";
        }

    //-ExGR---------------------------------------------------------------------------------------------------------------------
        if(ui->chkB_result_exgr->isChecked())
        {
            imgValues = SampleImage.get_Image_Values(config::ExGR.Method, config::ExGR.Threshold, config::ExGR.Threshold_Value, false);
            csv_file << imgValues.date_pic_taken + ";";
            csv_file << img_data.ImageName.toStdString() + ";";
            csv_file << "ExGR;";
            csv_file << Convert(imgValues.Coverage) + ";";
            csv_file << Convert(imgValues.Soil) + ";";
            csv_file << Convert(imgValues.rel_luminance) + ";";
            csv_file << Convert(imgValues.L_luminance) + ";";
            csv_file << Convert(imgValues.Mean) + "\n";
        }

    //-Filter---------------------------------------------------------------------------------------------------------------------
        if(ui->chkB_result_filter->isChecked())
        {
            if(ui->chkB_auto_filter->isChecked())
            {
                imgValues = SampleImage.get_Image_Values(config::Filter.ColorSpace,
                                                    config::Filter.FilterSettings,
                                                    config::Filter.ColorChangeType,
                                                    true);
                ///Achtung!!!!  Achtung!!!!  Achtung!!!!  Achtung!!!!  Achtung!!!!  true -> false!!!  Binary Image is inverted
            }
            else
            {
                imgValues = SampleImage.get_Image_Values(config::Filter.ColorSpace,
                                                    config::Filter.min1, config::Filter.max1,
                                                    config::Filter.min2, config::Filter.max2,
                                                    config::Filter.min3, config::Filter.max3,
                                                    config::Filter.ColorChangeType,
                                                    true);
            }



            csv_file << imgValues.date_pic_taken + ";";
            csv_file << img_data.ImageName.toStdString() + ";";
            switch(config::Filter.ColorSpace)
            {
            case DPA_Image::HSV:
                csv_file << "HSV;";
                break;
            case DPA_Image::CieLab:
                csv_file << "CieLab;";
            break;
            }
            csv_file << Convert(imgValues.Coverage) + ";";
            csv_file << Convert(imgValues.Soil) + ";";
            csv_file << Convert(imgValues.rel_luminance) + ";";
            csv_file << Convert(imgValues.L_luminance) + "\n";
        }
}

void save_window::writeCSVFile_Histogram(img_lib::ImageData img_data)
{
    DPA_Image::ImageAnalyse imgAnalysis;
    DPA_Image::ImageValues imgValues;
    std::vector<cv::Mat> imgHistograms; // H_hist, S_hist, V_hist, L_hist, a_hist, b_hist

    SampleImage.readImage(QString::fromStdString(img_data.ImagePath));
    if(config::ImgEditing.edited == true)
    {
        SampleImage.rotateImg(config::ImgEditing.rotate.angle);
        SampleImage.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);
    }

    imgValues = SampleImage.get_Image_Values(config::ExG.Method, DPA_Image::kindOfThresh::ManualThresh, 0, false);
    imgAnalysis = SampleImage.analyse_img(config::Filter.FilterSettings);
    imgHistograms = SampleImage.get_histograms();

    std::string tmpArray[] = {"HSV; H;", "HSV; S;", "HSV; V;",
                              "CieLab; L;", "CieLab; a;", "CieLab; b;"};

    for(int i=0; i<6; i++)
    {
        csv_file << imgValues.date_pic_taken + ";";
        csv_file << img_data.ImageName.toStdString() + ";";
        csv_file << tmpArray[i];

        for(int j=0; j<imgHistograms[i].rows; j++)
        {
            csv_file << imgHistograms[i].at<float>(j);
            csv_file << ";";
        }

        csv_file << "\n";
    }

    if(ui->chkB_auto_filter->isChecked())
    {
        std::string tmpArray[] = {"HSV; h_plant;", "CieLab; a_plant;", "HSV; h_soil;", "CieLab; a_soil;"};

        for(int i=0; i<4; i++)
        {
            csv_file << imgValues.date_pic_taken + ";";
            csv_file << img_data.ImageName.toStdString() + ";";
            csv_file << tmpArray[i];

            for(int j=0; j<imgAnalysis.hist_plant_soil[i].rows; j++)
            {
                csv_file << imgAnalysis.hist_plant_soil[i].at<float>(j);
                csv_file << ";";
            }

            csv_file << "\n";
        }
    }

}

void save_window::writeCSVFile_Mean_StdDev_Quantil(img_lib::ImageData img_data)
{

    DPA_Image::ImageAnalyse imgAnalysis;
    DPA_Image::ImageValues imgValues;

    SampleImage.readImage(QString::fromStdString(img_data.ImagePath));
    if(config::ImgEditing.edited == true)
    {
        SampleImage.rotateImg(config::ImgEditing.rotate.angle);
        SampleImage.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);
    }

    imgValues = SampleImage.get_Image_Values(config::ExG.Method, DPA_Image::kindOfThresh::ManualThresh, 0, false);
    imgAnalysis = SampleImage.analyse_img(config::Filter.FilterSettings);

    csv_file << imgValues.date_pic_taken + ";";
    csv_file << img_data.ImageName.toStdString() + ";";

    csv_file << imgAnalysis.thresh_HSV.mean_plant_H;    csv_file << ";";
    csv_file << imgAnalysis.thresh_HSV.stddev_plant_H;    csv_file << ";";
    csv_file << imgAnalysis.thresh_HSV.quantil_plant_H;    csv_file << ";";
    csv_file << imgAnalysis.thresh_HSV.mean_soil_H;    csv_file << ";";
    csv_file << imgAnalysis.thresh_HSV.stddev_soil_H;    csv_file << ";";
    csv_file << imgAnalysis.thresh_HSV.quantil_soil_H;    csv_file << ";";

    csv_file << imgAnalysis.thresh_Lab.mean_plant_a;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.stddev_plant_a;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.quantil_plant_a;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.mean_soil_a;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.stddev_soil_a;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.quantil_soil_a;    csv_file << ";";

    csv_file << imgAnalysis.thresh_Lab.mean_plant_b;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.stddev_plant_b;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.mean_soil_b;    csv_file << ";";
    csv_file << imgAnalysis.thresh_Lab.stddev_soil_b;    csv_file << ";";

    csv_file << "\n";
}

void save_window::writeCSVFile_Threshold_Analysis(img_lib::ImageData img_data)
{
    DPA_Image::ImageValues imgValues;

    SampleImage.readImage(QString::fromStdString(img_data.ImagePath));
    if(config::ImgEditing.edited == true)
    {
        SampleImage.rotateImg(config::ImgEditing.rotate.angle);
        SampleImage.clipImg(config::ImgEditing.crop.x, config::ImgEditing.crop.y, config::ImgEditing.crop.width, config::ImgEditing.crop.height);
    }

    imgValues = SampleImage.get_Image_Values(config::ExG.Method, DPA_Image::kindOfThresh::ManualThresh, 0, false);

    //-ExG---------------------------------------------------------------------------------------------------------------------
    if(ui->chkB_result_exg->isChecked())
    {
        csv_file << imgValues.date_pic_taken + ";";
        csv_file << img_data.ImageName.toStdString() + ";";

        csv_file << "ExG;";

        for(int i=0; i < 256; i++)
        {
            imgValues = SampleImage.get_Image_Values(config::ExG.Method, DPA_Image::kindOfThresh::ManualThresh, i, false);
            csv_file << Convert(imgValues.Coverage) + ";";
        }
        csv_file << "\n";
    }

    //-ExR---------------------------------------------------------------------------------------------------------------------
    if(ui->chkB_result_exr->isChecked())
    {
        csv_file << imgValues.date_pic_taken + ";";
        csv_file << img_data.ImageName.toStdString() + ";";

        csv_file << "ExR;";

        for(int i=0; i < 256; i++)
        {
            imgValues = SampleImage.get_Image_Values(config::ExR.Method, DPA_Image::kindOfThresh::ManualThresh, i, false);
            csv_file << Convert(imgValues.Soil) + ";"; //Bei ExR ist Schwarz die Bedeckung und nicht weiß!
        }
        csv_file << "\n";
    }

    //-ExGR---------------------------------------------------------------------------------------------------------------------
    if(ui->chkB_result_exgr->isChecked())
    {
        csv_file << imgValues.date_pic_taken + ";";
        csv_file << img_data.ImageName.toStdString() + ";";

        csv_file << "ExGR;";

        for(int i=0; i < 256; i++)
        {
            imgValues = SampleImage.get_Image_Values(config::ExGR.Method, DPA_Image::kindOfThresh::ManualThresh, i, false);
            csv_file << Convert(imgValues.Coverage) + ";";
        }
        csv_file << "\n";
    }
}

void save_window::on_btn_start_clicked()
{    
    std::string str;
    std::stringstream ss;
    QMessageBox::StandardButton reply;
    int vec_elements;

    targetFolder = (QFileDialog::getExistingDirectory(this, tr("Save to Directory..."),
                                                             "/home/driehle/Masterarbeit/MA-Datensatz",
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks));

    switch(processing)
    {
    case single:

        saveImages(img_list.allImages[indexOfCurrentImage]);

        if(ui->chkB_result_exg->isChecked() || ui->chkB_result_exr->isChecked() || ui->chkB_result_exgr->isChecked()
                || ui->chkB_result_filter->isChecked())
        {
            std::string csv_file_name = targetFolder.toStdString() + "/"  + ui->inputtxt_file_name_csv->text().toStdString() +".csv";// + "_" + currentDateTime() +".csv";
            csv_file.open(csv_file_name.c_str());
            csv_file << "date; variation; method; coverage; soil; rel_luminance; lab_luminance ;gray_mean \n";

            writeCSVFile(img_list.allImages[indexOfCurrentImage]);
            csv_file.close();
        }

        if(ui->chkB_thresh_analysis->isChecked())
        {
            std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Threshold_Analysis" +".csv";//_" + currentDateTime() +".csv";
            csv_file.open(csv_file_name.c_str());
            csv_file << "date; variation; method; ";

            for(int i=0; i<256; i++)
            {
                csv_file << Convert(i) + ";";
            }
            csv_file << "\n";

            writeCSVFile_Threshold_Analysis(img_list.allImages[indexOfCurrentImage]);
            csv_file.close();
        }

        if(ui->chkB_result_histogram->isChecked())
        {
            std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Histograms"  +".csv";//_" + currentDateTime() +".csv";
            csv_file.open(csv_file_name.c_str());
            csv_file << "date; variation; colorspace; channel; ";

            for(int i=0; i<256; i++)
            {
                csv_file << Convert(i) + ";";
            }
            csv_file << "\n";

            writeCSVFile_Histogram(img_list.allImages[indexOfCurrentImage]);
            csv_file.close();
        }

        if(ui->chkB_mean_stddev->isChecked())
        {
            std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Mean_StdDev_Quantil" +".csv";//_" + currentDateTime() +".csv";
            csv_file.open(csv_file_name.c_str());
            csv_file << "date; variation; mean_plant_h; stddev_plant_h; quantil_plant_h; mean_soil_h; stddev_soil_h; quantil_soil_h; mean_plant_a; stddev_plant_a; quantil_plant_a; mean_soil_a; stddev_soil_a; quantil_soil_a; mean_plant_b; stddev_plant_b; mean_soil_b; stddev_soil_b;";
            csv_file << "\n";

            writeCSVFile_Mean_StdDev_Quantil(img_list.allImages[indexOfCurrentImage]);

            csv_file.close();
        }

        break;

    case batch:

        vec_elements = img_list.allImages.size();

        ss << vec_elements;
        str = ss.str();

        reply = QMessageBox::question(this, "batch processing",
                                      "Number of Sample Pictures: "+ QString::fromStdString(str) + "\n\n" + "Do you want to continue processing?",
                                      QMessageBox::Yes|QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
        {
            ui->progressBar->show();
            ui->btn_start->hide();
            ui->btn_cancel->hide();

            ui->progressBar->setRange(0, vec_elements);
            ui->progressBar->setFormat("%p%");
            ui->progressBar->setValue(0);

            for(int i = 0; i < vec_elements; i++)
            {
                saveImages(img_list.allImages[i]);
                set_progressbar(i);
            }

            if(ui->chkB_result_exg->isChecked() || ui->chkB_result_exr->isChecked() || ui->chkB_result_exgr->isChecked()
                    || ui->chkB_result_filter->isChecked())
            {
                std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() +".csv";// + "_" + currentDateTime() +".csv";
                csv_file.open(csv_file_name.c_str());
                csv_file << "date; variation; method; coverage; soil; rel_luminance; lab_luminance ;gray_mean \n";

                ui->progressBar->setValue(0);

                for(int i = 0; i < vec_elements; i++)
                {
                    writeCSVFile(img_list.allImages[i]);
                    set_progressbar(i);
                }
                csv_file.close();
            }

            if(ui->chkB_thresh_analysis->isChecked())
            {
                std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Threshold_Analysis" +".csv";//_" + currentDateTime() +".csv";
                csv_file.open(csv_file_name.c_str());
                csv_file << "date; variation; method; ";

                for(int i=0; i<256; i++)
                {
                    csv_file << Convert(i) + ";";
                }
                csv_file << "\n";

                ui->progressBar->setValue(0);

                for(unsigned int i=0; i < img_list.allImages.size(); i++)
                {
                    writeCSVFile_Threshold_Analysis(img_list.allImages[i]);
                    set_progressbar(i);
                }
                csv_file.close();
            }

            if(ui->chkB_result_histogram->isChecked())
            {
                std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Histograms" +".csv";//_" + currentDateTime() +".csv";
                csv_file.open(csv_file_name.c_str());
                csv_file << "date; variation; colorspace; channel; ";

                for(int i=0; i<256; i++)
                {
                    csv_file << Convert(i) + ";";
                }
                csv_file << "\n";

                ui->progressBar->setValue(0);

                for(unsigned int i=0; i < img_list.allImages.size(); i++)
                {
                    writeCSVFile_Histogram(img_list.allImages[i]);
                    set_progressbar(i);
                }
                csv_file.close();
            }

            if(ui->chkB_mean_stddev->isChecked())
            {
                std::string csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Mean_StdDev_Median" +".csv";//_" + currentDateTime() +".csv";
                csv_file.open(csv_file_name.c_str());
                csv_file << "date; variation; mean_plant_h; stddev_plant_h; median_plant_h; mean_soil_h; stddev_soil_h; median_soil_h; mean_plant_a; stddev_plant_a; median_plant_a; mean_soil_a; stddev_soil_a; median_soil_a; mean_plant_b; stddev_plant_b; mean_soil_b; stddev_soil_b;";
                csv_file << "\n";

                ui->progressBar->setValue(0);

                for(unsigned int i=0; i < img_list.allImages.size(); i++)
                {
                    writeCSVFile_Mean_StdDev_Quantil(img_list.allImages[i]);
                    set_progressbar(i);
                }
                csv_file.close();
            }
        }
        break;

    default:
        break;

    }
    close();
}


