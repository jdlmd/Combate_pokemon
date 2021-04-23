QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/atacar.cpp \
    src/batalla.cpp \
    src/battle.cpp \
    src/cambio.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mochila.cpp \
    src/pers.cpp \
    src/personaje.cpp

HEADERS += \
    src/atacar.h \
    src/batalla.h \
    src/battle.h \
    src/cambio.h \
    src/mainwindow.h \
    src/mochila.h \
    src/pers.h \
    src/personaje.h

FORMS += \
    src/atacar.ui \
    src/batalla.ui \
    src/battle.ui \
    src/cambio.ui \
    src/mainwindow.ui \
    src/mochila.ui \
    src/pers.ui \
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

LIBS += \
    -L./lib/OpenAL/OpenAL32.dll # Se añade la librería de OpenAL al linkador
