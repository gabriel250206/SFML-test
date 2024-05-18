
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
        vector<Bala*> existentes;
    public:
        int municion;
        Principal();
        int getDanio();
        void recargar();
        virtual void especial();
        void disparo(Vector2f posicion, Vector2f direccion);
};