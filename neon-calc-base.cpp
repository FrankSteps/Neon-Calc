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
    

    // menu bar buttons
    std::vector<ray::Rectangle> bnt_up(4);
    std::vector<ray::Rectangle> bnt_sh(4);
    std::vector<ray::Rectangle> bnt_br(4);


    for(int i = 0; i < 4; i++){
        bnt_up[i] = {10.0f + i*(68+6), 40, 68, 30};
        bnt_sh[i] = {10.0f + i*(68+6), 40 + 26, 68, 4};
        bnt_br[i] = {10.0f + i*(68+6), 40, 68, 4}; 
    }

    bnt_up.erase(bnt_up.begin() + 1);
    bnt_sh.erase(bnt_sh.begin() + 1);
    bnt_br.erase(bnt_br.begin() + 1);


    // calculator buttons
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
            bright[vector_i] = {10.0f + j*(68+6), actual_row, 68, 4};

            vector_i++;
        }
        actual_row += 66.0f;
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

        ray::DrawRectangleRec(menuBar, background_Alt);

        ray::DrawRectangleRec(visor, ray::WHITE);
        ray::DrawRectangleLinesEx(visor, 1, border_c);

        for(int i = 0; i < num_buttons; i++){
            ray::DrawRectangleRec(button[i], background_Alt);
            ray::DrawRectangleRec(shadow[i], shadow_c);
            ray::DrawRectangleRec(bright[i], ray::WHITE);
            ray::DrawRectangleLinesEx(button[i], 1, border_c);
        }

        for(int i = 0; i < 3; i++){
            ray::DrawRectangleRec(bnt_up[i], background_Alt);
            ray::DrawRectangleRec(bnt_sh[i], shadow_c);
            ray::DrawRectangleRec(bnt_br[i], ray::WHITE);
            ray::DrawRectangleLinesEx(bnt_up[i], 1, border_c);
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
