#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <iostream>
#include "Snake.h"
#include "Food.h"

class Game {
private:
    Snake snake = Snake();
    Food food = Food(snake.getBody());
    bool _running = true;
public:
    void draw();
    void update();
    void changeSnakesDirection(const std::string &);
    void checkCollisionWithFood();
    void checkCollisionWithEdges();
    void checkCollisionWithTail();
    void updateRunning();
    void GameOver();
};


#endif //GAME_GAME_H
