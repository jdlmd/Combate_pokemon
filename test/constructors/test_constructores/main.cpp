#include <iostream>
#include "../../../src/entrenador.h"

using namespace std;

int main() {
    Entrenador* jesus = new Entrenador("Jesus.txt");
    Entrenador* def = new Entrenador();
    Entrenador* prueba = new Entrenador("prueba.txt");
    Entrenador* prueba2 = new Entrenador("prueba2.txt");
    string flag = "";
    cin >> flag;
    delete jesus;
    delete def;
    delete prueba;
    delete prueba2;
    return 0;
}
