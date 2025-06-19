#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "screens/Screen.h"

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
};

#endif