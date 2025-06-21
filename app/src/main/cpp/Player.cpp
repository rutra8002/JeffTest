#include "Player.h"

Player::Player(Vector2 position, float size, float speed)
        : position(position), velocity({0.0f, 0.0f}), size(size), speed(speed), angle(0.0f) {}

void Player::Update(const Joystick& movementJoystick, const Joystick& angleJoystick, float deltaTime) {
    if (movementJoystick.active) {
        velocity.x = movementJoystick.direction.x * speed;
        velocity.y = movementJoystick.direction.y * speed;
    } else {
        velocity = { 0.0f, 0.0f };
    }

    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;

    if (angleJoystick.active) {
        angle = atan2f(angleJoystick.direction.y, angleJoystick.direction.x) * (180.0f / PI);
    }
}

void Player::Draw() const {
    DrawRectanglePro({position.x, position.y, size, size}, {size / 2, size / 2}, angle, RED);
}