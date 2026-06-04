#include <iostream>
#include <queue>

#include "Food.h"
#include "Snake.h"
#include "Game.h"
#include "Includes.h"

double lastUpdateTime = 0;

bool eventTriggered(double interval) {
    double currTime = GetTime();
    if (currTime - lastUpdateTime >= interval) {
        lastUpdateTime = currTime;
        return true;
    }
    return false;
}

int main() {
    Game game;
    InitWindow(screenWidth, screenHeight, "Snake");
    SetTargetFPS(120);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(green);
        game.draw();
        if (eventTriggered(0.1)) game.update();
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            game.changeSnakesDirection("up");
            game.updateRunning();
        }
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
            game.changeSnakesDirection("left");
            game.updateRunning();
        }
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            game.changeSnakesDirection("right");
            game.updateRunning();
        }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            game.changeSnakesDirection("down");
            game.updateRunning();
        }
        if (IsKeyPressed(KEY_ENTER)) game.updateRunning();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
