#ifndef SQUARE_H
#define SQUARE_H

#include "raylib.h"
#include "Joystick.h"

class Player {
public:
    Vector2 position;
    float size;

    Player(Vector2 position, float size);
    void Update(const Joystick& joystick, float deltaTime);
    void Draw() const;
};

#endif