#ifndef rectangle_h
#define rectangle_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Rectangle{
private:
    Vector2f speed;
    RectangleShape shape;
public:
    Vector2f spawn;
    Vector2f acc;
    Rectangle(Vector2f size,RenderWindow &window);
    void update();
    void drawTo(RenderWindow &window);


};

#endif