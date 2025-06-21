#ifndef DEBUGMENU_H
#define DEBUGMENU_H

#include "raylib.h"
#include "UI/Button.h"
#include <vector>
#include <string>

class GameObject;

class DebugMenu {
public:
    DebugMenu();
    void Update();
    void Draw() const;

    // Track game objects
    void AddGameObject(const std::string& name, const GameObject* object);
    void ClearGameObjects();

private:
    bool active;
    Button debugButton;
    std::vector<std::pair<std::string, const GameObject*>> gameObjects;
};

#endif