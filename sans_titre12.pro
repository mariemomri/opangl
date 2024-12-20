QT += quick opengl
QT += widgets  # si vous utilisez un widget pour l'affichage OpenGL
QT += sql


CONFIG += c++11

SOURCES += \
    databasemanager.cpp \
    main.cpp \
    openglframebufferobject.cpp

HEADERS += \
    databasemanager.h \
    openglframebufferobject.h

RESOURCES += qml.qrc
