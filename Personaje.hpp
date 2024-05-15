#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Bala;

class Personaje{
    protected:
        vector<Sprite> animaciones;
        Vector2f velocidad;
        int vida;
        vector<Bala*> acumulados;
        Sprite* siguiente;
        
        
        
    public:
        Sprite* actual;
        
        int municion;
        void update(int x, int y, int danio);
        Personaje(int vida);
        void shot(Vector2f inicio);
        int vista;


        
    
        
};