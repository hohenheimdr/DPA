#include "edit_image.h"
#include "ui_edit_image.h"

EditImage::EditImage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditImage)
{
    ui->setupUi(this);

    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    ui->btn_cancel->hide(); //Hide for eventual use later...

    scaleVal = 1;
    ui->sBox_angle->setWrapping(true);
}

EditImage::~EditImage()
{
    delete ui;
}

void EditImage::setImagePath(QString ImagePath)
{
    imgPath = ImagePath;
    setSampleImage(imgPath);
}

void EditImage::setSampleImage(QString ImagePath)
{
    SampleImage.readImage(ImagePath);

    cv::Mat img;
    img = SampleImage.get_OriginalImage();
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    if(img.rows > 500)
    {
        scaleVal = img.rows / 500.0;
    }
    else
    {
        scaleVal = 1.0;
    }

    ui->label->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                         .scaled(img.cols/scaleVal, img.rows/scaleVal ,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    startPoint = mapToGlobal(ui->label->pos());
    endPoint = QPoint(img.cols/scaleVal, img.rows/scaleVal);

    ui->label->adjustSize();
    ui->btn_cancel->move(ui->label->pos().x(),
                         ui->label->pos().y()+ui->label->size().height());
    ui->btn_ok->move    (ui->label->pos().x()+ui->label->size().width()-80,
                         ui->label->pos().y()+ui->label->size().height());
    ui->sBox_angle->move(ui->label->pos().x()+(ui->label->size().width()/2),
                         ui->label->pos().y()+ui->label->size().height());

    ui->verti_line->setGeometry(1,1,20,ui->label->size().height());
    ui->verti_line->move(ui->label->pos().x()+ (ui->label->size().width()/2),
                        ui->label->pos().y());
    ui->hori_line->setGeometry(1,1,ui->label->size().width(), 20);
    ui->hori_line->move(ui->label->pos().x(),
                        ui->label->pos().y()+(ui->label->size().height()/2));

    this->adjustSize();

    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());


}

void EditImage::on_btn_cancel_clicked()
{
    this->close();
}

void EditImage::mousePressEvent(QMouseEvent *event)
{
        startPoint = event->pos();
        rubberBand->setGeometry(QRect(startPoint, event->pos()));
        rubberBand->show();

}

void EditImage::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(startPoint, event->pos()));
}

void EditImage::mouseReleaseEvent(QMouseEvent *event)
{
        endPoint = mapToGlobal(event->pos());
        startPoint = mapToGlobal(startPoint);
}

void EditImage::on_sBox_angle_valueChanged(double arg1)
{
    SampleImage.readImage(imgPath);
    SampleImage.rotateImg(arg1);

    cv::Mat img;
    img = SampleImage.get_OriginalImage();
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    scaleVal = img.rows / 500;

    ui->label->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                         .scaled(img.cols/scaleVal, img.rows/scaleVal ,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    ui->label->adjustSize();
    ui->btn_cancel->move(ui->label->pos().x(),
                         ui->label->pos().y()+ui->label->size().height());
    ui->btn_ok->move(ui->label->pos().x()+ui->label->size().width()-80,
                         ui->label->pos().y()+ui->label->size().height());
    ui->sBox_angle->move(ui->label->pos().x()+(ui->label->size().width()/2),
                         ui->label->pos().y()+ui->label->size().height());

    ui->verti_line->setGeometry(1,1,20,ui->label->size().height());
    ui->verti_line->move(ui->label->pos().x()+ (ui->label->size().width()/2),
                        ui->label->pos().y());
    ui->hori_line->setGeometry(1,1,ui->label->size().width(), 20);
    ui->hori_line->move(ui->label->pos().x(),
                        ui->label->pos().y()+(ui->label->size().height()/2));

    this->adjustSize();

    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());

    config::ImgEditing.rotate.angle = arg1;

}


void EditImage::on_btn_ok_clicked()
{
    if(rubberBand->isVisible())
    {
        config::ImgEditing.crop.x = (startPoint.x() - mapToGlobal(ui->label->pos()).x()) *scaleVal;
        config::ImgEditing.crop.y = (startPoint.y() - mapToGlobal(ui->label->pos()).y()) *scaleVal;
        config::ImgEditing.crop.width = (endPoint.x() - startPoint.x())  *scaleVal;
        config::ImgEditing.crop.height = (endPoint.y() - startPoint.y()) *scaleVal;
    }

    this->close();

    /*
    SampleImage.clipImg(config::ImgEditing.crop.x,
                        config::ImgEditing.crop.y,
                        config::ImgEditing.crop.width,
                        config::ImgEditing.crop.height);

    cv::Mat img;
    img = SampleImage.get_OriginalImage();
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    ui->label->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888))
                         .scaled(img.cols/2, img.rows/2 ,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    ui->label->adjustSize();
    ui->btn_cancel->move(ui->label->pos().x(),
                         ui->label->pos().y()+ui->label->size().height());
    ui->btn_ok->move(ui->label->pos().x()+ui->label->size().width()-80,
                         ui->label->pos().y()+ui->label->size().height());
    rubberBand->hide();
    this->adjustSize();

    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    */
}


