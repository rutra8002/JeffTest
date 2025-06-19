#include "Joystick.h"

Joystick::Joystick(Vector2 origin, float radius)
        : origin(origin), radius(radius), position(origin), direction({0, 0}), active(false), touchId(-1) {}

void Joystick::Update() {
    int touchCount = GetTouchPointCount();
    active = false;

    for (int i = 0; i < touchCount; i++) {
        Vector2 touchPosition = GetTouchPosition(i);
        if (CheckCollisionPointCircle(touchPosition, origin, radius)) {
            active = true;
            touchId = i;
            position = touchPosition;
            direction = Vector2Subtract(position, origin);
            direction = Vector2Normalize(direction);
            break;
        }
    }

    if (!active) {
        position = origin;
        direction = {0, 0};
        touchId = -1;
    }
}

void Joystick::Draw() const {
    DrawCircleV(origin, radius, LIGHTGRAY);
    DrawCircleV(position, radius / 2, DARKGRAY);
}