#include <SFML/Graphics.hpp>
using namespace sf;


float speedX=1.f;
float speedY=1.f;
int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    RectangleShape shape({20.f,10.f});
    
    window.setFramerateLimit(5000);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        //if(Mouse:)

        if(shape.getPosition().x+shape.getSize().x>=800|| shape.getPosition().x<0){
            
            speedX*= -1;
          
        }
        if(shape.getPosition().y+shape.getSize().y>=600|| shape.getPosition().y<0){
            
            speedY*= -1;
          
        }
        shape.setFillColor({shape.getPosition().x,shape.getPosition().y,shape.getPosition().x});
        shape.move({speedX,speedY});
        window.draw(shape);
        window.display();
    }

    return 0;
}