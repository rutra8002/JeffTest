#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, float size, float speed)
        : position(position), velocity({0.0f, 0.0f}), size(size), speed(speed) {}

void Enemy::Update(const Player& player, float deltaTime) {
    Vector2 direction = Vector2Subtract(player.position, position);
    direction = Vector2Normalize(direction);

    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed;

    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

void Enemy::Draw() const {
    DrawRectangleRec({ position.x - size / 2, position.y - size / 2, size, size }, BLUE);
}