#ifndef Grid_h
#define Grid_h
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid
{
private:
    vector<vector<int>> tablero;
    vector<vector<int>>next;
    int rows, cols;
    int sizeX,sizeY;
    Vector2i size;

public:
    Grid(int rows, int cols,int width, int height);
    void click(int x, int y);
    void drawTo(RenderWindow  &window);
    void update();
    int contarVecinos();
};

#endif