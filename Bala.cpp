#pragma once
#include "Bala.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
Bala::Bala(int danio, Vector2f posicion, Vector2f direccion){
    this->danio=danio;
    posicion.x=posicion.x+10;
    this->direccion=direccion;
    if(this->direccion.x==-1){
        if(!stmTexture.loadFromFile("assets/bala.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
        }
        stmTexture.setRepeated(true);

        this->actualTexture.setTexture(stmTexture);
        this->actualTexture.setPosition(posicion);
        this->actualTexture.setTextureRect(IntRect(13,21,20,7));
    
    }else if(this->direccion.x==1){
        if(!stmTexture.loadFromFile("assets/balaVolteada.png"))
        {
            std::cout << "Error al cargar imagen" << std::endl;
        }
        stmTexture.setRepeated(true);

        this->actualTexture.setTexture(stmTexture);
        this->actualTexture.setPosition(posicion);

        this->actualTexture.setTextureRect(IntRect(13,23,20,7));
       
    }
    this->direccion.x*=2;
    this->impactado=false;

    SoundBuffer buffer;
        if(!buffer.loadFromFile("assets/disparo.mp3"))
        {
            cout << "No funciona la musica" << endl;
        }
        Sound sound;
        sound.setBuffer(buffer);
        sound.play();
    
}

void Bala::trayectoria(){
    
    /*if(!impactado)*/this->actualTexture.move(this->direccion);
}
// void Bala::mover(int direcx,int direcy){
//     this->bullet.setPosition(this->bullet.getPosition().x+direcx,this->bullet.getPosition().y+direcy);
// }
void Bala::drawTo(RenderWindow &window){
    /*if(!impactado)*/window.draw(this->actualTexture);
}

Vector2f Bala::getPosition(){
    return this->actualTexture.getPosition();
}
Vector2f Bala::getDireccion(){
    return this->direccion;
}

void Bala::Impacto(Sprite actualTexture1, int &vida, bool muerto){
   
    if(this->actualTexture.getGlobalBounds().intersects(actualTexture1.getGlobalBounds()) && this->impactado==false && !muerto){
        cout<<"pega"<<endl;
        vida=vida-this->danio;
        this->impactado=true;
    }
}