#include "include/QAgent.h"
#include <sstream>
 // std::max_element i�in gerekli

using namespace Engine;

QAgent::QAgent(float epsilon, float alpha, float gamma)
    : epsilon(epsilon), alpha(alpha), gamma(gamma) {}

int QAgent::selectAction(const std::vector<float>& state) {
    if (q_table.find(state) == q_table.end()) {
        // �lk defa kar��la��lan state i�in ba�lat
        q_table[state] = std::vector<float>(4, 0.0f);
    }

    // Ke�if (Exploration) mi, yoksa kullanma (Exploitation) mi?
    if (static_cast<float>(rand()) / RAND_MAX < epsilon) {
        return rand() % 4;
    }
    else {
        std::vector<float>& q_values = q_table[state];
        return std::distance(q_values.begin(), std::max_element(q_values.begin(), q_values.end()));
    }
}


void QAgent::update(const std::vector<float>& state, int action, float reward, const std::vector<float>& next_state) {
    // E�er Q-tablolar� bo�sa, ba�lat�yoruz.
    if (q_table.find(state) == q_table.end()) {
        q_table[state] = std::vector<float>(4, 0.0f); // Varsay�lan de�erle ba�lat�yoruz, �rne�in 4 aksiyon var.
    }
    if (q_table.find(next_state) == q_table.end()) {
        q_table[next_state] = std::vector<float>(4, 0.0f); // Ayn� �ekilde
    }

    // Q-learning g�ncellemesi
    std::vector<float>& q_values = q_table[state];
    std::vector<float>& next_q_values = q_table[next_state];

    // next_state i�in en b�y�k Q-de�erini al
    float max_next_q_value = *std::max_element(next_q_values.begin(), next_q_values.end()); // std::max_element kullan�m�

    // Q-de�erlerini g�ncelle
    q_values[action] = q_values[action] + alpha * (reward + gamma * max_next_q_value - q_values[action]);

    // Epsilon'� zamanla azalt
    decayEpsilon();
}


void QAgent::decayEpsilon() {
    // Epsilon de�eri zamanla azalmal�
    epsilon = std::max(0.1f, static_cast<float>(epsilon * 0.995));
}
