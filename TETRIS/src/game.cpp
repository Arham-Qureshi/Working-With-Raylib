#include"game.h"
#include<raylib.h>
#include<iostream> // Include for debug output

#include<random> //randomly select the blocks.


Game::Game(){
    grid=Grid();     // initialize grid using member initializer list

    currentblock=getrandomBlock();
    nextblock=getrandomBlock();
    blocks =getallblocks();
    GameOver=false;
    score=0;

}

Block Game::getrandomBlock(){  //function to get randon block

    //below fucntion will first check all the that fucn has no block then it will fetch all the blocks and then it will select random.
    if(blocks.empty()){
        blocks=getallblocks();
    }
    int randomindex=rand()% blocks.size();

    Block block=blocks[randomindex];//---> assign random number to block of class BLOCK which each index holds one block.
    blocks.erase(blocks.begin()+randomindex); //this will erase the previous block .
    return block; //---> this will return the block with random value which holds the random block
}

vector<Block> Game::getallblocks(){
    return {Oblock(), Lblock(), Sblock(), Zblock(), Tblock(), Iblock(), Jblock()};
}

void Game::Draw(){
    //both draws are diff.
    grid.Draw(); //grid--> draw
    currentblock.Draw(21,21); //block--> draw---->11==>pixel set(hardcoded)
    switch(nextblock.id){
        case 3:
        nextblock.Draw(424,397);
        break;
        case 4:
        nextblock.Draw(464,383);
        default:
        nextblock.Draw(440,370);
        break;
    }
        // Reset nextblock offsets so it doesn't show twice
        // nextblock.rowoffset = 0;
        // nextblock.columnoffset = 0;
}

void Game::handleinput(){
    int keypressed=GetKeyPressed();
    if(GameOver && keypressed !=0){         //if any key pressed it will restart the game.
        GameOver=false;
        reset();
    }
    switch(keypressed){
        case KEY_LEFT:
        moveblockleft();
        break;
        case KEY_RIGHT:
        moveblockright();
        break;
        case KEY_DOWN:
        moveblockdown();
        UpdateScore(0,1);
        break;
        case KEY_UP:     // key will rotate the block.
        rotateblock();
        break;
    }
}
//each movement block if it goes outside the game window we will undo the move and we will check it by iscelloutside func.
void Game::moveblockleft(){
    if(!GameOver){
    currentblock.Move(0,-1);
    if(isblockoutside()|| blockFits()==false){
        currentblock.Move(0,1); //undo the move.
    }
}
}
void Game::moveblockright(){
    if(!GameOver){
    currentblock.Move(0,1);
    if(isblockoutside()|| blockFits()==false){
        currentblock.Move(0,-1);
    }
}
}
void Game::moveblockdown(){
    if(!GameOver){
    currentblock.Move(1,0);
    if(isblockoutside()|| blockFits()==false){      //it avoids overlapping...
        currentblock.Move(-1,0);
        lockBlock(); 

    }
}
}
bool Game::isblockoutside(){
    vector<Position> tiles=currentblock.getcellposition();  //-->it will store the position of current block.
    for(Position i:tiles){  //--> loop from i=0 to i=tiles of vector tiles..
    if(grid.iscelloutside(i.row,i.column)){ //-->it will check the position of the current block.
        return true;
    }
}
return false;
}

void Game::rotateblock(){ 
    if(!GameOver){
    currentblock.rotate();
    if(isblockoutside() || blockFits()==false){
        currentblock.undorotation();
    }
}
}
void Game::lockBlock(){
    vector<Position> tiles =currentblock.getcellposition();   //storing id of the block in grid.
    for(Position item: tiles){
        grid.grid[item.row][item.column]=currentblock.id;       //it will fix the block and the base line.
    }
    currentblock=nextblock;             //after the fixing the block our nextblock block will spawn and it will become currentblock.

    if(blockFits()==false){
        GameOver=true;
    }

    nextblock=getrandomBlock();
    int rowscleared=grid.clearRow();    //--->it returns the number of competed row.
    UpdateScore(rowscleared,0); 
}

bool Game::blockFits()              //it will check that if current block is upside the the block or not(empyt grid of block or not)
{
    vector<Position> tiles=currentblock.getcellposition();          //for this we need to all cell position if current block
    for(Position item:tiles){               //iterate every cell position.
        if(grid.iscellEmpty(item.row,item.column)==false){
            return false;
        }

    }
    return true;
}

void Game::reset(){             //it will start the game all over.
    grid.initialise();
    blocks=getallblocks();  
    currentblock=getrandomBlock();
    nextblock=getrandomBlock();
    score=0;
}

/*1 point for moving blocks down
100 points for a line cleared
200 pointes for 2 lines cleared
300 points for 3 lines cleared*/
void Game::UpdateScore(int linesCleared, int moveDownPoints){       
    switch(linesCleared){
        case 1:
        score+=100;
        break;
        case 2:
        score+=200;
        break;
        case 3:
        score=300;
        break;
        default:
        break;
    }
    score+=moveDownPoints;
}
