#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Personaje;

class Plataforma{
    private:
        Texture stmTexture;
        
    public:
        Sprite actualTexture;
        Vector2f posicion;
        bool eta;// no se si funcione esto 
        bool colision(Personaje &adan,int &x, int&y,bool saltando);
        Plataforma(Vector2f posicion);
        void desplazamiento(int x);
        void drawTo(RenderWindow &window);
        Vector2f getPosition();
        bool toca(Personaje adan);
        int a;
        

};