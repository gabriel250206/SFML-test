#pragma once
#include "Bala.hpp"

Bala::Bala(int danio, Vector2f posicion, Vector2f direccion){
    this->danio=danio;
    this->posicion=posicion;
    this->direccion=direccion;
    
}


// void Bala::mover(int direcx,int direcy){
//     this->bullet.setPosition(this->bullet.getPosition().x+direcx,this->bullet.getPosition().y+direcy);
// }