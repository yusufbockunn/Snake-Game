#include "include/SnakeEnv.h"
#include <cmath>
using namespace Engine;
SnakeEnv::SnakeEnv() {
    snake = new Engine::Snake(7);
    food = new Engine::Food();
    score = 0;
    done = false;
}

std::vector<float> SnakeEnv::reset() {
    delete snake;
    delete food;
    snake = new Engine::Snake(7);
    food = new Engine::Food();
    score = 0;
    done = false;
    return getState();
}

std::tuple<std::vector<float>, float, bool> SnakeEnv::step(int action) {
    snake->setDirection(static_cast<Engine::specs::Movement>(action));
    snake->Update();

    float reward = -0.1f;  // Küçük ceza

    // Yemek yediðinde büyük ödül
    if (snake->getHead().x == food->getPosition().x && snake->getHead().y == food->getPosition().y) {
        reward = 10.0f;
        snake->addBody();
        delete food;
        food = new Engine::Food();
        score++;
    }

    // Çarpýþma olursa büyük ceza
    auto body = snake->getBody();
    auto head = snake->getHead();

    for (int i = 1; i < body.size(); i++) {
        if (head.x == body[i].x && head.y == body[i].y) {
            reward = -10.0f;
            done = true;
            break;
        }
    }

    return { getState(), reward, done };
}


std::vector<float> SnakeEnv::getState() const {
    auto head = snake->getHead();
    auto food_pos = food->getPosition();

    float dx = (food_pos.x - head.x) / Engine::specs::cellCount;
    float dy = (food_pos.y - head.y) / Engine::specs::cellCount;

    return {
        dx, dy,
        checkObstacle(Engine::specs::LEFT),
        checkObstacle(Engine::specs::RIGHT),
        checkObstacle(Engine::specs::UP),
        checkObstacle(Engine::specs::DOWN)
    };
}

float SnakeEnv::checkObstacle(Engine::specs::Movement dir) const {

    auto head = snake->getHead();
    auto vec = Engine::specs::movementSet.at(dir);
    Vector2 next = {
        fmodf(head.x + vec.x + Engine::specs::cellCount, Engine::specs::cellCount),
        fmodf(head.y + vec.y + Engine::specs::cellCount, Engine::specs::cellCount)
    };

    for (auto segment : snake->getBody()) {
        if (segment.x == next.x && segment.y == next.y)
            return 1.0f;
    }

    return 0.0f;
}

void SnakeEnv::draw() const
{
    snake->Draw();
    food->Draw();

}