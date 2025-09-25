#include <iostream>
#include <string>

namespace ray {
    #include <raylib.h>
}

int main() {
    ray::InitWindow(306, 415, "Neon Calculator");

    ray::Image icon = ray::LoadImage("images/neon.png");
    ray::Texture base = ray::LoadTexture("images/base.png");

    ray::SetWindowIcon(icon);

    while (!ray::WindowShouldClose()) {
        ray::BeginDrawing();
        ray::ClearBackground(ray::WHITE);
        ray::DrawTexture(base, 0, 0, ray::WHITE);
        ray::EndDrawing();
    }

    // unloads
    ray::UnloadImage(icon);
    ray::UnloadTexture(base);
    ray::CloseWindow();
    return EXIT_SUCCESS;
}
