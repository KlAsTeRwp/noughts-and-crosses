QT += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = "Klaster"
TEMPLATE = app
#CONFIG += console

SOURCES += main.cpp \
    gamefield.cpp \
    gamebutton.cpp

HEADERS += \
    gamefield.h \
    gamebutton.h
