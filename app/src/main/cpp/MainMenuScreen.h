#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "Screen.h"
#include "Button.h"

class MainMenuScreen : public Screen {
public:
    MainMenuScreen();
    ~MainMenuScreen() override = default;

    void Update() override;
    void Draw() override;
    GameScreen FinishScreen() override;

private:
    Button playButton;
    Button quitButton;
    GameScreen finishScreen;
};

#endif