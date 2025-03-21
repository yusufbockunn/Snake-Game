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
    private:
        bool isLose;
    };
}



