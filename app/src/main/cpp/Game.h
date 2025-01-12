#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "Joystick.h"
#include "Player.h"

class Game {
public:
    Game();
    ~Game();
    void Run();

private:
    void Init();
    void Update();
    void Draw();
    void Cleanup();

    int screenWidth;
    int screenHeight;
    float joystickRadius;
    Joystick movementJoystick;
    Joystick angleJoystick;
    Player square;
    Camera2D camera;
};

#endif