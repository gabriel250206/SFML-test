#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Personaje;

class Plataforma{
    private:
        Texture stmTexture;
        Sprite actualTexture;
    public:
        Vector2f posicion;
        void colision(Personaje &adan,int &x, int&y);
        Plataforma(Vector2f posicion);
        void drawTo(RenderWindow &window);
        Vector2f getPosition();

};