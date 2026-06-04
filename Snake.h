#ifndef GAME_SNAKE_H
#define GAME_SNAKE_H

#include "Includes.h"
#include <deque>

class Snake {
private:
    static const std::unordered_map<std::string, Vector2> _dirs;
    std::deque<Vector2> _body;
    Vector2 _dir{};
    bool _addSegment = false;

    void init();
public:
    Snake();
    [[nodiscard]] const std::deque<Vector2> &getBody() const;
    Vector2 getDir() const;
    void setAddSegmentTrue();
    void update();
    void draw() const;
    void changeDirection(const std::string &);
    [[nodiscard]] bool checkCollision(const Vector2 &) const;
    void reset();
};


#endif //GAME_SNAKE_H
