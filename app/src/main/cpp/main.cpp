#include "raylib.h"
#include "Joystick.h"
#include "Player.h"

int main()
{
    InitWindow(0, 0, "Jeff Mobile");

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    const int baseScreenWidth = 1920;
    const int baseScreenHeight = 1080;

    float joystickRadius = screenHeight * 0.2f;
    Joystick movementJoystick({joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius);
    Joystick angleJoystick({static_cast<float>(screenWidth) - joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius);
    Player square({static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2}, screenHeight * 0.1f);

    Camera2D camera = {0};
    camera.target = square.position;
    camera.offset = {static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2};
    camera.rotation = 0.0f;
    camera.zoom = static_cast<float>(screenHeight) / baseScreenHeight;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        movementJoystick.Update();
        angleJoystick.Update();
        square.Update(movementJoystick, angleJoystick, deltaTime);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        movementJoystick.Draw();
        angleJoystick.Draw();

        BeginMode2D(camera);

        square.Draw();

        EndMode2D();

        DrawFPS(joystickRadius, joystickRadius);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}