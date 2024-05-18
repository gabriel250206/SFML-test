#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bala{
    protected:
        int danio;
        Vector2f posicion;
        Vector2f direccion;
        
    public:
        Sprite bullet;

        Bala(int danio, Vector2f posicion, Vector2f direccion);
        void Impacto();
        
};