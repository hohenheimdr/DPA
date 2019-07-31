/********************************************************************************
** Form generated from reading UI file 'development.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVELOPMENT_H
#define UI_DEVELOPMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Development
{
public:
    QLabel *lbl_dG;
    QLabel *lbl_Gn1;
    QLabel *lbl_Gn2;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *ButtonBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_start_Date;
    QComboBox *comboBox_end_Date;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_back;
    QPushButton *btn_next;
    QLabel *lbl_info_1;
    QLabel *lbl_info_2;
    QPushButton *btn_exit;
    QLabel *lbl_text;
    QLabel *lbl_img_start;
    QLabel *lbl_img_end;
    QLabel *lbl_img_end_dg;
    QCheckBox *chkBox_inc_dec;

    void setupUi(QDialog *Development)
    {
        if (Development->objectName().isEmpty())
            Development->setObjectName(QStringLiteral("Development"));
        Development->resize(1026, 775);
        lbl_dG = new QLabel(Development);
        lbl_dG->setObjectName(QStringLiteral("lbl_dG"));
        lbl_dG->setGeometry(QRect(300, 20, 384, 216));
        lbl_dG->setFrameShape(QFrame::Box);
        lbl_dG->setAlignment(Qt::AlignCenter);
        lbl_Gn1 = new QLabel(Development);
        lbl_Gn1->setObjectName(QStringLiteral("lbl_Gn1"));
        lbl_Gn1->setGeometry(QRect(40, 20, 384, 216));
        lbl_Gn1->setFrameShape(QFrame::Box);
        lbl_Gn1->setFrameShadow(QFrame::Plain);
        lbl_Gn1->setAlignment(Qt::AlignCenter);
        lbl_Gn2 = new QLabel(Development);
        lbl_Gn2->setObjectName(QStringLiteral("lbl_Gn2"));
        lbl_Gn2->setGeometry(QRect(590, 20, 384, 216));
        lbl_Gn2->setFrameShape(QFrame::Box);
        lbl_Gn2->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(Development);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 260, 301, 181));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 281, 126));
        ButtonBox = new QVBoxLayout(layoutWidget);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox_start_Date = new QComboBox(layoutWidget);
        comboBox_start_Date->setObjectName(QStringLiteral("comboBox_start_Date"));

        horizontalLayout->addWidget(comboBox_start_Date);

        comboBox_end_Date = new QComboBox(layoutWidget);
        comboBox_end_Date->setObjectName(QStringLiteral("comboBox_end_Date"));

        horizontalLayout->addWidget(comboBox_end_Date);


        ButtonBox->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_back = new QPushButton(layoutWidget);
        btn_back->setObjectName(QStringLiteral("btn_back"));

        horizontalLayout_2->addWidget(btn_back);

        btn_next = new QPushButton(layoutWidget);
        btn_next->setObjectName(QStringLiteral("btn_next"));

        horizontalLayout_2->addWidget(btn_next);


        ButtonBox->addLayout(horizontalLayout_2);

        lbl_info_1 = new QLabel(layoutWidget);
        lbl_info_1->setObjectName(QStringLiteral("lbl_info_1"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbl_info_1->setFont(font);
        lbl_info_1->setInputMethodHints(Qt::ImhMultiLine);
        lbl_info_1->setAlignment(Qt::AlignCenter);

        ButtonBox->addWidget(lbl_info_1);

        lbl_info_2 = new QLabel(layoutWidget);
        lbl_info_2->setObjectName(QStringLiteral("lbl_info_2"));
        lbl_info_2->setFont(font);
        lbl_info_2->setInputMethodHints(Qt::ImhMultiLine);
        lbl_info_2->setAlignment(Qt::AlignCenter);

        ButtonBox->addWidget(lbl_info_2);

        btn_exit = new QPushButton(layoutWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        ButtonBox->addWidget(btn_exit);

        lbl_text = new QLabel(groupBox);
        lbl_text->setObjectName(QStringLiteral("lbl_text"));
        lbl_text->setGeometry(QRect(40, 20, 221, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_text->setFont(font1);
        lbl_img_start = new QLabel(Development);
        lbl_img_start->setObjectName(QStringLiteral("lbl_img_start"));
        lbl_img_start->setGeometry(QRect(40, 250, 384, 216));
        lbl_img_start->setFrameShape(QFrame::Box);
        lbl_img_start->setFrameShadow(QFrame::Plain);
        lbl_img_start->setAlignment(Qt::AlignCenter);
        lbl_img_end = new QLabel(Development);
        lbl_img_end->setObjectName(QStringLiteral("lbl_img_end"));
        lbl_img_end->setGeometry(QRect(590, 250, 384, 216));
        lbl_img_end->setFrameShape(QFrame::Box);
        lbl_img_end->setAlignment(Qt::AlignCenter);
        lbl_img_end_dg = new QLabel(Development);
        lbl_img_end_dg->setObjectName(QStringLiteral("lbl_img_end_dg"));
        lbl_img_end_dg->setGeometry(QRect(30, 230, 384, 216));
        lbl_img_end_dg->setFrameShape(QFrame::Box);
        lbl_img_end_dg->setAlignment(Qt::AlignCenter);
        chkBox_inc_dec = new QCheckBox(Development);
        chkBox_inc_dec->setObjectName(QStringLiteral("chkBox_inc_dec"));
        chkBox_inc_dec->setGeometry(QRect(310, 540, 171, 20));
        groupBox->raise();
        lbl_Gn1->raise();
        lbl_Gn2->raise();
        lbl_dG->raise();
        lbl_img_start->raise();
        lbl_img_end->raise();
        lbl_img_end_dg->raise();
        chkBox_inc_dec->raise();

        retranslateUi(Development);

        QMetaObject::connectSlotsByName(Development);
    } // setupUi

    void retranslateUi(QDialog *Development)
    {
        Development->setWindowTitle(QApplication::translate("Development", "Plant Development", 0));
        lbl_dG->setText(QApplication::translate("Development", "dG", 0));
        lbl_Gn1->setText(QApplication::translate("Development", "Gn1", 0));
        lbl_Gn2->setText(QApplication::translate("Development", "Gn2", 0));
        groupBox->setTitle(QString());
        btn_back->setText(QApplication::translate("Development", "\342\206\220 &Back", 0));
        btn_next->setText(QApplication::translate("Development", "&Next \342\206\222", 0));
        lbl_info_1->setText(QApplication::translate("Development", "Img1 to Img2", 0));
        lbl_info_2->setText(QApplication::translate("Development", "xxx Images", 0));
        btn_exit->setText(QApplication::translate("Development", "&Exit", 0));
        lbl_text->setText(QApplication::translate("Development", "plant development range", 0));
        lbl_img_start->setText(QApplication::translate("Development", "Start", 0));
        lbl_img_end->setText(QApplication::translate("Development", "End", 0));
        lbl_img_end_dg->setText(QApplication::translate("Development", "End + dG", 0));
        chkBox_inc_dec->setText(QApplication::translate("Development", "zunahme / abnhame", 0));
    } // retranslateUi

};

namespace Ui {
    class Development: public Ui_Development {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOPMENT_H
