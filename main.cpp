#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>

class GlobalLib {
    public:
    [[noreturn]] virtual void fail(std::string message) = 0;
    virtual ~GlobalLib() = default;
};

class GlobalSDL : public GlobalLib {
  public:
    GlobalSDL() {
        int init = SDL_Init(SDL_INIT_VIDEO);
        if (init < 0) { fail("Error at init."); }
    }

    [[noreturn]] void fail(std::string message) {
        std::cerr << message << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        exit(1);
    }

    ~GlobalSDL() {
        SDL_Quit();
    }
};

std::unique_ptr<GlobalLib> make_global_sdl() {
    return std::make_unique<GlobalSDL>();
}

using namespace std;

int main(int, char**) {
    auto g = make_global_sdl();

    cout << "Hello world\n";
    return 0;
}