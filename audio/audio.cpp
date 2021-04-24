#include "audio.h"

// Constructor
Audio::Audio() {
    SDL_Init(SDL_INIT_EVERYTHING); // Se inicia SDL
    SDL_memset(&want, 0, sizeof(want)); // Se generan los bloques de memoria para want
    want.freq = 44100;// Especificaciones de los archivos de audio
    want.format = AUDIO_S16;
    want.channels = 1;
    want.samples = 4096;
}

// Destructor
Audio::~Audio() {
    killAudio(); // Se llama a killaudio
}

// Método para lanzar el audio de la ventana actual
void Audio::launchAudio(std::string filename) {
    // Generación del dispoisitivo de audio
    audio = SDL_OpenAudioDevice(nullptr, false, &want, &have, 0);
    Uint8* buf; // Puntero para el buffer
    Uint32 len; // Longitud de la onda
    SDL_LoadWAV(filename.c_str(), &have ,&buf, &len); // Se carga el archivo y se genera el buffer de audio
    SDL_QueueAudio(audio, buf, len); // Se añade el audio al buffer del dispositivo
    SDL_FreeWAV(buf); // Libera los datos del buffer
    SDL_PauseAudioDevice(audio,false); // Que se reproduzca
}

// Método para liberar el audio
void Audio::killAudio() {
    SDL_CloseAudioDevice(audio); // Se cierra el dispositivo de audio
    SDL_Quit(); // Se cierra SDL (liberando la memoria)
}
