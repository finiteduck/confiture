#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "GlobalLib.hpp"

using namespace std;

int main(int, char**) {
    auto g = make_global_sdl(USE_TTF);

    cout << "Hello world\n";
    return 0;
}