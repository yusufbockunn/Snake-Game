#pragma once

#include <raylib.h>
#include "QAgent.h"
#include "SnakeEnv.h"
#include "Specs.h"

namespace Engine
{
    class Game
    {
    public:
        Game();
        ~Game();

        void Init();                // Ana oyun döngüsü
        void Update();              // RL ve ortam adýmý
        void Draw() const;          // Ana çizim
        void DrawLoseScreen() const; // Kaybetme ekraný

    private:
        QAgent* agent;              // Q-learning ajaný
        SnakeEnv* env;              // Ortam (snake, food vs.)
        int score;                  // Skor takibi (env'den de alýnabilir)
        bool isLose;                // Oyun bitiþ durumu
    };
}
