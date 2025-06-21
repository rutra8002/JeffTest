#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

class Button {
public:
    Rectangle bounds;
    const char* text;

    Button(Rectangle bounds, const char* text);
    void Draw() const;
    bool IsPressed() const;

private:
    mutable bool wasTouched = false;
};

#endif