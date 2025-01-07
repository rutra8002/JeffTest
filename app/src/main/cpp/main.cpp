#include "raylib.h"
#include "raymath.h"

struct Joystick {
    Vector2 position;
    Vector2 origin;
    float radius;
    Vector2 direction;
    bool active;
};

struct Square {
    Vector2 position;
    float size;
};

int main()
{
    InitWindow(0, 0, "Movable Square with Joystick");

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    float joystickRadius = screenHeight * 0.2f;
    Joystick joystick = { {joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, {joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius, {0, 0}, false };
    Square square = { {static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2}, screenHeight * 0.1f };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        DrawFPS(joystickRadius, joystickRadius);
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 touchPosition = GetMousePosition();
            if (CheckCollisionPointCircle(touchPosition, joystick.origin, joystick.radius)) {
                joystick.active = true;
                joystick.position = touchPosition;
                joystick.direction = Vector2Subtract(joystick.position, joystick.origin);
                joystick.direction = Vector2Normalize(joystick.direction);
            }
        } else {
            joystick.active = false;
            joystick.position = joystick.origin;
            joystick.direction = {0, 0};
        }

        // Update square position
        if (joystick.active) {
            square.position.x += joystick.direction.x * 5.0f;
            square.position.y += joystick.direction.y * 5.0f;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircleV(joystick.origin, joystick.radius, LIGHTGRAY);
        DrawCircleV(joystick.position, joystick.radius / 2, DARKGRAY);

        DrawRectangleV(square.position, {square.size, square.size}, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}