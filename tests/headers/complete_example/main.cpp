#include <iostream>

namespace ray {
    #include <raylib.h>
}

int main(){
    ray::InitWindow(400, 300, "Hello, world - example");

    ray::Rectangle button = {150, 120, 100, 50};
    bool mousePresed = false;

    while(!ray::WindowShouldClose()){
        ray::Vector2 mousePos = ray::GetMousePosition();
        bool hovering = ray::CheckCollisionPointRec(mousePos, button);

        if(hovering && ray::IsMouseButtonPressed(ray::MOUSE_BUTTON_LEFT)){
            std::cout << "Hello, world!\n"; 
            mousePresed = true;
        }

        if(!ray::IsMouseButtonDown(ray::MOUSE_BUTTON_LEFT)){
            mousePresed = false;
        }

        ray::BeginDrawing();
            ray::ClearBackground(ray::BLACK);

            if(hovering){
                ray::DrawRectangleRec(button, ray::LIGHTGRAY);
            }else{
                ray::DrawRectangleRec(button, ray::GRAY);
            }
            
            ray::DrawText("Click-me", button.x + 10, button.y + 15, 20, ray::BLACK);
        ray::EndDrawing();
    }
    ray::CloseWindow();
    return 0;
}