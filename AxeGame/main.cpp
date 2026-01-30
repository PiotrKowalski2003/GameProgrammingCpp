#include "raylib.h"

int main() {

    const int width = 350;

    InitWindow(width, 200, "Init Window");

    while (true) {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }


    return 0;
}