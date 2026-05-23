#include <cxxopts.hpp>
#include <fmt/format.h>
#include <range/v3/view.hpp>
#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>

namespace view = ranges::views;

int main()
{
    // Initialize device and context
    ALCdevice *device = alcOpenDevice(NULL);
    ALCcontext *context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);

    // Set listener (user) position and orientation
    alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

    // Setup buffer (placeholder for actual audio loading)
    ALuint buffer;
    alGenBuffers(1, &buffer);
    // alBufferData(buffer, ...);
    // std::vector<char> pcmData = loadWavData("sound.wav");
    // Setup source and position it in 3D space
    ALuint source;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    alSource3f(source, AL_POSITION, 5.0f, 0.0f, 0.0f); // Source to the right

    // Play sound and cleanup
    alSourcePlay(source);
    // ... cleanup code ...

    std::cout << "Hello Audio World baby!" << std::endl;
    return 0;
}