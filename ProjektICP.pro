#-------------------------------------------------
#
# Project created by QtCreator 2018-04-07T11:46:36
#
#-------------------------------------------------

QT       += core gui widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjektICP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = ../ICP/bin


SOURCES += \
    src/main.cpp \
    src/GUI/mainwindow.cpp \
    src/GUI/menu.cpp \
    src/LOGIC/block.cpp \
    src/LOGIC/ICPmath.cpp \
    src/LOGIC/ide.cpp \
    src/LOGIC/port.cpp \
    src/GUI/GraphicsScene.cpp \
    src/GUI/gBlock.cpp \
    src/LOGIC/Scheme.cpp

HEADERS += \
    src/GUI/mainwindow.h \
    src/GUI/menu.h \
    src/LOGIC/block.hpp \
    src/LOGIC/ICPmath.hpp \
    src/LOGIC/ide.hpp \
    src/LOGIC/port.hpp \
    src/GUI/GraphicsScene.h \
    src/GUI/gBlock.h \
    src/LOGIC/Scheme.hpp

FORMS += \
    src/GUI/ui/mainwindow.ui \
    src/GUI/ui/menu.ui

RESOURCES += \
    src/GUI/reusorce.qrc
