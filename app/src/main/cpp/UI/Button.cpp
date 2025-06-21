#include "Button.h"
#include "raymob.h"

Button::Button(Rectangle bounds, const char* text) : bounds(bounds), text(text) {}

void Button::Draw() const {
    DrawRectangleRec(bounds, LIGHTGRAY);
    int fontSize = bounds.height / 2;
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, bounds.x + (bounds.width - textWidth) / 2, bounds.y + (bounds.height - fontSize) / 2, fontSize, DARKGRAY);
}

bool Button::IsPressed() const {
    bool pressed = false;

    // Check for mouse input (for desktop testing)
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), bounds)) {
        pressed = true;
    }

    // Check for touch input, ensuring it's a single press event
    bool touchDown = GetTouchPointCount() > 0 && CheckCollisionPointRec(GetTouchPosition(0), bounds);
    if (touchDown && !wasTouched) {
        pressed = true;
    }
    wasTouched = touchDown;

    if (pressed) {
        VibrateMS(50);
    }

    return pressed;
}