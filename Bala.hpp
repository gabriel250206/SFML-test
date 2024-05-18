#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bala{
    protected:
        int danio;
        Vector2f posicion;
        Vector2f direccion;
        Sprite actualTexture;
        Texture stmTexture;
        
    public:
        
        
        Bala(int danio, Vector2f posicion, Vector2f direccion);
        void trayectoria();
        void Impacto();
        void drawTo(RenderWindow &window);
        
};