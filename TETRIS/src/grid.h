// instruction to only compile once to avoid duplicate definition(pragma)
#pragma once
#include<vector>
#include<raylib.h>
#include<iostream>
using namespace std;
class Grid{
    private:
    int numRows;
    int numcols;
    int cellsize;
    int offsetX;
    int offsetY;
    vector<Color> colors; //will store the colurs
    bool isRowFull(int row);            //it will check the row if it is full or not.
    void clearRow(int row);             //will clear the entire row.
    void moveRowDown(int row,int numrows);      //after clearing the entire above row must move down this func will do the job...
                                                //row--->which row to be moved...numrow--->how many rows the rows down it must move.

    public:
    Grid(); //constructor
    int grid[20][10]; //20x10 martix. 
    bool iscelloutside(int row,int column); 
    void initialise(); //0---> to grid(empty)
    void print(); // print the grid
    void Draw();
    bool iscellEmpty(int row,int cloumn);
    int clearRow();
};