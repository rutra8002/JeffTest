#include "Joystick.h"

Joystick::Joystick(Vector2 origin, float radius)
        : origin(origin), radius(radius), position(origin), direction({0, 0}), active(false) {}

void Joystick::Update() {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 touchPosition = GetMousePosition();
        if (CheckCollisionPointCircle(touchPosition, origin, radius)) {
            active = true;
            position = touchPosition;
            direction = Vector2Subtract(position, origin);
            direction = Vector2Normalize(direction);
        }
    } else {
        active = false;
        position = origin;
        direction = {0, 0};
    }
}

void Joystick::Draw() const {
    DrawCircleV(origin, radius, LIGHTGRAY);
    DrawCircleV(position, radius / 2, DARKGRAY);
}