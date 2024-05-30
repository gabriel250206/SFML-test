#pragma once
#include "enemigo.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace sf;
using namespace std;

Enemigo::Enemigo(int x){
    this->vida=100;
    if(!stmTexture.loadFromFile("assets/enemigoRojo.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    this->actualTexture.setScale(4,4);

    this->actualTexture.setPosition(x,400);
    this->dibujar=true;
    this->pistola= new Principal(this->actualTexture.getPosition());
    this->tiempo=0;
    this->muerto=false;
    this->vista={-1,0};
    this->rangoX=1;
    this->mov=rand() %500;
    
}


void Enemigo::drawTo(RenderWindow &window){
    if(dibujar){
        window.draw(this->actualTexture);
    }else{
        muerto=true;
        this->pistola->tirada=true;
    }
}

void Enemigo::update(Personaje* adan, int x, int y){
    if(muerto==false){
        
    this->actualTexture.setPosition(actualTexture.getPosition().x-x,actualTexture.getPosition().y);

    this->actualTexture.setPosition(this->actualTexture.getPosition().x+rangoX,this->actualTexture.getPosition().y);
    if((mov==0||mov==500)||(mov==-500||mov==0)){
        rangoX *= -1;
    }
    mov +=rangoX;
    



    }
    if(this->vida<=0){
        this->muerto=true;
        this->dibujar=false;
    }
    
   
    

    
    


    
}

void Enemigo::disparo(Personaje adan, int x, int y){
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
    
    this->pistola->update(this->actualTexture.getPosition(),x,y, vista,0);
}

bool Enemigo::getEstado(){
    return muerto;
}

