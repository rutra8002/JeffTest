#include "GameObject.h"

GameObject::GameObject(Vector2 position, float size, float speed)
        : position(position), velocity({0.0f, 0.0f}), size(size), speed(speed), isColliding(false) {}

void GameObject::Update(float deltaTime) {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

Rectangle GameObject::GetRect() const {
    return { position.x - size / 2, position.y - size / 2, size, size };
}