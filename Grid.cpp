#include "Grid.hpp"
#include <iostream>
using namespace std;
Grid::Grid(int rows, int cols, int width, int height)
{
    this->rows = rows;
    this->cols = cols;
    this->sizeX=width/cols;
    this->sizeY=height/rows;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }

    this->next=vector<vector<int>>(rows,vector<int>(cols,0));

}
void Grid::drawTo(RenderWindow  &window){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(Vector2f(this->sizeX,this->sizeY));
            rect.setPosition(Vector2f(j*this->sizeX,i*this->sizeY));
            rect.setOutlineThickness(1);
            rect.setOutlineColor(Color::Black);
            if(tablero[j][i]==1){
                rect.setFillColor(Color::Blue);
            }else{
                rect.setFillColor(Color::Cyan);
            }
            
            window.draw(rect);
        }
    }
}

void Grid::click(int x, int y){
    
    int indexX=x/this->sizeX;
    int indexY=y/this->sizeY;
    std::cout<<x<<" , "<<y<<endl;
    tablero[indexX][indexY]=(tablero[indexX][indexY]+1)%2;
}

void Grid::update(){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            
            if (tablero[i][j]==1){
                if(j==this->cols-1){
                
            }else{
                if(tablero[i][j+1]==0){
                    next[i][j]=0;
                    next[i][j+1]=1;
                }else{
                    this->next[i][j]=1;
                }
                
            }
                
            }
            
        }
    }
    this->tablero=this->next;
}