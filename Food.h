#ifndef GAME_FOOD_H
#define GAME_FOOD_H

#include "./include/raylib.h"
#include "./include/raymath.h"
#include "Includes.h"

class Food {
private:
    Vector2 _pos;
public:
    Food(const std::deque<Vector2> &);
    ~Food();
    [[nodiscard]] Vector2 getPosition() const;
    void setX(int);
    void setY(int);
    void generateNewPosition(const std::deque<Vector2> &);
    void draw() const;
};


#endif //GAME_FOOD_H
