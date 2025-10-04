#include"block.h"
#include<raylib.h>
#include<iostream> // Include iostream for std::cout

Block::Block() {
    cellsize = 45;
    rotationState = 0;
    colors = getcellcolors();
    columnoffset = 0;
    rowoffset = 0;
    
    // Initialize cells map with empty vectors for all rotation states
    cells[0] = vector<Position>();
    cells[1] = vector<Position>();
    cells[2] = vector<Position>();
    cells[3] = vector<Position>();
}

void Block::Draw(int offsetX,int offsetY){
    vector<Position> tiles=getcellposition(); //existing and updated recursicely.
    for(Position i:tiles){
        DrawRectangle(i.column*cellsize+offsetX,i.row*cellsize+offsetY,cellsize-2,cellsize-2,colors[id]);
    }
}
// add movement to the existing block
void Block::Move(int rows,int columns){
    rowoffset +=rows;
    columnoffset +=columns;
}

// function to calculate and ipdate the actual position of moved block or tile.

vector<Position> Block::getcellposition(){
    vector<Position> tiles=cells[rotationState]; //existing rotation of tiles
    vector<Position> movedtiles;
    for(Position i:tiles){
        Position newpos=Position(i.row+rowoffset, i.column+columnoffset);//updates the movement
        movedtiles.push_back(newpos);  //storing the new updated tiles.

    }
    return movedtiles;

}

void Block::rotate() {
    rotationState++;
    if(rotationState == (int)cells.size()) {
        rotationState = 0;
    }
}

void Block::undorotation(){
    rotationState--;
    if(rotationState==-1){
        rotationState=cells.size()-1;
        
    }
}
