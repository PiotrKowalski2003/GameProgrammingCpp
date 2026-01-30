#include "raylib.h"

int main() {

    const int width = 350;

    InitWindow(width, 200, "Init Window");

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }


    return 0;
}