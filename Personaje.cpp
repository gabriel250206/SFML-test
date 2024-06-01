#include "Personaje.hpp"
#include "Armas.hpp"
#include "Plataformas.hpp"
#include "Obstaculos.hpp"
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
    this->pistola= new LanzaGuizantes(this->actualTexture.getPosition());
    this->contRecarga=0;
    this->vista.x=1;
    this->muerto=false;
    this->boss=false;
   
    
    
}

void Personaje::update(int &x, int y/*, int danio, bool piso*/, Fondo &paisaje,Plataforma & piso, vector<Enemigo> &serpiente, vector<Barrera> &obstaculos){
    
    if((this->actualTexture.getPosition().x<225 && (x==1|| x==3) || (paisaje.getA()>=9500 && this->actualTexture.getPosition().x<450 && x==1  ))){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y);
        int x2=0;
        for(int i=0;i<serpiente.size();i++){
            serpiente[i].update(this,x2,y);
            if(serpiente[i].pistola->base==false){
                serpiente[i].pistola->update(serpiente[i].actualTexture.getPosition(),0,y,this->vista,paisaje.getA());
                
            }else{
                serpiente[i].pistola->update(serpiente[i].actualTexture.getPosition(),0,y,Vector2f {0,-1},paisaje.getA());
                
            }
            
            
        }
        if(paisaje.getA()>=9500){
            this->boss=true;
        }
        

        
        
        

    }else {
        if(this->actualTexture.getPosition().x>=225 && (x==1|| x==3) && paisaje.getA()<10000 ){
            
            paisaje.desplaza(x);
            piso.desplazamiento(x);
            for(int i=0;i<serpiente.size();i++){
                serpiente[i].update(this,x,y);
          
                serpiente[i].pistola->update(serpiente[i].actualTexture.getPosition(),x,y,this->vista,paisaje.getA());
                cout<<"entrando"<<endl;
            }
            for(int i=0;i<obstaculos.size();i++){
                obstaculos[i].movimiento(x);
            }
            if(paisaje.getA()==9500){
            this->boss=true;
            }
            
            
        }
    }
    if(this->actualTexture.getPosition().x>0 && (x==-1||x==-3) ){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y);
        int x2=0;
        for(int i=0;i<serpiente.size();i++){
            serpiente[i].update(this,x2,y);
            serpiente[i].pistola->update(serpiente[i].actualTexture.getPosition(),0,y,this->vista,paisaje.getA());
        }
        
        
        
    }else{
        if(this->actualTexture.getPosition().x<=0 && (x==-1|| x==-3) && paisaje.getA()>0 ){
            paisaje.desplaza(x);
            piso.desplazamiento(x);
            for(int i=0;i<serpiente.size();i++){
                serpiente[i].update(this,x,y);
                serpiente[i].pistola->update(serpiente[i].actualTexture.getPosition(),x,y,this->vista,paisaje.getA());
            }
            for(int i=0;i<obstaculos.size();i++){
                obstaculos[i].movimiento(x);
            }
           
        }
    }
    if(this->actualTexture.getPosition().y<401 /*&& piso==false*/){
        this->actualTexture.setPosition(this->actualTexture.getPosition().x,this->actualTexture.getPosition().y+y);
    }
    if(this->pistola!=nullptr){

    }
    
    //this->actualTexture.setPosition(this->actualTexture.getPosition().x+x,this->actualTexture.getPosition().y+y);
   
    if(x==0){
        for(int i=0;i<serpiente.size();i++){
            serpiente[i].update(this,x,y);
            serpiente[i].pistola->update(serpiente[i].actualTexture.getPosition(),x,y,this->vista,paisaje.getA());
        }
         
          
    }

   if(this->pistola!=nullptr)this->pistola->update(this->actualTexture.getPosition(), x, y, this->vista,paisaje.getA());
   if(this->vida==0)this->muerto=true;
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

void Personaje::saltar(int &y,Plataforma base, int &x, bool saltando, bool &click){
    
    if(this->salto==false && !base.toca(*this)){
                //cout<<"sube"<<endl;
                y=-1;
                
                if(this->contSalto==100){
                    this->contSalto=0;
                    this->salto=true;
                    click=false;
                }
                this->contSalto++;
            }else{
                
                if(base.toca(*this) ^ !click )y=0;
                //cout<<"queda"<<endl;
                
                // if(base.colision(*this,x,y,saltando)){
                //     this->siguienteS=true;
                //     this->
                // }
            }
            if(this->actualTexture.getPosition().y==400 || base.eta==true){
              
               this->siguienteS=true;
            }
            
            
}


void Personaje::recargar(bool &recarga){
    if(this->pistola!=nullptr){
        if(contRecarga==500){
        this->pistola->municion=this->pistola->getMun();
        contRecarga=0;
        recarga=false;
    }
    contRecarga++;
    }
}