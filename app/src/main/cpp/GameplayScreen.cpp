#include "GameplayScreen.h"

GameplayScreen::GameplayScreen()
        : player({0, 0}, 0),
          movementJoystick({0, 0}, 0),
          angleJoystick({0, 0}, 0) {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    float joystickRadius = screenHeight * 0.2f;

    movementJoystick = Joystick({joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius);
    angleJoystick = Joystick({static_cast<float>(screenWidth) - joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius);
    player = Player({static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2}, screenHeight * 0.1f);

    camera = {0};
    camera.target = player.position;
    camera.offset = {static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2};
    camera.rotation = 0.0f;
    camera.zoom = static_cast<float>(screenHeight) / 1080.0f;
}

void GameplayScreen::Update() {
    float deltaTime = GetFrameTime();
    movementJoystick.Update();
    angleJoystick.Update();
    player.Update(movementJoystick, angleJoystick, deltaTime);
}

void GameplayScreen::Draw() {
    movementJoystick.Draw();
    angleJoystick.Draw();

    BeginMode2D(camera);
    player.Draw();
    EndMode2D();

    DrawFPS(100, 100);
}

GameScreen GameplayScreen::FinishScreen() {
    return GAMEPLAY;
}