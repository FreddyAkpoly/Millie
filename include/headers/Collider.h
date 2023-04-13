#include <SDL.h>


class Collider{

    public:
        inline SDL_Rect Get(){return m_Box;}
        inline void SetBuffer(int x, int y, int w, int h){m_buffer = {x,y,w,h};}

        void Set(int x, int y, int w, int h){
            m_Box ={
                x - m_buffer.x,
                y - m_buffer.y,
                w - m_buffer.w,
                h - m_buffer.h


            };
        }


    private:

        SDL_Rect m_Box;
        SDL_Rect m_buffer;

};


