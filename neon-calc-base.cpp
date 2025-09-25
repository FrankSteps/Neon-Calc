#include <iostream>
#include <vector>
#include <string>

namespace ray {
    #include <raylib.h>
}

int main() {
    ray::InitWindow(310, 420, "Neon Calculator");

    ray::Image icon = ray::LoadImage("images/neon.png");
    ray::SetWindowIcon(icon);

    // define colors
    ray::Color background = {224, 224, 224, 255};  
    ray::Color background_Alt = {240, 240, 240, 255}; 
    ray::Color border = {176, 176, 176, 255};  
    ray::Color shadow = {128, 128, 128, 255}; 


    // menu bar
    ray::Rectangle menuBar = {0, 0, 310, 30};

    //visor
    ray::Rectangle visor = {10, 80, 290, 60};
    //ray::Rectangle border_visor = {10, 80, 290, 60};


    // buttons
    ray::Rectangle clear = {10, 40, 68, 30};
    //ray::Rectangle clear1  = {84, 40, 68, 30};
    ray::Rectangle copy = {158, 40, 68, 30};
    ray::Rectangle clear_all  = {232, 40, 68, 30};


    // calculators buttons 
    ray::Rectangle button9 = {10, 160, 68, 68};
    ray::Rectangle button8 = {84, 160, 68, 68};
    ray::Rectangle button7 = {158, 160, 68, 68};
    ray::Rectangle button_div = {232, 160, 68, 68};

    int num_buttons = 4;
    std::vector<ray::Rectangle> button(num_buttons);

    for(int i = 0; i < num_buttons; i++){
        button[i] = {10.0f + i*(68+5), 160, 68, 60};  
    }

    //output
    ray::Rectangle output = {10, 390, 290, 25};

    while (!ray::WindowShouldClose()) {
        ray::BeginDrawing();
        ray::ClearBackground(background);
        

        // interface
        ray::DrawRectangleRec(menuBar, background_Alt);

        // menu bar buttons
        ray::DrawRectangleRec(clear, background_Alt);
        ray::DrawRectangleRec(copy, background_Alt);
        ray::DrawRectangleRec(clear_all, background_Alt);

        // menu bar border buttons
        ray::DrawRectangleLinesEx(clear, 1, border);
        ray::DrawRectangleLinesEx(copy, 1, border);
        ray::DrawRectangleLinesEx(clear_all, 1, border);


        // buttons -> numbers ans symbols 
        for(int i = 0; i < num_buttons; i++){
            ray::DrawRectangleRec(button[i], background_Alt);
        }

        ray::DrawRectangleRec(visor, ray::WHITE);
        ray::DrawRectangleLinesEx(visor, 1, border);

        ray::DrawRectangleLinesEx(output, 2, border);

        ray::EndDrawing();
    }

    // unloads
    ray::UnloadImage(icon);
    ray::CloseWindow();
    return EXIT_SUCCESS;
}
