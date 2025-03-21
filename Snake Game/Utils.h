#pragma once
#include "Specs.h"
#include <raylib.h>
namespace Engine {
    namespace utils {

        inline Vector2 generateRandomPosition(const int xRange, const int yRange) {
            return { static_cast<float>(GetRandomValue(0, xRange)),
                     static_cast<float>(GetRandomValue(0, yRange)) };
        }

       inline bool EventTimer() {
            static  double lastUpdateTime = 0;  
            double current_time = GetTime();

            if (current_time - lastUpdateTime >specs::interval) {
                lastUpdateTime = current_time;
                return true;
            }
            return false;
        }

    }
} 
