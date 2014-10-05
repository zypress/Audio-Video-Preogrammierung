#-------------------------------------------------
#
# Project created by QtCreator 2014-10-05T17:25:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoPlayer
TEMPLATE = app


SOURCES += main.cpp\
        videoplayer.cpp \
        colorkeyer.cpp

HEADERS  += videoplayer.h \
            colorkeyer.h \
    videoplayer.h

FORMS    += videoplayer.ui

include(../videoengine/videoengine.pri)
