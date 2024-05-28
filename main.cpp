#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Plataformas.hpp"
#include "Armas.hpp"
#include "back.hpp"
#include <iostream>
#include <vector>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(500, 500), "le contre");
    window.setFramerateLimit(200);
    Personaje adan(150);
    Enemigo serpiente(100);
    vector<Principal*>dropeadas;
    Plataforma base(Vector2f{250,350});
    Plataforma base2(Vector2f{400,200});

    vector<Plataforma> plataformeo;
    plataformeo.push_back(base);
    plataformeo.push_back(base2);

    Fondo atras;
    int x=0,y=0;
    int movx=0,movy=0; // desconozco funcionamiento de estas *-
    int ultima=0;
    bool saltando;// no se si funcione *-
    bool recargar=false;
    int dash=0;
    
    bool presion=false;
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
                    presion=true;
                    adan.actualTexture.setTexture(adan.espejo);
                    adan.actualTexture.setTextureRect(IntRect(18,17,13,17));
                    
                    
                    
                    
                }
                if(event.key.code==Keyboard::D){
                    if(adan.tatekieto==false)x=1;
                    adan.vista.x=1;
                    ultima=adan.vista.x;
                    presion=true;
                    adan.actualTexture.setTexture(adan.stmTexture);
                    adan.actualTexture.setTextureRect(IntRect(30,20,13,17));
                   
                    
            
                    
                    
                    
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
                    cout<<adan.vida<<" "<<serpiente.vida<<endl;
                    // std::cout<<atras.getA()<<std::endl;
                    // std::cout<<adan.actualTexture.getPosition().x<<std::endl;
                    //std::cout<<adan.contRecarga<<std::endl;
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
                if(event.key.code==Keyboard::E){
                    if(adan.pistola!=nullptr)adan.pistola->especial(x,dash);
                }
                if(event.key.code==Keyboard::Q){ ///dropear arma--
                    if(adan.pistola!=nullptr)adan.pistola->tirada=true;
                    if(adan.pistola!=nullptr)adan.pistola->dropJugador(adan,dropeadas);

                }
                


                


            }else if(event.type==Event::KeyReleased){// para que no se queden haciendo algo infinitamente
                
                if(event.key.code == Keyboard::A) {
                    if(x==-1)x=0;
                    presion=false;
                    if(!event.key.code==Keyboard::W || !event.key.code==Keyboard::S)adan.vista.x=0; // esto hace que no se muevan si está parado, pero si no lo ponemos entonces no puede disparar para arriba
                }
                if( event.key.code == Keyboard::D ) {
                    if(x==1)x=0;
                    presion=false;
                    if(!event.key.code==Keyboard::W||!event.key.code==Keyboard::S)adan.vista.x=0;
                }
                //if(event.key.code == Keyboard::S) y=0;
                if(event.key.code==Keyboard::W ) adan.vista.y=0;
                if(event.key.code==Keyboard::S )adan.vista.y=0;
                if(event.key.code == Keyboard::LShift) adan.tatekieto=false;
                if(event.key.code == Keyboard::A && event.key.code == Keyboard::D && event.key.code==Keyboard::W && event.key.code==Keyboard::S) adan.vista.x=ultima; // no funciona
               
            }
            
            
        }

        ///EFRA NO TOQUES ESTO 
        if((adan.actualTexture.getPosition().y<400 && adan.salto==true  )){
            y=1;
            cout<<"sale"<<endl;
            if(base.toca(adan)&&adan.salto==true){
                cout<<"entra"<<endl;
                saltando=true;
                y=-1;
                adan.saltar(y,base);
            }
           
        }else {
            cout<<"entra"<<endl;
            saltando=true;
            adan.saltar(y,base);
        }
        /// NADA DE ESTO

        if(recargar==true && adan.pistola!=nullptr){
            adan.recargar(recargar);
        }

        base.colision(adan,x,y,saltando);
        if(adan.pistola!=nullptr && adan.pistola->desplazar==true && dash<20){
            
            if(x==0)x=adan.vista.x;
            if(dash==0)x=x*3;
            dash++;
            
            cout<<x<<" "<<dash<<" "<<adan.pistola->desplazar<<endl;
            
        }else if(dash==20 && adan.pistola!=nullptr){ 
            if(adan.pistola!=nullptr)adan.pistola->desplazar=false;
            dash=0;
            cout<<adan.vista.x<<endl;

            if(presion==false){
                x=0;
            }else{
                x=adan.vista.x;
            }
            cout<<x<<endl;
        }
        adan.update(x,y,atras,base,serpiente);
        if(!serpiente.getEstado())serpiente.disparo(adan,x,y);
        window.clear();
        atras.drawTo(window);
        adan.drawTo(window);
        if(adan.pistola!=nullptr)adan.pistola->drawTo(window);
        serpiente.drawTo(window);
        serpiente.pistola->drawTo(window);
        base.drawTo(window);
        //base2.drawTo(window);

        if(adan.pistola!=nullptr){
            for(int i=0;i<adan.pistola->existentes.size(); i-=-1){
            adan.pistola->existentes[i]->trayectoria();
            adan.pistola->existentes[i]->Impacto(serpiente.actualTexture,serpiente.vida);
            adan.pistola->existentes[i]->drawTo(window);
            
        }
        }
        
        for(int i=0;i<serpiente.pistola->existentes.size();i-=-1){
            serpiente.pistola->existentes[i]->trayectoria();

            serpiente.pistola->existentes[i]->Impacto(adan.actualTexture,adan.vida);
            serpiente.pistola->existentes[i]->drawTo(window);
        }

        
        window.display();
    }

    return 0;
}