#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Plataformas.hpp"
#include "Armas.hpp"
#include "back.hpp"
#include "Obstaculos.hpp"
#include "Boss.hpp"
#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include <SFML/Audio.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(500, 500), "le contre");
    window.setFramerateLimit(200);
    Personaje adan(150);
    Boss lucy(Vector2f{400,400});
    //Barrera primero(Vector2f{200,0});
    //PisoLava segundo(Vector2f{400,460});
    //segundo.setExtention(100);
    vector<Barrera>obstaculos;

    //obstaculos.push_back(primero);
    //obstaculos.push_back(segundo);
    vector<Enemigo>hongos;
    
    
    for(int i=0;i<3;i++){
        int primero=(rand() %350)+1000;
        Enemigo* serpiente= new Rapido(primero);
        hongos.push_back(*serpiente);
    }
    // for(int i=0;i<3;i++){
    //     int primero=rand() %350+200;
    //     Fuerte* serpiente= new Fuerte(primero);
    //     hongos.push_back(*serpiente);
    // }

    
    
    
    // primero=rand() %400+100;
    // Enemigo lilith(primero);
    vector<Principal*>dropeadas;
    
    Plataforma base(Vector2f{250,350});
    Plataforma base2(Vector2f{400,200});
    Plataforma base3(Vector2f{500,350});
    vector<Plataforma> plataformeo;
    //plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);

    
    //hongos.push_back(lilith);

    Fondo atras;
    int x=0,y=0;
    int movx=0,movy=0; // desconozco funcionamiento de estas *-
    int ultima=0;
    bool saltando;// no se si funcione *-
    bool recargar=false;
    int dash=0;
    bool click=false;
    bool presion=false;
    
    bool si=false;
    Plataforma* tocando;

    SoundBuffer buffer;
    if (!buffer.loadFromFile("musica.wav"))
    {
        cout << "No funciona la musica" << endl;
    }
    Sound sound;
    sound.setBuffer(buffer);
    sound.play();


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
                if(event.key.code==Keyboard::Space  && adan.salto==true ){ // si presionas y puede saltar
                    
                    std::cout<<"Espacio"<<endl;
                    adan.salto=false;
                                     
                }
                if(event.key.code==Keyboard::W){ /// tecla de comprobacion
                    adan.vista.y=-1;

                }
                if(event.key.code==Keyboard::S){ /// tecla de comprobacion
                    adan.vista.y=1;
                    

                }
                if(event.key.code==Keyboard::I){ /// tecla de comprobacion
                    //for(int i=0;i<hongos.size();i++) cout<<hongos[i].vida<<endl;
                    // cout<<atras.getA()<<endl;
                    // cout<<adan.boss<<endl;
                    // for(int i=0;i<hongos.size();i++){
                    //     cout<<adan.actualTexture.getPosition().x-hongos[i].actualTexture.getPosition().x<<endl;
                    // }
                    // for(int i=0;i<lucy.cuernitos.size();i++){
                    //     cout<<lucy.cuernitos[i].actualTexture.getPosition().x<<" "<< lucy.cuernitos[i].actualTexture.getPosition().y<<endl;
                    // }
                    cout<<y<<endl;
                    //cout<<adan.getPosition().y<<endl;
                    //cout<<adan.vida<<" "<<serpiente.vida<<endl<<atras.getA();
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
        si=false;
        for(int i=0;i<plataformeo.size();i++){
            if(plataformeo[i].toca(adan)){
                si=true;
                
                tocando=&plataformeo[i];
            }

        }
        if(adan.actualTexture.getPosition().y<400 && adan.salto==true && !si){
            
            y=1;
           
        }else {
            if(!adan.salto){
                adan.saltar(y);
            }

            if(si && adan.salto){
                y=0;
                adan.contSalto=0;

            }else{
                if(si){
                    si=false;
                    
                    
                }
                
            }
                
            if(adan.actualTexture.getPosition().y==400 && adan.salto){
            
                y=0;
                adan.contSalto=0;
            }
        } 
            
         
        /// NADA DE ESTO

        if(recargar==true && adan.pistola!=nullptr){
            adan.recargar(recargar);
        }

        
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
        adan.update(x,y,atras,plataformeo,hongos,obstaculos,lucy);
        for(int i=0;i<hongos.size();i++){
            if(!hongos[i].getEstado() && hongos[i].aparecer(&adan))hongos[i].disparo(adan,x,y);
        }
        
        
        atras.drawTo(window);
        if(!adan.muerto)adan.drawTo(window);
        if(adan.pistola!=nullptr)adan.pistola->drawTo(window);
        for(int i=0;i<hongos.size();i++){
            if(hongos[i].aparecer(&adan)){
                hongos[i].drawTo(window);
                hongos[i].pistola->drawTo(window);
            }
            
        }
        
        for(int i=0;i<plataformeo.size();i++)plataformeo[i].drawTo(window);
        

        
            for(int i=0;i<adan.pistola->existentes.size(); i-=-1){
                for(int j=0;j<hongos.size();j++){
                    adan.pistola->existentes[i]->trayectoria();
                    adan.pistola->existentes[i]->Impacto(hongos[j].actualTexture,hongos[j].vida,hongos[j].getEstado());
                    adan.pistola->existentes[i]->drawTo(window);
                }
                
            
            }
        
        for(int h=0;h<hongos.size();h++){
            for(int i=0;i<hongos[h].pistola->existentes.size();i-=-1){
                if(hongos[i].aparecer(&adan)){
                    hongos[h].pistola->existentes[i]->trayectoria();
                    hongos[h].pistola->existentes[i]->Impacto(adan.actualTexture,adan.vida,adan.muerto);
                
                    hongos[h].pistola->existentes[i]->drawTo(window);
                }
                
        }
        }
        
        for(int i=0;i<obstaculos.size();i++){
            obstaculos[i].desaparecer();
            obstaculos[i].golpe(adan);
            obstaculos[i].drawTo(window);
        }


        lucy.disparo();


        for(int i=0;i<lucy.cuernitos.size();i++){
            for(int j=0;j<lucy.cuernitos[i].existentes.size();j++){
                lucy.cuernitos[i].existentes[j]->trayectoria();
                lucy.cuernitos[i].existentes[j]->Impacto(adan.actualTexture,adan.vida,adan.muerto);
                lucy.cuernitos[i].existentes[j]->drawTo(window);
            }
        }
        for(int i=0;i<lucy.cuernitos.size();i++){
            lucy.cuernitos[i].drawTo(window);
        }
        lucy.drawTo(window);
        
        window.display();
    }

    return 0;
}
