#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;
int width=400;
int height=400;
int numCells=10;

int main()
{

    int juega=0;
    RenderWindow window(VideoMode(400, 400), "SFML works!");
    window.setFramerateLimit(5);
    Grid grid(numCells,numCells,width,height);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            
            if(event.type==Event::MouseButtonPressed){
                if(event.mouseButton.button==Mouse::Left){
                int x=event.mouseButton.x;
                int y=event.mouseButton.y;
                grid.click(x,y);
            
            }
                if(event.mouseButton.button==Mouse::Right){
                    juega=(juega+1)%2;
                }
                
            }
            
            
            
        }
        if(juega==1){
            grid.contarVecinos();
        }
            

        window.clear();
        
        grid.drawTo(window);
        window.display();
    }

    return 0;
}


