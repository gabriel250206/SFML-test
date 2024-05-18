#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include <iostream>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(500, 500), "SFML works!");
    window.setFramerateLimit(200);
    Personaje adan(150);
    int x=0,y=0;
    int movx=0,movy=0;
    adan.drawTo(window);
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
                        //adan.shot(adan.actual.getPosition());
                    }
                    
                }
                if(event.key.code==Keyboard::A ){
                    if(adan.tatekieto==false) x=-1;
                    adan.vista.x=-1;
                    std::cout<<"A"<<endl;
                    
                    
                    
                    
                }
                if(event.key.code==Keyboard::D){
                    if(adan.tatekieto==false)x=1;
                    adan.vista.x=1;
                    std::cout<<"D"<<endl;
                    
            
                    
                    
                    
                }
                
                if(event.key.code==Keyboard::Space && adan.salto==true && adan.siguienteS==true && adan.tatekieto==false){ // si presionas y puede saltar
                    
                    std::cout<<"W"<<endl;
                    adan.salto=false;
                    adan.siguienteS=false;
                    
                    
                }
                if(event.key.code==Keyboard::W){ /// tecla de comprobacion
                    adan.vista.y=-1;

                }
                if(event.key.code==Keyboard::S){ /// tecla de comprobacion
                    adan.vista.y=1;

                }
                if(event.key.code==Keyboard::I){ /// tecla de comprobacion
                    std::cout<<adan.salto<<" "<<adan.siguienteS<<" "<<  adan.actualTexture.getPosition().y<<std::endl;

                }
                if(event.key.code==Keyboard::LShift){
                    adan.tatekieto=true;
                }
                // if(event.key.code==Keyboard::W){
                //     
                //y=-1;
                    
                // }





            }else if(event.type==Event::KeyReleased){
                if(event.key.code == Keyboard::A && x==-1) x=0;
                if( event.key.code == Keyboard::D && x==1) x=0;
                //if(event.key.code == Keyboard::S) y=0;
                if(event.key.code == Keyboard::LShift) adan.tatekieto=false;
                
               
            }
            
            
        }
        ///EFRA NO TOQUES ESTO 
        if((adan.actualTexture.getPosition().y<400 && adan.salto==true )){
            y=1;

           
        }else {
            if(adan.salto==false){
                y=-1;
                
                if(adan.contSalto==100){
                    adan.contSalto=0;
                    adan.salto=true;
                }
                adan.contSalto++;
            }else{
                y=0;
            }
            if(adan.actualTexture.getPosition().y==400){
              
               adan.siguienteS=true;
            }
            
            
        }
        adan.update(x,y);
        window.clear();
        adan.drawTo(window);

        window.display();
    }

    return 0;
}