#include "Snake.h"

const std::unordered_map<std::string, Vector2> Snake::_dirs = {
    {"up",    {0.f, -1.f}},
    {"right", {1.f,  0.f}},
    {"down",  {0.f,  1.f}},
    {"left",  {-1.f, 0.f}},
};

void Snake::init() {
    _body.clear();
    _addSegment = false;
    float x = static_cast<float>(GetRandomValue(11, screenWidth  / cellSize / 2));
    float y = static_cast<float>(GetRandomValue(0,  screenHeight / cellSize - 1));
    _body.push_back({x,       y}); // head
    _body.push_back({x - 1.f, y}); // body trails one cell behind (snake starts moving right)
    _dir = _dirs.at("right");
}

Snake::Snake() {
    init();
}

const std::deque<Vector2> &Snake::getBody() const {
    return _body;
}

Vector2 Snake::getDir() const {
    return _dir;
}

void Snake::setAddSegmentTrue() {
    _addSegment = true;
}

void Snake::update() {
    _body.push_front(Vector2Add(_body.front(), _dir));
    if (_addSegment)
        _addSegment = false;
    else
        _body.pop_back();
}

void Snake::draw() const {
    for (const Vector2 &cell : _body) {
        auto rec = Rectangle{cell.x * cellSize, cell.y * cellSize,
                             static_cast<float>(cellSize), static_cast<float>(cellSize)};
        DrawRectangleRounded(rec, 0.4f, 6, darkGreen);
    }
}

void Snake::changeDirection(const std::string &newDirection) {
    if (Vector2Equals(_dir, _dirs.at("left"))  && newDirection != "right")
        _dir = _dirs.at(newDirection);
    else if (Vector2Equals(_dir, _dirs.at("right")) && newDirection != "left")
        _dir = _dirs.at(newDirection);
    else if (Vector2Equals(_dir, _dirs.at("down"))  && newDirection != "up")
        _dir = _dirs.at(newDirection);
    else if (Vector2Equals(_dir, _dirs.at("up"))    && newDirection != "down")
        _dir = _dirs.at(newDirection);
}

bool Snake::checkCollision(const Vector2 &pos) const {
    return Vector2Equals(pos, _body.front());
}

void Snake::reset() {
    init();
}
