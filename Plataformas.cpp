#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;
#include "Plataformas.hpp"
#include "Personaje.hpp"


Plataforma::Plataforma(Vector2f posicion){

    if(!stmTexture.loadFromFile("assets/pasto.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);
    
    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(10,21,28,50));
    this->actualTexture.scale(4,4);


    this->actualTexture.setPosition(posicion);
}


void Plataforma::colision(Personaje &adan,int &x, int &y){

    // int bmax=this->actualTexture.getPosition().x+105;
    // int hmax=this->actualTexture.getPosition().y+99;

    if(adan.actualTexture.getGlobalBounds().intersects(this->actualTexture.getGlobalBounds())){
        y=0;
    }

    // bool tocaBase=adan.actualTexture.getPosition().x<=bmax && adan.actualTexture.getPosition().x + adan.actualTexture.ge().x>=this->actualTexture.getPosition().x;
    // bool tocaAltura=adan.actualTexture.getPosition().y==this->actualTexture.getPosition().y-1;
    // if(tocaBase && tocaAltura){
    //     y=0;
    // }
    
    


}

void Plataforma::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}

Vector2f Plataforma::getPosition(){
    return this->actualTexture.getPosition();
}