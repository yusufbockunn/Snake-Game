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

        void Init();                // Ana oyun d�ng�s�
        void Update();              // RL ve ortam ad�m�
        void Draw() const;          // Ana �izim
        void DrawLoseScreen() const; // Kaybetme ekran�

    private:
        QAgent* agent;              // Q-learning ajan�
        SnakeEnv* env;              // Ortam (snake, food vs.)
        int score;                  // Skor takibi (env'den de al�nabilir)
        bool isLose;                // Oyun biti� durumu
    };
}
