#pragma once
#include "Bala.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Bala::Bala(int danio, Vector2f posicion, Vector2f direccion){
    this->danio=danio;
    this->direccion=direccion;
    
    if(!stmTexture.loadFromFile("assets/stickman.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setPosition(posicion);
    this->actualTexture.setTextureRect(IntRect(0,0,100,100));

}

void Bala::trayectoria(){
    this->actualTexture.move(this->direccion);
}
// void Bala::mover(int direcx,int direcy){
//     this->bullet.setPosition(this->bullet.getPosition().x+direcx,this->bullet.getPosition().y+direcy);
// }
void Bala::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}