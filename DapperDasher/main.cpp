#include "raylib.h"

int main() {

    // window dimensions
    constexpr int windowWidth {512};
    constexpr int windowHeight {380};
    // initialize the window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);


        // stop drawing
        EndDrawing();
    }
    CloseWindow();


    return 0;
}