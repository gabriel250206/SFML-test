#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Plataformas.hpp"
#include <iostream>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(500, 500), "SFML works!");
    window.setFramerateLimit(200);
    Personaje adan(150);
    Enemigo serpiente(100);
    Plataforma base(Vector2f{150,450});
    int x=0,y=0;
    int movx=0,movy=0;
    int ultima=0;
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
                    ultima=adan.vista.x;
                    std::cout<<"A"<<endl;
                    
                    
                    
                    
                }
                if(event.key.code==Keyboard::D){
                    if(adan.tatekieto==false)x=1;
                    adan.vista.x=1;
                    ultima=adan.vista.x;
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
                    std::cout<<base.getPosition().x<<" "<<base.getPosition().y<<endl;
                    std::cout<<adan.getPosition().x<<" "<<adan.getPosition().y<<endl;
                    // for(int i=0;i<adan.pistola->existentes.size();i++){
                        
                    //     //std::cout<<"disparo "<<i+1<<": "<<adan.pistola->existentes[i]->getPosition().x<<" "<<adan.pistola->existentes[i]->getPosition().x<< " direccion x:"<<adan.pistola->existentes[i]->getDireccion().x<<" direccion y:"<<adan.pistola->existentes[i]->getDireccion().y<<std::endl;
                    // }// modificalo para ver que esta pasando, por que no guarda el ultimo disparo, por que no detecta cual fue la ultima etc,

                }
                if(event.key.code==Keyboard::LShift){
                    adan.tatekieto=true;
                }
                if(event.key.code==Keyboard::Left){
                    adan.shot(adan.vista,ultima);
                }
                


                


            }else if(event.type==Event::KeyReleased){// para que no se queden haciendo algo infinitamente
                
                if(event.key.code == Keyboard::A) {
                    if(x==-1)x=0;
                    adan.vista.x=0; // esto hace que no se muevan si está parado, pero si no lo ponemos entonces no puede disparar para arriba
                }
                if( event.key.code == Keyboard::D ) {
                    if(x==1)x=0;
                    adan.vista.x=0;
                }
                //if(event.key.code == Keyboard::S) y=0;
                if(event.key.code==Keyboard::W ) adan.vista.y=0;
                if(event.key.code==Keyboard::S )adan.vista.y=0;
                if(event.key.code == Keyboard::LShift) adan.tatekieto=false;
                if(event.key.code == Keyboard::A && event.key.code == Keyboard::D && event.key.code==Keyboard::W && event.key.code==Keyboard::S) adan.vista.x=ultima; // no funciona
               
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

        base.colision(adan,x,y);
        adan.update(x,y);
        serpiente.update(adan);
        window.clear();
        adan.drawTo(window);
        serpiente.drawTo(window);
        base.drawTo(window);
        for(int i=0;i<adan.pistola->existentes.size(); i++){
            adan.pistola->existentes[i]->trayectoria();
            adan.pistola->existentes[i]->drawTo(window);
            
        }

        
        window.display();
    }

    return 0;
}