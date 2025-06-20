#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Player.h"

class Enemy {
public:
    Vector2 position;
    float size;
    float speed;

    Enemy(Vector2 position, float size, float speed);
    void Update(const Player& player, float deltaTime);
    void Draw() const;
};

#endif