#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include <vector>
#include "Screen.h"
#include "../Player.h"
#include "../Enemy.h"
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
    std::vector<Enemy> enemies;
    Joystick movementJoystick;
    Joystick angleJoystick;
    Camera2D camera{};
};

#endif