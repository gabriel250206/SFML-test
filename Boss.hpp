#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Principal;
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
        //vector<Principal>cuernitos;
        void disparo(Personaje &adan);
        void update();
        void mover(int x);
        void drawTo(RenderWindow &window);





};