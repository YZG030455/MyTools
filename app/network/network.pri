#�pri文件用于网络模块
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/networktaskthread.h \
    $$PWD/tcpclientthread.h \
    $$PWD/tcpserverthread.h \
    $$PWD/udpsocketthread.h

SOURCES += \
    $$PWD/networktaskthread.cpp \
    $$PWD/tcpclientthread.cpp \
    $$PWD/tcpserverthread.cpp \
    $$PWD/udpsocketthread.cpp
