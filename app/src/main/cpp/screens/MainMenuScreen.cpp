#include "MainMenuScreen.h"
#include "raylib.h"

MainMenuScreen::MainMenuScreen()
        : playButton({0, 0, 0, 0}, ""),
          quitButton({0, 0, 0, 0}, ""),
          finishScreen(MAIN_MENU) {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    float buttonWidth = screenWidth * 0.6f;
    float buttonHeight = screenHeight * 0.1f;
    float spacing = screenHeight * 0.05f;

    playButton = Button({(screenWidth - buttonWidth) / 2, screenHeight / 2.0f - buttonHeight - spacing / 2.0f, buttonWidth, buttonHeight}, "PLAY");
    quitButton = Button({(screenWidth - buttonWidth) / 2, screenHeight / 2.0f + spacing / 2.0f, buttonWidth, buttonHeight}, "QUIT");
}

void MainMenuScreen::Update() {
    if (playButton.IsPressed()) {
        finishScreen = GAMEPLAY;
    }
    if (quitButton.IsPressed()) {
        finishScreen = EXIT_GAME;
    }
}

void MainMenuScreen::Draw() {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    DrawText("JEFF MOBILE", screenWidth / 2 - MeasureText("JEFF MOBILE", 40) / 2, screenHeight * 0.2f, 40, DARKGRAY);
    playButton.Draw();
    quitButton.Draw();
}

GameScreen MainMenuScreen::FinishScreen() {
    return finishScreen;
}