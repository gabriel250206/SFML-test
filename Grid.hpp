#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;
class Grid{
    private:
        vector<vector<int>>grid;
        int rows;
        int cols;
    public:
        Grid(int rows, int cols);
        void drawTo(RenderWindow &window);


};