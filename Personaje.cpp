#include "Personaje.hpp"
#include "Armas.hpp"
#include "Plataformas.hpp"
#include "enemigo.hpp"
#include "back.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Personaje::Personaje(int vida){


    if(!espejo.loadFromFile("assets/soldadoespejo.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    espejo.setRepeated(true);

    this->actualTexture.setTexture(espejo);
    this->actualTexture.setTextureRect(IntRect(18,17,13,17));
    this->actualTexture.scale(4,4);
    // animaciones.push_back(this->actualTexture);


    if(!stmTexture.loadFromFile("assets/soldadoMejorado.png"))
    {
        std::cout << "Error al cargar imagen" << std::endl;
    }
    stmTexture.setRepeated(true);

    this->actualTexture.setTexture(stmTexture);
    this->actualTexture.setTextureRect(IntRect(30,20,13,17));
    

    
    // animaciones.push_back(actualTexture);
    //this->actualTexture.setScale(-1,1);
    
    
    this->vida=vida;
    this->salto=true; // puede saltar
    this->contSalto=0;
    this->siguienteS=true;
    this->tatekieto=false;
    this->pistola= new Principal(this->actualTexture.getPosition());
    this->contRecarga=0;
    this->vista.x=1;
   
    
    
}

void Personaje::update(int &x, int y/*, int danio, bool piso*/, Fondo &paisaje,Plataforma & piso, Enemigo &serpiente){
    
    if((this->actualTexture.getPosition().x<225 && (x==1|| x==3) || (paisaje.getA()>=1000 && this->actualTexture.getPosition().x<450 && x==1))){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y);
        
        
        

    }else {
        if(this->actualTexture.getPosition().x>=225 && (x==1|| x==3) && paisaje.getA()<1000){
            
            paisaje.desplaza(x);
            piso.desplazamiento(x);
            serpiente.update(this,x,y);
            
        }
    }
    if(this->actualTexture.getPosition().x>0 && (x==-1||x==-3)){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y);
        serpiente.pistola->update(serpiente.actualTexture.getPosition(),x,y,this->vista);
        
        
    }else{
        if(this->actualTexture.getPosition().x<=0 && (x==-1|| x==-3) && paisaje.getA()>0){
            paisaje.desplaza(x);
            piso.desplazamiento(x);
            serpiente.update(this,x,y);
           
        }
    }
    if(this->actualTexture.getPosition().y<401 /*&& piso==false*/){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x,this->actualTexture.getPosition().y+y);
    }

    for(int i=0;i<this->pistola->existentes.size();i++){
        
        if(this->pistola->existentes[i]->getPosition().x>=401 || this->pistola->existentes[i]->getPosition().y>=401) {
            
           
        }else{
            this->pistola->existentes[i]->trayectoria();
        }
        
    }
    //this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y+y);
   
   this->pistola->update(this->actualTexture.getPosition(), x, y, this->vista);
   
}

void Personaje::drawTo(RenderWindow &window){
    window.draw(this->actualTexture);
}



void Personaje::shot(Vector2f inicio, int ultima){
    // Bala* disparo=new Bala(10,inicio);
    // acumulados.push_back(disparo);
    
    if(vista.x==0 && vista.y==0) vista.x=ultima;
    if(pistola->municion!=0){
        pistola->disparo(this->actualTexture.getPosition(),vista);
        pistola->municion--;
    }
}



Vector2f Personaje::getPosition(){
    return this->actualTexture.getPosition();
}

void Personaje::saltar(int &y,Plataforma base){
    if(this->salto==false){
                y=-1;
                
                if(this->contSalto==100){
                    this->contSalto=0;
                    this->salto=true;
                }
                this->contSalto++;
            }else{
                y=0;
            }
            if(this->actualTexture.getPosition().y==400 || base.eta==true){
              
               this->siguienteS=true;
            }
            
            
}


void Personaje::recargar(bool &recarga){
    if(contRecarga==500){
        this->pistola->municion=this->pistola->getMun();
        contRecarga=0;
        recarga=false;
    }
    contRecarga++;
}