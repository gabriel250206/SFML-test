#include "Personaje.hpp"
#include "Armas.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Personaje::Personaje(int vida){


    // if(!espejo.loadFromFile("assets/soldadoespejo.png"))
    // {
    //     std::cout << "Error al cargar imagen" << std::endl;
    // }
    // espejo.setRepeated(true);

    // this->actualTexture.setTexture(espejo);
    // this->actualTexture.setTextureRect(IntRect(20,0,16,40));

    // animaciones.push_back(this->actualTexture);


    if(!stmTexture.loadFromFile("assets/soldadoMejorado.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(30,0,16,40));
    this->actualTexture.scale(4,4);

    
    animaciones.push_back(actualTexture);
    //this->actualTexture.setScale(-1,1);
    
    
    this->vida=vida;
    this->salto=true; // puede saltar
    this->contSalto=0;
    this->siguienteS=true;
    this->tatekieto=false;
    this->pistola= new Principal();
    
}

void Personaje::update(int x, int y/*, int danio, bool piso*/){
    
    if(this->actualTexture.getPosition().x<401 && x==1){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y);
        //this->actualTexture.setTexture(animaciones[0]);
    }else if(this->actualTexture.getPosition().x>0 && x==-1){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y);
        //this->actualTexture.setTexture(animaciones[1]);
    }
    if(this->actualTexture.getPosition().y<401 /*&& piso==false*/){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x,this->actualTexture.getPosition().y+y);
    }

    for(int i=0;i<this->pistola->existentes.size();i++){
        
        if(this->pistola->existentes[i]->getPosition().x>=401 || this->pistola->existentes[i]->getPosition().y>=401) {
            
           
        }else{
            this->pistola->existentes[i]->trayectoria();
        }
        
    }
    //this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y+y);
   
   
}

void Personaje::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}



void Personaje::shot(Vector2f inicio, int ultima){
    // Bala* disparo=new Bala(10,inicio);
    // acumulados.push_back(disparo);
    // municion--;
    if(vista.x==0 && vista.y==0) vista.x=ultima;
    pistola->disparo(this->actualTexture.getPosition(),vista);
}



Vector2f Personaje::getPosition(){
    return this->actualTexture.getPosition();
}