#pragma once 
#include "Game.h"
using namespace Engine;

Game::Game()

{
    SetTargetFPS(60);

    InitWindow(specs::width_screen, specs::height_screen, "Snake Game");

    firstFood = new Food();
    snake = new Snake(7);

}

Game::~Game()
{
}

void Game::Draw() const
{
   
        BeginDrawing();

        firstFood->Draw();
        snake->Draw();
        ClearBackground(specs::green);
        EndDrawing();
}

inline bool Game::CheckCollision() const

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

    snake->Update();


    if (snake->getHead().x == firstFood->getPosition().x && snake->getHead().y == firstFood->getPosition().y)
    {

        snake->addBody();
        delete firstFood;
        firstFood = new Food();

    }

    isLose = CheckCollision();

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
