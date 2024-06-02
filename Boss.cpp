#pragma once
#include "Boss.hpp"
#include "Bala.hpp"
#include <iostream>
using namespace std;
Boss::Boss(Vector2f posicion){
    if(!stmTexture.loadFromFile("assets/enemigoRojo.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);
    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    this->actualTexture.setScale(4,4);
}