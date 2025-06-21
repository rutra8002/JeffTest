#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 position, float size, float speed)
        : GameObject(position, size, speed) {}

void Enemy::Update(const Player& player, float deltaTime) {
    Vector2 direction = Vector2Subtract(player.position, position);
    direction = Vector2Normalize(direction);

    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed;

    GameObject::Update(deltaTime);
}

void Enemy::Draw() const {
    DrawRectangleRec(GetRect(), isColliding ? ORANGE : BLUE);
}