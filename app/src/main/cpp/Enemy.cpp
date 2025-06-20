#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, float size, float speed)
        : position(position), size(size), speed(speed) {}

void Enemy::Update(const Player& player, float deltaTime) {
    Vector2 direction = Vector2Subtract(player.position, position);
    direction = Vector2Normalize(direction);

    position.x += direction.x * speed * deltaTime;
    position.y += direction.y * speed * deltaTime;
}

void Enemy::Draw() const {
    DrawRectangleRec({ position.x - size / 2, position.y - size / 2, size, size }, BLUE);
}