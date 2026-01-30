#include "raylib.h"

int main() {

    // window dimensions
    constexpr int width{800};
    constexpr int height{450};
    InitWindow(width, height, "Init Window");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};

    SetTargetFPS(60);
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins
        DrawCircle(circle_x, circle_y, 25, BLUE);
        DrawRectangle(axe_x,axe_y, 50,50, RED);

        // move the axe
        axe_y += 10;

        if (IsKeyDown(KEY_D) && circle_x < 350) {
            circle_x += 5;
        }
        if (IsKeyDown(KEY_A) && circle_x > 0) {
            circle_x -= 5;
        }

        // Game logic ends
        EndDrawing();
    }


    return 0;
}