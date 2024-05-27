#pragma once
#include "Armas.hpp"
#include "Personaje.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Personaje;
using namespace sf;

class Enemigo{
    protected:
        
        Texture stmTexture;
        bool dibujar; // solo de prueba, luego hay que eliminarlo
        int tiempo;
        bool muerto;
    public:
        Sprite actualTexture;
        int vida;
        Vector2f vista;
        Principal* pistola;
        Enemigo( int vida);
        bool getEstado();
        void disparo(Personaje adan, int x, int y);
        void drawTo(RenderWindow &window);
        void update(Personaje* adan, int x, int y);
        

};