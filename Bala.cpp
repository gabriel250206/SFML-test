#pragma once
#include "Bala.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Bala::Bala(int danio, Vector2f posicion, Vector2f direccion){
    this->danio=danio;
    posicion.x=posicion.x+10;
    this->direccion=direccion;
    if(this->direccion.x==-1){
        if(!stmTexture.loadFromFile("assets/bala.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
        }
        stmTexture.setRepeated(true);

        this->actualTexture.setTexture(stmTexture);
        this->actualTexture.setPosition(posicion);
        this->actualTexture.setTextureRect(IntRect(13,21,20,7));
    
    }else if(this->direccion.x==1){
        if(!stmTexture.loadFromFile("assets/balaVolteada.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
        }
        stmTexture.setRepeated(true);

        this->actualTexture.setTexture(stmTexture);
        this->actualTexture.setPosition(posicion);

        this->actualTexture.setTextureRect(IntRect(13,23,20,7));
       
    }
    
    this->impactado=false;

}

void Bala::trayectoria(){
    
    /*if(!impactado)*/this->actualTexture.move(this->direccion);
}
// void Bala::mover(int direcx,int direcy){
//     this->bullet.setPosition(this->bullet.getPosition().x+direcx,this->bullet.getPosition().y+direcy);
// }
void Bala::drawTo(RenderWindow &window){
    /*if(!impactado)*/window.draw(this->actualTexture);
}

Vector2f Bala::getPosition(){
    return this->actualTexture.getPosition();
}
Vector2f Bala::getDireccion(){
    return this->direccion;
}

void Bala::Impacto(Sprite actualTexture1, int &vida){
    if(this->actualTexture.getGlobalBounds().intersects(actualTexture1.getGlobalBounds()) && impactado==false){
        vida=vida-this->danio;
        this->impactado=true;
    }
}