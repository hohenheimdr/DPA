/********************************************************************************
** Form generated from reading UI file 'save_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_WINDOW_H
#define UI_SAVE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_save_window
{
public:
    QPushButton *btn_start;
    QPushButton *btn_cancel;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *label_4;
    QLabel *lbl_img;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rdbtn_single;
    QRadioButton *rdbtn_batch;
    QComboBox *comboBox_img_list;
    QCheckBox *chkB_thresh_analysis;
    QWidget *tab_2;
    QWidget *layoutWidget_1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *chkB_result_exg;
    QCheckBox *chkB_result_exr;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *chkB_result_exgr;
    QCheckBox *chkB_result_filter;
    QCheckBox *chkB_auto_filter;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *chkB_result_histogram;
    QCheckBox *chkB_mean_stddev;
    QLabel *empty;
    QLabel *label_3;
    QLabel *lbl_file_name_csv;
    QLineEdit *inputtxt_file_name_csv;
    QWidget *tab_1;
    QLabel *label_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *chkB_img_exg_binary;
    QCheckBox *chkB_img_exg_color;
    QCheckBox *chkB_img_exr_binary;
    QCheckBox *chkB_img_exr_color;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chkB_img_exgr_binary;
    QCheckBox *chkB_img_exgr_color;
    QCheckBox *chkB_img_filter_binary;
    QCheckBox *chkB_img_filter_color;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *chkB_img_histogram;
    QCheckBox *chkB_img_EditedImage;
    QCheckBox *chkB_img_all_grey;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;

    void setupUi(QDialog *save_window)
    {
        if (save_window->objectName().isEmpty())
            save_window->setObjectName(QStringLiteral("save_window"));
        save_window->resize(400, 230);
        btn_start = new QPushButton(save_window);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(310, 200, 80, 22));
        btn_cancel = new QPushButton(save_window);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setGeometry(QRect(220, 200, 80, 22));
        tabWidget = new QTabWidget(save_window);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 381, 181));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 121, 16));
        lbl_img = new QLabel(tab_3);
        lbl_img->setObjectName(QStringLiteral("lbl_img"));
        lbl_img->setGeometry(QRect(250, 30, 101, 20));
        layoutWidget_3 = new QWidget(tab_3);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 50, 128, 22));
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

        comboBox_img_list = new QComboBox(tab_3);
        comboBox_img_list->setObjectName(QStringLiteral("comboBox_img_list"));
        comboBox_img_list->setGeometry(QRect(250, 50, 121, 22));
        chkB_thresh_analysis = new QCheckBox(tab_3);
        chkB_thresh_analysis->setObjectName(QStringLiteral("chkB_thresh_analysis"));
        chkB_thresh_analysis->setGeometry(QRect(10, 100, 131, 20));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget_1 = new QWidget(tab_2);
        layoutWidget_1->setObjectName(QStringLiteral("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(10, 31, 361, 76));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        chkB_result_exg = new QCheckBox(layoutWidget_1);
        chkB_result_exg->setObjectName(QStringLiteral("chkB_result_exg"));

        verticalLayout_4->addWidget(chkB_result_exg);

        chkB_result_exr = new QCheckBox(layoutWidget_1);
        chkB_result_exr->setObjectName(QStringLiteral("chkB_result_exr"));

        verticalLayout_4->addWidget(chkB_result_exr);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        chkB_result_exgr = new QCheckBox(layoutWidget_1);
        chkB_result_exgr->setObjectName(QStringLiteral("chkB_result_exgr"));

        verticalLayout_5->addWidget(chkB_result_exgr);

        chkB_result_filter = new QCheckBox(layoutWidget_1);
        chkB_result_filter->setObjectName(QStringLiteral("chkB_result_filter"));

        verticalLayout_5->addWidget(chkB_result_filter);

        chkB_auto_filter = new QCheckBox(layoutWidget_1);
        chkB_auto_filter->setObjectName(QStringLiteral("chkB_auto_filter"));

        verticalLayout_5->addWidget(chkB_auto_filter);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        chkB_result_histogram = new QCheckBox(layoutWidget_1);
        chkB_result_histogram->setObjectName(QStringLiteral("chkB_result_histogram"));

        verticalLayout_6->addWidget(chkB_result_histogram);

        chkB_mean_stddev = new QCheckBox(layoutWidget_1);
        chkB_mean_stddev->setObjectName(QStringLiteral("chkB_mean_stddev"));

        verticalLayout_6->addWidget(chkB_mean_stddev);

        empty = new QLabel(layoutWidget_1);
        empty->setObjectName(QStringLiteral("empty"));
        empty->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(empty);


        horizontalLayout_2->addLayout(verticalLayout_6);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 331, 16));
        lbl_file_name_csv = new QLabel(tab_2);
        lbl_file_name_csv->setObjectName(QStringLiteral("lbl_file_name_csv"));
        lbl_file_name_csv->setGeometry(QRect(10, 110, 331, 16));
        inputtxt_file_name_csv = new QLineEdit(tab_2);
        inputtxt_file_name_csv->setObjectName(QStringLiteral("inputtxt_file_name_csv"));
        inputtxt_file_name_csv->setGeometry(QRect(10, 130, 271, 22));
        inputtxt_file_name_csv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(tab_2, QString());
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        label_2 = new QLabel(tab_1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 151, 16));
        layoutWidget_2 = new QWidget(tab_1);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 31, 361, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        chkB_img_exg_binary = new QCheckBox(layoutWidget_2);
        chkB_img_exg_binary->setObjectName(QStringLiteral("chkB_img_exg_binary"));

        verticalLayout->addWidget(chkB_img_exg_binary);

        chkB_img_exg_color = new QCheckBox(layoutWidget_2);
        chkB_img_exg_color->setObjectName(QStringLiteral("chkB_img_exg_color"));

        verticalLayout->addWidget(chkB_img_exg_color);

        chkB_img_exr_binary = new QCheckBox(layoutWidget_2);
        chkB_img_exr_binary->setObjectName(QStringLiteral("chkB_img_exr_binary"));

        verticalLayout->addWidget(chkB_img_exr_binary);

        chkB_img_exr_color = new QCheckBox(layoutWidget_2);
        chkB_img_exr_color->setObjectName(QStringLiteral("chkB_img_exr_color"));

        verticalLayout->addWidget(chkB_img_exr_color);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        chkB_img_exgr_binary = new QCheckBox(layoutWidget_2);
        chkB_img_exgr_binary->setObjectName(QStringLiteral("chkB_img_exgr_binary"));

        verticalLayout_2->addWidget(chkB_img_exgr_binary);

        chkB_img_exgr_color = new QCheckBox(layoutWidget_2);
        chkB_img_exgr_color->setObjectName(QStringLiteral("chkB_img_exgr_color"));

        verticalLayout_2->addWidget(chkB_img_exgr_color);

        chkB_img_filter_binary = new QCheckBox(layoutWidget_2);
        chkB_img_filter_binary->setObjectName(QStringLiteral("chkB_img_filter_binary"));

        verticalLayout_2->addWidget(chkB_img_filter_binary);

        chkB_img_filter_color = new QCheckBox(layoutWidget_2);
        chkB_img_filter_color->setObjectName(QStringLiteral("chkB_img_filter_color"));

        verticalLayout_2->addWidget(chkB_img_filter_color);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        chkB_img_histogram = new QCheckBox(layoutWidget_2);
        chkB_img_histogram->setObjectName(QStringLiteral("chkB_img_histogram"));

        verticalLayout_3->addWidget(chkB_img_histogram);

        chkB_img_EditedImage = new QCheckBox(layoutWidget_2);
        chkB_img_EditedImage->setObjectName(QStringLiteral("chkB_img_EditedImage"));
        chkB_img_EditedImage->setChecked(false);

        verticalLayout_3->addWidget(chkB_img_EditedImage);

        chkB_img_all_grey = new QCheckBox(layoutWidget_2);
        chkB_img_all_grey->setObjectName(QStringLiteral("chkB_img_all_grey"));
        chkB_img_all_grey->setChecked(false);

        verticalLayout_3->addWidget(chkB_img_all_grey);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_1, QString());
        progressBar = new QProgressBar(save_window);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 200, 381, 23));
        progressBar->setValue(0);
        progressBar->raise();
        btn_start->raise();
        btn_cancel->raise();
        tabWidget->raise();

        retranslateUi(save_window);
        QObject::connect(rdbtn_single, SIGNAL(clicked()), lbl_img, SLOT(show()));
        QObject::connect(rdbtn_batch, SIGNAL(clicked()), lbl_img, SLOT(hide()));
        QObject::connect(rdbtn_batch, SIGNAL(clicked()), comboBox_img_list, SLOT(hide()));
        QObject::connect(rdbtn_single, SIGNAL(clicked()), comboBox_img_list, SLOT(show()));

        tabWidget->setCurrentIndex(0);
        comboBox_img_list->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(save_window);
    } // setupUi

    void retranslateUi(QDialog *save_window)
    {
        save_window->setWindowTitle(QApplication::translate("save_window", "Save Analysis", 0));
        btn_start->setText(QApplication::translate("save_window", "&Start", 0));
        btn_cancel->setText(QApplication::translate("save_window", "&Cancel", 0));
        label_4->setText(QApplication::translate("save_window", "kind of processing:", 0));
        lbl_img->setText(QApplication::translate("save_window", "Image:", 0));
        rdbtn_single->setText(QApplication::translate("save_window", "single", 0));
        rdbtn_batch->setText(QApplication::translate("save_window", "batch", 0));
        chkB_thresh_analysis->setText(QApplication::translate("save_window", "Treshold Analysis", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("save_window", "batch-config", 0));
        chkB_result_exg->setText(QApplication::translate("save_window", "ExG", 0));
        chkB_result_exr->setText(QApplication::translate("save_window", "ExR", 0));
        chkB_result_exgr->setText(QApplication::translate("save_window", "ExGR", 0));
        chkB_result_filter->setText(QApplication::translate("save_window", "Filter", 0));
        chkB_auto_filter->setText(QApplication::translate("save_window", "auto filter", 0));
        chkB_result_histogram->setText(QApplication::translate("save_window", "Histogram", 0));
        chkB_mean_stddev->setText(QApplication::translate("save_window", "Mean & StdDev", 0));
        empty->setText(QApplication::translate("save_window", "(Plant / Soil)", 0));
        label_3->setText(QApplication::translate("save_window", "choose results of the methods to be saved in csv-file:", 0));
        lbl_file_name_csv->setText(QApplication::translate("save_window", "Dataset Name:", 0));
        inputtxt_file_name_csv->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("save_window", "results", 0));
        label_2->setText(QApplication::translate("save_window", "choose images to save:", 0));
        chkB_img_exg_binary->setText(QApplication::translate("save_window", "ExG Binary", 0));
        chkB_img_exg_color->setText(QApplication::translate("save_window", "ExG Color", 0));
        chkB_img_exr_binary->setText(QApplication::translate("save_window", "ExR Binary", 0));
        chkB_img_exr_color->setText(QApplication::translate("save_window", "ExR Color", 0));
        chkB_img_exgr_binary->setText(QApplication::translate("save_window", "ExGR Binary", 0));
        chkB_img_exgr_color->setText(QApplication::translate("save_window", "ExGR Color", 0));
        chkB_img_filter_binary->setText(QApplication::translate("save_window", "Filter Binary", 0));
        chkB_img_filter_color->setText(QApplication::translate("save_window", "Filter Color", 0));
        chkB_img_histogram->setText(QApplication::translate("save_window", "Histogram", 0));
        chkB_img_EditedImage->setText(QApplication::translate("save_window", "edited Image", 0));
        chkB_img_all_grey->setText(QApplication::translate("save_window", "all Grey", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("save_window", "images", 0));
        progressBar->setFormat(QApplication::translate("save_window", "%p%", 0));
    } // retranslateUi

};

namespace Ui {
    class save_window: public Ui_save_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_WINDOW_H
