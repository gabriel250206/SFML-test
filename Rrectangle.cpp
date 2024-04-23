#include "Rrectangle.hpp"

Rectangle::Rectangle(Vector2f size, RenderWindow &window){
    this->shape = RectangleShape(size);
    this->shape.setPosition({Mouse::getPosition(window).x,Mouse::getPosition(window).y});
    this->shape.setFillColor(Color::Red);
    this->shape.setOutlineThickness(3);
    this->shape.setOutlineColor(Color::Red);
    this->speed=Vector2f(0.f,4.f);
    this->acc=Vector2f(0.f,1.f);


}

void Rectangle::update(){
    
    if(shape.getPosition().x+shape.getSize().x>=800|| shape.getPosition().x<0){
            
            speed.x*= -1;
          
    }
    if(this->shape.getPosition().y+this->shape.getSize().y<=600){
            
            this->speed += this->acc;
            this->shape.move(speed);
            
    }
    if(shape.getPosition().y+shape.getSize().y>=600|| shape.getPosition().y<0){

            this->speed.y*=-1;
            this->shape.setPosition(this->shape.getPosition().x,600-this->shape.getSize().y);
            
    }
    

    
}

void Rectangle::changeColorIfClick(Vector2i position){
    float x=this->shape.getPosition().x;
    float y=this->shape.getPosition().y;
    float w=this->shape.getSize().x;
    float h=this->shape.getSize().y;

    int mouseX=position.x;
    int mouseY=position.y;

    if(mouseX>=x && mouseX<=x+w && mouseY>=y && mouseY<=y+h){
        this->shape.setFillColor(Color::Green);
    }
}

void Rectangle::drawTo(RenderWindow &window){
    window.draw(this->shape);
}