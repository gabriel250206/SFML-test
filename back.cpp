#pragma once
#include "back.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Fondo::Fondo(){
    if(!stmTexture.loadFromFile("assets/pazto.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    //this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    //this->actualTexture.setScale(4,4);
    this->actualTexture.setPosition(0,0);
    this->a=0;
}

void Fondo::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}

void Fondo::desplaza(int x){
    cout<<"desplaza"<<endl;
    a=a+x;
    this->actualTexture.setTextureRect(IntRect(0+a,0,500,500));

}