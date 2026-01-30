#include "raylib.h"

int main() {

    const int width = 350;

    InitWindow(width, 200, "Init Window");

    // circle coordinates
    int circle_x {175};
    int circle_y {100};

    SetTargetFPS(60);
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins

        DrawCircle(circle_x, circle_y, 25, BLUE);

        if (IsKeyDown(KEY_D)) {
            circle_x += 5;
        }
        if (IsKeyDown(KEY_A)) {
            circle_x -= 5;
        }

        // Game logic ends
        EndDrawing();
    }


    return 0;
}