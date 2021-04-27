TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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
