#pragma once
#include<vector>
#include"grid.h"
using namespace std;
//extern is used when we assign a variable in one file and have to use it in another.

extern const Color darkgrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightblue;
extern const Color darkblue;


vector<Color> getcellcolors();
