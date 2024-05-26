#pragma once
#include "enemigo.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Enemigo::Enemigo(int vida){
    this->vida=vida;
    if(!stmTexture.loadFromFile("assets/enemigoRojo.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    this->actualTexture.setScale(4,4);
    this->actualTexture.setPosition(300,400);
    this->dibujar=true;
    this->pistola= new Principal(this->actualTexture.getPosition());
    this->tiempo=0;
    this->muerto=false;
}


void Enemigo::drawTo(RenderWindow &window){
    if(dibujar){
        window.draw(this->actualTexture);
    }else{
        muerto=true;
        this->pistola->tirada=true;
    }
}

void Enemigo::update(Personaje adan, int x, int y){
    if(muerto==false){
        if(this->tiempo==0){
        
        this->pistola->disparo(this->actualTexture.getPosition(),Vector2f{-1,0});
        
    }
    tiempo++;

    if(this->tiempo==500){
        this->tiempo=0;
    }
    for(int i=0;i<adan.pistola->existentes.size();i++){
        if(this->actualTexture.getPosition()==adan.pistola->existentes[i]->getPosition()){
            dibujar=false;
        }
    }
    this->actualTexture.setPosition(actualTexture.getPosition().x-x,actualTexture.getPosition().y);
    }
    
    this->pistola->update(this->actualTexture.getPosition(),x,y);
    


    
}