QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../../../src/entrenador.cpp \
        ../../../src/estados.cpp \
        ../../../src/movimientoestado.cpp \
        ../../../src/movimientos.cpp \
        ../../../src/pokemon.cpp \
        ../../../src/tipo.cpp \
        main.cpp

HEADERS += \
        ../../../src/definiciones.h \
        ../../../src/entrenador.h \
        ../../../src/estados.h \
        ../../../src/movimientoestado.h \
        ../../../src/movimientos.h \
        ../../../src/pokemon.h \
        ../../../src/tipo.h

# Copia de los archivos de entrenadores a la carpeta build
COPIES += trainerFiles
trainerFiles.files = $$files(*.txt) # Path de copia
trainerFiles.path = $$OUT_PWD/ # Path destino
# trainerFiles.base = $$PWD/audio # Base del path
