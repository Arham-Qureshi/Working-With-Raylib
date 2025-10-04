#include"grid.h"
#include"color.h"
#include<iostream>
using namespace std;


// it mns we are using grind constructor of grid class
Grid::Grid(){
    numRows=20;
    numcols=10;
    cellsize=45; //size of each cells of the grid
    offsetX=40;  // offset from left side of window
    offsetY=20;  // offset from top of window
    initialise(); //calling the initialise function in contructor
    colors=getcellcolors(); //constructor for cell colors.
}

// initialising 0--> empty spaces in all the grid.
// it mns using initialise function of class Grid.
void Grid::initialise(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numcols;j++){
            grid[i][j]=0;
        }
    }
}

// it will print the initialised grid
void Grid::print(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numcols;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}



void Grid::Draw(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numcols;j++){
            int cellvalue=grid[i][j]; //it will assign the cellvalue to each cell of the grid.
            DrawRectangle(j*cellsize + 20, i*cellsize + 20, cellsize-1, cellsize-1, colors[cellvalue]); //drawrect(col,row,w,h,color)
        }
    }
}


bool Grid::iscelloutside(int row,int column){
    if(row>=0 && row<numRows && column>=0 && column<numcols) return false;
    else return true;
}

bool Grid::iscellEmpty(int row, int cloumn)
{
    if(grid[row][cloumn]==0) return true;           //it check whether the BLOCK GRID is empty or not
    else return false;                              //to avoid collison and overlapping.
}


bool Grid::isRowFull(int row)
{
    for(int column=0;column<numcols;column++){       //checks the each COLUMN in a particluar ROW
        if(grid[row][column]==0) return false;      //row not full
    }
    return true; 
}

void Grid::clearRow(int row){
    for(int column=0;column<numcols;column++) grid[row][column]=0;      //it will assign value to ZERO which mns it will clear it.

}

void Grid::moveRowDown(int row,int numrows){
    for(int column=0;column<numcols;column++){
        grid[row+numrows][column]=grid[row][column];
        grid[row][column]=0;
    }
}

int Grid::clearRow(){           //it will bind all the function
    int completed=0;
    for(int row=numRows-1;row>0;row--){
    if(isRowFull(row)){
        clearRow(row);          //clear the row in full
        completed++;            //increment the completed later used to movedown the row
    }
    else if(completed>0){
        moveRowDown(row,completed); //to fill the gap.
    }
    }
    return completed;

}