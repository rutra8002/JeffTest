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
void Enemy::HandleCollision(GameObject* other) {
    // Calculate collision normal (direction from other to this)
    Vector2 normal = Vector2Normalize(Vector2Subtract(position, other->position));

    // Calculate relative velocity
    Vector2 relativeVelocity = Vector2Subtract(velocity, other->velocity);

    // Only apply impulse if objects are moving toward each other
    float velDotNormal = Vector2DotProduct(relativeVelocity, normal);
    if (velDotNormal < 0) {
        // Calculate bounce factor
        float bounceFactor = 7.7f;

        // Calculate impulse magnitude (with correct sign)
        float impulseMagnitude = -velDotNormal * (1.0f + bounceFactor);

        // Apply impulse to velocity (adding, not subtracting)
        Vector2 impulse = Vector2Scale(normal, impulseMagnitude);
        velocity = Vector2Add(velocity, impulse);

        // Slightly separate objects to prevent sticking
        position = Vector2Add(position, Vector2Scale(normal, 1.0f));
    }
}

void Enemy::Draw() const {
    DrawRectangleRec(GetRect(), isColliding ? ORANGE : BLUE);
}