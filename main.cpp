#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Plataformas.hpp"
#include "back.hpp"
#include <iostream>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(500, 500), "SFML works!");
    window.setFramerateLimit(200);
    Personaje adan(150);
    //Enemigo serpiente(100);
    Plataforma base(Vector2f{250,350});
    Fondo atras;
    int x=0,y=0;
    int movx=0,movy=0; // desconozco funcionamiento de estas *-
    int ultima=0;
    bool saltando;// no se si funcione *-
    bool recargar=false;

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
                    adan.actualTexture.setTexture(adan.espejo);
                    adan.actualTexture.setTextureRect(IntRect(18,17,13,17));
                    std::cout<<"A"<<endl;
                    
                    
                    
                    
                }
                if(event.key.code==Keyboard::D){
                    if(adan.tatekieto==false)x=1;
                    adan.vista.x=1;
                    ultima=adan.vista.x;
                    adan.actualTexture.setTexture(adan.stmTexture);
                    adan.actualTexture.setTextureRect(IntRect(30,20,13,17));
                    std::cout<<"D"<<endl;
                    
            
                    
                    
                    
                }
                /// TAMPOCO ESTO, ES QUE NOS DA DOBLE SALTO
                if(event.key.code==Keyboard::Space && adan.salto==true && adan.siguienteS==true && adan.tatekieto==false){ // si presionas y puede saltar
                    
                    std::cout<<"Espacio"<<endl;
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
                    std::cout<<adan.contRecarga<<std::endl;
                    //std::cout<<adan.pistola->municion<<std::endl;
                    // std::cout<<base.getPosition().x<<" "<<base.getPosition().y<<endl;
                    // std::cout<<adan.getPosition().x<<" "<<adan.getPosition().y<<endl;
                    // for(int i=0;i<adan.pistola->existentes.size();i++){
                        
                    //     //std::cout<<"disparo "<<i+1<<": "<<adan.pistola->existentes[i]->getPosition().x<<" "<<adan.pistola->existentes[i]->getPosition().x<< " direccion x:"<<adan.pistola->existentes[i]->getDireccion().x<<" direccion y:"<<adan.pistola->existentes[i]->getDireccion().y<<std::endl;
                    // }// modificalo para ver que esta pasando, por que no guarda el ultimo disparo, por que no detecta cual fue la ultima etc,

                }
                if(event.key.code==Keyboard::R){
                    recargar=true;
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
            saltando=true;
            adan.saltar(y,base);
        }
        /// NADA DE ESTO

        if(recargar==true){
            adan.recargar(recargar);
        }

        base.colision(adan,x,y,saltando);
        adan.update(x,y,atras);
        //serpiente.update(adan);
        window.clear();
        atras.drawTo(window);
        adan.drawTo(window);
        adan.pistola->drawTo(window);
       // serpiente.drawTo(window);
        base.drawTo(window);
        for(int i=0;i<adan.pistola->existentes.size(); i++){
            adan.pistola->existentes[i]->trayectoria();
            adan.pistola->existentes[i]->drawTo(window);
            
        }

        
        window.display();
    }

    return 0;
}