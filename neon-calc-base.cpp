#include <iostream>
#include <vector>
#include <string>

namespace ray {
    #include <raylib.h>
}

int main() {
    ray::InitWindow(310, 450, "Neon Calculator");

    ray::Image icon = ray::LoadImage("images/neon.png");
    ray::SetWindowIcon(icon);

    // define colors
    ray::Color background = {224, 224, 224, 255};  
    ray::Color background_Alt = {240, 240, 240, 255}; 
    ray::Color border_c = {0, 0, 0, 155};  
    ray::Color shadow_c = {148, 148, 148, 70}; 


    // menu bar
    ray::Rectangle menuBar = {0, 0, 310, 30};

    //visor
    ray::Rectangle visor = {10, 80, 290, 60};
    //ray::Rectangle border_visor = {10, 80, 290, 60};


    // buttons
    ray::Rectangle clear = {10, 40, 68, 30};
    ray::Rectangle copy = {158, 40, 68, 30};
    ray::Rectangle clear_all  = {232, 40, 68, 30};

    // buttons shaders
    ray::Rectangle clear_sh = {10, 67, 68, 3};
    ray::Rectangle copy_sh = {158, 67, 68, 3};
    ray::Rectangle clear_all_sh = {232, 67, 68, 3};

    // buttons bright
    ray::Rectangle clear_br = {10, 40, 68, 3};
    ray::Rectangle copy_br = {158, 40, 68, 3};
    ray::Rectangle clear_all_br = {232, 40, 68, 3};

    // calculators buttons
    int num_row = 4;
    int num_col = 4;
    int num_buttons = num_row  * num_col;

    std::vector<ray::Rectangle> button(num_buttons);
    std::vector<ray::Rectangle> shadow(num_buttons);
    std::vector<ray::Rectangle> bright(num_buttons);

    int vector_i = 0;
    float actual_row = 150.0f;


    for(int i = 0; i < num_row; i++){
        for(int j = 0; j < num_col; j++){
            button[vector_i] = {10.0f + j*(68+6), actual_row, 68, 60};
            shadow[vector_i] = {10.0f + j*(68+6), actual_row + 56, 68, 4};
            bright[vector_i] = {10.0f + j*(68+6), actual_row + 1, 68, 4};
            vector_i++; 
        }
        actual_row = actual_row + 66.0f; 
    }

    ray::Rectangle Jury_rig = {84, 348, 142, 60};
    ray::Rectangle Jury_rig_sh = {84, 404, 142, 4};
    ray::Rectangle Jury_rig_br = {84, 348, 142, 4};

    //output
    ray::Rectangle output = {10, 420, 290, 25};
    ray::Rectangle output_sh = {10, 420, 290, 3};

    while (!ray::WindowShouldClose()) {
        ray::BeginDrawing();
        ray::ClearBackground(background);

        // interface
        ray::DrawRectangleRec(menuBar, background_Alt);

        // menu bar buttons
        ray::DrawRectangleRec(clear, background_Alt);
        ray::DrawRectangleRec(copy, background_Alt);
        ray::DrawRectangleRec(clear_all, background_Alt);

        // menu bar shaders
        ray::DrawRectangleRec(clear_sh, shadow_c);
        ray::DrawRectangleRec(copy_sh, shadow_c);
        ray::DrawRectangleRec(clear_all_sh, shadow_c);

        // menu bar bright
        ray::DrawRectangleRec(clear_br, ray::WHITE);
        ray::DrawRectangleRec(copy_br, ray::WHITE);
        ray::DrawRectangleRec(clear_all_br, ray::WHITE);

        // menu bar border buttons
        ray::DrawRectangleLinesEx(clear, 1, border_c);
        ray::DrawRectangleLinesEx(copy, 1, border_c);
        ray::DrawRectangleLinesEx(clear_all, 1, border_c);

        ray::DrawRectangleRec(visor, ray::WHITE);
        ray::DrawRectangleLinesEx(visor, 1, border_c);

        // drawing buttons
        for(int i = 0; i < num_buttons; i++){
            ray::DrawRectangleRec(button[i], background_Alt);
            ray::DrawRectangleRec(shadow[i], shadow_c);
            ray::DrawRectangleRec(bright[i], ray::WHITE);
            ray::DrawRectangleLinesEx(button[i], 1, border_c);
        }

        ray::DrawRectangleRec(Jury_rig, background_Alt);
        ray::DrawRectangleRec(Jury_rig_sh, shadow_c);
        ray::DrawRectangleRec(Jury_rig_br, ray::WHITE);
        ray::DrawRectangleLinesEx(Jury_rig, 1, border_c);

        ray::DrawRectangleLinesEx(output, 1, border_c);
        ray::DrawRectangleRec(output_sh, shadow_c);

        ray::EndDrawing();
    }

    // unloads
    ray::UnloadImage(icon);
    ray::CloseWindow();
    return EXIT_SUCCESS;
}
