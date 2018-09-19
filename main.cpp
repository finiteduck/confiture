#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "GlobalLib.hpp"

using namespace std;

int main(int, char**) {
    auto g = make_global_sdl(USE_TTF);

    SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xAA, 0xAA));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);

    SDL_DestroyWindow(window);

    return 0;
}