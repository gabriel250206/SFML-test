#include "Personaje.hpp"
#include "Armas.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Personaje::Personaje(int vida){

    if(!stmTexture.loadFromFile("assets/stickman.png"))
    {
        std::cout << "Error al cargar imagen" << endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(0,0,105,99));
    
    this->vida=vida;
    this->salto=true; // puede saltar
    this->contSalto=0;
    this->siguienteS=true;
    this->tatekieto=false;
    this->pistola= new Principal();
}

void Personaje::update(int x, int y/*, int danio*/){
    
    
    this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y+y);
   
   
}

void Personaje::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}



void Personaje::shot(Vector2f inicio){
    // Bala* disparo=new Bala(10,inicio);
    // acumulados.push_back(disparo);
    // municion--;
    pistola->disparo(this->actualTexture.getPosition(),vista);
}

