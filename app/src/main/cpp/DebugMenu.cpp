#include "DebugMenu.h"
#include "gameobjects/GameObject.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <android/log.h>

// Function prototype
unsigned int GetMemoryUsage();

DebugMenu::DebugMenu() :
        active(false),
        debugButton(Rectangle{10, 10, 100, 40}, "Debug") {
}

void DebugMenu::Update() {
    if (debugButton.IsPressed()) {
        active = !active;
    }
}

void DebugMenu::Draw() const {
    // Only in debug builds
#ifdef NDEBUG
    const char* buildMode = "Release";
#else
    const char* buildMode = "Debug";
    debugButton.Draw(); // Only show button in debug mode
#endif

    if (active) {
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        // Draw debug panel
        Rectangle panel = {screenWidth - 300.0f, 10.0f, 290.0f, 400.0f};
        DrawRectangleRec(panel, Fade(LIGHTGRAY, 0.9f));
        DrawRectangleLinesEx(panel, 2, DARKGRAY);

        int y = panel.y + 10;

        // Build mode
        DrawText(TextFormat("Build: %s", buildMode), panel.x + 10, y, 20, BLACK);
        y += 25;

        // RAM usage (real value)
        DrawText(TextFormat("Memory: %u KB", GetMemoryUsage() / 1024), panel.x + 10, y, 20, BLACK);
        y += 30;

        // Game objects positions
        DrawText("Game Objects:", panel.x + 10, y, 20, BLACK);
        y += 25;

        for (const auto& obj : gameObjects) {
            if (obj.second) {
                DrawText(TextFormat("%s: (%.1f, %.1f)", obj.first.c_str(),
                                    obj.second->position.x, obj.second->position.y),
                         panel.x + 10, y, 18, BLACK);
                y += 20;
            }
        }
    }
}

// Implementation to get actual memory usage on Android
unsigned int GetMemoryUsage() {
    unsigned int memoryUsage = 0;

    try {
        std::ifstream statusFile("/proc/self/status");
        std::string line;

        if (statusFile.is_open()) {
            while (std::getline(statusFile, line)) {
                // Look for VmRSS line which shows physical memory usage
                if (line.find("VmRSS:") != std::string::npos) {
                    // Format is typically "VmRSS:     12345 kB"
                    std::string memStr = line.substr(line.find("VmRSS:") + 6);
                    // Remove "kB" and spaces
                    memStr = memStr.substr(0, memStr.find("kB"));

                    // Remove whitespace
                    memStr.erase(0, memStr.find_first_not_of(" \t\n\r\f\v"));
                    memStr.erase(memStr.find_last_not_of(" \t\n\r\f\v") + 1);

                    // Convert to integer (values in the file are in KB)
                    memoryUsage = static_cast<unsigned int>(std::atoi(memStr.c_str())) * 1024;
                    break;
                }
            }
            statusFile.close();
        }
    } catch (const std::exception& e) {
        // Fallback to default value if we encounter an error
        return 100 * 1024;
    }

    if (memoryUsage == 0) {
        // If we failed to get memory usage, return a default value
        return 100 * 1024;
    }

    return memoryUsage;
}

void DebugMenu::AddGameObject(const std::string& name, const GameObject* object) {
    gameObjects.push_back({name, object});
}

void DebugMenu::ClearGameObjects() {
    gameObjects.clear();
}