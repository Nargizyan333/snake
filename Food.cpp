#include "Food.h"

Food::Food(const std::deque<Vector2> &deque) {
    generateNewPosition(deque);
}

Food::~Food() = default;

Vector2 Food::getPosition() const {
    return _pos;
}

void Food::setX(const int x) {
    _pos.x = x;
}

void Food::setY(const int y) {
    _pos.y = y;
}

void Food::generateNewPosition(const std::deque<Vector2> &deque) {
    do {
        _pos.x = (float) GetRandomValue(0, screenWidth / cellSize - 1);
        _pos.y = (float) GetRandomValue(0, screenHeight / cellSize - 1);
    } while (elementInDeque(_pos, deque));
}

void Food::draw() const {
    auto rec = Rectangle{_pos.x * cellSize, _pos.y * cellSize, static_cast<float>(cellSize), static_cast<float>(cellSize)};
    DrawRectangleRounded(rec, 0.4, 6, red);
}