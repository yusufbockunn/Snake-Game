#pragma once 
#include "Game.h"
using namespace Engine;

Game::Game()

{
    SetTargetFPS(60);
    specs::width_screen = specs::cellSize * specs::cellCount;
    specs::height_screen = specs::cellSize * specs::cellCount;

    InitWindow(specs::width_screen, specs::height_screen, "Snake Game");

    firstFood = new Food(specs::cellCount);
    snake = new Snake(7);
    Engine::specs::score = 0;

}

void Game::Draw() const
{
   
        BeginDrawing();

        firstFood->Draw(specs::cellSize);
        snake->Draw(specs::cellSize);
        ClearBackground(specs::green);
        EndDrawing();
}

bool Game::CheckCollision() const

{
    for (int i = 1; i < snake->getBody().size(); i++)
    {

        if (snake->getHead().x == snake->getBody().at(i).x && snake->getHead().y == snake->getBody().at(i).y)
        {
            return true;
        }

    }
    return false;
}


void Game::Update()
{

    snake->Update(0.1, Engine::specs::cellCount);


    if (snake->getHead().x == firstFood->getPosition().x && snake->getHead().y == firstFood->getPosition().y)
    {

        snake->addBody();
        delete firstFood;
        firstFood = new Food(Engine::specs::cellCount);

    }

    Engine::specs::isLose = CheckCollision();

}


const void Game::DrawLoseScreen() const
{

    BeginDrawing();
    DrawText("Kaybettin la Gardasým", Engine::specs::width_screen / 2, Engine::specs::height_screen / 2, 20, BLACK);
    EndDrawing();
}

void Engine::Game::Init()
{

    while (WindowShouldClose() == false)
    {
        if (!CheckCollision())
        {
            Draw();
            Update();
        }
        else
        {
            DrawLoseScreen();
        }
    }

    CloseWindow();
}
