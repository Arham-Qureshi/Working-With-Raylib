#include"position.h"
#include"block.h"

//this fie will include all the child class of block,
class Lblock : public Block{
    public:
    Lblock(){
    id=1;  //its unique id is 1 meaninf whenever 1 is called we will know its Lblock and also represent colors

    Move(0,3);  //it spawn blocks at centre..


    //using maps to store key-->roation state and rotation-->position(x,y).
    cells[0]={Position(0,2),Position(1,0),Position(1,1),Position(1,2)};
    cells[1]={Position(0,1),Position(1,1),Position(2,1),Position(2,2)};
    cells[2]={Position(1,0),Position(1,1),Position(1,2),Position(2,0)};
    cells[3]={Position(0,0),Position(0,1),Position(1,1),Position(2,1)};
    
    }
};

class Jblock : public Block{
    public:
    Jblock(){
    id=2;
    Move(0,3);  //it spawn blocks at centre..

    cells[0]={Position(0,0),Position(1,0),Position(1,1),Position(1,2)};
    cells[1]={Position(0,1),Position(0,2),Position(1,1),Position(2,1)};
    cells[2]={Position(1,0),Position(1,1),Position(1,2),Position(2,2)};
    cells[3]={Position(0,1),Position(1,1),Position(2,0),Position(2,1)};
    }
};

class Iblock : public Block{
    public:
    Iblock(){
    id=3;
    Move(-1,3);  //it spawn blocks at centre..

    cells[0]={Position(1,0),Position(1,1),Position(1,2),Position(1,3)};
    cells[1]={Position(0,2),Position(1,2),Position(2,2),Position(3,2)};
    cells[2]={Position(2,0),Position(2,1),Position(2,2),Position(2,3)};
    cells[3]={Position(0,1),Position(1,1),Position(2,1),Position(3,1)};
    }
};

class Oblock : public Block{
    public:
    Oblock(){
    id=4;
    Move(0,4);  //it spawn blocks at centre..

    cells[0]={Position(0,0),Position(0,1),Position(1,0),Position(1,1)};
    
    }
};

class Sblock : public Block{
    public:
    Sblock(){
    id=5;
    Move(0,3);  //it spawn blocks at centre..

    cells[0]={Position(0,1),Position(0,2),Position(1,0),Position(1,1)};
    cells[1]={Position(0,1),Position(1,1),Position(1,2),Position(2,2)};
    cells[2]={Position(1,1),Position(1,2),Position(2,0),Position(2,1)};
    cells[3]={Position(0,0),Position(1,0),Position(1,1),Position(2,1)};
    }
};

class Zblock : public Block{
    public:
    Zblock(){
    id=6;
    Move(0,3);  //it spawn blocks at centre..

    cells[0]={Position(0,0),Position(0,1),Position(1,1),Position(1,2)};
    cells[1]={Position(0,2),Position(1,1),Position(1,2),Position(2,1)};
    cells[2]={Position(1,0),Position(1,1),Position(2,1),Position(2,2)};
    cells[3]={Position(0,1),Position(1,0),Position(1,1),Position(2,0)};
    }
};
class Tblock : public Block{
    public:
    Tblock(){
    id=7;
    Move(0,3);  //it spawn blocks at centre (changed from -1 to 0)

    cells[0]={Position(0,1),Position(1,0),Position(1,1),Position(1,2)};
    cells[1]={Position(0,1),Position(1,1),Position(1,2),Position(2,1)};
    cells[2]={Position(1,0),Position(1,1),Position(1,2),Position(2,1)};
    cells[3]={Position(0,1),Position(1,0),Position(1,1),Position(2,1)};
    }
};