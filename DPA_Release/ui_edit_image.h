/********************************************************************************
** Form generated from reading UI file 'edit_image.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_IMAGE_H
#define UI_EDIT_IMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditImage
{
public:
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QLabel *label;
    QFrame *hori_line;
    QDoubleSpinBox *sBox_angle;
    QFrame *verti_line;

    void setupUi(QWidget *EditImage)
    {
        if (EditImage->objectName().isEmpty())
            EditImage->setObjectName(QStringLiteral("EditImage"));
        EditImage->resize(280, 190);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditImage->sizePolicy().hasHeightForWidth());
        EditImage->setSizePolicy(sizePolicy);
        EditImage->setFocusPolicy(Qt::TabFocus);
        EditImage->setContextMenuPolicy(Qt::DefaultContextMenu);
        EditImage->setWindowTitle(QStringLiteral("Edit Image"));
        btn_ok = new QPushButton(EditImage);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(190, 160, 80, 22));
        btn_cancel = new QPushButton(EditImage);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setGeometry(QRect(10, 160, 80, 22));
        label = new QLabel(EditImage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 251, 151));
        label->setCursor(QCursor(Qt::CrossCursor));
        label->setAlignment(Qt::AlignCenter);
        hori_line = new QFrame(EditImage);
        hori_line->setObjectName(QStringLiteral("hori_line"));
        hori_line->setGeometry(QRect(10, 60, 261, 20));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        hori_line->setFont(font);
        hori_line->setAutoFillBackground(false);
        hori_line->setFrameShadow(QFrame::Plain);
        hori_line->setLineWidth(4);
        hori_line->setMidLineWidth(4);
        hori_line->setFrameShape(QFrame::HLine);
        sBox_angle = new QDoubleSpinBox(EditImage);
        sBox_angle->setObjectName(QStringLiteral("sBox_angle"));
        sBox_angle->setGeometry(QRect(110, 160, 66, 23));
        sBox_angle->setWrapping(true);
        sBox_angle->setDecimals(1);
        sBox_angle->setMaximum(360);
        sBox_angle->setSingleStep(0.5);
        sBox_angle->setValue(0);
        verti_line = new QFrame(EditImage);
        verti_line->setObjectName(QStringLiteral("verti_line"));
        verti_line->setGeometry(QRect(130, 10, 20, 131));
        verti_line->setFont(font);
        verti_line->setFrameShadow(QFrame::Plain);
        verti_line->setLineWidth(4);
        verti_line->setMidLineWidth(4);
        verti_line->setFrameShape(QFrame::VLine);

        retranslateUi(EditImage);

        QMetaObject::connectSlotsByName(EditImage);
    } // setupUi

    void retranslateUi(QWidget *EditImage)
    {
        btn_ok->setText(QApplication::translate("EditImage", "&OK", 0));
        btn_cancel->setText(QApplication::translate("EditImage", "&Cancel", 0));
        label->setText(QApplication::translate("EditImage", "TextLabel", 0));
        sBox_angle->setPrefix(QString());
        sBox_angle->setSuffix(QApplication::translate("EditImage", "\302\260", 0));
        Q_UNUSED(EditImage);
    } // retranslateUi

};

namespace Ui {
    class EditImage: public Ui_EditImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_IMAGE_H
