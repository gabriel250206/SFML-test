#include "Bala.hpp"
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Armas.hpp"

Principal::Principal(Vector2f posicion){
    this->danio=10;
    this->municionMax=10;
    this->municion=municionMax;
    this->tirada=false;

    if(!stmTexture.loadFromFile("assets/raygun.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(2,25,24,20));
    //this->actualTexture.setScale(2,2);
    this->actualTexture.setPosition(posicion.x+40,posicion.y+35);



}

Principal::Principal(){
    this->danio=10;
    this->municionMax=10;
    this->municion=municionMax;

    if(!stmTexture.loadFromFile("assets/raygun.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    this->actualTexture.setScale(4,4);
    this->actualTexture.setPosition(250,250);



}


int Principal::getDanio(){
    return this->danio;
}

void Principal::recargar(){
    this->municion=municionMax;
}
void Principal::especial(int &x, int &cont){

}
void Principal::disparo(Vector2f posicion,Vector2f direccion){
    Bala* nueva=new Bala(this->danio, posicion,direccion);
    existentes.push_back(nueva);
    std::cout<<"pum"<<endl;
}

LanzaGuizantes::LanzaGuizantes(Vector2f posicion){
    this->danio=10;
    this->municionMax=10;
    this->municion=municionMax;
    this->desplazar=false;
}


void LanzaGuizantes::especial(int &x, int& cont){
    this->desplazar=true;
}

int Principal::getMun(){
    return this->municionMax;
}

void Principal::update(Vector2f posicion, int x, int y){
    if(!tirada){
        this->actualTexture.setPosition(posicion.x+40,posicion.y+35);
    }else{
        this->actualTexture.setPosition(this->actualTexture.getPosition().x+(-1*x),this->actualTexture.getPosition().y);
    }
}

void Principal::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}

void Principal::drop(){
    
}