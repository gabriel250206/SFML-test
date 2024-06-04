#pragma once
#include "back.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Fondo::Fondo(){
    if(!stmTexture.loadFromFile("assets/FONDOFINAL.png"))
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
    
    a=a+x*2;
    if(a<10000 && a>0)this->actualTexture.setTextureRect(IntRect(0+a,0,500,500));

}

int Fondo::getA(){
    return this->a;
}

Outro::Outro(){
    this->opacidad=0;
     if(!stmTexture.loadFromFile("assets/fondoNegro.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setColor(Color(255,255,255,opacidad % 255));
}

void Outro::fin(RenderWindow & window){
    this->opacidad++;
    this->actualTexture.setColor(Color(255,255,255,opacidad % 255));
    window.draw(this->actualTexture);
}

Inicio::Inicio(){
    this->font.loadFromFile("assets/sewer.ttf");
    Text title("Ascomicidas",font,75);
    title.setFillColor(Color::Red);
    title.setPosition(Vector2f{25,0});
    this->title=title;

    
    Text inicio("Jugar",font,50);
    inicio.setPosition(Vector2f{50,100});
    inicio.setFillColor(Color::Yellow);




    Text scoreboard("Scoreboard",font,50);
    scoreboard.setPosition(Vector2f{50,200});
    scoreboard.setFillColor(Color::White);

    Text salir("Salir",font,50);
    salir.setPosition(Vector2f{50,300});
    salir.setFillColor(Color::White);



    Text eleccion("X",font,50);
    eleccion.setPosition(Vector2f{0,100});
    eleccion.setFillColor(Color::White);

    this->inicio=inicio;
    this->scoreboard=scoreboard;
    this->salir=salir;
    this->eleccion=eleccion;
    this->lleva=0;
}

void Inicio::drawTo(RenderWindow &window){
    window.draw(this->title);
    window.draw(this->inicio);
    window.draw(this->scoreboard);
    window.draw(this->salir);
    //window.draw(this->eleccion);
}

void Inicio::interaccion(int &x){
    if(x==1){
        this->inicio.setFillColor(Color::Yellow);
        this->scoreboard.setFillColor(Color::White);
        this->salir.setFillColor(Color::White);
        // this->eleccion.setPosition(eleccion.getPosition().x,eleccion.getPosition().y+100);
        // this->lleva+=100;
    }
    if(x==2){
        this->inicio.setFillColor(Color::White);
        this->scoreboard.setFillColor(Color::Yellow);
        this->salir.setFillColor(Color::White);
    }
        // this->eleccion.setPosition(eleccion.getPosition().x,eleccion.getPosition().y+100);
        // this->lleva-=100;
    
    if(x==3){
        this->inicio.setFillColor(Color::White);
        this->scoreboard.setFillColor(Color::White);
        this->salir.setFillColor(Color::Yellow);
    }
    if(x==4){
        x=1;
        // this->eleccion.setPosition(eleccion.getPosition().x,eleccion.getPosition().y-300);
        // this->lleva=0;
    }
    if(x==-1){
        x=3;
        // this->eleccion.setPosition(eleccion.getPosition().x,eleccion.getPosition().y+300);
    }
    
}