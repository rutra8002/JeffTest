#ifndef SQUARE_H
#define SQUARE_H

#include "raylib.h"
#include "Joystick.h"

class Square {
public:
    Vector2 position;
    float size;

    Square(Vector2 position, float size);
    void Update(const Joystick& joystick, float deltaTime);
    void Draw() const;
};

#endif