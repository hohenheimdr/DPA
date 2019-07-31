/********************************************************************************
** Form generated from reading UI file 'analyse_binary_img.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSE_BINARY_IMG_H
#define UI_ANALYSE_BINARY_IMG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Analyse_Binary_Img
{
public:
    QDialogButtonBox *btn_ok_cancel;
    QPushButton *btn_OpenImage;
    QComboBox *comboBox_img_list;
    QLabel *lbl_GTI;
    QPushButton *btn_back;
    QPushButton *btn_next;
    QTextBrowser *txtBrw_result;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rdbtn_single;
    QRadioButton *rdbtn_batch;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkB_BlackPix_Coverage;
    QLabel *lbl_file_name_csv;
    QLineEdit *inputtxt_file_name_csv;

    void setupUi(QDialog *Analyse_Binary_Img)
    {
        if (Analyse_Binary_Img->objectName().isEmpty())
            Analyse_Binary_Img->setObjectName(QStringLiteral("Analyse_Binary_Img"));
        Analyse_Binary_Img->resize(481, 437);
        btn_ok_cancel = new QDialogButtonBox(Analyse_Binary_Img);
        btn_ok_cancel->setObjectName(QStringLiteral("btn_ok_cancel"));
        btn_ok_cancel->setGeometry(QRect(280, 400, 191, 27));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        btn_ok_cancel->setFont(font);
        btn_ok_cancel->setOrientation(Qt::Horizontal);
        btn_ok_cancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        btn_OpenImage = new QPushButton(Analyse_Binary_Img);
        btn_OpenImage->setObjectName(QStringLiteral("btn_OpenImage"));
        btn_OpenImage->setGeometry(QRect(190, 10, 106, 27));
        btn_OpenImage->setFont(font);
        comboBox_img_list = new QComboBox(Analyse_Binary_Img);
        comboBox_img_list->setObjectName(QStringLiteral("comboBox_img_list"));
        comboBox_img_list->setGeometry(QRect(90, 10, 301, 27));
        lbl_GTI = new QLabel(Analyse_Binary_Img);
        lbl_GTI->setObjectName(QStringLiteral("lbl_GTI"));
        lbl_GTI->setGeometry(QRect(10, 50, 461, 281));
        lbl_GTI->setFrameShape(QFrame::NoFrame);
        lbl_GTI->setFrameShadow(QFrame::Plain);
        lbl_GTI->setAlignment(Qt::AlignCenter);
        btn_back = new QPushButton(Analyse_Binary_Img);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setGeometry(QRect(10, 10, 71, 27));
        QFont font1;
        font1.setPointSize(12);
        btn_back->setFont(font1);
        btn_next = new QPushButton(Analyse_Binary_Img);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        btn_next->setGeometry(QRect(400, 10, 71, 27));
        btn_next->setFont(font1);
        txtBrw_result = new QTextBrowser(Analyse_Binary_Img);
        txtBrw_result->setObjectName(QStringLiteral("txtBrw_result"));
        txtBrw_result->setGeometry(QRect(10, 370, 241, 57));
        txtBrw_result->setFont(font1);
        layoutWidget_3 = new QWidget(Analyse_Binary_Img);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(340, 370, 128, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rdbtn_single = new QRadioButton(layoutWidget_3);
        rdbtn_single->setObjectName(QStringLiteral("rdbtn_single"));
        rdbtn_single->setChecked(true);

        horizontalLayout_3->addWidget(rdbtn_single);

        rdbtn_batch = new QRadioButton(layoutWidget_3);
        rdbtn_batch->setObjectName(QStringLiteral("rdbtn_batch"));

        horizontalLayout_3->addWidget(rdbtn_batch);

        widget = new QWidget(Analyse_Binary_Img);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 340, 461, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chkB_BlackPix_Coverage = new QCheckBox(widget);
        chkB_BlackPix_Coverage->setObjectName(QStringLiteral("chkB_BlackPix_Coverage"));

        horizontalLayout->addWidget(chkB_BlackPix_Coverage);

        lbl_file_name_csv = new QLabel(widget);
        lbl_file_name_csv->setObjectName(QStringLiteral("lbl_file_name_csv"));

        horizontalLayout->addWidget(lbl_file_name_csv);

        inputtxt_file_name_csv = new QLineEdit(widget);
        inputtxt_file_name_csv->setObjectName(QStringLiteral("inputtxt_file_name_csv"));
        inputtxt_file_name_csv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(inputtxt_file_name_csv);


        retranslateUi(Analyse_Binary_Img);
        QObject::connect(btn_ok_cancel, SIGNAL(accepted()), Analyse_Binary_Img, SLOT(accept()));
        QObject::connect(btn_ok_cancel, SIGNAL(rejected()), Analyse_Binary_Img, SLOT(reject()));

        QMetaObject::connectSlotsByName(Analyse_Binary_Img);
    } // setupUi

    void retranslateUi(QDialog *Analyse_Binary_Img)
    {
        Analyse_Binary_Img->setWindowTitle(QApplication::translate("Analyse_Binary_Img", "Analyse Binary Image", 0));
        btn_OpenImage->setText(QApplication::translate("Analyse_Binary_Img", "Open Image", 0));
        lbl_GTI->setText(QApplication::translate("Analyse_Binary_Img", "Binary Image", 0));
        btn_back->setText(QApplication::translate("Analyse_Binary_Img", "\342\206\220 &Back", 0));
        btn_next->setText(QApplication::translate("Analyse_Binary_Img", "&Next \342\206\222", 0));
        txtBrw_result->setHtml(QApplication::translate("Analyse_Binary_Img", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p></body></html>", 0));
        rdbtn_single->setText(QApplication::translate("Analyse_Binary_Img", "single", 0));
        rdbtn_batch->setText(QApplication::translate("Analyse_Binary_Img", "batch", 0));
        chkB_BlackPix_Coverage->setText(QApplication::translate("Analyse_Binary_Img", "Black Pixel \342\206\222 Coverage   |", 0));
        lbl_file_name_csv->setText(QApplication::translate("Analyse_Binary_Img", "Dataset Name:", 0));
        inputtxt_file_name_csv->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Analyse_Binary_Img: public Ui_Analyse_Binary_Img {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSE_BINARY_IMG_H
