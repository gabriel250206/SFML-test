#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Armas.hpp"
using namespace sf;
using namespace std;



class Personaje{
    protected:
        vector<Sprite> animaciones;
         Vector2f velocidad;
        int vida;
        Texture stmTexture;
        Texture espejo;
        Sprite* siguiente;
        
        
        
    public:
        
        Sprite actualTexture;
        bool salto;
        int contSalto;
        Vector2f vista;
        bool siguienteS;
        bool tatekieto;
        Principal* pistola;

        Personaje(int vida);
        void drawTo(RenderWindow &window);
        void update(int x, int y /*t danio, bool piso*/);
        void shot(Vector2f inicio, int ultima);
        Vector2f getPosition();

       


        
    
        
};