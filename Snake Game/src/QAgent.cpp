#include "include/QAgent.h"
#include <sstream>
 // std::max_element için gerekli

using namespace Engine;

QAgent::QAgent(float epsilon, float alpha, float gamma)
    : epsilon(epsilon), alpha(alpha), gamma(gamma) {}

int QAgent::selectAction(const std::vector<float>& state) {
    if (q_table.find(state) == q_table.end()) {
        // Ýlk defa karþýlaþýlan state için baþlat
        q_table[state] = std::vector<float>(4, 0.0f);
    }

    // Keþif (Exploration) mi, yoksa kullanma (Exploitation) mi?
    if (static_cast<float>(rand()) / RAND_MAX < epsilon) {
        return rand() % 4;
    }
    else {
        std::vector<float>& q_values = q_table[state];
        return std::distance(q_values.begin(), std::max_element(q_values.begin(), q_values.end()));
    }
}


void QAgent::update(const std::vector<float>& state, int action, float reward, const std::vector<float>& next_state) {
    // Eðer Q-tablolarý boþsa, baþlatýyoruz.
    if (q_table.find(state) == q_table.end()) {
        q_table[state] = std::vector<float>(4, 0.0f); // Varsayýlan deðerle baþlatýyoruz, örneðin 4 aksiyon var.
    }
    if (q_table.find(next_state) == q_table.end()) {
        q_table[next_state] = std::vector<float>(4, 0.0f); // Ayný þekilde
    }

    // Q-learning güncellemesi
    std::vector<float>& q_values = q_table[state];
    std::vector<float>& next_q_values = q_table[next_state];

    // next_state için en büyük Q-deðerini al
    float max_next_q_value = *std::max_element(next_q_values.begin(), next_q_values.end()); // std::max_element kullanýmý

    // Q-deðerlerini güncelle
    q_values[action] = q_values[action] + alpha * (reward + gamma * max_next_q_value - q_values[action]);

    // Epsilon'ý zamanla azalt
    decayEpsilon();
}


void QAgent::decayEpsilon() {
    // Epsilon deðeri zamanla azalmalý
    epsilon = std::max(0.1f, static_cast<float>(epsilon * 0.995));
}
