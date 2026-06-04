#ifndef GAME_INCLUDES_H
#define GAME_INCLUDES_H

#include <deque>
#include "./include/raylib.h"
#include "./include/raymath.h"

extern const Color green;
extern const Color darkGreen;
extern const Color red;

extern const int screenWidth;
extern const int screenHeight;
extern const int cellSize;

bool operator==(const Vector2 &, const Vector2 &);
bool elementInDeque(const Vector2 &, const std::deque<Vector2> &);

#endif //GAME_INCLUDES_H
