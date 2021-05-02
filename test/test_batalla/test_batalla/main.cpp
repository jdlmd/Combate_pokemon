#include <iostream>
#include "../../../src/entrenador.h"

using namespace std;

int main() {
    Entrenador* nerea = new Entrenador("Nerea.txt");
    Entrenador* user = new Entrenador("Willy",MALE,"user.txt");


    delete nerea;
    delete user;
}
