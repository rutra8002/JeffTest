#include "Button.h"

Button::Button(Rectangle bounds, const char* text) : bounds(bounds), text(text) {}

void Button::Draw() const {
    DrawRectangleRec(bounds, LIGHTGRAY);
    int fontSize = bounds.height / 2;
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, bounds.x + (bounds.width - textWidth) / 2, bounds.y + (bounds.height - fontSize) / 2, fontSize, DARKGRAY);
}

bool Button::IsPressed() const {
    // Check for mouse input (for desktop testing)
    if (CheckCollisionPointRec(GetMousePosition(), bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        return true;
    }

    // Check for touch input
    if (GetTouchPointCount() > 0 && CheckCollisionPointRec(GetTouchPosition(0), bounds)) {
        return true;
    }
    return false;
}