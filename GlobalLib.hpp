#include <string>
#include <memory>

class GlobalLib {
  public:
    virtual ~GlobalLib() = default;
};

enum GlobalSDLFlags {
    NO_LIB,
    USE_TTF
};
std::unique_ptr<GlobalLib> make_global_sdl(GlobalSDLFlags flags);