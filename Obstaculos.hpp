#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bala.hpp"
#include <iostream>

class Personaje;
class Barrera{
    protected:
    Texture stmTexture;
    int tiempo;
    bool mostrar;
    bool prevalece;
    long long siguiente;
    public:
    Sprite actualTexture;
    Barrera(Vector2f posicion);
    void drawTo(RenderWindow &window);
    void desaparecer();
    void golpe(Personaje & adan);
    void movimiento(int x);
};

class PisoLava: public Barrera{
    public:
    PisoLava(Vector2f posicion);
    void setExtention(int x);

};