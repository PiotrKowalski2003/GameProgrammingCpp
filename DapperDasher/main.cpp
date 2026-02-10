#include "raylib.h"

struct AnimData {
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};



int main() {

    // window dimensions
    constexpr int windowWidth {512};
    constexpr int windowHeight {380};
    // initialize the window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // acceleration due to gravity (pixels/frame/frame)
    constexpr int gravity{1'000};

    // nebula variables
    const Texture2D nebula = LoadTexture("../textures/12_nebula_spritesheet.png");

    // AnimData for nebula
    AnimData nebData;
    nebData.rec.width = nebula.width/8;
    nebData.rec.height = nebula.height/8;
    nebData.pos.x = 0.0;
    nebData.pos.y = 0.0;
    nebData.pos.x = windowWidth;
    nebData.pos.y = windowHeight - nebula.height/8;
    nebData.frame = 0;
    nebData.updateTime = 1.0/12.0;
    nebData.runningTime = 0.0;

    AnimData neb2Data{
            {0.0, 0.0, nebula.width/8, nebula.height/8},
            {windowWidth + 300, windowHeight - nebula.height/8},
            0,
            1.0/16.0,
            0.0
        };


    Rectangle nebRec;
    nebRec.width = nebula.width/8;
    nebRec.height = nebula.height/8;
    nebRec.x = 0.0;
    nebRec.y = 0.0;
    Vector2 nebPos{windowWidth, windowHeight - nebRec.height};

    Rectangle neb2Rec{0.0, 0.0};
    neb2Rec.width = nebula.width/8;
    neb2Rec.height = nebula.height/8;
    Vector2 neb2Pos{windowWidth + 300, windowHeight - nebRec.height};



    // nebula animation variables
    int nebFrame{};
    const float nebUpdateTime{1.0/12.0};
    float nebRunningTime{};

    int neb2Frame{};
    const float neb2UpdateTime{1.0/16.0};
    float neb2RunningTime{};

    // nebula X velocity (pixels/second)
    int nebVel{-200};



    // scarfy variables
    const Texture2D scarfy = LoadTexture("../textures/scarfy.png");
    AnimData scarfyData;
    scarfyData.rec.width = scarfy.width/6;
    scarfyData.rec.height = scarfy.height;
    scarfyData.rec.x = 0;
    scarfyData.rec.y = 0;
    scarfyData.pos.x = windowWidth/2 - scarfyData.rec.width/2;
    scarfyData.pos.y = windowHeight - scarfyData.rec.height;
    scarfyData.frame = 0;
    scarfyData.updateTime = 1.0/12.0;
    scarfyData.runningTime = 0.0;


    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;


    // animation frame
    int frame{};
    // amount of time before we update the animation frame
    constexpr float updateTime{1.0/12.0};
    float runningTime{};

    // is the rectangle in the air?
    bool isInAir{};
    // jump velocity (pixels/sec)
    constexpr int jumpVel{-600};

    int velocity{0};


    SetTargetFPS(60);
    while (!WindowShouldClose()) {

        // delta time (time since last frame)
        const float dT{GetFrameTime()};

        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // perform ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.height) {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        } else {
            // rectangle is in the air
            velocity += gravity * dT;
            isInAir = true;
        }

        // jump check
        if (IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity += jumpVel;
        }

        // update nebula position
        nebPos.x += nebVel * dT;

        // update the second nebula's position
        neb2Pos.x += nebVel * dT;

        // update scarfy position
        scarfyPos.y += velocity * dT;

        // update scarfy's animation frame
        if (!isInAir) {
            // update running time
            runningTime += dT;
            if (runningTime >= updateTime) {
                runningTime = 0.0;
                // update animation frame
                scarfyRec.x = scarfyRec.width * frame;
                frame ++;
                if (frame > 5) {
                    frame = 0;
                }
            }
        }


        // update nebula animation frame
        nebRunningTime += dT;
        if (nebRunningTime >= nebUpdateTime)
        {
            nebRunningTime = 0.0;
            nebRec.x = nebFrame * nebRec.width;
            nebFrame++;
            if (nebFrame > 7)
            {
                nebFrame = 0;
            }
        }

        // update nebula 2 animation frame
        neb2RunningTime += dT;
        if (neb2RunningTime >= neb2UpdateTime)
        {
            neb2RunningTime = 0.0;
            neb2Rec.x = neb2Frame * neb2Rec.width;
            neb2Frame++;
            if (neb2Frame > 7)
            {
                neb2Frame = 0;
            }
        }


        // draw nebula
        DrawTextureRec(nebula, nebRec, nebPos, WHITE);
        // draw the second nebula
        DrawTextureRec(nebula, neb2Rec, neb2Pos, RED);

        // draw scarfy
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);


        // stop drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();



    return 0;
}