QT += qml quick

CONFIG += c++11 qml_debug

SOURCES += main.cpp \
           dataobject.cpp \
    grid.cpp \
    polygonitem.cpp
HEADERS += dataobject.h \
    grid.h \
    polygonitem.h
RESOURCES += snake.qrc

INSTALLS += target

DISTFILES +=
