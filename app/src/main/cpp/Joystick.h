#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "raylib.h"
#include "raymath.h"

class Joystick {
public:
    Vector2 position;
    Vector2 origin;
    float radius;
    Vector2 direction;
    bool active;

    Joystick(Vector2 origin, float radius);
    void Update();
    void Draw() const;
};

#endif