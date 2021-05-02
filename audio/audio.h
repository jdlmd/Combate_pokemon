#ifndef AUDIO_H
#define AUDIO_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_main.h>
#include <string>

class Audio
{
    public:
        Audio();
        ~Audio();
        void launchAudio(std::string filename);
        void killAudio();
        void launchSound(std::string filename);

    private:
//        SDL_AudioSpec want, have; // Especificaciones de audio
//        SDL_AudioDeviceID audio;
//        Uint8* buf; // Puntero para el buffer
//        Uint32 len; // Longitud de la onda

        Mix_Music* bgm;
        Mix_Chunk* effect;

};

#endif // AUDIO_H
