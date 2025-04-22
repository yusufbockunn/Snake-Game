#pragma once
#include <map>
#include <vector>
#include <array>
#include <string>
#include <random>
#include <algorithm>

namespace Engine
 {
    class QAgent {
    public:
        QAgent(float epsilon = 1.0f, float alpha = 0.1f, float gamma = 0.9f);
        int selectAction(const std::vector<float>& state);
        void update(const std::vector<float>& state, int action, float reward, const std::vector<float>& next_state);

    private:
        std::map<std::vector<float>, std::vector<float>> q_table;  // Q-tablo
        float epsilon;  // Keþif oraný
        float alpha;    // Öðrenme oraný
        float gamma;    // Ýndirim oraný

        void decayEpsilon();
    };

}

