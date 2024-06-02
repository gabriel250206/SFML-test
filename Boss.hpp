#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Principal;
class Bala;
class Boss{
    protected:
        int vida;
        Texture stmTexture;
    public:
        Sprite actualTexture;
        Boss(Vector2f posicion);
        vector<Bala> disparadas;

        void disparo();
        void update();
        void mover(int x);
        void drawTo(RenderWindow &window);





};