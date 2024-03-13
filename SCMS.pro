#-------------------------------------------------
#
# Project created by QtCreator 2022-06-29T18:43:02
#
#-------------------------------------------------

QT       += core gui
QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SCMS
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
    login.cpp \
    sqlcon.cpp \
    stu_info.cpp \
    stu_cour.cpp \
    clscour.cpp \
    tch_info.cpp \
    tchcour.cpp \
    admin.cpp

HEADERS += \
    login.h \
    sqlcon.h \
    stu_info.h \
    stu_cour.h \
    clscour.h \
    tch_info.h \
    tchcour.h \
    admin.h

FORMS += \
    login.ui \
    stu_info.ui \
    stu_cour.ui \
    clscour.ui \
    tch_info.ui \
    tchcour.ui \
    admin.ui

DISTFILES +=

RESOURCES += \
    image.qrc
