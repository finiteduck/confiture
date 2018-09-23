#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "GlobalLib.hpp"

using namespace std;

namespace cf { namespace SDL {
    // ============================================================================================
    //   Window class
    // ============================================================================================
    class Window {
        unique_ptr<SDL_Window, void (*)(SDL_Window*)> window;

      public:
        Window(std::string title, int w, int h)
            : window(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN),
                  SDL_DestroyWindow) {}

        SDL_Window* get() { return window.get(); }

        void update_surface() { SDL_UpdateWindowSurface(window.get()); }
    };

    // ============================================================================================
    //   Surface class
    // ============================================================================================
    class Surface {
        unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface;

      public:
        Surface(Window& window) : surface(SDL_GetWindowSurface(window.get()), SDL_FreeSurface) {}

        SDL_Surface* get() { return surface.get(); }
    };

}}  // namespace cf::SDL

using namespace cf;

int main(int, char**) {
    auto g = make_global_sdl(USE_TTF);

    SDL::Window w("SDL Tutorial", 800, 600);
    /* if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    } */

    SDL::Surface s(w);
    SDL_FillRect(s.get(), NULL, SDL_MapRGB(s.get()->format, 0xFF, 0xAA, 0xAA));
    w.update_surface();
    SDL_Delay(2000);

    return 0;
}