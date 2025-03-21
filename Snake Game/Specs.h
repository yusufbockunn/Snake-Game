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

       


        constexpr const int width_screen=cellSize*cellCount;
        constexpr const int height_screen=cellSize*cellCount;


        enum  Movement { LEFT, RIGHT, UP, DOWN };

        constexpr int interval = 5;

       // extern bool isLose=false;
	}

}