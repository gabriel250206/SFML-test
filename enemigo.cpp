#pragma once
#include "enemigo.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Enemigo::Enemigo(int vida){
    this->vida=vida;
    if(!stmTexture.loadFromFile("assets/enemigoRojo.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    this->actualTexture.setScale(4,4);
    this->actualTexture.setPosition(300,400);
    this->dibujar=true;
}


void Enemigo::drawTo(RenderWindow &window){
    if(dibujar)window.draw(this->actualTexture);
}

void Enemigo::update(Personaje adan){
    for(int i=0;i<adan.pistola->existentes.size();i++){
        if(this->actualTexture.getPosition()==adan.pistola->existentes[i]->getPosition()){
            dibujar=false;
        }
    }
}