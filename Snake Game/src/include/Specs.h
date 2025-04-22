#pragma once
#include <raylib.h>
#include <unordered_map>


namespace Engine
{
	namespace specs
	{
        constexpr Color green = { 173,204,96,255 };
        constexpr Color darkGreen = { 43,51,24,255 };
        constexpr Color loseScreen = { 255,255,255,255 };


        constexpr int cellSize = 30;
        constexpr int cellCount = 25;

       


        constexpr const int width_screen=cellSize*cellCount;
        constexpr const int height_screen=cellSize*cellCount;

        
        enum  Movement { LEFT, RIGHT, UP, DOWN };

        inline const std::unordered_map<Movement, Vector2> movementSet = {
            { LEFT, {-1, 0} },
            { RIGHT, {1, 0} },
            { UP, {0, -1} },
            { DOWN, {0, 1} }
        };

        //SNAKE MOVEMENT TIME INTERVAL
        constexpr double interval = 0.0001;


        


	}

}