#include "Square.h"

Square::Square(Vector2 position, float size)
        : position(position), size(size) {}

void Square::Update(const Joystick& joystick, float deltaTime) {
    if (joystick.active) {
        position.x += joystick.direction.x * 200.0f * deltaTime;
        position.y += joystick.direction.y * 200.0f * deltaTime;
    }
}

void Square::Draw() const {
    DrawRectangleV(position, {size, size}, RED);
}