
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bala.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Principal {
    protected:
        int danio;
        int municionMax;
        
    public:
        vector<Bala*> existentes;
        int municion;
        Texture stmTexture;
        Sprite actualTexture;

        Principal();
        Principal(Vector2f posicion);
        int getDanio();
        void recargar();
        virtual void especial(int &x, int &cont);
        void disparo(Vector2f posicion, Vector2f direccion);
        int getMun();
        void update(Vector2f posicion);
        void drawTo(RenderWindow &window);
};

class LanzaGuizantes:public Principal{
    
    public:
    int dash;
    LanzaGuizantes(Vector2f posicion);
    
    void especial(int &x, int &cont);
};