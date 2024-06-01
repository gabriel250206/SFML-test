#pragma once
#include "enemigo.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace sf;
using namespace std;

Enemigo::Enemigo(){
    this->vida=100000;
    if(!stmTexture.loadFromFile("assets/enemigoRojo.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);
    this->movimiento=false;
    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    this->actualTexture.setScale(4,4);
    this->cooldown=0;
    this->actualTexture.setPosition(100,400);
    this->dibujar=true;
    this->pistola= new Principal(this->actualTexture.getPosition());
    this->tiempo=0;
    this->muerto=false;
    this->vista={-1,0};
    this->disparar=true;
    
}

Enemigo::Enemigo(int x){
    this->vida=100;
    if(!stmTexture.loadFromFile("assets/enemigoRojo.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);
    this->movimiento=true;
    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(16,16,18,17));
    this->actualTexture.setScale(4,4);
    this->cooldown=0;
    this->actualTexture.setPosition(x,400);
    this->dibujar=true;
    this->pistola= new Principal(this->actualTexture.getPosition());
    this->tiempo=0;
    this->muerto=false;
    this->vista={-1,0};
    this->rangoX=1;
    this->mov=rand() %500;
    this->disparar=true;
    
}

void Enemigo::drawTo(RenderWindow &window){
    if(dibujar){
        window.draw(this->actualTexture);
    }else{
        muerto=true;
        this->pistola->tirada=true;
    }
}

void Enemigo::update(Personaje* adan, int x, int y){
    if(muerto==false){
        
        
    this->actualTexture.setPosition(actualTexture.getPosition().x-x,actualTexture.getPosition().y);

    if(movimiento)this->actualTexture.setPosition(this->actualTexture.getPosition().x+rangoX,this->actualTexture.getPosition().y);
    if((mov==0||mov==500)||(mov==-500||mov==0)){
        rangoX *= -1;
    }
    mov +=rangoX;
    



    }
    if(this->vida<=0){
        this->muerto=true;
        this->dibujar=false;
    }
    
   if(this->cooldown==0){
        if(this->actualTexture.getGlobalBounds().intersects(adan->actualTexture.getGlobalBounds())){
            cout<<"golpe"<<endl;
            adan->vida= adan->vida-10;
            this->cooldown++;
            adan->actualTexture.setPosition(adan->actualTexture.getPosition().x-40,adan->actualTexture.getPosition().y-20);
        }
   }else{
    cooldown++;
    if(this->cooldown==300){
        this->cooldown=0;
    }
   }
    
}

void Enemigo::disparo(Personaje adan, int x, int y){
    if(this->tiempo==0 && disparar==true){
        
        this->pistola->disparo(this->actualTexture.getPosition(),Vector2f{-1,0});
        
    }
    tiempo++;

    if(this->tiempo==500){
        this->tiempo=0;
    }
    for(int i=0;i<adan.pistola->existentes.size();i++){
        if(this->actualTexture.getPosition()==adan.pistola->existentes[i]->getPosition()){
            dibujar=false;
        }
    }
    
    this->pistola->update(this->actualTexture.getPosition(),x,y, vista,0);
}

bool Enemigo::getEstado(){
    return muerto;
}










Disparador::Disparador(Vector2f posicion, Vector2f vista):Enemigo(){
    if(!stmTexture.loadFromFile("assets/pium.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);
    this->movimiento=true;
    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(18,46,10,4));
    this->actualTexture.setPosition(posicion);
    this->pistola=new Base(this->actualTexture.getPosition());
    this->vista=vista;
    this->muerto=false;

}

void Disparador::update(Personaje* adan, int x, int y){
    this->actualTexture.setPosition(actualTexture.getPosition().x-x,actualTexture.getPosition().y);

    if(this->cooldown==0){
        if(this->actualTexture.getGlobalBounds().intersects(adan->actualTexture.getGlobalBounds())){
            cout<<"golpe"<<endl;
            adan->vida= adan->vida-10;
            this->cooldown++;
            adan->actualTexture.setPosition(adan->actualTexture.getPosition().x-40,adan->actualTexture.getPosition().y-20);
        }
   }else{
    cooldown++;
    if(this->cooldown==300){
        this->cooldown=0;
    }
   }
   
   this->pistola->update(this->actualTexture.getPosition(),x,y, vista,0);
}

void Disparador::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}

void Disparador::disparo(Personaje adan, int x, int y){
    if(this->tiempo==0){
        
        this->pistola->disparo(this->actualTexture.getPosition(),Vector2f{0,-1});
        
    }
    tiempo++;

    if(this->tiempo==500){
        this->tiempo=0;
    }
    
    
    this->pistola->update(this->actualTexture.getPosition(),x,y, vista,0);
}







Fuerte::Fuerte(int x):Enemigo(x){
    this->actualTexture.setColor(Color::Blue);
    this->vida=200;
}

Rapido::Rapido(int x):Enemigo(x){

    this->vida=50;
    this->actualTexture.setColor(Color::Green);
    this->mov=2;
    this->rangoX=2;
}


Barrera::Barrera(Vector2f posicion):Enemigo(){
    this->actualTexture.getPosition();
    this->vista=Vector2f{0,0};
    this->disparar=false;
    this->cont=0;
}

void Barrera::update(Personaje* adan, int x, int y){
    cout<<"oli"<<endl;
    if(cont<100){
        this->muerto=false;
    }
    if(cont>=100){
        this->muerto=true;
    }
    cont++;
    if(cont==200){
        cont=0;
    }
}

