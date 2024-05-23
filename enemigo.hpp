#pragma once
#include "Armas.hpp"
#include "Personaje.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Personaje;
using namespace sf;

class Enemigo{
    protected:
        int vida;
        Texture stmTexture;
        bool dibujar; // solo de prueba, luego hay que eliminarlo
    public:
        Sprite actualTexture;

        Principal pistola;
        Enemigo( int vida);
        int getVida();
        void setVida(int danio);
        void drawTo(RenderWindow &window);
        void update(Personaje adan);
        

};