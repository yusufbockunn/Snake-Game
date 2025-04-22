#pragma once
#include "include/Game.h"
#include "include/QAgent.h"
#include "include/SnakeEnv.h"
#include "include/Specs.h"

using namespace Engine;

Game::Game()
{
    SetTargetFPS(60);
    InitWindow(specs::width_screen, specs::height_screen, "Snake RL Game");

    agent = new QAgent();         // Q-learning agent
    env = new SnakeEnv();         // Environment (snake, food, etc.)
    score = 0;
    isLose = false;
}

Game::~Game()
{
    delete agent;
    delete env;
}

void Game::Draw() const
{
    BeginDrawing();
    ClearBackground(specs::green);

    env->draw();  // Env içindeki snake ve food'u çiz
    DrawText(TextFormat("Score: %d", env->getScore()), 20, 20, 20, BLACK);

    EndDrawing();
}



void Game::Update()
{
    std::vector<float> state = env->getState();
    int action = agent->selectAction(state);

    std::vector<float> next_state;
    float reward;
    bool done;

    std::tie(next_state, reward, done) = env->step(action);

    agent->update(state, action, reward, next_state);

    if (done)
    {
        env->reset();   // Ortamı sıfırla
    }
}


void Game::Init()
{
    while (!WindowShouldClose())
    {

            Update();
            Draw();
       

    }

    CloseWindow();
}
