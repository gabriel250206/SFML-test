#include "Personaje.hpp"
#include "Bala.hpp"

Personaje::Personaje(int vida){
    this->vida=vida;
    this->municion=25;
    this->actual->setPosition(0,250);
    this->vista=0;
}

void Personaje::update(int x, int y, int danio){
    if(this->actual->getPosition().x<500 && this->actual->getPosition().x>0){
        this->siguiente->setPosition(actual->getPosition().x+x,this->actual->getPosition().y);
    }
    if(this->actual->getPosition().y<500&& this->actual->getPosition().y>0){
        this->siguiente->setPosition(actual->getPosition().x,this->actual->getPosition().y+y);
    }
    
        this->vida=this->vida-danio;

    for(auto &a: acumulados){
        a->mover(x,y);
    }
    this->actual->setPosition(this->siguiente->getPosition());
}



void Personaje::shot(Vector2f inicio){
    Bala* disparo=new Bala(10,inicio);
    acumulados.push_back(disparo);
    municion--;
}

