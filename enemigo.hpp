#pragma once
#include "Armas.hpp"
#include "Personaje.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Personaje;
using namespace sf;

class Enemigo{
    protected:
        int cooldown;
        Texture stmTexture;
        bool dibujar; // solo de prueba, luego hay que eliminarlo
        int tiempo;
        bool muerto;
        float rangoX;
        int mov;
        int cont;
    public:
        Sprite actualTexture;
        int vida;
        Vector2f vista;
        Principal* pistola;
        Enemigo( int x);
        Enemigo();
        bool movimiento;
        bool disparar;
        bool getEstado();
        bool aparecer(Personaje* adan);
        virtual void disparo(Personaje adan, int x, int y);
        virtual void drawTo(RenderWindow &window);
        virtual void update(Personaje* adan, int x, int y);
        
        
        

};









class Disparador: public Enemigo{
    public:
        Disparador(Vector2f posicion, Vector2f vista);
        void drawTo(RenderWindow &window);
        void update(Personaje* adan, int x, int y);
        void disparo(Personaje adan, int x, int y);
};

class Fuerte: public Enemigo{
    public:
        Fuerte(int x);
};

class   Rapido: public Enemigo{
    public:
        Rapido(int x);
        
};

