#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(500, 500), "SFML works!");
    Personaje adan(100);
    int x=1,y=1;
    int movx=0,movy=0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed){
                
                if(Event::KeyPressed==102){
                    if(adan.municion>0){
                        adan.shot(adan.actual->getPosition());
                    }
                    
                }
                if(Event::KeyPressed==14){
                    y=-1;


                    
                }
                if(Event::KeyPressed==15){
                    y=1;

                    
                }
                if(Event::KeyPressed==17){
                    x=1;
                    
                }
                if(Event::KeyPressed==16){
                    x=-1;
                    
                }

            }
            
            adan.update(x,y,10);
            
        }

        window.clear();
        window.display();
    }

    return 0;
}