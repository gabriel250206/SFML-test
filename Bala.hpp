#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bala{
    protected:
        int danio;
        Vector2f posicion;
        Vector2f direccion;
        Sprite actualTexture;
        Texture stmTexture;
        
    public:
        
        bool impactado;
        Bala(int danio, Vector2f posicion, Vector2f direccion);
        void trayectoria();
        void Impacto(Sprite actualtexture1,int &vida);
        void drawTo(RenderWindow &window);
        Vector2f getPosition();
        Vector2f getDireccion();
        
        
};