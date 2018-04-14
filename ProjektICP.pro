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
QMAKE_CXXFLAGS +=-Wno-expansion-to-defined

CONFIG += c++11
CONFIG += c++14
CONFIG += c++17

QMAKE_CXXFLAGS_RELEASE += -O3

SOURCES += \
    src/main.cpp \
    src/LOGIC/block.cpp \
    src/LOGIC/ICPmath.cpp \
    src/LOGIC/port.cpp \
    src/LOGIC/Scheme.cpp \
    src/GUI/mainwindow.cpp \
    src/GUI/menu.cpp \
    src/GUI/GraphicsScene.cpp \
    src/GUI/gBlock.cpp \
    src/GUI/blockDialogCreate/createblock.cpp \
    src/GUI/blockDialogCreate/tabPort/portform.cpp \
    src/GUI/blockDialogCreate/tabPort/portaddform.cpp \
    src/GUI/blockDialogCreate/tabPort/porttoolbox.cpp \
    src/GUI/blockDialogCreate/tabPort/portpage.cpp \
    src/GUI/blockDialogCreate/tabPort/portdataform.cpp \
    src/GUI/blockDialogCreate/tabPort/portadddataform.cpp

HEADERS += \
    src/LOGIC/block.hpp \
    src/LOGIC/ICPmath.hpp \
    src/LOGIC/port.hpp \
    src/LOGIC/Scheme.hpp \
    src/GUI/mainwindow.h \
    src/GUI/menu.h \
    src/GUI/GraphicsScene.h \
    src/GUI/gBlock.h \
    src/GUI/blockDialogCreate/createblock.h \
    src/GUI/blockDialogCreate/tabPort/portform.h \
    src/GUI/blockDialogCreate/tabPort/portaddform.h \
    src/GUI/blockDialogCreate/tabPort/porttoolbox.h \
    src/GUI/blockDialogCreate/tabPort/portpage.h \
    src/GUI/blockDialogCreate/tabPort/portdataform.h \
    src/GUI/blockDialogCreate/tabPort/portadddataform.h

FORMS += \
    src/GUI/mainwindow.ui \
    src/GUI/menu.ui \
    src/GUI/blockDialogCreate/createblock.ui \
    src/GUI/blockDialogCreate/tabPort/portform.ui \
    src/GUI/blockDialogCreate/tabPort/portaddform.ui \
    src/GUI/blockDialogCreate/tabPort/porttoolbox.ui \
    src/GUI/blockDialogCreate/tabPort/portpage.ui \
    src/GUI/blockDialogCreate/tabPort/portdataform.ui \
    src/GUI/blockDialogCreate/tabPort/portadddataform.ui

RESOURCES += \
