#-------------------------------------------------
#
# Project created by QtCreator 2017-10-05T14:38:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    start.cpp \
    traffic.cpp

HEADERS  += mainwindow.h \
    start.h \
    traffic.h

FORMS    += mainwindow.ui \
    start.ui \
    traffic.ui
