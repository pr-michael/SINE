#include "raylib.h"
#include "math.h"

void drawSine(int screenHeight, int screenWidth, double amplitude, double freq, double cnt);

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1850;
    int screenHeight = 950;
    double speed = 1.f;
    double cnt = 0;
    double amplitude = (screenHeight / 2.f) - 40;
    double freq = 1.f / (screenWidth * 0.25);

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if (IsKeyPressed(KEY_F11) && IsWindowFullscreen())
        {
            ToggleFullscreen();
            SetWindowSize(1850, 950);
            screenWidth = 1850.f;
            screenHeight = 950.f;
            amplitude = (screenHeight / 2.f) - 40;
            SetWindowPosition(30, 30);
        }
        else if (IsKeyPressed(KEY_F11) && !IsWindowFullscreen())
        {
            ToggleFullscreen();
            SetWindowSize(1920, 1080);
            screenWidth = 1920.f;
            screenHeight = 1080.f;
            amplitude = (screenHeight / 2.f) - 40;
            SetWindowPosition(0, 0);
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            speed += 0.1;
        }
        if (IsKeyDown(KEY_LEFT))
        {
            speed -= 0.1;
        }
        cnt = (cnt + speed * GetFrameTime());
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        drawSine(screenHeight, screenWidth, amplitude, freq, cnt);

        DrawFPS(10, 10);
        DrawText("toggle Fullscreen: F11", 115, 10, 20, GRAY);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void drawSine(int screenHeight, int screenWidth, double amplitude, double freq, double cnt)
{
    for (int i = 0; i < screenWidth - 40; i++)
    {
        DrawLine(20 + i,                                                            // x1
                 screenHeight / 2 - amplitude * sin(2 * PI * freq * i + cnt),       // y1
                 20 + (i + 1),                                                      // x2
                 screenHeight / 2 - amplitude * sin(2 * PI * freq * (i + 1) + cnt), // y2
                 BLACK);
    }
}