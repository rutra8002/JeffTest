#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "raylib.h"

class GameObject {
public:
    Vector2 position;
    Vector2 velocity;
    float size;
    float speed;
    bool isColliding;

    GameObject(Vector2 position, float size, float speed);
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime);
    virtual void Draw() const = 0;

    Rectangle GetRect() const;
};

#endif