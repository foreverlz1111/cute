#-------------------------------------------------
#
# Project created by QtCreator 2020-10-19T11:11:42
#
#-------------------------------------------------
#https://github.com/foreverlz1111/CuTe
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo6
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    standdialog.cpp \
    geometry.cpp \
    messagebox.cpp \
    toolbox.cpp \
    drawer.cpp

HEADERS  += mainwindow.h \
    standdialog.h \
    geometry.h \
    messagebox.h \
    toolbox.h \
    drawer.h

FORMS    += mainwindow.ui \
    standdialog.ui \
    geometry.ui \
    messagebox.ui \
    drawer.ui \
    toolbox.ui

RESOURCES += \
    qqimg.qrc
