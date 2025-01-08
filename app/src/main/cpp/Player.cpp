#include "Player.h"

Player::Player(Vector2 position, float size)
        : position(position), size(size) {}

void Player::Update(const Joystick& joystick, float deltaTime) {
    if (joystick.active) {
        position.x += joystick.direction.x * 200.0f * deltaTime;
        position.y += joystick.direction.y * 200.0f * deltaTime;
    }
}

void Player::Draw() const {
    DrawRectangleV(position, {size, size}, RED);
}