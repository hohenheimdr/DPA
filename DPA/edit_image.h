#ifndef EDITIMAGE_H
#define EDITIMAGE_H

#include "dpa_image.h"
#include "config.h"


#include <QDialog>
#include <QWidget>

#include <QDesktopWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QRubberBand>

namespace Ui {
class EditImage;
}

class EditImage : public QDialog
{
    Q_OBJECT

public:
    explicit EditImage(QWidget *parent = 0);
    ~EditImage();

    void setImagePath(QString ImagePath);

private slots:
    void on_btn_cancel_clicked();
    void on_btn_ok_clicked();

    void on_sBox_angle_valueChanged(double arg1);

private:
    Ui::EditImage *ui;

    QString imgPath = NULL;
    DPA_Image SampleImage;
    QRubberBand* rubberBand;
    QPoint startPoint, endPoint; // for drawing clipping rectangle
    double scaleVal;

    void setSampleImage(QString ImagePath);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // EDITIMAGE_H
