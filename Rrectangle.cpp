#include "Rrectangle.hpp"

Rectangle::Rectangle(Vector2f size, RenderWindow &window){
    this->shape = RectangleShape(size);
    this->shape.setPosition({Mouse::getPosition(window).x,Mouse::getPosition(window).y});
    this->shape.setFillColor(Color::Blue);
    this->speed=Vector2f(4.f,4.f);

}

void Rectangle::update(){
    if(shape.getPosition().x+shape.getSize().x>=800|| shape.getPosition().x<0){
            
            speed.x*= -1;
          
    }
    if(shape.getPosition().y+shape.getSize().y>=600|| shape.getPosition().y<0){
            
            speed.y*= -1;
          
    }
        
    shape.move(speed);
}

void Rectangle::drawTo(RenderWindow &window){
    window.draw(this->shape);
}