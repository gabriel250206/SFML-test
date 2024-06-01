#pragma once
#include "Obstaculos.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personaje.hpp"

using namespace std;

Barrera::Barrera(Vector2f posicion){

            if(!stmTexture.loadFromFile("assets/barrera.png"))
            {
                std::cout << "Error al cargar imagen" << std::endl;
            }
            stmTexture.setRepeated(true);

            this->actualTexture.setTexture(stmTexture);
            this->actualTexture.setTextureRect(IntRect(0,0,50,500));
            this->actualTexture.setPosition(posicion.x,posicion.y);

            this->tiempo=0;
            this->mostrar=true;
            siguiente=0;
            this->prevalece=false;
}

void Barrera::drawTo(RenderWindow &window){
    if(mostrar || prevalece)window.draw(this->actualTexture);
}

void Barrera::desaparecer(){
    if(this->tiempo==300){
        siguiente++;
        tiempo=0;
    }
    if(siguiente %2==0){
        this->mostrar=false;
    }else{
        this->mostrar=true;
    }
    tiempo++;
    cout<<tiempo<<endl;


}

void Barrera::golpe(Personaje &adan){
    if(this->mostrar && this->actualTexture.getGlobalBounds().intersects(adan.actualTexture.getGlobalBounds())){
        adan.vida-=10;
        adan.actualTexture.setPosition(adan.getPosition().x-50,adan.actualTexture.getPosition().y);
    }
}

void Barrera::movimiento(int x){
    this->actualTexture.setPosition(this->actualTexture.getPosition().x-x,this->actualTexture.getPosition().y);
}

PisoLava::PisoLava(Vector2f posicion):Barrera(posicion){
    if(!stmTexture.loadFromFile("assets/pisoRojo.png"))
            {
                std::cout << "Error al cargar imagen" << std::endl;
            }
            stmTexture.setRepeated(true);

            this->actualTexture.setTexture(stmTexture);
            this->actualTexture.setTextureRect(IntRect(0,0,50,30));
            this->actualTexture.setPosition(posicion.x,posicion.y);

    this->prevalece=true;

}
void PisoLava::setExtention(int x){
    this->actualTexture.setTextureRect(IntRect(0,0,x,30));
}