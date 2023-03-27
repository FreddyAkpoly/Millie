#pragma once
#include <headers/Vector2D.h>
class Transform
{
    public:
        float X,Y;

    public:
        Transform(float x = 0, float y = 0): X(x),Y(x){};
        void Log(std::string msg = "")
        {
            std::cout << "X: " << X << " Y: " << Y << std::endl;
        }

    public:
        inline void TranslateX(float x)
        {
            X += x;
        }
        inline void TranslateY(float y)
        {
            Y += y;
        }
        inline void Translate(Vector2D vec)
        {
            X += vec.X;
            Y += vec.Y;
        }


};