#include "Bala.hpp"
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Armas.hpp"

Principal::Principal(){
    this->danio=10;
    this->municionMax=20;
    this->municion=municionMax;
}

int Principal::getDanio(){
    return this->danio;
}

void Principal::recargar(){
    this->municion=municionMax;
}
void Principal::especial(){

}
void Principal::disparo(Vector2f posicion,Vector2f direccion){
    Bala* nueva=new Bala(this->danio, posicion,direccion);
    existentes.push_back(nueva);
    std::cout<<"pum"<<endl;
}

LanzaGuizantes::LanzaGuizantes(){
    this->danio=10;
    this->municionMax=10;
    this->municion=municionMax;
}


void LanzaGuizantes::especial(){

}