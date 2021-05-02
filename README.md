# Combate_pokemon
Ejercicio final para Informática avanzada. Compilar con Qt 6.0.3 MinGW.

Nuestro ejercicio se basa en un Combate Pokémon. 
    Cada entrenador debe tener como máximo 6 pokémon 
    Cada Pokémon como máximo tiene 4 movimientos 
    Cada Pokémon tiene entre uno y dos tipos que deben ser distintos
    Cada Pokémon tendrá un estado
    Los movimientos son de dos tipos, los que pueden cambiar el estado del pokémon y los que no.

En el comienzo de programa se puede elegir el género y el nombre del usuario o empezar el juego directamente, 
eligiendo aleatoriamente el género del personaje. 

Tras empezar el juego aparece el mapa con 4 botones, según el botón pulsado empezará el combate con uno de los cuatro
rivales distintos. 

El combate acaba cuando todos los pokémon de uno de los entrenadores son derrotados. 
    Si pierde el usuario aparece un cuadro de texto y aparece de nuevo la ventana de inicio para volver a intentarlo. 
    Si el usuario derrota al rival entonces debe enfrentarse al resto de rivales, cuando derrota a los cuatro aparece
    un cuadro de texto y se bloquean los botones y no puedes continuar.

