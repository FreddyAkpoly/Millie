#include <headers/Characters.h>

class Player : public Characters
{
    public:
      Player(Properties props);
        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);

    
};