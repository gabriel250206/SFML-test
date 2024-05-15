#include <SFML/Graphics.hpp>
using namespace sf;
class Bala{
    protected:
        int danio;
        Vector2f posicion;
        
    public:
    Sprite bullet;

        Bala(int danio, Vector2f);
        void mover(int direcx, int direcy);
        
};