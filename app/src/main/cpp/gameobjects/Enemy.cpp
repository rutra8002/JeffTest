#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, float size, float speed)
        : GameObject(position, size, speed) {}

void Enemy::Update(const Player& player, float deltaTime) {
    const float acceleration = 800.0f;

    Vector2 direction = Vector2Subtract(player.position, position);
    direction = Vector2Normalize(direction);

    Vector2 targetVelocity = {direction.x * speed, direction.y * speed};

    velocity.x = Lerp(velocity.x, targetVelocity.x, acceleration * deltaTime / speed);
    velocity.y = Lerp(velocity.y, targetVelocity.y, acceleration * deltaTime / speed);

    GameObject::Update(deltaTime);
}

void Enemy::Draw() const {
    DrawRectangleRec(GetRect(), isColliding ? ORANGE : BLUE);
}