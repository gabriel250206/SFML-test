#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ataquesB.hpp"
using namespace sf;
using namespace std;


class Bala;
class Personaje;
class Boss{
    protected:
        int vida;
        Texture stmTexture;
        int contador;
    public:
        Sprite actualTexture;
        Boss(Vector2f posicion);
        vector<Antenas>cuernitos;
       
        void disparo();
        void update(Personaje &adan);
        void mover(int x);
        void drawTo(RenderWindow &window);





};