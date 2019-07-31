/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QTabWidget *tabWidget_main;
    QWidget *tab_org;
    QLabel *lbl_org_img;
    QWidget *tab_info;
    QTextBrowser *txtBrw_Info;
    QWidget *tab_hist;
    QTabWidget *tabWidget_hist;
    QWidget *tab6_1;
    QLabel *lbl_hist_hue_img;
    QLabel *label_9;
    QWidget *tab6_2;
    QLabel *lbl_hist_a_img;
    QLabel *lbl_hist_b_img;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *tab6_3;
    QLabel *label_19;
    QLabel *lbl_hist_L_img;
    QWidget *tab_exg;
    QTabWidget *tabWidget_exg;
    QWidget *tab2_3;
    QLabel *lbl_exg_color_img;
    QWidget *tab2_1;
    QLabel *lbl_exg_grey_img;
    QWidget *tab2_2;
    QLabel *lbl_exg_binary_img;
    QLabel *lbl_org_img_1;
    QFrame *frm_exg_thresh;
    QWidget *layoutWidget_1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rdbtn_exg_positiv;
    QRadioButton *rdbtn_exg_otsu;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rdbtn_exg_manual;
    QSpinBox *sBox_exg_man_thresh;
    QLabel *lbl_exg_thresh_range;
    QSpacerItem *verticalSpacer_3;
    QTextBrowser *txtBrw_ExG;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_15;
    QSlider *slider_opacity_exg;
    QCheckBox *chkB_exg_invert;
    QWidget *tab_exr;
    QTabWidget *tabWidget_exr;
    QWidget *tab3_3;
    QLabel *lbl_exr_color_img;
    QWidget *tab3_1;
    QLabel *lbl_exr_grey_img;
    QWidget *tab3_2;
    QLabel *lbl_exr_binary_img;
    QLabel *lbl_org_img_2;
    QFrame *frm_exr_thresh;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *rdbtn_exr_positiv;
    QRadioButton *rdbtn_exr_otsu;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *rdbtn_exr_manual;
    QSpinBox *sBox_exr_man_thresh;
    QLabel *lbl_exr_thresh_range;
    QSpacerItem *verticalSpacer_6;
    QTextBrowser *txtBrw_ExR;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_14;
    QSlider *slider_opacity_exr;
    QCheckBox *chkB_exr_invert;
    QWidget *tab_exgr;
    QTabWidget *tabWidget_exgr;
    QWidget *tab4_3;
    QLabel *lbl_exgr_color_img;
    QWidget *tab4_1;
    QLabel *lbl_exgr_grey_img;
    QWidget *tab4_2;
    QLabel *lbl_exgr_binary_img;
    QLabel *lbl_org_img_3;
    QFrame *frm_exgr_thresh;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *rdbtn_exgr_positiv;
    QRadioButton *rdbtn_exgr_otsu;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_9;
    QRadioButton *rdbtn_exgr_manual;
    QSpinBox *sBox_exgr_man_thresh;
    QLabel *lbl_exgr_thresh_range;
    QSpacerItem *verticalSpacer_8;
    QTextBrowser *txtBrw_ExGR;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_13;
    QSlider *slider_opacity_exgr;
    QCheckBox *chkB_exgr_invert;
    QWidget *tab_filter;
    QTabWidget *tabWidget_filter;
    QWidget *tab5_1;
    QLabel *lbl_filter_color_img;
    QWidget *tab5_2;
    QLabel *lbl_filter_processedColor_img;
    QWidget *tab5_3;
    QLabel *lbl_filter_binary_img;
    QLabel *lbl_org_img_4;
    QTextBrowser *txtBrw_filter;
    QTabWidget *tabWidget_filter_settings;
    QWidget *tab5_4;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rdbtn_filter_hsv;
    QRadioButton *rdbtn_filter_cielab;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *chkB_filter_addExG;
    QCheckBox *chkB_filter_addExR;
    QSpinBox *sBox_min1;
    QSpinBox *sBox_max1;
    QSpinBox *sBox_min2;
    QSpinBox *sBox_max2;
    QSpinBox *sBox_min3;
    QSpinBox *sBox_max3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lbl_filter_h_l;
    QLabel *lbl_filter_s_a;
    QLabel *lbl_filter_v_b;
    QTextBrowser *txtBrw_min1;
    QTextBrowser *txtBrw_min2;
    QTextBrowser *txtBrw_min3;
    QTextBrowser *txtBrw_max1;
    QTextBrowser *txtBrw_max2;
    QTextBrowser *txtBrw_max3;
    QWidget *tab_2;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rdbtn_auto_filter_method_MeanStdDev;
    QSpacerItem *horizontalSpacer;
    QRadioButton *rdbtn_auto_filter_method_Quantile;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rdbtn_auto_filter_on;
    QRadioButton *rdbtn_auto_filter_off;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *sBox_plant_quantil;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *sBox_soil_quantil;
    QLabel *label_17;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *sBox_Sigma;
    QLabel *label_3;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_14;
    QRadioButton *rdbtn_ExG_ExR_Filter;
    QRadioButton *rdbtn_ExG_Filter;
    QRadioButton *rdbtn_ExGR_Filter;
    QWidget *tab5_6;
    QLabel *label_10;
    QWidget *tab;
    QLabel *label_11;
    QLabel *label_2;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout;
    QLabel *label_12;
    QSlider *slider_opacity_filter;
    QCheckBox *chkB_filter_invert;
    QCheckBox *chkB_zoom_filter;
    QPushButton *btn_save_filter_binary;
    QPushButton *btn_Quit;
    QPushButton *btn_edit_image;
    QPushButton *btn_OpenImage;
    QLabel *label;
    QLabel *label_4;
    QPushButton *btn_save;
    QPushButton *btn_reset;
    QPushButton *btn_development;
    QComboBox *comboBox_img_list;
    QPushButton *btn_Analyse_BinaryImg;
    QPushButton *btn_next;
    QPushButton *btn_back;
    QPushButton *btn_gtMask_vs_binaryImg;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->setEnabled(true);
        main_window->resize(764, 812);
        tabWidget_main = new QTabWidget(main_window);
        tabWidget_main->setObjectName(QStringLiteral("tabWidget_main"));
        tabWidget_main->setEnabled(true);
        tabWidget_main->setGeometry(QRect(10, 90, 741, 651));
        tab_org = new QWidget();
        tab_org->setObjectName(QStringLiteral("tab_org"));
        tab_org->setEnabled(true);
        lbl_org_img = new QLabel(tab_org);
        lbl_org_img->setObjectName(QStringLiteral("lbl_org_img"));
        lbl_org_img->setGeometry(QRect(10, 40, 711, 531));
        lbl_org_img->setAutoFillBackground(false);
        lbl_org_img->setAlignment(Qt::AlignCenter);
        tabWidget_main->addTab(tab_org, QString());
        tab_info = new QWidget();
        tab_info->setObjectName(QStringLiteral("tab_info"));
        txtBrw_Info = new QTextBrowser(tab_info);
        txtBrw_Info->setObjectName(QStringLiteral("txtBrw_Info"));
        txtBrw_Info->setGeometry(QRect(10, 20, 711, 331));
        QFont font;
        font.setPointSize(12);
        txtBrw_Info->setFont(font);
        tabWidget_main->addTab(tab_info, QString());
        tab_hist = new QWidget();
        tab_hist->setObjectName(QStringLiteral("tab_hist"));
        tabWidget_hist = new QTabWidget(tab_hist);
        tabWidget_hist->setObjectName(QStringLiteral("tabWidget_hist"));
        tabWidget_hist->setGeometry(QRect(10, 10, 721, 591));
        tabWidget_hist->setCursor(QCursor(Qt::ArrowCursor));
        tab6_1 = new QWidget();
        tab6_1->setObjectName(QStringLiteral("tab6_1"));
        lbl_hist_hue_img = new QLabel(tab6_1);
        lbl_hist_hue_img->setObjectName(QStringLiteral("lbl_hist_hue_img"));
        lbl_hist_hue_img->setGeometry(QRect(10, 60, 691, 401));
        lbl_hist_hue_img->setAutoFillBackground(false);
        lbl_hist_hue_img->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(tab6_1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 20, 691, 40));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignCenter);
        tabWidget_hist->addTab(tab6_1, QString());
        tab6_2 = new QWidget();
        tab6_2->setObjectName(QStringLiteral("tab6_2"));
        lbl_hist_a_img = new QLabel(tab6_2);
        lbl_hist_a_img->setObjectName(QStringLiteral("lbl_hist_a_img"));
        lbl_hist_a_img->setGeometry(QRect(10, 50, 691, 221));
        lbl_hist_a_img->setAutoFillBackground(false);
        lbl_hist_a_img->setAlignment(Qt::AlignCenter);
        lbl_hist_b_img = new QLabel(tab6_2);
        lbl_hist_b_img->setObjectName(QStringLiteral("lbl_hist_b_img"));
        lbl_hist_b_img->setGeometry(QRect(10, 330, 691, 221));
        lbl_hist_b_img->setAutoFillBackground(false);
        lbl_hist_b_img->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(tab6_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 691, 40));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(tab6_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 290, 691, 40));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);
        tabWidget_hist->addTab(tab6_2, QString());
        tab6_3 = new QWidget();
        tab6_3->setObjectName(QStringLiteral("tab6_3"));
        label_19 = new QLabel(tab6_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 20, 691, 40));
        label_19->setLayoutDirection(Qt::LeftToRight);
        label_19->setAlignment(Qt::AlignCenter);
        lbl_hist_L_img = new QLabel(tab6_3);
        lbl_hist_L_img->setObjectName(QStringLiteral("lbl_hist_L_img"));
        lbl_hist_L_img->setGeometry(QRect(10, 60, 691, 401));
        lbl_hist_L_img->setAutoFillBackground(false);
        lbl_hist_L_img->setAlignment(Qt::AlignCenter);
        tabWidget_hist->addTab(tab6_3, QString());
        tabWidget_main->addTab(tab_hist, QString());
        tab_exg = new QWidget();
        tab_exg->setObjectName(QStringLiteral("tab_exg"));
        tab_exg->setEnabled(true);
        tabWidget_exg = new QTabWidget(tab_exg);
        tabWidget_exg->setObjectName(QStringLiteral("tabWidget_exg"));
        tabWidget_exg->setGeometry(QRect(10, 10, 721, 421));
        tabWidget_exg->setCursor(QCursor(Qt::ArrowCursor));
        tab2_3 = new QWidget();
        tab2_3->setObjectName(QStringLiteral("tab2_3"));
        lbl_exg_color_img = new QLabel(tab2_3);
        lbl_exg_color_img->setObjectName(QStringLiteral("lbl_exg_color_img"));
        lbl_exg_color_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exg_color_img->setAutoFillBackground(false);
        lbl_exg_color_img->setAlignment(Qt::AlignCenter);
        tabWidget_exg->addTab(tab2_3, QString());
        tab2_1 = new QWidget();
        tab2_1->setObjectName(QStringLiteral("tab2_1"));
        lbl_exg_grey_img = new QLabel(tab2_1);
        lbl_exg_grey_img->setObjectName(QStringLiteral("lbl_exg_grey_img"));
        lbl_exg_grey_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exg_grey_img->setAutoFillBackground(false);
        lbl_exg_grey_img->setAlignment(Qt::AlignCenter);
        tabWidget_exg->addTab(tab2_1, QString());
        tab2_2 = new QWidget();
        tab2_2->setObjectName(QStringLiteral("tab2_2"));
        lbl_exg_binary_img = new QLabel(tab2_2);
        lbl_exg_binary_img->setObjectName(QStringLiteral("lbl_exg_binary_img"));
        lbl_exg_binary_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exg_binary_img->setAutoFillBackground(false);
        lbl_exg_binary_img->setAlignment(Qt::AlignCenter);
        lbl_org_img_1 = new QLabel(tab2_2);
        lbl_org_img_1->setObjectName(QStringLiteral("lbl_org_img_1"));
        lbl_org_img_1->setGeometry(QRect(10, 10, 691, 371));
        lbl_org_img_1->setAutoFillBackground(false);
        lbl_org_img_1->setAlignment(Qt::AlignCenter);
        tabWidget_exg->addTab(tab2_2, QString());
        lbl_org_img_1->raise();
        lbl_exg_binary_img->raise();
        frm_exg_thresh = new QFrame(tab_exg);
        frm_exg_thresh->setObjectName(QStringLiteral("frm_exg_thresh"));
        frm_exg_thresh->setGeometry(QRect(10, 440, 211, 111));
        frm_exg_thresh->setFrameShape(QFrame::StyledPanel);
        frm_exg_thresh->setFrameShadow(QFrame::Raised);
        layoutWidget_1 = new QWidget(frm_exg_thresh);
        layoutWidget_1->setObjectName(QStringLiteral("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(10, 10, 191, 91));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        rdbtn_exg_positiv = new QRadioButton(layoutWidget_1);
        rdbtn_exg_positiv->setObjectName(QStringLiteral("rdbtn_exg_positiv"));
        rdbtn_exg_positiv->setChecked(true);

        verticalLayout_3->addWidget(rdbtn_exg_positiv);

        rdbtn_exg_otsu = new QRadioButton(layoutWidget_1);
        rdbtn_exg_otsu->setObjectName(QStringLiteral("rdbtn_exg_otsu"));

        verticalLayout_3->addWidget(rdbtn_exg_otsu);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(28, 74, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rdbtn_exg_manual = new QRadioButton(layoutWidget_1);
        rdbtn_exg_manual->setObjectName(QStringLiteral("rdbtn_exg_manual"));
        rdbtn_exg_manual->setChecked(false);

        verticalLayout_2->addWidget(rdbtn_exg_manual);

        sBox_exg_man_thresh = new QSpinBox(layoutWidget_1);
        sBox_exg_man_thresh->setObjectName(QStringLiteral("sBox_exg_man_thresh"));
        sBox_exg_man_thresh->setEnabled(true);
        sBox_exg_man_thresh->setMaximum(255);

        verticalLayout_2->addWidget(sBox_exg_man_thresh);

        lbl_exg_thresh_range = new QLabel(layoutWidget_1);
        lbl_exg_thresh_range->setObjectName(QStringLiteral("lbl_exg_thresh_range"));
        lbl_exg_thresh_range->setEnabled(true);
        lbl_exg_thresh_range->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lbl_exg_thresh_range);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_2);

        txtBrw_ExG = new QTextBrowser(tab_exg);
        txtBrw_ExG->setObjectName(QStringLiteral("txtBrw_ExG"));
        txtBrw_ExG->setGeometry(QRect(310, 490, 421, 121));
        txtBrw_ExG->setFont(font);
        layoutWidget_7 = new QWidget(tab_exg);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(520, 440, 210, 37));
        verticalLayout_12 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_7);
        label_15->setObjectName(QStringLiteral("label_15"));
        QFont font1;
        font1.setPointSize(9);
        font1.setUnderline(true);
        label_15->setFont(font1);

        verticalLayout_12->addWidget(label_15);

        slider_opacity_exg = new QSlider(layoutWidget_7);
        slider_opacity_exg->setObjectName(QStringLiteral("slider_opacity_exg"));
        slider_opacity_exg->setMaximum(10);
        slider_opacity_exg->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(slider_opacity_exg);

        chkB_exg_invert = new QCheckBox(tab_exg);
        chkB_exg_invert->setObjectName(QStringLiteral("chkB_exg_invert"));
        chkB_exg_invert->setGeometry(QRect(450, 450, 61, 20));
        tabWidget_main->addTab(tab_exg, QString());
        frm_exg_thresh->raise();
        tabWidget_exg->raise();
        txtBrw_ExG->raise();
        layoutWidget_7->raise();
        chkB_exg_invert->raise();
        tab_exr = new QWidget();
        tab_exr->setObjectName(QStringLiteral("tab_exr"));
        tabWidget_exr = new QTabWidget(tab_exr);
        tabWidget_exr->setObjectName(QStringLiteral("tabWidget_exr"));
        tabWidget_exr->setGeometry(QRect(10, 10, 721, 421));
        tabWidget_exr->setCursor(QCursor(Qt::ArrowCursor));
        tab3_3 = new QWidget();
        tab3_3->setObjectName(QStringLiteral("tab3_3"));
        lbl_exr_color_img = new QLabel(tab3_3);
        lbl_exr_color_img->setObjectName(QStringLiteral("lbl_exr_color_img"));
        lbl_exr_color_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exr_color_img->setAutoFillBackground(false);
        lbl_exr_color_img->setAlignment(Qt::AlignCenter);
        tabWidget_exr->addTab(tab3_3, QString());
        tab3_1 = new QWidget();
        tab3_1->setObjectName(QStringLiteral("tab3_1"));
        lbl_exr_grey_img = new QLabel(tab3_1);
        lbl_exr_grey_img->setObjectName(QStringLiteral("lbl_exr_grey_img"));
        lbl_exr_grey_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exr_grey_img->setAutoFillBackground(false);
        lbl_exr_grey_img->setAlignment(Qt::AlignCenter);
        tabWidget_exr->addTab(tab3_1, QString());
        tab3_2 = new QWidget();
        tab3_2->setObjectName(QStringLiteral("tab3_2"));
        lbl_exr_binary_img = new QLabel(tab3_2);
        lbl_exr_binary_img->setObjectName(QStringLiteral("lbl_exr_binary_img"));
        lbl_exr_binary_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exr_binary_img->setAutoFillBackground(false);
        lbl_exr_binary_img->setAlignment(Qt::AlignCenter);
        lbl_org_img_2 = new QLabel(tab3_2);
        lbl_org_img_2->setObjectName(QStringLiteral("lbl_org_img_2"));
        lbl_org_img_2->setGeometry(QRect(10, 10, 691, 371));
        lbl_org_img_2->setAutoFillBackground(false);
        lbl_org_img_2->setAlignment(Qt::AlignCenter);
        tabWidget_exr->addTab(tab3_2, QString());
        lbl_org_img_2->raise();
        lbl_exr_binary_img->raise();
        frm_exr_thresh = new QFrame(tab_exr);
        frm_exr_thresh->setObjectName(QStringLiteral("frm_exr_thresh"));
        frm_exr_thresh->setGeometry(QRect(10, 440, 211, 111));
        frm_exr_thresh->setFrameShape(QFrame::StyledPanel);
        frm_exr_thresh->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(frm_exr_thresh);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 191, 91));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        rdbtn_exr_positiv = new QRadioButton(layoutWidget_2);
        rdbtn_exr_positiv->setObjectName(QStringLiteral("rdbtn_exr_positiv"));
        rdbtn_exr_positiv->setChecked(true);

        verticalLayout_8->addWidget(rdbtn_exr_positiv);

        rdbtn_exr_otsu = new QRadioButton(layoutWidget_2);
        rdbtn_exr_otsu->setObjectName(QStringLiteral("rdbtn_exr_otsu"));

        verticalLayout_8->addWidget(rdbtn_exr_otsu);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_7);


        horizontalLayout_7->addLayout(verticalLayout_8);

        horizontalSpacer_5 = new QSpacerItem(28, 74, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        rdbtn_exr_manual = new QRadioButton(layoutWidget_2);
        rdbtn_exr_manual->setObjectName(QStringLiteral("rdbtn_exr_manual"));
        rdbtn_exr_manual->setChecked(false);

        verticalLayout_7->addWidget(rdbtn_exr_manual);

        sBox_exr_man_thresh = new QSpinBox(layoutWidget_2);
        sBox_exr_man_thresh->setObjectName(QStringLiteral("sBox_exr_man_thresh"));
        sBox_exr_man_thresh->setEnabled(true);
        sBox_exr_man_thresh->setMaximum(255);

        verticalLayout_7->addWidget(sBox_exr_man_thresh);

        lbl_exr_thresh_range = new QLabel(layoutWidget_2);
        lbl_exr_thresh_range->setObjectName(QStringLiteral("lbl_exr_thresh_range"));
        lbl_exr_thresh_range->setEnabled(true);
        lbl_exr_thresh_range->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(lbl_exr_thresh_range);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);


        horizontalLayout_7->addLayout(verticalLayout_7);

        txtBrw_ExR = new QTextBrowser(tab_exr);
        txtBrw_ExR->setObjectName(QStringLiteral("txtBrw_ExR"));
        txtBrw_ExR->setGeometry(QRect(310, 490, 421, 121));
        txtBrw_ExR->setFont(font);
        layoutWidget_6 = new QWidget(tab_exr);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(520, 440, 210, 37));
        verticalLayout_11 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        verticalLayout_11->addWidget(label_14);

        slider_opacity_exr = new QSlider(layoutWidget_6);
        slider_opacity_exr->setObjectName(QStringLiteral("slider_opacity_exr"));
        slider_opacity_exr->setMaximum(10);
        slider_opacity_exr->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_opacity_exr);

        chkB_exr_invert = new QCheckBox(tab_exr);
        chkB_exr_invert->setObjectName(QStringLiteral("chkB_exr_invert"));
        chkB_exr_invert->setGeometry(QRect(450, 450, 61, 20));
        tabWidget_main->addTab(tab_exr, QString());
        tab_exgr = new QWidget();
        tab_exgr->setObjectName(QStringLiteral("tab_exgr"));
        tabWidget_exgr = new QTabWidget(tab_exgr);
        tabWidget_exgr->setObjectName(QStringLiteral("tabWidget_exgr"));
        tabWidget_exgr->setGeometry(QRect(10, 10, 721, 421));
        tab4_3 = new QWidget();
        tab4_3->setObjectName(QStringLiteral("tab4_3"));
        lbl_exgr_color_img = new QLabel(tab4_3);
        lbl_exgr_color_img->setObjectName(QStringLiteral("lbl_exgr_color_img"));
        lbl_exgr_color_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exgr_color_img->setAutoFillBackground(false);
        lbl_exgr_color_img->setAlignment(Qt::AlignCenter);
        tabWidget_exgr->addTab(tab4_3, QString());
        tab4_1 = new QWidget();
        tab4_1->setObjectName(QStringLiteral("tab4_1"));
        lbl_exgr_grey_img = new QLabel(tab4_1);
        lbl_exgr_grey_img->setObjectName(QStringLiteral("lbl_exgr_grey_img"));
        lbl_exgr_grey_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exgr_grey_img->setAutoFillBackground(false);
        lbl_exgr_grey_img->setAlignment(Qt::AlignCenter);
        tabWidget_exgr->addTab(tab4_1, QString());
        tab4_2 = new QWidget();
        tab4_2->setObjectName(QStringLiteral("tab4_2"));
        lbl_exgr_binary_img = new QLabel(tab4_2);
        lbl_exgr_binary_img->setObjectName(QStringLiteral("lbl_exgr_binary_img"));
        lbl_exgr_binary_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_exgr_binary_img->setAutoFillBackground(false);
        lbl_exgr_binary_img->setAlignment(Qt::AlignCenter);
        lbl_org_img_3 = new QLabel(tab4_2);
        lbl_org_img_3->setObjectName(QStringLiteral("lbl_org_img_3"));
        lbl_org_img_3->setGeometry(QRect(10, 10, 691, 371));
        lbl_org_img_3->setAutoFillBackground(false);
        lbl_org_img_3->setAlignment(Qt::AlignCenter);
        tabWidget_exgr->addTab(tab4_2, QString());
        lbl_org_img_3->raise();
        lbl_exgr_binary_img->raise();
        frm_exgr_thresh = new QFrame(tab_exgr);
        frm_exgr_thresh->setObjectName(QStringLiteral("frm_exgr_thresh"));
        frm_exgr_thresh->setGeometry(QRect(10, 440, 211, 111));
        frm_exgr_thresh->setFrameShape(QFrame::StyledPanel);
        frm_exgr_thresh->setFrameShadow(QFrame::Raised);
        layoutWidget_3 = new QWidget(frm_exgr_thresh);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 10, 191, 91));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        rdbtn_exgr_positiv = new QRadioButton(layoutWidget_3);
        rdbtn_exgr_positiv->setObjectName(QStringLiteral("rdbtn_exgr_positiv"));
        rdbtn_exgr_positiv->setChecked(true);

        verticalLayout_10->addWidget(rdbtn_exgr_positiv);

        rdbtn_exgr_otsu = new QRadioButton(layoutWidget_3);
        rdbtn_exgr_otsu->setObjectName(QStringLiteral("rdbtn_exgr_otsu"));

        verticalLayout_10->addWidget(rdbtn_exgr_otsu);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_9);


        horizontalLayout_8->addLayout(verticalLayout_10);

        horizontalSpacer_6 = new QSpacerItem(28, 74, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        rdbtn_exgr_manual = new QRadioButton(layoutWidget_3);
        rdbtn_exgr_manual->setObjectName(QStringLiteral("rdbtn_exgr_manual"));
        rdbtn_exgr_manual->setChecked(false);

        verticalLayout_9->addWidget(rdbtn_exgr_manual);

        sBox_exgr_man_thresh = new QSpinBox(layoutWidget_3);
        sBox_exgr_man_thresh->setObjectName(QStringLiteral("sBox_exgr_man_thresh"));
        sBox_exgr_man_thresh->setEnabled(true);
        sBox_exgr_man_thresh->setMaximum(255);

        verticalLayout_9->addWidget(sBox_exgr_man_thresh);

        lbl_exgr_thresh_range = new QLabel(layoutWidget_3);
        lbl_exgr_thresh_range->setObjectName(QStringLiteral("lbl_exgr_thresh_range"));
        lbl_exgr_thresh_range->setEnabled(true);
        lbl_exgr_thresh_range->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(lbl_exgr_thresh_range);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_8);


        horizontalLayout_8->addLayout(verticalLayout_9);

        txtBrw_ExGR = new QTextBrowser(tab_exgr);
        txtBrw_ExGR->setObjectName(QStringLiteral("txtBrw_ExGR"));
        txtBrw_ExGR->setGeometry(QRect(310, 490, 421, 121));
        txtBrw_ExGR->setFont(font);
        layoutWidget = new QWidget(tab_exgr);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(520, 440, 210, 37));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        verticalLayout_6->addWidget(label_13);

        slider_opacity_exgr = new QSlider(layoutWidget);
        slider_opacity_exgr->setObjectName(QStringLiteral("slider_opacity_exgr"));
        slider_opacity_exgr->setMaximum(10);
        slider_opacity_exgr->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(slider_opacity_exgr);

        chkB_exgr_invert = new QCheckBox(tab_exgr);
        chkB_exgr_invert->setObjectName(QStringLiteral("chkB_exgr_invert"));
        chkB_exgr_invert->setGeometry(QRect(450, 450, 61, 20));
        tabWidget_main->addTab(tab_exgr, QString());
        tab_filter = new QWidget();
        tab_filter->setObjectName(QStringLiteral("tab_filter"));
        tabWidget_filter = new QTabWidget(tab_filter);
        tabWidget_filter->setObjectName(QStringLiteral("tabWidget_filter"));
        tabWidget_filter->setGeometry(QRect(10, 10, 721, 421));
        tab5_1 = new QWidget();
        tab5_1->setObjectName(QStringLiteral("tab5_1"));
        lbl_filter_color_img = new QLabel(tab5_1);
        lbl_filter_color_img->setObjectName(QStringLiteral("lbl_filter_color_img"));
        lbl_filter_color_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_filter_color_img->setAutoFillBackground(false);
        lbl_filter_color_img->setAlignment(Qt::AlignCenter);
        tabWidget_filter->addTab(tab5_1, QString());
        tab5_2 = new QWidget();
        tab5_2->setObjectName(QStringLiteral("tab5_2"));
        lbl_filter_processedColor_img = new QLabel(tab5_2);
        lbl_filter_processedColor_img->setObjectName(QStringLiteral("lbl_filter_processedColor_img"));
        lbl_filter_processedColor_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_filter_processedColor_img->setAutoFillBackground(false);
        lbl_filter_processedColor_img->setAlignment(Qt::AlignCenter);
        tabWidget_filter->addTab(tab5_2, QString());
        tab5_3 = new QWidget();
        tab5_3->setObjectName(QStringLiteral("tab5_3"));
        lbl_filter_binary_img = new QLabel(tab5_3);
        lbl_filter_binary_img->setObjectName(QStringLiteral("lbl_filter_binary_img"));
        lbl_filter_binary_img->setGeometry(QRect(10, 10, 691, 371));
        lbl_filter_binary_img->setAutoFillBackground(false);
        lbl_filter_binary_img->setAlignment(Qt::AlignCenter);
        lbl_org_img_4 = new QLabel(tab5_3);
        lbl_org_img_4->setObjectName(QStringLiteral("lbl_org_img_4"));
        lbl_org_img_4->setGeometry(QRect(10, 10, 691, 371));
        lbl_org_img_4->setAutoFillBackground(false);
        lbl_org_img_4->setAlignment(Qt::AlignCenter);
        tabWidget_filter->addTab(tab5_3, QString());
        lbl_org_img_4->raise();
        lbl_filter_binary_img->raise();
        txtBrw_filter = new QTextBrowser(tab_filter);
        txtBrw_filter->setObjectName(QStringLiteral("txtBrw_filter"));
        txtBrw_filter->setGeometry(QRect(310, 490, 421, 121));
        txtBrw_filter->setFont(font);
        tabWidget_filter_settings = new QTabWidget(tab_filter);
        tabWidget_filter_settings->setObjectName(QStringLiteral("tabWidget_filter_settings"));
        tabWidget_filter_settings->setGeometry(QRect(10, 440, 291, 171));
        QFont font2;
        font2.setPointSize(8);
        tabWidget_filter_settings->setFont(font2);
        tab5_4 = new QWidget();
        tab5_4->setObjectName(QStringLiteral("tab5_4"));
        layoutWidget_4 = new QWidget(tab5_4);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 10, 81, 48));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        rdbtn_filter_hsv = new QRadioButton(layoutWidget_4);
        rdbtn_filter_hsv->setObjectName(QStringLiteral("rdbtn_filter_hsv"));
        rdbtn_filter_hsv->setChecked(true);

        verticalLayout_4->addWidget(rdbtn_filter_hsv);

        rdbtn_filter_cielab = new QRadioButton(layoutWidget_4);
        rdbtn_filter_cielab->setObjectName(QStringLiteral("rdbtn_filter_cielab"));

        verticalLayout_4->addWidget(rdbtn_filter_cielab);

        layoutWidget_5 = new QWidget(tab5_4);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 60, 81, 48));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        chkB_filter_addExG = new QCheckBox(layoutWidget_5);
        chkB_filter_addExG->setObjectName(QStringLiteral("chkB_filter_addExG"));

        verticalLayout_5->addWidget(chkB_filter_addExG);

        chkB_filter_addExR = new QCheckBox(layoutWidget_5);
        chkB_filter_addExR->setObjectName(QStringLiteral("chkB_filter_addExR"));

        verticalLayout_5->addWidget(chkB_filter_addExR);

        sBox_min1 = new QSpinBox(tab5_4);
        sBox_min1->setObjectName(QStringLiteral("sBox_min1"));
        sBox_min1->setGeometry(QRect(166, 30, 51, 23));
        sBox_min1->setMaximum(255);
        sBox_max1 = new QSpinBox(tab5_4);
        sBox_max1->setObjectName(QStringLiteral("sBox_max1"));
        sBox_max1->setGeometry(QRect(230, 30, 51, 23));
        sBox_max1->setMaximum(255);
        sBox_max1->setValue(255);
        sBox_min2 = new QSpinBox(tab5_4);
        sBox_min2->setObjectName(QStringLiteral("sBox_min2"));
        sBox_min2->setGeometry(QRect(166, 60, 51, 23));
        sBox_min2->setMinimum(0);
        sBox_min2->setMaximum(255);
        sBox_max2 = new QSpinBox(tab5_4);
        sBox_max2->setObjectName(QStringLiteral("sBox_max2"));
        sBox_max2->setGeometry(QRect(230, 60, 51, 23));
        sBox_max2->setMaximum(255);
        sBox_max2->setValue(255);
        sBox_min3 = new QSpinBox(tab5_4);
        sBox_min3->setObjectName(QStringLiteral("sBox_min3"));
        sBox_min3->setGeometry(QRect(166, 90, 51, 23));
        sBox_min3->setMaximum(255);
        sBox_max3 = new QSpinBox(tab5_4);
        sBox_max3->setObjectName(QStringLiteral("sBox_max3"));
        sBox_max3->setGeometry(QRect(230, 90, 51, 23));
        sBox_max3->setMaximum(255);
        sBox_max3->setValue(255);
        label_5 = new QLabel(tab5_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 10, 41, 16));
        label_6 = new QLabel(tab5_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 10, 41, 16));
        lbl_filter_h_l = new QLabel(tab5_4);
        lbl_filter_h_l->setObjectName(QStringLiteral("lbl_filter_h_l"));
        lbl_filter_h_l->setGeometry(QRect(120, 30, 31, 21));
        lbl_filter_h_l->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_filter_s_a = new QLabel(tab5_4);
        lbl_filter_s_a->setObjectName(QStringLiteral("lbl_filter_s_a"));
        lbl_filter_s_a->setGeometry(QRect(120, 60, 31, 21));
        lbl_filter_s_a->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_filter_v_b = new QLabel(tab5_4);
        lbl_filter_v_b->setObjectName(QStringLiteral("lbl_filter_v_b"));
        lbl_filter_v_b->setGeometry(QRect(120, 90, 31, 21));
        lbl_filter_v_b->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtBrw_min1 = new QTextBrowser(tab5_4);
        txtBrw_min1->setObjectName(QStringLiteral("txtBrw_min1"));
        txtBrw_min1->setGeometry(QRect(170, 30, 41, 21));
        txtBrw_min1->setInputMethodHints(Qt::ImhNone);
        txtBrw_min1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_min1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_min2 = new QTextBrowser(tab5_4);
        txtBrw_min2->setObjectName(QStringLiteral("txtBrw_min2"));
        txtBrw_min2->setGeometry(QRect(170, 60, 41, 21));
        txtBrw_min2->setInputMethodHints(Qt::ImhNone);
        txtBrw_min2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_min2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_min3 = new QTextBrowser(tab5_4);
        txtBrw_min3->setObjectName(QStringLiteral("txtBrw_min3"));
        txtBrw_min3->setGeometry(QRect(170, 90, 41, 21));
        txtBrw_min3->setInputMethodHints(Qt::ImhNone);
        txtBrw_min3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_min3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_max1 = new QTextBrowser(tab5_4);
        txtBrw_max1->setObjectName(QStringLiteral("txtBrw_max1"));
        txtBrw_max1->setGeometry(QRect(230, 30, 41, 21));
        txtBrw_max1->setInputMethodHints(Qt::ImhNone);
        txtBrw_max1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_max1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_max2 = new QTextBrowser(tab5_4);
        txtBrw_max2->setObjectName(QStringLiteral("txtBrw_max2"));
        txtBrw_max2->setGeometry(QRect(230, 60, 41, 21));
        txtBrw_max2->setInputMethodHints(Qt::ImhNone);
        txtBrw_max2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_max2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_max3 = new QTextBrowser(tab5_4);
        txtBrw_max3->setObjectName(QStringLiteral("txtBrw_max3"));
        txtBrw_max3->setGeometry(QRect(230, 90, 41, 21));
        txtBrw_max3->setInputMethodHints(Qt::ImhNone);
        txtBrw_max3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBrw_max3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget_filter_settings->addTab(tab5_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget_8 = new QWidget(tab_2);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 30, 241, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rdbtn_auto_filter_method_MeanStdDev = new QRadioButton(layoutWidget_8);
        rdbtn_auto_filter_method_MeanStdDev->setObjectName(QStringLiteral("rdbtn_auto_filter_method_MeanStdDev"));
        rdbtn_auto_filter_method_MeanStdDev->setChecked(true);

        horizontalLayout_3->addWidget(rdbtn_auto_filter_method_MeanStdDev);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        rdbtn_auto_filter_method_Quantile = new QRadioButton(layoutWidget_8);
        rdbtn_auto_filter_method_Quantile->setObjectName(QStringLiteral("rdbtn_auto_filter_method_Quantile"));
        rdbtn_auto_filter_method_Quantile->setChecked(false);

        horizontalLayout_3->addWidget(rdbtn_auto_filter_method_Quantile);

        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 92, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rdbtn_auto_filter_on = new QRadioButton(layoutWidget1);
        rdbtn_auto_filter_on->setObjectName(QStringLiteral("rdbtn_auto_filter_on"));

        horizontalLayout->addWidget(rdbtn_auto_filter_on);

        rdbtn_auto_filter_off = new QRadioButton(layoutWidget1);
        rdbtn_auto_filter_off->setObjectName(QStringLiteral("rdbtn_auto_filter_off"));
        rdbtn_auto_filter_off->setChecked(true);

        horizontalLayout->addWidget(rdbtn_auto_filter_off);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(170, 50, 97, 58));
        verticalLayout_13 = new QVBoxLayout(layoutWidget2);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        sBox_plant_quantil = new QDoubleSpinBox(layoutWidget2);
        sBox_plant_quantil->setObjectName(QStringLiteral("sBox_plant_quantil"));
        sBox_plant_quantil->setDecimals(2);
        sBox_plant_quantil->setMaximum(1);
        sBox_plant_quantil->setSingleStep(0.01);
        sBox_plant_quantil->setValue(0.5);

        horizontalLayout_4->addWidget(sBox_plant_quantil);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QStringLiteral("label_16"));
        QFont font3;
        font3.setPointSize(9);
        label_16->setFont(font3);

        horizontalLayout_4->addWidget(label_16);


        verticalLayout_13->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        sBox_soil_quantil = new QDoubleSpinBox(layoutWidget2);
        sBox_soil_quantil->setObjectName(QStringLiteral("sBox_soil_quantil"));
        sBox_soil_quantil->setDecimals(2);
        sBox_soil_quantil->setMaximum(1);
        sBox_soil_quantil->setSingleStep(0.01);
        sBox_soil_quantil->setValue(0.5);

        horizontalLayout_5->addWidget(sBox_soil_quantil);

        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font2);

        horizontalLayout_5->addWidget(label_17);


        verticalLayout_13->addLayout(horizontalLayout_5);

        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 50, 97, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        sBox_Sigma = new QSpinBox(layoutWidget3);
        sBox_Sigma->setObjectName(QStringLiteral("sBox_Sigma"));
        sBox_Sigma->setMinimum(1);
        sBox_Sigma->setMaximum(3);

        horizontalLayout_6->addWidget(sBox_Sigma);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        horizontalLayout_6->addWidget(label_3);

        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 80, 77, 71));
        verticalLayout_14 = new QVBoxLayout(layoutWidget4);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        rdbtn_ExG_ExR_Filter = new QRadioButton(layoutWidget4);
        rdbtn_ExG_ExR_Filter->setObjectName(QStringLiteral("rdbtn_ExG_ExR_Filter"));
        rdbtn_ExG_ExR_Filter->setChecked(true);

        verticalLayout_14->addWidget(rdbtn_ExG_ExR_Filter);

        rdbtn_ExG_Filter = new QRadioButton(layoutWidget4);
        rdbtn_ExG_Filter->setObjectName(QStringLiteral("rdbtn_ExG_Filter"));

        verticalLayout_14->addWidget(rdbtn_ExG_Filter);

        rdbtn_ExGR_Filter = new QRadioButton(layoutWidget4);
        rdbtn_ExGR_Filter->setObjectName(QStringLiteral("rdbtn_ExGR_Filter"));

        verticalLayout_14->addWidget(rdbtn_ExGR_Filter);

        tabWidget_filter_settings->addTab(tab_2, QString());
        tab5_6 = new QWidget();
        tab5_6->setObjectName(QStringLiteral("tab5_6"));
        label_10 = new QLabel(tab5_6);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 0, 231, 141));
        tabWidget_filter_settings->addTab(tab5_6, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 0, 251, 141));
        tabWidget_filter_settings->addTab(tab, QString());
        label_2 = new QLabel(tab_filter);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 430, 471, 16));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        label_2->setFont(font4);
        layoutWidget5 = new QWidget(tab_filter);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(520, 440, 210, 37));
        verticalLayout = new QVBoxLayout(layoutWidget5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        verticalLayout->addWidget(label_12);

        slider_opacity_filter = new QSlider(layoutWidget5);
        slider_opacity_filter->setObjectName(QStringLiteral("slider_opacity_filter"));
        slider_opacity_filter->setMaximum(10);
        slider_opacity_filter->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_opacity_filter);

        chkB_filter_invert = new QCheckBox(tab_filter);
        chkB_filter_invert->setObjectName(QStringLiteral("chkB_filter_invert"));
        chkB_filter_invert->setGeometry(QRect(450, 450, 61, 20));
        chkB_zoom_filter = new QCheckBox(tab_filter);
        chkB_zoom_filter->setObjectName(QStringLiteral("chkB_zoom_filter"));
        chkB_zoom_filter->setGeometry(QRect(360, 450, 81, 20));
        btn_save_filter_binary = new QPushButton(tab_filter);
        btn_save_filter_binary->setObjectName(QStringLiteral("btn_save_filter_binary"));
        btn_save_filter_binary->setGeometry(QRect(310, 450, 41, 22));
        tabWidget_main->addTab(tab_filter, QString());
        btn_Quit = new QPushButton(main_window);
        btn_Quit->setObjectName(QStringLiteral("btn_Quit"));
        btn_Quit->setGeometry(QRect(650, 750, 101, 40));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        btn_Quit->setFont(font5);
        btn_edit_image = new QPushButton(main_window);
        btn_edit_image->setObjectName(QStringLiteral("btn_edit_image"));
        btn_edit_image->setGeometry(QRect(460, 40, 111, 22));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        btn_edit_image->setFont(font6);
        btn_OpenImage = new QPushButton(main_window);
        btn_OpenImage->setObjectName(QStringLiteral("btn_OpenImage"));
        btn_OpenImage->setGeometry(QRect(620, 40, 121, 22));
        btn_OpenImage->setFont(font6);
        label = new QLabel(main_window);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 201, 61));
        label_4 = new QLabel(main_window);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 750, 291, 40));
        btn_save = new QPushButton(main_window);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(470, 750, 161, 40));
        btn_save->setFont(font6);
        btn_reset = new QPushButton(main_window);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));
        btn_reset->setGeometry(QRect(460, 40, 111, 22));
        btn_reset->setFont(font6);
        btn_development = new QPushButton(main_window);
        btn_development->setObjectName(QStringLiteral("btn_development"));
        btn_development->setGeometry(QRect(10, 750, 131, 40));
        btn_development->setFont(font6);
        comboBox_img_list = new QComboBox(main_window);
        comboBox_img_list->setObjectName(QStringLiteral("comboBox_img_list"));
        comboBox_img_list->setGeometry(QRect(460, 70, 281, 20));
        btn_Analyse_BinaryImg = new QPushButton(main_window);
        btn_Analyse_BinaryImg->setObjectName(QStringLiteral("btn_Analyse_BinaryImg"));
        btn_Analyse_BinaryImg->setEnabled(true);
        btn_Analyse_BinaryImg->setGeometry(QRect(390, 750, 71, 41));
        QFont font7;
        font7.setPointSize(7);
        btn_Analyse_BinaryImg->setFont(font7);
        btn_next = new QPushButton(main_window);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        btn_next->setGeometry(QRect(690, 90, 51, 20));
        btn_next->setFont(font3);
        btn_back = new QPushButton(main_window);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setGeometry(QRect(460, 90, 51, 20));
        btn_back->setFont(font3);
        btn_gtMask_vs_binaryImg = new QPushButton(main_window);
        btn_gtMask_vs_binaryImg->setObjectName(QStringLiteral("btn_gtMask_vs_binaryImg"));
        btn_gtMask_vs_binaryImg->setGeometry(QRect(320, 750, 61, 40));
        QFont font8;
        font8.setPointSize(7);
        font8.setBold(false);
        font8.setWeight(50);
        btn_gtMask_vs_binaryImg->setFont(font8);
        tabWidget_main->raise();
        btn_Quit->raise();
        label->raise();
        label_4->raise();
        btn_save->raise();
        btn_reset->raise();
        btn_edit_image->raise();
        btn_OpenImage->raise();
        btn_development->raise();
        comboBox_img_list->raise();
        btn_Analyse_BinaryImg->raise();
        btn_next->raise();
        btn_back->raise();
        btn_gtMask_vs_binaryImg->raise();

        retranslateUi(main_window);
        QObject::connect(rdbtn_exg_manual, SIGNAL(clicked()), sBox_exg_man_thresh, SLOT(show()));
        QObject::connect(rdbtn_exg_manual, SIGNAL(clicked()), lbl_exg_thresh_range, SLOT(show()));
        QObject::connect(rdbtn_exg_otsu, SIGNAL(clicked()), sBox_exg_man_thresh, SLOT(hide()));
        QObject::connect(rdbtn_exg_otsu, SIGNAL(clicked()), lbl_exg_thresh_range, SLOT(hide()));
        QObject::connect(rdbtn_exg_positiv, SIGNAL(clicked()), sBox_exg_man_thresh, SLOT(hide()));
        QObject::connect(rdbtn_exg_positiv, SIGNAL(clicked()), lbl_exg_thresh_range, SLOT(hide()));
        QObject::connect(rdbtn_exr_manual, SIGNAL(clicked()), sBox_exr_man_thresh, SLOT(show()));
        QObject::connect(rdbtn_exr_manual, SIGNAL(clicked()), lbl_exr_thresh_range, SLOT(show()));
        QObject::connect(rdbtn_exr_positiv, SIGNAL(clicked()), sBox_exr_man_thresh, SLOT(hide()));
        QObject::connect(rdbtn_exr_positiv, SIGNAL(clicked()), lbl_exr_thresh_range, SLOT(hide()));
        QObject::connect(rdbtn_exr_otsu, SIGNAL(clicked()), sBox_exr_man_thresh, SLOT(hide()));
        QObject::connect(rdbtn_exr_otsu, SIGNAL(clicked()), lbl_exr_thresh_range, SLOT(hide()));
        QObject::connect(rdbtn_exgr_manual, SIGNAL(clicked()), sBox_exgr_man_thresh, SLOT(show()));
        QObject::connect(rdbtn_exgr_manual, SIGNAL(clicked()), lbl_exgr_thresh_range, SLOT(show()));
        QObject::connect(rdbtn_exgr_positiv, SIGNAL(clicked()), sBox_exgr_man_thresh, SLOT(hide()));
        QObject::connect(rdbtn_exgr_positiv, SIGNAL(clicked()), lbl_exgr_thresh_range, SLOT(hide()));
        QObject::connect(rdbtn_exgr_otsu, SIGNAL(clicked()), sBox_exgr_man_thresh, SLOT(hide()));
        QObject::connect(rdbtn_exgr_otsu, SIGNAL(clicked()), lbl_exgr_thresh_range, SLOT(hide()));

        tabWidget_main->setCurrentIndex(0);
        tabWidget_hist->setCurrentIndex(0);
        tabWidget_exg->setCurrentIndex(0);
        tabWidget_exr->setCurrentIndex(0);
        tabWidget_exgr->setCurrentIndex(0);
        tabWidget_filter->setCurrentIndex(0);
        tabWidget_filter_settings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "DPA", 0));
        lbl_org_img->setText(QApplication::translate("main_window", "Orinial Image", 0));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_org), QApplication::translate("main_window", "Original", 0));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_info), QApplication::translate("main_window", "Info", 0));
        lbl_hist_hue_img->setText(QApplication::translate("main_window", "Histogram Image", 0));
        label_9->setText(QApplication::translate("main_window", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; font-style:italic;\">&quot;Hue&quot;</span></p></body></html>", 0));
        tabWidget_hist->setTabText(tabWidget_hist->indexOf(tab6_1), QApplication::translate("main_window", "HSV", 0));
        lbl_hist_a_img->setText(QApplication::translate("main_window", "Histogram Image \n"
" CieLab \n"
" \"a\"", 0));
        lbl_hist_b_img->setText(QApplication::translate("main_window", "Histogram Image \n"
" CieLab \n"
" \"b\"", 0));
        label_7->setText(QApplication::translate("main_window", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; font-style:italic;\">&quot;a&quot;</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("main_window", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; font-style:italic;\">&quot;b&quot;</span></p></body></html>", 0));
        tabWidget_hist->setTabText(tabWidget_hist->indexOf(tab6_2), QApplication::translate("main_window", "CieLab", 0));
        label_19->setText(QApplication::translate("main_window", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; font-style:italic;\">&quot;L&quot;</span></p></body></html>", 0));
        lbl_hist_L_img->setText(QApplication::translate("main_window", "Histogram Image \n"
" CieLab \n"
" \"L\"", 0));
        tabWidget_hist->setTabText(tabWidget_hist->indexOf(tab6_3), QApplication::translate("main_window", "\"L\"", 0));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_hist), QApplication::translate("main_window", "Histogram", 0));
        lbl_exg_color_img->setText(QApplication::translate("main_window", "ExG Color-Image", 0));
        tabWidget_exg->setTabText(tabWidget_exg->indexOf(tab2_3), QApplication::translate("main_window", "Color-Style", 0));
        lbl_exg_grey_img->setText(QApplication::translate("main_window", "ExG Grey-Image", 0));
        tabWidget_exg->setTabText(tabWidget_exg->indexOf(tab2_1), QApplication::translate("main_window", "Gray-Style", 0));
        lbl_exg_binary_img->setText(QApplication::translate("main_window", "ExG Binary-Image", 0));
        lbl_org_img_1->setText(QApplication::translate("main_window", "Original Image", 0));
        tabWidget_exg->setTabText(tabWidget_exg->indexOf(tab2_2), QApplication::translate("main_window", "Binary-Style", 0));
        rdbtn_exg_positiv->setText(QApplication::translate("main_window", "Positiv (0)", 0));
        rdbtn_exg_otsu->setText(QApplication::translate("main_window", "Otsu", 0));
        rdbtn_exg_manual->setText(QApplication::translate("main_window", "Manual", 0));
        lbl_exg_thresh_range->setText(QApplication::translate("main_window", "(0 - 255)", 0));
        label_15->setText(QApplication::translate("main_window", "                Transparency                 ", 0));
        chkB_exg_invert->setText(QApplication::translate("main_window", "Invert", 0));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_exg), QApplication::translate("main_window", "ExG", 0));
        lbl_exr_color_img->setText(QApplication::translate("main_window", "ExR Color-Image", 0));
        tabWidget_exr->setTabText(tabWidget_exr->indexOf(tab3_3), QApplication::translate("main_window", "Color-Style", 0));
        lbl_exr_grey_img->setText(QApplication::translate("main_window", "ExR Grey-Image", 0));
        tabWidget_exr->setTabText(tabWidget_exr->indexOf(tab3_1), QApplication::translate("main_window", "Gray-Style", 0));
        lbl_exr_binary_img->setText(QApplication::translate("main_window", "ExR Binary-Image", 0));
        lbl_org_img_2->setText(QApplication::translate("main_window", "Original Image", 0));
        tabWidget_exr->setTabText(tabWidget_exr->indexOf(tab3_2), QApplication::translate("main_window", "Binary-Style", 0));
        rdbtn_exr_positiv->setText(QApplication::translate("main_window", "Positiv (0)", 0));
        rdbtn_exr_otsu->setText(QApplication::translate("main_window", "Otsu", 0));
        rdbtn_exr_manual->setText(QApplication::translate("main_window", "Manual", 0));
        lbl_exr_thresh_range->setText(QApplication::translate("main_window", "(0 - 255)", 0));
        label_14->setText(QApplication::translate("main_window", "                Transparency                 ", 0));
        chkB_exr_invert->setText(QApplication::translate("main_window", "Invert", 0));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_exr), QApplication::translate("main_window", "ExR", 0));
        lbl_exgr_color_img->setText(QApplication::translate("main_window", "ExG-ExR Color-Image", 0));
        tabWidget_exgr->setTabText(tabWidget_exgr->indexOf(tab4_3), QApplication::translate("main_window", "Color-Style", 0));
        lbl_exgr_grey_img->setText(QApplication::translate("main_window", "ExG-ExR Grey-Image", 0));
        tabWidget_exgr->setTabText(tabWidget_exgr->indexOf(tab4_1), QApplication::translate("main_window", "Gray-Style", 0));
        lbl_exgr_binary_img->setText(QApplication::translate("main_window", "ExG-ExR Binary-Image", 0));
        lbl_org_img_3->setText(QApplication::translate("main_window", "Original Image", 0));
        tabWidget_exgr->setTabText(tabWidget_exgr->indexOf(tab4_2), QApplication::translate("main_window", "Binary-Style", 0));
        rdbtn_exgr_positiv->setText(QApplication::translate("main_window", "Positiv (0)", 0));
        rdbtn_exgr_otsu->setText(QApplication::translate("main_window", "Otsu", 0));
        rdbtn_exgr_manual->setText(QApplication::translate("main_window", "Manual", 0));
        lbl_exgr_thresh_range->setText(QApplication::translate("main_window", "(0 - 255)", 0));
        label_13->setText(QApplication::translate("main_window", "                Transparency                 ", 0));
        chkB_exgr_invert->setText(QApplication::translate("main_window", "Invert", 0));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_exgr), QApplication::translate("main_window", "ExG-ExR", 0));
        lbl_filter_color_img->setText(QApplication::translate("main_window", "Filter Color-Image", 0));
        tabWidget_filter->setTabText(tabWidget_filter->indexOf(tab5_1), QApplication::translate("main_window", "Color-Style", 0));
        lbl_filter_processedColor_img->setText(QApplication::translate("main_window", "Filter processed Image", 0));
        tabWidget_filter->setTabText(tabWidget_filter->indexOf(tab5_2), QApplication::translate("main_window", "processed Color", 0));
        lbl_filter_binary_img->setText(QApplication::translate("main_window", "Filter Binary-Image", 0));
        lbl_org_img_4->setText(QApplication::translate("main_window", "Original Image", 0));
        tabWidget_filter->setTabText(tabWidget_filter->indexOf(tab5_3), QApplication::translate("main_window", "Binary-Style", 0));
        rdbtn_filter_hsv->setText(QApplication::translate("main_window", "HSV", 0));
        rdbtn_filter_cielab->setText(QApplication::translate("main_window", "CieLab", 0));
        chkB_filter_addExG->setText(QApplication::translate("main_window", "add ExG", 0));
        chkB_filter_addExR->setText(QApplication::translate("main_window", "add ExR", 0));
        label_5->setText(QApplication::translate("main_window", "Min.", 0));
        label_6->setText(QApplication::translate("main_window", "Max.", 0));
        lbl_filter_h_l->setText(QApplication::translate("main_window", "H / L", 0));
        lbl_filter_s_a->setText(QApplication::translate("main_window", "S / a", 0));
        lbl_filter_v_b->setText(QApplication::translate("main_window", "V / b", 0));
        txtBrw_min1->setHtml(QApplication::translate("main_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">255</span></p></body></html>", 0));
        txtBrw_min2->setHtml(QApplication::translate("main_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">255</span></p></body></html>", 0));
        txtBrw_min3->setHtml(QApplication::translate("main_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">255</span></p></body></html>", 0));
        txtBrw_max1->setHtml(QApplication::translate("main_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">255</span></p></body></html>", 0));
        txtBrw_max2->setHtml(QApplication::translate("main_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">255</span></p></body></html>", 0));
        txtBrw_max3->setHtml(QApplication::translate("main_window", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">255</span></p></body></html>", 0));
        tabWidget_filter_settings->setTabText(tabWidget_filter_settings->indexOf(tab5_4), QApplication::translate("main_window", "Filter", 0));
        rdbtn_auto_filter_method_MeanStdDev->setText(QApplication::translate("main_window", "Mean_StdDev", 0));
        rdbtn_auto_filter_method_Quantile->setText(QApplication::translate("main_window", "Quantile", 0));
        rdbtn_auto_filter_on->setText(QApplication::translate("main_window", "On", 0));
        rdbtn_auto_filter_off->setText(QApplication::translate("main_window", "Off", 0));
        label_16->setText(QApplication::translate("main_window", "Plant", 0));
        label_17->setText(QApplication::translate("main_window", "Soil", 0));
        label_3->setText(QApplication::translate("main_window", "\317\203 StdDev", 0));
        rdbtn_ExG_ExR_Filter->setText(QApplication::translate("main_window", "ExG & ExR", 0));
        rdbtn_ExG_Filter->setText(QApplication::translate("main_window", "ExG", 0));
        rdbtn_ExGR_Filter->setText(QApplication::translate("main_window", "ExGR", 0));
        tabWidget_filter_settings->setTabText(tabWidget_filter_settings->indexOf(tab_2), QApplication::translate("main_window", "Auto Filter", 0));
        label_10->setText(QApplication::translate("main_window", "<html><head/><body><p><img src=\":/images/HSV.png\" height=\"160\"/></p></body></html>", 0));
        tabWidget_filter_settings->setTabText(tabWidget_filter_settings->indexOf(tab5_6), QApplication::translate("main_window", "HSV", 0));
        label_11->setText(QApplication::translate("main_window", "<html><head/><body><p><img src=\":/images/lab3.png\" height=\"130\"/></p></body></html>", 0));
        tabWidget_filter_settings->setTabText(tabWidget_filter_settings->indexOf(tab), QApplication::translate("main_window", "CieLab", 0));
        label_2->setText(QApplication::translate("main_window", "Das Tool mit LAB Vektor zum spielen einbauen", 0));
        label_12->setText(QApplication::translate("main_window", "                Transparency                 ", 0));
        chkB_filter_invert->setText(QApplication::translate("main_window", "Invert", 0));
        chkB_zoom_filter->setText(QApplication::translate("main_window", "Fullscreen", 0));
        btn_save_filter_binary->setText(QApplication::translate("main_window", "Save", 0));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_filter), QApplication::translate("main_window", "Filter", 0));
        btn_Quit->setText(QApplication::translate("main_window", "Quit", 0));
        btn_edit_image->setText(QApplication::translate("main_window", "Edit Image", 0));
        btn_OpenImage->setText(QApplication::translate("main_window", "Open Image", 0));
        label->setText(QApplication::translate("main_window", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">DPA </span><span style=\" font-weight:600;\"><br/></span><span style=\" font-size:10pt; font-weight:600;\">DIGITAL PLANT ANALYZER</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("main_window", "<html><head/><body><p align=\"justify\"><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">Copyright (c) 2017-2027, driehle </span><br><align=\"justify\"><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">University of Hohenheim, Germany</span></p></body></html>", 0));
        btn_save->setText(QApplication::translate("main_window", "Save Analysis", 0));
        btn_reset->setText(QApplication::translate("main_window", "Reset", 0));
        btn_development->setText(QApplication::translate("main_window", "Development", 0));
        comboBox_img_list->clear();
        comboBox_img_list->insertItems(0, QStringList()
         << QApplication::translate("main_window", "empty", 0)
        );
        btn_Analyse_BinaryImg->setText(QApplication::translate("main_window", "Analyze \n"
"Binary Image", 0));
        btn_next->setText(QApplication::translate("main_window", "&Next \342\206\222", 0));
        btn_back->setText(QApplication::translate("main_window", "\342\206\220 &Back", 0));
        btn_gtMask_vs_binaryImg->setText(QApplication::translate("main_window", "GT_Mask \n"
" vs \n"
" Binary Img", 0));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
