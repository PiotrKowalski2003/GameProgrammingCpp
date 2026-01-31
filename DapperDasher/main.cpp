#include "raylib.h"

int main() {

    // window dimensions
    constexpr int windowWidth {512};
    constexpr int windowHeight {380};
    // initialize the window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // acceleration due to gravity (pixels/frame/frame)
    constexpr int gravity{1};


    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    Vector2 scarfyPos;


    // rectangle dimensions
    constexpr int width{50};
    constexpr int height{80};

    // is the rectangle in the air?
    bool isInAir{};
    // jump velocity
    constexpr int jumpVel{-22};


    int posY{windowHeight - height};
    int velocity{0};


    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // perform ground check
        if (posY >= windowHeight - height) {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        } else {
            // rectangle is in the air
            velocity += gravity;
            isInAir = true;
        }

        // jump check
        if (IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity += jumpVel;
        }

        posY += velocity;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);


        // stop drawing
        EndDrawing();
    }
    CloseWindow();


    return 0;
}