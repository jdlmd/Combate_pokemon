QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audio/audio.cpp \
    main.cpp \
    src/movimientoestado.cpp \
    src/movimientos.cpp \
    src/pokemon.cpp \
    src/tipo.cpp \
    src/entrenador.cpp \
    src/estados.cpp 

SOURCES += \
    graphics/pers.cpp \
    graphics/personaje.cpp \
    graphics/batalla.cpp \
    graphics/battle.cpp \
    graphics/atacar.cpp \
    graphics/mainwindow.cpp \
    graphics/mapa.cpp \
    graphics/cambio.cpp

HEADERS += \
    audio/extern.h \
    src/atacar.h \
    audio/audio.h \
    src/entrenador.h \
    src/estados.h \
    src/movimientoestado.h \
    src/movimientos.h \
    src/pokemon.h \
    src/tipo.h \
    src/definiciones.h 

HEADERS += \
    graphics/pers.h \
    graphics/personaje.h \
    graphics/batalla.h \
    graphics/battle.h \
    graphics/atacar.h \
    graphics/mainwindow.h \
    graphics/mapa.h \
    graphics/cambio.h

FORMS += \
    graphics/pers.ui \
    graphics/personaje.ui \
    graphics/batalla.ui \
    graphics/battle.ui \
    graphics/atacar.ui \
    graphics/mainwindow.ui \
    graphics/mapa.ui \
    graphics/cambio.ui

TRANSLATIONS += \
    Combate_pokemon_es_ES.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
        README.md

RESOURCES += \
    graphics/ResourcesVisual.qrc

# Copia de los archivos de audio a la carpeta build
CONFIG += file_copies
COPIES += audioFiles
audioFiles.files = $$files(audio/files/*.wav) # Path de copia
audioFiles.path = $$OUT_PWD/audio # Path destino
audioFiles.base = $$PWD/audio # Base del path

# Copia de los archivos de entrenadores a la carpeta build
COPIES += trainerFiles
trainerFiles.files = $$files(entrenadores/*.txt) # Path de copia
trainerFiles.path = $$OUT_PWD/Combate_pokemon # Path destino
# trainerFiles.base = $$PWD/audio # Base del path

# Instalación de las librería SDL
INCLUDEPATH += ./lib/SDL2-2.0.14/include/

unix|win32: LIBS += -L$$PWD/lib/SDL2-2.0.14/lib/x64/ -lSDL2

INCLUDEPATH += $$PWD/lib/SDL2-2.0.14/lib/x64
DEPENDPATH += $$PWD/lib/SDL2-2.0.14/lib/x64

unix|win32: LIBS += -L$$PWD/lib/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib/ -lSDL2_mixer

INCLUDEPATH += $$PWD/lib/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/
DEPENDPATH += $$PWD/lib/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/
