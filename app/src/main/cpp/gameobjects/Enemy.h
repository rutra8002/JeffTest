#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject {
public:
    Enemy(Vector2 position, float size, float speed);
    void Update(const Player& player, float deltaTime);
    void Draw() const override;
    void HandleCollision(GameObject* other);

};

#endif