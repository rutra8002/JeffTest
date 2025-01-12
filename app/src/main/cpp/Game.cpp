#include "Game.h"

Game::Game()
        : joystickRadius(0),
          movementJoystick({0, 0}, 0),
          angleJoystick({0, 0}, 0),
          square({0, 0}, 0) {
    Init();
}

Game::~Game() {
    Cleanup();
}

void Game::Init() {
    InitWindow(0, 0, "Jeff Mobile");

    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    joystickRadius = screenHeight * 0.2f;

    movementJoystick = Joystick({joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius);
    angleJoystick = Joystick({static_cast<float>(screenWidth) - joystickRadius, static_cast<float>(screenHeight) - joystickRadius}, joystickRadius);
    square = Player({static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2}, screenHeight * 0.1f);

    camera = {0};
    camera.target = square.position;
    camera.offset = {static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2};
    camera.rotation = 0.0f;
    camera.zoom = static_cast<float>(screenHeight) / 1080.0f;
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Update() {
    float deltaTime = GetFrameTime();

    movementJoystick.Update();
    angleJoystick.Update();
    square.Update(movementJoystick, angleJoystick, deltaTime);
}

void Game::Draw() {
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

void Game::Cleanup() {
    CloseWindow();
}