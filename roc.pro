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
    dialogloadsettings.cpp \
    dialogabout.cpp \
    dialogsavesettings.cpp

HEADERS  += \
    mainwindow.h \
    dialogloadsettings.h \
    dialogabout.h \
    dialogsavesettings.h

FORMS    += mainwindow.ui \
    dialogloadsettings.ui \
    dialogabout.ui \
    dialogsavesettings.ui
