#include "Player.h"

Player::Player(Vector2 position, float size)
        : position(position), size(size), angle(0.0f) {}

void Player::Update(const Joystick& movementJoystick, const Joystick& angleJoystick, float deltaTime) {
    if (movementJoystick.active) {
        position.x += movementJoystick.direction.x * 200.0f * deltaTime;
        position.y += movementJoystick.direction.y * 200.0f * deltaTime;
    }
    if (angleJoystick.active) {
        angle = atan2f(angleJoystick.direction.y, angleJoystick.direction.x) * (180.0f / PI);
    }
}

void Player::Draw() const {
    DrawRectanglePro({position.x, position.y, size, size}, {size / 2, size / 2}, angle, RED);
}