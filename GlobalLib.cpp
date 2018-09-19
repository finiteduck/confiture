#include "GlobalLib.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_TTF.h>
#include <iostream>

class GlobalSDL : public GlobalLib {
  public:
    GlobalSDL(GlobalSDLFlags flags) {
        int init = SDL_Init(SDL_INIT_VIDEO);
        if (init < 0) { fail_sdl("Error while initializing SDL."); }
        if (flags == USE_TTF) {
            int ttf_init = TTF_Init();
            if (ttf_init < 0) { fail_ttf("Error while initializing TTF."); }
        }
    }

    [[noreturn]] void fail_sdl(std::string message) {
        std::cerr << message << std::endl;
        std::string e = SDL_GetError();
        if (e != "") { std::cerr << e << std::endl; }
        exit(1);
    }

    [[noreturn]] void fail_ttf(std::string message) {
        std::cerr << message << std::endl;
        std::string e = TTF_GetError();
        if (e != "") { std::cerr << e << std::endl; }
        exit(1);
    }

    ~GlobalSDL() { SDL_Quit(); }
};

std::unique_ptr<GlobalLib> make_global_sdl(GlobalSDLFlags flags) {
    return std::make_unique<GlobalSDL>(flags);
}