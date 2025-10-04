#pragma once
#include"position.h"
#include<iostream>
#include<vector>
#include<map>
#include"color.h"

class Block{
    public:
    void Draw(int offsetX,int offsetY);    
    int id; //will store the distinction from other blocks
    Block(); //constructor.
    map<int ,vector<Position>> cells;
    void Move(int rows,int columns);
    vector<Position> getcellposition();
    void rotate(); //it will rotate the block as per user input.
    int rotationState;
    void undorotation();    //it undo the rotation.
    
    
    private:
    int cellsize;
    vector<Color> colors;
    int rowoffset,columnoffset;
};