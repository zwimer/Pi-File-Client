#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T08:14:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pi-File-Client
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Console.cpp \
    Command.cpp

HEADERS  += MainWindow.hpp \
    main.hpp \
    Console.hpp \
    Command.hpp

FORMS    += mainwindow.ui
