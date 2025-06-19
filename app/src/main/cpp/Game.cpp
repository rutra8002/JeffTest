#include "Game.h"
#include "Button.h"

Game::Game()
        : joystickRadius(0),
          movementJoystick({0, 0}, 0),
          angleJoystick({0, 0}, 0),
          square({0, 0}, 0),
          playButton({0, 0, 0, 0}, ""),
          quitButton({0, 0, 0, 0}, "") {
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

    currentScreen = MAIN_MENU;
    float buttonWidth = screenWidth * 0.6f;
    float buttonHeight = screenHeight * 0.1f;
    float spacing = screenHeight * 0.05f;
    playButton = Button({(screenWidth - buttonWidth) / 2, screenHeight / 2.0f - buttonHeight - spacing / 2.0f, buttonWidth, buttonHeight}, "PLAY");
    quitButton = Button({(screenWidth - buttonWidth) / 2, screenHeight / 2.0f + spacing / 2.0f, buttonWidth, buttonHeight}, "QUIT");
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Update() {
    switch (currentScreen) {
        case MAIN_MENU: {
            if (playButton.IsPressed()) {
                currentScreen = GAMEPLAY;
            }
            if (quitButton.IsPressed()) {
                CloseWindow();
            }
        } break;
        case GAMEPLAY: {
            float deltaTime = GetFrameTime();
            movementJoystick.Update();
            angleJoystick.Update();
            square.Update(movementJoystick, angleJoystick, deltaTime);
        } break;
        default: break;
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (currentScreen) {
        case MAIN_MENU: {
            DrawText("JEFF MOBILE", screenWidth / 2 - MeasureText("JEFF MOBILE", 40) / 2, screenHeight * 0.2f, 40, DARKGRAY);
            playButton.Draw();
            quitButton.Draw();
        } break;
        case GAMEPLAY: {
            movementJoystick.Draw();
            angleJoystick.Draw();

            BeginMode2D(camera);
            square.Draw();
            EndMode2D();

            DrawFPS(joystickRadius, joystickRadius);
        } break;
        default: break;
    }

    EndDrawing();
}

void Game::Cleanup() {
    CloseWindow();
}