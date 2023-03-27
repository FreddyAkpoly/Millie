#include <sdl/SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.h>

class IObject{

public:
    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Clean() = 0;


};