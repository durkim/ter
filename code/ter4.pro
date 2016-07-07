#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T11:46:10
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ter4
TEMPLATE = app


SOURCES += main.cpp\
    board.cpp \
    segment.cpp \
    unitcell.cpp \
    window.cpp \
    matrix.cpp \
    board2.cpp

HEADERS  += \
    board.h \
    segment.h \
    unitcell.h \
    window.h \
    matrix.h \
    board2.h

FORMS    += mainwindow.ui
