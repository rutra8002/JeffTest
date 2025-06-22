#include "Player.h"
#include "raymath.h"

Player::Player(Vector2 position, float size, float speed)
        : GameObject(position, size, speed), angle(0.0f) {}

void Player::Update(const Joystick& movementJoystick, const Joystick& angleJoystick, float deltaTime) {
    const float acceleration = 4000.0f; // Acceleration rate - adjust as needed
    const float deceleration = 800.0f;  // Deceleration rate - adjust as needed
    Vector2 targetVelocity = {0.0f, 0.0f};

    if (movementJoystick.active) {
        // Set target velocity based on joystick direction
        targetVelocity.x = movementJoystick.direction.x * speed;
        targetVelocity.y = movementJoystick.direction.y * speed;
    }

    // Gradually adjust velocity toward target
    if (movementJoystick.active) {
        // Accelerate
        velocity.x = Lerp(velocity.x, targetVelocity.x, acceleration * deltaTime / speed);
        velocity.y = Lerp(velocity.y, targetVelocity.y, acceleration * deltaTime / speed);
    } else {
        // Decelerate when no input
        float currentSpeed = Vector2Length(velocity);
        if (currentSpeed > 0) {
            float decelerationAmount = deceleration * deltaTime;
            float newSpeed = fmaxf(0, currentSpeed - decelerationAmount);
            if (newSpeed > 0) {
                velocity = Vector2Scale(Vector2Normalize(velocity), newSpeed);
            } else {
                velocity = {0, 0};
            }
        }
    }

    // Update position based on velocity
    GameObject::Update(deltaTime);

    // Update player angle based on angle joystick
    if (angleJoystick.active) {
        angle = atan2f(angleJoystick.direction.y, angleJoystick.direction.x) * (180.0f / PI);
    }
}

void Player::HandleCollision(GameObject* other) {
    // Calculate collision normal (direction from other to this)
    Vector2 normal = Vector2Normalize(Vector2Subtract(position, other->position));

    // Calculate relative velocity
    Vector2 relativeVelocity = Vector2Subtract(velocity, other->velocity);

    // Calculate bounce factor (can be adjusted)
    float bounceFactor = 2.7f;

    // Calculate impulse magnitude
    float impulseMagnitude = Vector2DotProduct(relativeVelocity, normal) * (1.0f + bounceFactor);

    // Apply impulse to velocities
    Vector2 impulse = Vector2Scale(normal, impulseMagnitude);
    velocity = Vector2Subtract(velocity, Vector2Scale(impulse, 0.5f));

    // Slightly separate objects to prevent sticking
    position = Vector2Add(position, Vector2Scale(normal, 1.0f));
}


void Player::Draw() const {
    DrawRectanglePro({position.x, position.y, size, size}, {size / 2, size / 2}, angle, isColliding ? YELLOW : RED);
}