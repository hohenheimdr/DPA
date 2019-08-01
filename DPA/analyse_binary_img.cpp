#include "analyse_binary_img.h"
#include "ui_analyse_binary_img.h"

Analyse_Binary_Img::Analyse_Binary_Img(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analyse_Binary_Img)
{
    ui->setupUi(this);

    ui->btn_back->hide();
    ui->btn_next->hide();
    ui->comboBox_img_list->hide();

    BlackPixel_Label = "Soil";
    WhitePixel_Label = "Coverage";
}

Analyse_Binary_Img::~Analyse_Binary_Img()
{
    delete ui;
}

/*void Analyse_Binary_Img::on_buttonBox_accepted()
{
            Löschen!!!!!!
}*/

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string Analyse_Binary_Img::currentDateTime()
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

std::string Analyse_Binary_Img::Convert_float2string(float number)
{
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

void Analyse_Binary_Img::on_btn_OpenImage_clicked()
{
    QString tmpPath = QFileDialog::getOpenFileName(this, tr("Open Image"), "~/DPA/datasets", tr("Image Files (*.png *.jpg *.bmp *.tif)"));
    if(tmpPath != NULL)
    {
        ui->comboBox_img_list->clear();

        img_list.build_img_library(tmpPath,false,true);

        //add Image_Library to comboBox_img_list
        for(unsigned int i=0; i < img_list.allImages.size(); i++)
        {
            ui->comboBox_img_list->addItem(img_list.allImages[i].ImageDate.toString() + "   " + img_list.allImages[i].ImageName);

            //get index of the current loaded image
            if(tmpPath == QString::fromStdString(img_list.allImages[i].ImagePath))
            {
                indexOfCurrentImage = i;
            }
        }
        ui->comboBox_img_list->setCurrentIndex(indexOfCurrentImage);
        loadImage();

        ui->btn_back->show();
        ui->btn_next->show();
        ui->comboBox_img_list->show();
        ui->btn_OpenImage->hide();
    }
}

void Analyse_Binary_Img::loadImage()
{
    QFileInfo check_file(QString::fromStdString(img_list.allImages[indexOfCurrentImage].ImagePath));
    // check if file exists and if yes: Is it really a file and no directory?
    if(check_file.exists() && check_file.isFile())
    {
        image = cv::imread(img_list.allImages[indexOfCurrentImage].ImagePath);

        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

        ui->lbl_GTI->setPixmap(QPixmap::fromImage(QImage(image.data,image.cols,image.rows,image.step,QImage::Format_RGB888))
                             .scaled(ui->lbl_GTI->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

        cv::cvtColor(image,image,cv::COLOR_RGB2GRAY);

        TotalNumberOfPixels = image.rows * image.cols;
        BlackPixel = TotalNumberOfPixels - cv::countNonZero(image);
        WhitePixel = TotalNumberOfPixels - BlackPixel;

        ui->txtBrw_result->setText(BlackPixel_Label + ": " + QString::number(100.0/TotalNumberOfPixels*BlackPixel) + " %");
        ui->txtBrw_result->append( WhitePixel_Label + ": " + QString::number(100.0/TotalNumberOfPixels*WhitePixel) + " %");
    }
}



void Analyse_Binary_Img::on_comboBox_img_list_currentIndexChanged(int index)
{
    indexOfCurrentImage = index;
    loadImage();

}

void Analyse_Binary_Img::on_btn_next_clicked()
{
    if(indexOfCurrentImage < img_list.allImages.size()-1) // -1 cause imgIndex is starting from 0, Size ist starting from 1
    {
        indexOfCurrentImage++;
        ui->comboBox_img_list->setCurrentIndex(indexOfCurrentImage);
    }
}

void Analyse_Binary_Img::on_btn_back_clicked()
{
    if(indexOfCurrentImage > 0)
    {
        indexOfCurrentImage--;
        ui->comboBox_img_list->setCurrentIndex(indexOfCurrentImage);
    }
}

void Analyse_Binary_Img::on_rdbtn_single_clicked()
{
    processing = single;
}

void Analyse_Binary_Img::on_rdbtn_batch_clicked()
{
    processing = batch;
}

void Analyse_Binary_Img::on_chkB_BlackPix_Coverage_toggled(bool checked)
{
    if(checked == true)
    {
        BlackPixel_Label = "Coverage";
        WhitePixel_Label = "Soil";
    }
    else
    {
        BlackPixel_Label = "Soil";
        WhitePixel_Label = "Coverage";
    }

    loadImage();
}

void Analyse_Binary_Img::on_btn_ok_cancel_accepted()
{
    std::string str;
    std::stringstream ss;
    QMessageBox::StandardButton reply;  
    std::string csv_file_name;

    QString targetFolder;

    targetFolder = (QFileDialog::getExistingDirectory(this, tr("Save to Directory..."),
                                                             "~/DPA/datasets",
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks));

    switch(processing)
    {
    case single:
        csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Binary_Image_Result" +".csv";//_" + currentDateTime() +".csv";
        csv_file.open(csv_file_name.c_str());
        csv_file << "date; variation; coverage; soil \n";

        csv_file << img_list.allImages[indexOfCurrentImage].ImageDate.toString("dd.MM.yyyy").toStdString() + ";";
        csv_file << img_list.allImages[indexOfCurrentImage].ImageName.toStdString() + ";";

        if(ui->chkB_BlackPix_Coverage->isChecked())
        {
            csv_file << Convert_float2string(100.0/TotalNumberOfPixels*BlackPixel) + ";";
            csv_file << Convert_float2string(100.0/TotalNumberOfPixels*WhitePixel) + "\n";
        }
        else
        {
            csv_file << Convert_float2string(100.0/TotalNumberOfPixels*WhitePixel) + ";";
            csv_file << Convert_float2string(100.0/TotalNumberOfPixels*BlackPixel) + "\n";
        }


        csv_file.close();

        break;

    case batch:

        ss << img_list.allImages.size();
        str = ss.str();

        reply = QMessageBox::question(this, "batch processing",
                                      "Number of Sample Pictures: "+ QString::fromStdString(str) + "\n\n" + "Do you want to continue processing?",
                                      QMessageBox::Yes|QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
        {
            indexOfCurrentImage = 0;
            csv_file_name = targetFolder.toStdString() + "/" + ui->inputtxt_file_name_csv->text().toStdString() + "_Binary_Image_Result" +".csv";//_" + currentDateTime() +".csv";
            csv_file.open(csv_file_name.c_str());
            csv_file << "date; variation; coverage; soil \n";

            for(unsigned int i = 0; i < img_list.allImages.size(); i++)
            {
                loadImage();

                csv_file << img_list.allImages[indexOfCurrentImage].ImageDate.toString().toStdString() + ";";
                csv_file << img_list.allImages[indexOfCurrentImage].ImageName.toStdString() + ";";

                if(ui->chkB_BlackPix_Coverage->isChecked())
                {
                    csv_file << Convert_float2string(100.0/TotalNumberOfPixels*BlackPixel) + ";";
                    csv_file << Convert_float2string(100.0/TotalNumberOfPixels*WhitePixel) + "\n";
                }
                else
                {
                    csv_file << Convert_float2string(100.0/TotalNumberOfPixels*WhitePixel) + ";";
                    csv_file << Convert_float2string(100.0/TotalNumberOfPixels*BlackPixel) + "\n";
                }

                indexOfCurrentImage ++;
            }
            csv_file.close();
        }
        break;

    default:
        break;

    }
    close();
}


