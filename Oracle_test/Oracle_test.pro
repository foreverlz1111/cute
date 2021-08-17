#-------------------------------------------------
#
# Project created by QtCreator 2020-11-06T21:58:49
#
#-------------------------------------------------
#https://github.com/foreverlz1111/CuTe
QT       += core gui
QT += core


QT += sql
#QMAKE_LFLAGS += oci.lib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Oracle_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
