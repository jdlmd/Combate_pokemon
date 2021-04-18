QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/inicio.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/personaje.cpp

HEADERS += \
    src/inicio.h \
    src/mainwindow.h \
    src/personaje.h

FORMS += \
    src/inicio.ui \
    src/mainwindow.ui \
    src/personaje.ui

TRANSLATIONS += \
    Combate_pokemon_es_ES.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
        README.md

RESOURCES += \
    src/ResourcesVisual.qrc
