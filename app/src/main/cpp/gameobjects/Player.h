#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "../UI/Joystick.h"

class Player : public GameObject {
public:
    float angle;

    Player(Vector2 position, float size, float speed);
    void Update(const Joystick& movementJoystick, const Joystick& angleJoystick, float deltaTime);
    void Draw() const override;
};

#endif