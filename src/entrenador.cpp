#include "entrenador.h"

Entrenador::Entrenador() {
    nombre = "N";
    genre = MALE;
    numPoke = 0;
    derrotado = false;
}

Entrenador::Entrenador(std::string filename) {
    std::ifstream entrada;
    entrada.open(filename.c_str()); // Se genera el stream de entrada
    if(entrada.fail()) {
        std::cout << "Archivo no encontrado\n";
        Entrenador(); // Se llama al constructor por defecto
        return;
    }

    // Hacer función para el entrenador con el filename de entrada

}

Entrenador::~Entrenador() {
    /* Vacío */
}

void Entrenador::setNombre(std::string name) {
    nombre = name;
}

std::string Entrenador::getNombre(){
    return nombre;
}

void Entrenador::setNumPoke(uint num) {
    numPoke = num;
}

uint Entrenador::getNumPoke(){
    return numPoke;
}

void Entrenador::updateStatus() {
    // Hacer la función de updateStatus
}

bool Entrenador::checkStatus() {
    return derrotado;
}
