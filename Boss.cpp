#pragma once
#include "Boss.hpp"
#include "Bala.hpp"
#include <iostream>
using namespace std;
Boss::Boss(Vector2f posicion){
    if(!stmTexture.loadFromFile("assets/BossVista1.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);
    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(15,14,22,19));
    this->actualTexture.setScale(4,4);
    this->actualTexture.setPosition(posicion);

    for(int i=0; i<4;i++){
        Antenas* cuerno = new Antenas(1,*this);
        this->cuernitos.push_back(*cuerno);
    }
   
    




    
}

void Boss::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
    cuernitos[0].drawTo(window);
    
}



void Boss::mover(int x){
    this->actualTexture.setPosition(this->actualTexture.getPosition().x-x,this->actualTexture.getPosition().y);
}

void Boss::disparo(){
    
    for(int i=0;i<this->cuernitos.size();i++){
        
    }

}