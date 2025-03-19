#pragma once
#include <raylib.h>
#include <iostream>
#include "Food.h"
#include "Snake.h"
#include "Drawable.h"
#include "Specs.h"
namespace Engine
{
    class Game: public Drawable
    {
    private:
        void Draw() const override;
        Food* firstFood;
        Snake* snake;
        void Update();
        const void DrawLoseScreen()const;

    public:
        Game();
        ~Game();
        bool CheckCollision() const;
        void Init();
    };
}



//class Game
//{
//private:
//
//
//    Color green = { 173,204,96,255 };
//    Color darkGreen = { 43,51,24,255 };
//
//    int cellSize = 30;
//    int cellCount = 25;
//
//    int score;
//
//
//    const int width_screen;
//    const int height_screen;
//
//    Food* firstFood;
//    Snake* snake;
//    bool isLose;
//
//
//    void Draw() 
//    {
//        BeginDrawing();
//
//        firstFood->Draw(cellSize);
//        snake->Draw(cellSize);
//        ClearBackground(green);
//        EndDrawing();
//    }
//
//
//    void DrawLoseScreen()
//    {
//
//
//    }
//public:
//
//    Game() :width_screen(cellSize*cellCount),height_screen(cellSize*cellCount)
//    {
//        SetTargetFPS(60);
//
//        InitWindow(width_screen, height_screen, "Snake Game");
//
//        firstFood = new Food(cellCount);
//        snake = new Snake(7);
//        score = 0;
//     
//    }
//
//
//    ~Game()
//    {
//
//        delete snake;
//        delete firstFood;
//    }
//
//
//    void Run() 
//    {
//
//
//
//
//    }
//
//    bool CheckCollision()   
//    {
//        
//        for(int i=1;i<snake->getBody().size();i++)
//        {
//         
//            if(snake->getHead().x== snake->getBody().at(i).x && snake->getHead().y==snake->getBody().at(i).y)
//            {
//                return true;
//            }
//
//        }
//        return false;
//
//    }
//
//
//};
//
