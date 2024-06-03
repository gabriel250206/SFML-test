
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bala.hpp"
#include <iostream>


using namespace sf;
using namespace std;

class Personaje;
class Boss;
class Bala;

class Antenas{
    protected:
    int lado;
    int danio;
    Texture stmTexture;
    public:
    vector<Bala*>existentes;
    Sprite actualTexture;
    Antenas(int lado, Vector2f posicion);
    void especial();
    void drawTo(RenderWindow &window);

};