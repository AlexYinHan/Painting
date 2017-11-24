#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T18:43:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Painting
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


SOURCES += main.cpp\
        mainwindow.cpp \
    openglwidget.cpp \
    GeometricObjectManager.cpp \
    ToolMenu.cpp \
    Vector3.cpp \
    Graphics/Circle.cpp \
    Graphics/GeometricObject.cpp \
    Graphics/Line.cpp \
    Graphics/Oval.cpp

HEADERS  += mainwindow.h \
    openglwidget.h \
    common.h \
    GeometricObjectManager.h \
    ToolMenu.h \
    Vector3.h \
    Graphics/Circle.h \
    Graphics/GeometricObject.h \
    Graphics/Line.h \
    Graphics/Oval.h

FORMS    += mainwindow.ui \
    openglwidget.ui

LIBS     += -lOpengl32 \
                -lglu32 \
                -lglut

RESOURCES += \
    res.qrc
