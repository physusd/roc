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

win32: LIBS += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
win32: INCLUDEPATH += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Include"
