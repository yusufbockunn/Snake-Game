#pragma once
#include "Snake.h"
#include "Food.h"
#include "Specs.h"
#include <vector>
#include <tuple>
#include <deque>
#include <map>
#include <array>


namespace Engine
{
    class SnakeEnv {
    public:
        SnakeEnv();
        std::vector<float> reset();
        std::tuple<std::vector<float>, float, bool> step(int action);
        std::vector<float> getState() const;
        void draw() const;
        int getScore() const { return score; }
    private:
        Engine::Snake* snake;
        Engine::Food* food;
        int score;
        bool done;

        float checkObstacle(Engine::specs::Movement dir) const;
    };

}

