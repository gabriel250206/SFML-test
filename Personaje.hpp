#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Bala;

class Personaje{
    protected:
        // vector<Sprite> animaciones;
         Vector2f velocidad;
        int vida;
        Texture stmTexture;
        
        // vector<Bala*> acumulados;
        Sprite siguiente;
        
        
        
    public:
        
        Sprite actualTexture;
        bool salto;
        int contSalto;
        int municion;
        void update(int x, int y /*t danio*/);
        Personaje(int vida);
        // void shot(Vector2f inicio);
        Vector2f vista;
        void drawTo(RenderWindow &window);
        bool siguienteS;
        bool tatekieto;

       


        
    
        
};