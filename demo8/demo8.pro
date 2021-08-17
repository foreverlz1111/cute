#-------------------------------------------------
#
# Project created by QtCreator 2020-10-29T00:09:36
#
#-------------------------------------------------
#https://github.com/foreverlz1111/CuTe
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo8
TEMPLATE = app


SOURCES += main.cpp\
        calculater.cpp \
    aboutit.cpp

HEADERS  += calculater.h \
    aboutit.h

FORMS    += calculater.ui \
    aboutit.ui

RESOURCES += \
    img.qrc
