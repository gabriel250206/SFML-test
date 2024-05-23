#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Fondo{
    protected:
        Texture stmTexture;
        Sprite actualTexture;
    public:
        Fondo();
        int a;
        void desplaza(int x);
        void drawTo(RenderWindow &window);
        int getA();

};