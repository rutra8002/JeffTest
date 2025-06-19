#ifndef SQUARE_H
#define SQUARE_H

#include "raylib.h"
#include "UI/Joystick.h"

class Player {
public:
    Vector2 position;
    float size;
    float angle;

    Player(Vector2 position, float size);
    void Update(const Joystick& movementJoystick, const Joystick& angleJoystick, float deltaTime);
    void Draw() const;
};

#endif