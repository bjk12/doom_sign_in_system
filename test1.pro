#-------------------------------------------------
#
# Project created by QtCreator 2019-07-31T21:08:52
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        dialog.cpp \
    student1.cpp \
    teacher1.cpp \
    database1.cpp \
    time1.cpp

HEADERS += \
        dialog.h \
    stable.h \
    student1.h \
    teacher1.h \
    database1.h \
    time1.h

FORMS += \
        dialog.ui \
    student1.ui \
    teacher1.ui \
    database1.ui \
    time1.ui

CONFIG += precompile_header
PRECOMPILED_HEADER = stable.h

RC_ICONS = icon.ico
