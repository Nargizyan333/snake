#include "Includes.h"

const Color green = {173, 204, 96, 255};
const Color darkGreen = {43, 51, 24, 255};
const Color red = {173, 16, 16, 255};

const int screenWidth = 1800;
const int screenHeight = 1040;
const int cellSize = 20;

bool operator==(const Vector2 &a, const Vector2 &b) {
    return Vector2Equals(a, b);
}

bool elementInDeque(const Vector2 &el, const std::deque<Vector2> &deque) {
    for (auto &i : deque)
        if (el == i) return true;
    return false;
}