#ifndef SCREEN_H
#define SCREEN_H

typedef enum GameScreen {
    MAIN_MENU,
    GAMEPLAY,
    EXIT_GAME
} GameScreen;

class Screen {
public:
    virtual ~Screen() = default;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual GameScreen FinishScreen() = 0;
};

#endif