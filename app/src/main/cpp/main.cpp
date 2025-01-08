#include "raylib.h"
#include "Joystick.h"
#include "Player.h"

int main()
{
    InitWindow(0, 0, "Jeff Mobile");

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    float joystickRadius = screenHeight * 0.2f;
    Joystick joystick({joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius);
    Player square({static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2}, screenHeight * 0.1f);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        joystick.Update();
        square.Update(joystick, deltaTime);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        joystick.Draw();
        square.Draw();

        DrawFPS(joystickRadius, joystickRadius);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}