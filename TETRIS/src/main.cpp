#include <iostream>
#include <raylib.h>
#include "game.h"//it includes both grid and blocks..
#include "color.h"

double lastUpdateTime = 0.0; // Initialize this!

bool eventTriggered(double interval){
    double currentTime=GetTime();
    if(currentTime-lastUpdateTime>=interval){
        lastUpdateTime=currentTime;
        return true;
    }
    return false;
}

   

using namespace std;

int main () {
    Color voilet = {95, 45, 127, 255};
    InitWindow(820, 940, "TETRIS GAME");//--->(width,hieght,<name>)
    SetTargetFPS(60);  

    Font font=LoadFontEx("Font/monogram.ttf",64,0,0);       //argumrnts-->('directory',pixels_size,arg,arg)

    Game game = Game();
    //loading font in GPU memory.
    lastUpdateTime = GetTime(); // Set initial time when game starts
    
    while(WindowShouldClose() == false){    
        UpdateMusicStream(game.music);                    
        BeginDrawing();
        game.handleinput();
        
        // Make blocks fall every 0.5 seconds
        if(eventTriggered(0.5)){
            game.moveblockdown();
        }
        
        ClearBackground(voilet); 
        //drawing font
        DrawTextEx(font, "SCORE", {585,15}, 38, 2, WHITE);  // Score label
        DrawRectangleRounded({530,80,230,80},0.3,6,lightblue);  // Score rectangle
        
        // Draw score text centered in the score rectangle
        char scoretext[10];
        sprintf(scoretext,"%d",game.score);
        Vector2 textsize=MeasureTextEx(font,scoretext,48,2);  // Increased font size, reduced spacing
        float scoreX = 530 + (230 - textsize.x)/2;  // Center horizontally in rectangle
        float scoreY = 80 + (80 - textsize.y)/2;    // Center vertically in rectangle
        DrawTextEx(font,scoretext,{scoreX,scoreY},48,2,WHITE);
        
        DrawTextEx(font, "Next Block", {535,235}, 38, 2, WHITE);  // Next block label
        DrawRectangleRounded({530,330,230,200},0.3,6,lightblue);

        if(game.GameOver){
            
            DrawTextEx(font, "GAME OVER !!", {535,735}, 42, 4, WHITE);  // 
        }
        game.Draw();
        EndDrawing();
    } 
    CloseWindow();
}