#pragma once
#include<vector>
using namespace std;
#include"blocks.cpp"
#include"grid.h"

//when game starts frist thing will be grid
#include"grid.h"
class Game{
    public:
    Game();
    void Draw(); //draw grid with random blocks
    void handleinput(); //keyboards control
    bool GameOver;
    int score;
    void moveblockdown();
    
    private:
    Grid grid;
    Block getrandomBlock();
    vector<Block> getallblocks();
    vector<Block> blocks;
    void moveblockleft(); 
    void moveblockright();
    Block currentblock;
    Block nextblock;
    bool isblockoutside();
    void rotateblock();
    void lockBlock();
    bool blockFits();
    void reset();   
    void UpdateScore(int linesCleared,int moveDownPoints);
};