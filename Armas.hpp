
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bala.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Personaje;
class Principal {
    protected:
        int danio;
        int municionMax;
        
        
    public:
        bool tirada;
        vector<Bala*> existentes;
        int municion;
        Texture stmTexture;
        Sprite actualTexture;
        
        void dropJugador(Personaje &adan, vector<Principal*>&dropeadas );

        bool base;
        bool desplazar;
        bool piso;
        Principal();
        Principal(Vector2f posicion);
        int getDanio();
        void recargar();
        virtual void especial(int &x, int &cont);
        virtual void disparo(Vector2f posicion, Vector2f direccion);
        int getMun();
        virtual void update(Vector2f posicion, int x, int y, Vector2f vista, int a);
        void drawTo(RenderWindow &window);
};

class LanzaGuizantes:public Principal{
    
    public:
    int dash;
    
    LanzaGuizantes(Vector2f posicion);
    
    void especial(int &x, int &cont);
};

class Espadon:public Principal{
    public:
    Espadon();
    void especial(int &x, int &cont);
};

class Base :public Principal{
    public:
        Base(Vector2f posicion);
        void update(Vector2f posicion, int x, int y, Vector2f vista, int a);
        void disparo(Vector2f posicion, Vector2f direccion);
};

