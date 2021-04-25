#ifndef AUDIO_H
#define AUDIO_H

#include <SDL.h>
#include <SDL_main.h>
#include <string>

class Audio
{
    public:
        Audio();
        ~Audio();
        void launchAudio(std::string filename);
        void killAudio();

    private:
        SDL_AudioSpec want, have; // Especificaciones de audio
        SDL_AudioDeviceID audio;

};

#endif // AUDIO_H
