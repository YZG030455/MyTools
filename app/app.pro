#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T19:42:07
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += network
QT       += charts
QT       += webenginewidgets           # 网页模块
QT       +=  multimedia
QT      += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app


SOURCES += \
        main/main.cpp\
        widgets/mainwindow.cpp \
        widgets/loginwidget.cpp \
        global.cpp \
        widgets/dockwidget/filetreedockwidget.cpp \
        messdispath.cpp \
        widgets/dockwidget/loginfodockwidget.cpp

HEADERS  +=\
        widgets/mainwindow.h \
        widgets/loginwidget.h \
        global.h \
        widgets/dockwidget/filetreedockwidget.h \
        messdispath.h \
        widgets/dockwidget/loginfodockwidget.h

FORMS    += \
        widgets/mainwindow.ui


include($$PWD/network/network.pri)              #网络模块
include($$PWD/file/file.pri)
include($$PWD/table/table.pri)
include($$PWD/graph/graph.pri)
#include($$PWD/webKit/wibKit.pri)
include($$PWD/video/video.pri)
include($$PWD/music/music.pri)
include($$PWD/common/common.pri)
include($$PWD/topologicalGraph/topologicalGraph.pri)    # 拓扑图

RESOURCES += \
    resource.qrc
