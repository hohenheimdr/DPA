/********************************************************************************
** Form generated from reading UI file 'gt_mask_vs_binary_img.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GT_MASK_VS_BINARY_IMG_H
#define UI_GT_MASK_VS_BINARY_IMG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GTMvsBimg
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *ButtonBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_back;
    QPushButton *btn_next;
    QSpacerItem *verticalSpacer;
    QLabel *lbl_file_name_csv;
    QLineEdit *inputtxt_file_name_csv;
    QPushButton *btn_save_csv;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_exit;
    QLabel *lbl_text;
    QTextBrowser *txtBrw_BinaryImg;
    QTextBrowser *txtBrw_gtMask;
    QCheckBox *chkB_invert;
    QTextBrowser *txtBrw_gtMask_result;
    QTextBrowser *txtBrw_binaryImg_result;
    QLabel *lbl_gt_mask;
    QLabel *lbl_binary_img;
    QLabel *lbl_diff_result;
    QLabel *lbl_text_2;
    QLabel *lbl_text_3;
    QLabel *lbl_text_4;

    void setupUi(QDialog *GTMvsBimg)
    {
        if (GTMvsBimg->objectName().isEmpty())
            GTMvsBimg->setObjectName(QStringLiteral("GTMvsBimg"));
        GTMvsBimg->resize(1026, 775);
        groupBox = new QGroupBox(GTMvsBimg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(90, 480, 861, 191));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 50, 281, 142));
        ButtonBox = new QVBoxLayout(layoutWidget);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_back = new QPushButton(layoutWidget);
        btn_back->setObjectName(QStringLiteral("btn_back"));

        horizontalLayout_2->addWidget(btn_back);

        btn_next = new QPushButton(layoutWidget);
        btn_next->setObjectName(QStringLiteral("btn_next"));

        horizontalLayout_2->addWidget(btn_next);


        ButtonBox->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ButtonBox->addItem(verticalSpacer);

        lbl_file_name_csv = new QLabel(layoutWidget);
        lbl_file_name_csv->setObjectName(QStringLiteral("lbl_file_name_csv"));

        ButtonBox->addWidget(lbl_file_name_csv);

        inputtxt_file_name_csv = new QLineEdit(layoutWidget);
        inputtxt_file_name_csv->setObjectName(QStringLiteral("inputtxt_file_name_csv"));
        inputtxt_file_name_csv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        ButtonBox->addWidget(inputtxt_file_name_csv);

        btn_save_csv = new QPushButton(layoutWidget);
        btn_save_csv->setObjectName(QStringLiteral("btn_save_csv"));

        ButtonBox->addWidget(btn_save_csv);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ButtonBox->addItem(verticalSpacer_2);

        btn_exit = new QPushButton(layoutWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        ButtonBox->addWidget(btn_exit);

        lbl_text = new QLabel(groupBox);
        lbl_text->setObjectName(QStringLiteral("lbl_text"));
        lbl_text->setGeometry(QRect(290, 20, 281, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        lbl_text->setFont(font);
        lbl_text->setAlignment(Qt::AlignCenter);
        txtBrw_BinaryImg = new QTextBrowser(groupBox);
        txtBrw_BinaryImg->setObjectName(QStringLiteral("txtBrw_BinaryImg"));
        txtBrw_BinaryImg->setGeometry(QRect(580, 50, 271, 51));
        txtBrw_BinaryImg->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtBrw_BinaryImg->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtBrw_gtMask = new QTextBrowser(groupBox);
        txtBrw_gtMask->setObjectName(QStringLiteral("txtBrw_gtMask"));
        txtBrw_gtMask->setGeometry(QRect(10, 50, 271, 51));
        txtBrw_gtMask->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        chkB_invert = new QCheckBox(groupBox);
        chkB_invert->setObjectName(QStringLiteral("chkB_invert"));
        chkB_invert->setGeometry(QRect(10, 30, 61, 20));
        txtBrw_gtMask_result = new QTextBrowser(groupBox);
        txtBrw_gtMask_result->setObjectName(QStringLiteral("txtBrw_gtMask_result"));
        txtBrw_gtMask_result->setGeometry(QRect(10, 110, 271, 71));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        txtBrw_gtMask_result->setFont(font1);
        txtBrw_gtMask_result->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtBrw_binaryImg_result = new QTextBrowser(groupBox);
        txtBrw_binaryImg_result->setObjectName(QStringLiteral("txtBrw_binaryImg_result"));
        txtBrw_binaryImg_result->setGeometry(QRect(580, 110, 271, 71));
        txtBrw_binaryImg_result->setFont(font1);
        txtBrw_binaryImg_result->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lbl_gt_mask = new QLabel(GTMvsBimg);
        lbl_gt_mask->setObjectName(QStringLiteral("lbl_gt_mask"));
        lbl_gt_mask->setGeometry(QRect(40, 250, 384, 216));
        lbl_gt_mask->setFrameShape(QFrame::Box);
        lbl_gt_mask->setFrameShadow(QFrame::Plain);
        lbl_gt_mask->setAlignment(Qt::AlignCenter);
        lbl_binary_img = new QLabel(GTMvsBimg);
        lbl_binary_img->setObjectName(QStringLiteral("lbl_binary_img"));
        lbl_binary_img->setGeometry(QRect(590, 250, 384, 216));
        lbl_binary_img->setFrameShape(QFrame::Box);
        lbl_binary_img->setAlignment(Qt::AlignCenter);
        lbl_diff_result = new QLabel(GTMvsBimg);
        lbl_diff_result->setObjectName(QStringLiteral("lbl_diff_result"));
        lbl_diff_result->setGeometry(QRect(310, 250, 384, 216));
        lbl_diff_result->setFrameShape(QFrame::Box);
        lbl_diff_result->setAlignment(Qt::AlignCenter);
        lbl_text_2 = new QLabel(GTMvsBimg);
        lbl_text_2->setObjectName(QStringLiteral("lbl_text_2"));
        lbl_text_2->setGeometry(QRect(70, 210, 171, 31));
        lbl_text_2->setFont(font);
        lbl_text_2->setAlignment(Qt::AlignCenter);
        lbl_text_3 = new QLabel(GTMvsBimg);
        lbl_text_3->setObjectName(QStringLiteral("lbl_text_3"));
        lbl_text_3->setGeometry(QRect(760, 210, 121, 31));
        lbl_text_3->setFont(font);
        lbl_text_3->setAlignment(Qt::AlignCenter);
        lbl_text_4 = new QLabel(GTMvsBimg);
        lbl_text_4->setObjectName(QStringLiteral("lbl_text_4"));
        lbl_text_4->setGeometry(QRect(460, 200, 91, 31));
        lbl_text_4->setFont(font);
        lbl_text_4->setAlignment(Qt::AlignCenter);

        retranslateUi(GTMvsBimg);

        QMetaObject::connectSlotsByName(GTMvsBimg);
    } // setupUi

    void retranslateUi(QDialog *GTMvsBimg)
    {
        GTMvsBimg->setWindowTitle(QApplication::translate("GTMvsBimg", "GT_Mask vs Binary Image", 0));
        groupBox->setTitle(QString());
        btn_back->setText(QApplication::translate("GTMvsBimg", "\342\206\220 &Back", 0));
        btn_next->setText(QApplication::translate("GTMvsBimg", "&Next \342\206\222", 0));
        lbl_file_name_csv->setText(QApplication::translate("GTMvsBimg", "Dataset Name:", 0));
        inputtxt_file_name_csv->setText(QString());
        btn_save_csv->setText(QApplication::translate("GTMvsBimg", "Save CSV", 0));
        btn_exit->setText(QApplication::translate("GTMvsBimg", "&Exit", 0));
        lbl_text->setText(QApplication::translate("GTMvsBimg", "GT_Mask to Binary Img", 0));
        txtBrw_BinaryImg->setHtml(QApplication::translate("GTMvsBimg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        txtBrw_gtMask->setHtml(QApplication::translate("GTMvsBimg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        chkB_invert->setText(QApplication::translate("GTMvsBimg", "Invert", 0));
        txtBrw_gtMask_result->setHtml(QApplication::translate("GTMvsBimg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:600;\"><br /></p></body></html>", 0));
        txtBrw_binaryImg_result->setHtml(QApplication::translate("GTMvsBimg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:600;\"><br /></p></body></html>", 0));
        lbl_gt_mask->setText(QApplication::translate("GTMvsBimg", "GT_Mask", 0));
        lbl_binary_img->setText(QApplication::translate("GTMvsBimg", "Binary Image", 0));
        lbl_diff_result->setText(QApplication::translate("GTMvsBimg", "Difference Result", 0));
        lbl_text_2->setText(QApplication::translate("GTMvsBimg", "Groundtruth Mask ", 0));
        lbl_text_3->setText(QApplication::translate("GTMvsBimg", "Binary Image", 0));
        lbl_text_4->setText(QApplication::translate("GTMvsBimg", "Difference", 0));
    } // retranslateUi

};

namespace Ui {
    class GTMvsBimg: public Ui_GTMvsBimg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GT_MASK_VS_BINARY_IMG_H
