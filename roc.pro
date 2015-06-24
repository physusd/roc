#-------------------------------------------------
#
# Project created by QtCreator 2015-06-11T15:49:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = roc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mydialog.cpp \
    dialogloadsettings.cpp

HEADERS  += \
    mydialog.h \
    mainwindow.h \
    dialogloadsettings.h

FORMS    += mainwindow.ui \
    mydialog.ui \
    dialogloadsettings.ui
