#include "audio.h"
#include "iostream"
//#include "filesystem"
#include "fstream"

Audio audio; // Variable externa audio (audio/extern.h)

// Constructor
Audio::Audio() {
    SDL_Init(SDL_INIT_EVERYTHING); // Se inicia SDL

    if (Mix_OpenAudio(44100,AUDIO_S16,1,4096) < 0) {
        std::cout << "No se ha podido inicializar el mixer.\n";
    }
}

// Destructor
Audio::~Audio() {
    killAudio(); // Se llama a killaudio
}

// Método para lanzar el audio de la ventana actual
void Audio::launchAudio(std::string filename) {

    std::string fullPath = SDL_GetBasePath();
    std::ifstream f(fullPath+"./Combate_pokemon/audio/files/" + filename);
    if(f.good()){
        fullPath.append("./Combate_pokemon/audio/files/" + filename);
    }else{
        fullPath.append("../Combate_pokemon/audio/files/" + filename);
    }
//        fullPath.append("./Combate_pokemon/audio/files/" + filename);

    bgm = Mix_LoadMUS(fullPath.c_str());
    Mix_PlayMusic(bgm,-1);

    // Este sería el código para SDL puro
/*
    SDL_memset(&want, 0, sizeof(want)); // Se generan los bloques de memoria para want
    want.freq = 44100;// Especificaciones de los archivos de audio
    want.format = AUDIO_S16;
    want.channels = 1;
    want.samples = 4096;
    // Generación del dispoisitivo de audio
    audio = SDL_OpenAudioDevice(nullptr, false, &want, &have, 0);
    SDL_LoadWAV("Combate_pokemon/audio/files/theme.wav", &have ,&buf, &len); // Se carga el archivo y se genera el buffer de audio
    SDL_QueueAudio(audio, buf, len); // Se añade el audio al buffer del dispositivo
    SDL_PauseAudioDevice(audio,false); // Que se reproduzca */

}

// Método para liberar el audio
void Audio::killAudio() {

    Mix_FreeChunk(effect);
    Mix_FreeMusic(bgm);
    Mix_Quit();
    bgm = nullptr;
    effect = nullptr;

    // Este sería el código para SDL puro

    /*SDL_FreeWAV(buf); // Libera los datos del buffer
    SDL_CloseAudioDevice(audio); // Se cierra el dispositivo de audio
    SDL_Quit(); // Se cierra SDL (liberando la memoria)*/
}

void Audio::launchSound(std::string filename){
    std::string fullPath = SDL_GetBasePath();
    std::ifstream f(fullPath+"./Combate_pokemon/audio/files/" + filename);
    if(f.good()){
        fullPath.append("./Combate_pokemon/audio/files/" + filename);
    }else{
        fullPath.append("../Combate_pokemon/audio/files/" + filename);
    }
    effect = Mix_LoadWAV(fullPath.c_str());
    Mix_PlayChannel(2,effect,0);
}
