#include "Game.h"
#include "MainMenuScreen.h"
#include "GameplayScreen.h"

Game::Game() : screenWidth(0), screenHeight(0), currentScreen(nullptr), currentScreenIdentifier(MAIN_MENU) {
    Init();
}

Game::~Game() {
    Cleanup();
}

void Game::Init() {
    InitWindow(0, 0, "Jeff Mobile");

    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    currentScreenIdentifier = MAIN_MENU;
    currentScreen = new MainMenuScreen();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Update() {
    if (currentScreen != nullptr) {
        currentScreen->Update();
        GameScreen nextScreen = currentScreen->FinishScreen();

        if (nextScreen != currentScreenIdentifier) {
            ChangeScreen(nextScreen);
        }
    }
}

void Game::ChangeScreen(GameScreen screen) {
    if (currentScreen != nullptr) {
        delete currentScreen;
        currentScreen = nullptr;
    }

    currentScreenIdentifier = screen;

    switch (screen) {
        case MAIN_MENU:
            currentScreen = new MainMenuScreen();
            break;
        case GAMEPLAY:
            currentScreen = new GameplayScreen();
            break;
        case EXIT_GAME:
            // The main loop will handle closing the window
            break;
        default:
            break;
    }

    if (screen == EXIT_GAME) {
        CloseWindow();
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (currentScreen != nullptr) {
        currentScreen->Draw();
    }

    EndDrawing();
}

void Game::Cleanup() {
    if (currentScreen != nullptr) {
        delete currentScreen;
        currentScreen = nullptr;
    }
}