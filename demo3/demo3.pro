#-------------------------------------------------
#
# Project created by QtCreator 2020-10-18T20:09:57
#
#-------------------------------------------------
#https://github.com/foreverlz1111/CuTe
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login_dialog.cpp \
    mydialog.cpp


HEADERS  += mainwindow.h \
    login_dialog.h \
    mydialog.h

FORMS    += mainwindow.ui \
    login_dialog.ui \
    mydialog.ui

RESOURCES += \
    images.qrc
