#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include "Screen.h"
#include "../Player.h"
#include "../UI/Joystick.h"

class GameplayScreen : public Screen {
public:
    GameplayScreen();
    ~GameplayScreen() override = default;

    void Update() override;
    void Draw() override;
    GameScreen FinishScreen() override;

private:
    Player player;
    Joystick movementJoystick;
    Joystick angleJoystick;
    Camera2D camera;
};

#endif