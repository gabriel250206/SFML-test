#include <SFML/Graphics.hpp>
#include "Rrectangle.hpp"
#include <vector>
using namespace std;
using namespace sf;


vector <Rectangle>rectangulos;
float speedX=1.f;
float speedY=1.f;
int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    
    
    window.setFramerateLimit(5000);

Rectangle rect(Vector2f(60.f,30.f));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type==Event::MouseButtonPresse){
                if(event.mouseButton.button== Mouse::left){
                    float x=float(rand()%100);
                    float y=float(rand()%100);
                    Rectangle r= Rectangle (Vector2f(x,y))
                    rectangulos.push_back(r);
                    r.drawTo(window);
                }
|
            }
        }

        window.clear();
        rect.update();
        rect.drawTo(window);
        window.display();
    }

    return 0;
}