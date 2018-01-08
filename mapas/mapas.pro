#-------------------------------------------------
#
# Project created by QtCreator 2017-02-22T17:58:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mapas
TEMPLATE = app

CONFIG += release
CONFIG += declarative_debug


SOURCES += main.cpp\
        principal.cpp \
    personedicion.cpp \
    mainwindow.cpp \
    arista.cpp \
    nodo.cpp

HEADERS  += principal.h \
    mainwindow.h \
    personedicion.h \
    arista.h \
    nodo.h

FORMS    += principal.ui \
    mainwindow.ui \
    personedicion.ui

RESOURCES += icos.qrc
