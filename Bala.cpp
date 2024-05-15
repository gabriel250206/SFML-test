#include "Bala.hpp"

Bala::Bala(int danio, Vector2f inicio){
    this->danio=danio;
    this->bullet.setPosition(inicio);
}


void Bala::mover(int direcx,int direcy){
    this->bullet.setPosition(this->bullet.getPosition().x+direcx,this->bullet.getPosition().y+direcy);
}