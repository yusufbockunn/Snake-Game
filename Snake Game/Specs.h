#pragma once
#include <raylib.h>


namespace Engine
{
	namespace specs
	{
        constexpr Color green = { 173,204,96,255 };
        constexpr Color darkGreen = { 43,51,24,255 };

        constexpr int cellSize = 30;
        constexpr int cellCount = 25;

        int score;


        extern int width_screen;
        extern int height_screen;


        constexpr enum  Movement { LEFT, RIGHT, UP, DOWN };

        double lastUpdateTime = 0;

        bool isLose=false;
	}

}