#include "raylib.h"

int main() {

    const int width = 350;

    InitWindow(width, 200, "Init Window");

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(175, 100, 25, BLUE);

        EndDrawing();
    }


    return 0;
}