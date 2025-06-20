#include "Game.h"
#include "screens/MainMenuScreen.h"
#include "screens/GameplayScreen.h"

Game::Game() : screenWidth(0), screenHeight(0), currentScreen(nullptr), currentScreenIdentifier(MAIN_MENU),
               transitionState(TransitionState::NONE), transitionAlpha(0.0f), transitionToScreen(MAIN_MENU) {
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
    switch (transitionState) {
        case FADE_OUT: {
            transitionAlpha += 2.0f * GetFrameTime(); // Fade speed
            if (transitionAlpha >= 1.0f) {
                transitionAlpha = 1.0f;
                ChangeScreen(transitionToScreen);
                if (transitionToScreen != EXIT_GAME) {
                    transitionState = FADE_IN;
                } else {
                    transitionState = NONE;
                }
            }
        } break;
        case FADE_IN: {
            transitionAlpha -= 2.0f * GetFrameTime(); // Fade speed
            if (transitionAlpha <= 0.0f) {
                transitionAlpha = 0.0f;
                transitionState = NONE;
            }
        } break;
        default: { // NONE
            if (currentScreen != nullptr) {
                currentScreen->Update();
                GameScreen nextScreen = currentScreen->FinishScreen();

                if (nextScreen != currentScreenIdentifier) {
                    transitionState = FADE_OUT;
                    transitionToScreen = nextScreen;
                    transitionAlpha = 0.0f;
                }
            }
        } break;
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

    if (transitionState != NONE) {
        DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, transitionAlpha));
    }

    EndDrawing();
}

void Game::Cleanup() {
    if (currentScreen != nullptr) {
        delete currentScreen;
        currentScreen = nullptr;
    }
}