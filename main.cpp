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
                /// TAMPOCO ESTO, ES QUE NOS DA DOBLE SALTO
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
                    std::cout<<"x: "<<adan.vista.x<<" "<<"y: "<<adan.vista.y<<" "<<std::endl;

                }
                if(event.key.code==Keyboard::LShift){
                    adan.tatekieto=true;
                }
                if(event.key.code==Keyboard::Left){
                    adan.shot(adan.vista);
                }
                





            }else if(event.type==Event::KeyReleased){// para que no se queden haciendo algo infinitamente
                if(event.key.code == Keyboard::A ) {
                    x=0;
                    adan.vista.x=0;
                }
                if( event.key.code == Keyboard::D ) {
                    x=0;
                    adan.vista.x=0;
                }
                //if(event.key.code == Keyboard::S) y=0;
                if(event.key.code==Keyboard::W ) adan.vista.y=0;
                if(event.key.code==Keyboard::S )adan.vista.y=0;
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
        /// NADA DE ESTO
        adan.update(x,y);
        window.clear();
        adan.drawTo(window);
        for(int i=0;i<adan.pistola->existentes.size(); i++){
            adan.pistola->existentes[i]->trayectoria();
            adan.pistola->existentes[i]->drawTo(window);
        }

        
        window.display();
    }

    return 0;
}