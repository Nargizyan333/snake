#include "Game.h"

void Game::draw() {
    snake.draw();
    food.draw();
}

void Game::update() {
    if (_running) {
        snake.update();
        checkCollisionWithFood();
        checkCollisionWithEdges();
        checkCollisionWithTail();
    }
}

void Game::changeSnakesDirection(const std::string &newDirection) {
    snake.changeDirection(newDirection);
}

void Game::checkCollisionWithFood() {
    if (snake.checkCollision(food.getPosition())) {
        food.generateNewPosition(snake.getBody());
        snake.setAddSegmentTrue();
    }
}

void Game::checkCollisionWithEdges() {
    auto [x,y] = snake.getBody().front();
    if (x < 0 || x >= screenWidth / cellSize) GameOver();
    if (y < 0 || y >= screenHeight / cellSize) GameOver();
}

void Game::checkCollisionWithTail() {
    const auto &body = snake.getBody();
    const Vector2 &head = body.front();
    for (size_t i = 1; i < body.size(); ++i)
        if (Vector2Equals(head, body[i])) GameOver();
}

void Game::updateRunning() {
    _running = true;
}

void Game::GameOver() {
    snake.reset();
    _running = false;
    std::cout << "Game Over." << std::endl;
}