#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "screens/Screen.h"
#include "DebugMenu.h"

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
    void ChangeScreen(GameScreen screen);

    int screenWidth;
    int screenHeight;

    Screen* currentScreen;
    GameScreen currentScreenIdentifier;

    // Screen transition
    enum TransitionState { NONE, FADE_OUT, FADE_IN };
    TransitionState transitionState;
    float transitionAlpha;
    GameScreen transitionToScreen;

    DebugMenu debugMenu;
};

#endif