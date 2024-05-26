#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Armas.hpp"
using namespace sf;
using namespace std;

class Plataforma;
class Fondo;
class Personaje{
    protected:
        vector<Sprite> animaciones;
         Vector2f velocidad;
        
        
        Sprite* siguiente;
        
        
        
    public:
        int vida;
        Texture stmTexture;
        Texture espejo;
        Sprite actualTexture;
        bool salto;
        int contSalto;
        int contRecarga;
        Vector2f vista;
        bool siguienteS;
        bool tatekieto;
        Principal* pistola;
        

        Personaje(int vida);
        void drawTo(RenderWindow &window);
        void update(int &x, int y /*t danio, bool piso*/, Fondo &paisaje, Plataforma &piso);
        void shot(Vector2f inicio, int ultima);
        Vector2f getPosition();
        void saltar(int &y, Plataforma base);
        void recargar(bool &recarga);

       


        
    
        
};