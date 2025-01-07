#include "raymob.h"
int main()
{
    InitWindow(0, 0, "raylib [core] example - basic window");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello World", 190, 200, 60, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}