#-------------------------------------------------
#
# Project created by QtCreator 2017-10-16T21:15:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# TARGET = DPA
TARGET = DPA
TEMPLATE = app


SOURCES += main.cpp\
    main_window.cpp \
    save_window.cpp \
    dpa_image.cpp \
    config.cpp \
    edit_image.cpp \
    development.cpp \
    image_library.cpp \
    analyse_binary_img.cpp \
    gt_mask_vs_binary_img.cpp

HEADERS  += \
    main_window.h \
    save_window.h \
    dpa_image.h \
    config.h \
    edit_image.h \
    development.h \
    image_library.h \
    analyse_binary_img.h \
    gt_mask_vs_binary_img.h

FORMS    += \
    main_window.ui \
    save_window.ui \
    edit_image.ui \
    development.ui \
    analyse_binary_img.ui \
    gt_mask_vs_binary_img.ui

INCLUDEPATH += "/usr/local/include/"

LIBS += `pkg-config --libs opencv`

RESOURCES += \
    bilder.qrc
