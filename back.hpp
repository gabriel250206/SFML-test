#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Fondo{
    protected:
        Texture stmTexture;
        Sprite actualTexture;
    public:
        Fondo();
        int a;
        void desplaza(int x);
        void drawTo(RenderWindow &window);
        int getA();

};

class Outro{
    protected:
        int opacidad;
        Texture stmTexture;
        Sprite actualTexture;
    public:
        Outro();
        void fin(RenderWindow &window);
};

class Inicio{
    protected:
        Texture stmTexture;
        Sprite actualTexture;
        Font font;
        
        Text title;
        Text inicio;
        Text scoreboard;
        Text salir;
        Text eleccion;
        int lleva;
    public:
        Inicio();
        void drawTo(RenderWindow &window);
        void interaccion(int &x);
};