#-------------------------------------------------
#
# Project created by QtCreator 2020-11-10T22:22:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TRANSLATIONS += cn.ts us.ts
TARGET = demo11
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#https://github.com/foreverlz1111/CuTe
SOURCES += main.cpp\
        mainwindow.cpp \
    clzy.cpp

HEADERS  += mainwindow.h \
    clzy.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
RC_ICONS = "sicon.ico"
