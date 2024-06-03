#pragma once

#include "ataquesB.hpp"
#include <vector>
using namespace std;
Antenas::Antenas(int lado, Vector2f posicion){
    
    if(lado==1){
        if(!stmTexture.loadFromFile("assets/antenaIA.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
            stmTexture.setRepeated(true);
            this->actualTexture.setTexture(stmTexture);
            this->actualTexture.setTextureRect(IntRect(0,0,2,1));
            this->actualTexture.setScale(4,4);
            this->actualTexture.setPosition(posicion);
            this->lado=lado;
            cout<<lado<<endl;
            
        }
    }
    if(lado==2){
        if(!stmTexture.loadFromFile("assets/antenaDA.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
            stmTexture.setRepeated(true);
            this->actualTexture.setTexture(stmTexture);
            this->actualTexture.setTextureRect(IntRect(0,0,2,1));
            this->actualTexture.setScale(4,4);
            this->actualTexture.setPosition(posicion);
            this->lado=lado;
            cout<<lado<<endl;
        }
    }
    if(lado==3){
        if(!stmTexture.loadFromFile("assets/antenaIB.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
            stmTexture.setRepeated(true);
            this->actualTexture.setTexture(stmTexture);
            this->actualTexture.setTextureRect(IntRect(0,0,2,1));
            this->actualTexture.setScale(4,4);
            this->actualTexture.setPosition(posicion);
            this->lado=lado;
            cout<<lado<<endl;
        }
    }
    if(lado==4){
        if(!stmTexture.loadFromFile("assets/antenaDB.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
            stmTexture.setRepeated(true);
            this->actualTexture.setTexture(stmTexture);
            this->actualTexture.setTextureRect(IntRect(0,0,2,1));
            this->actualTexture.setScale(4,4);
            this->actualTexture.setPosition(posicion);
            this->lado=lado;
            cout<<lado<<endl;
        }
    }
  
    
    
    
     

}

void Antenas::especial(){
    if(lado==1){
        Bala* nueva=new Bala(this->danio, this->actualTexture.getPosition(),Vector2f{-1,1});
        existentes.push_back(nueva); 
    }
    if(lado==2){
        Bala* nueva=new Bala(this->danio, this->actualTexture.getPosition(),Vector2f{1,1});
        existentes.push_back(nueva); 
    }
    if(lado==3){
        Bala* nueva=new Bala(this->danio, this->actualTexture.getPosition(),Vector2f{-1,-1});
        existentes.push_back(nueva); 
    }
    if(lado==4){
        Bala* nueva=new Bala(this->danio, this->actualTexture.getPosition(),Vector2f{1,-1});
        existentes.push_back(nueva); 
    }
    
}


void Antenas::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}