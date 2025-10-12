/*
    Developed by: Francisco Passos | Frank Steps
    Developed in: 25/09/2025
    Modifield in: 12/10/2025

    [PT-BR]
        Este programa é um teste de capacidade do uso de C++ e raylib. Com exceção das fontes,
    este projeto é 100% autoral. A interface apenas foi inspirada no visual antigo do windows.
    O projeto consiste em uma calculadora simples que realiza operações básicas

    [EN-US]
        This program is a capacity test for using C++ and Raylib. This project is 100% original.
    The interface was inspired by the old Windows visual style. This project consists of a simple 
    calculator that performs basic operations.
*/

#include <iostream>
#include <vector>
#include <string>

namespace ray {
    #include <raylib.h>
}

std::string textButtons[16] = { 
    "7","8","9","/",
    "4","5","6","*",
    "1","2","3","-",
    "0","="," ","+"
};

ray::Vector2 pos_textButtons[16] = {
    {36,162},{110,162},{183,162},{258,162},
    {36,230},{110,230},{183,230},{258,234},
    {36,295},{110,295},{183,295},{260,296},
    {36,360},{144,360},{144,360},{256,360} 
};

std::vector<ray::Rectangle> bnt_up(4);
std::vector<ray::Rectangle> bnt_sh(4);
std::vector<ray::Rectangle> bnt_br(4);

int num_row = 4;
int num_col = 4;
int num_buttons = num_row  * num_col;

std::vector<ray::Rectangle> button(num_buttons);
std::vector<ray::Rectangle> shadow(num_buttons);
std::vector<ray::Rectangle> bright(num_buttons);

int main() {
    ray::InitWindow(310, 450, "Neon Calculator");

    // icon
    ray::Image icon = ray::LoadImage("images/neon.png");
    ray::SetWindowIcon(icon);

    // fonts
    ray::Font ms_sans = ray::LoadFont("fonts/ms-sans-serif.otf");
    ray::Font tahoma = ray::LoadFont("fonts/tahomabd.ttf");

    // define colors
    ray::Color background = {224, 224, 224, 255};  
    ray::Color background_Alt = {240, 240, 240, 255}; 
    ray::Color border_c = {0, 0, 0, 155};  
    ray::Color shadow_c = {148, 148, 148, 70}; 

    // menu bar
    ray::Rectangle menuBar = {0, 0, 310, 30};

    //visor
    ray::Rectangle visor = {10, 80, 290, 60};

    for(int i = 0; i < 4; i++){
        bnt_up[i] = {10.0f + i*(68+6), 40, 68, 30};
        bnt_sh[i] = {10.0f + i*(68+6), 40 + 26, 68, 4};
        bnt_br[i] = {10.0f + i*(68+6), 40, 68, 4}; 
    }
    bnt_up.erase(bnt_up.begin() + 1);
    bnt_sh.erase(bnt_sh.begin() + 1);
    bnt_br.erase(bnt_br.begin() + 1);

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

    // jury-rig button :/
    ray::Rectangle Jury_rig = {84, 348, 142, 60};
    ray::Rectangle Jury_rig_sh = {84, 404, 142, 4};
    ray::Rectangle Jury_rig_br = {84, 348, 142, 4};

    //output
    ray::Rectangle output = {10, 420, 290, 25};
    ray::Rectangle output_sh = {10, 420, 290, 3};

    ray::Vector2 pos_button = {0.0f, 0.0f};

    while (!ray::WindowShouldClose()) {
        ray::Vector2 mousepos = ray::GetMousePosition();

        ray::BeginDrawing();
        ray::ClearBackground(background);

        // mouse cordinates
        ray::Vector2 mousePoint = ray::GetMousePosition();

        // menu bar interface
        ray::DrawRectangleRec(menuBar, background_Alt);

        // render buttons
        for(int i = 0; i < 3; i++){
            ray::DrawRectangleRec(bnt_up[i], background_Alt);
            ray::DrawRectangleRec(bnt_sh[i], shadow_c);
            ray::DrawRectangleRec(bnt_br[i], ray::WHITE);
            ray::DrawRectangleLinesEx(bnt_up[i], 1, border_c);
        }

        // visor
        ray::DrawRectangleRec(visor, ray::WHITE);
        ray::DrawRectangleLinesEx(visor, 1, border_c);

        // render arithmetic buttons 
        for(int i = 0; i < num_buttons; i++){
            ray::DrawRectangleRec(button[i], background_Alt);
            ray::DrawRectangleRec(shadow[i], shadow_c);
            ray::DrawRectangleRec(bright[i], ray::WHITE);
            ray::DrawRectangleLinesEx(button[i], 1, border_c);

            if(i == 13 || i == 14){
                // junction
                ray::DrawRectangleRec(Jury_rig, background_Alt);
                ray::DrawRectangleRec(Jury_rig_sh, shadow_c);
                ray::DrawRectangleRec(Jury_rig_br, ray::WHITE);
                ray::DrawRectangleLinesEx(Jury_rig, 1, border_c);
            }

            // colision
            if (ray::CheckCollisionPointRec(mousepos, button[i]) && ray::IsMouseButtonPressed(ray::MOUSE_BUTTON_LEFT)){
                std::cout << "Button pressed: " << textButtons[i] << std::endl;
            }
        }

        // draw button's text
        for(int i = 0; i < num_buttons; i++){
            ray::DrawTextEx(tahoma, textButtons[i].c_str(), pos_textButtons[i], 32, 1, ray::BLACK);
        }


        // output
        ray::DrawRectangleLinesEx(output, 1, border_c);
        ray::DrawRectangleRec(output_sh, shadow_c);

        ray::DrawTextEx(ms_sans, "Menu", {10, 7}, 17, 1, ray::DARKGRAY);
        ray::DrawTextEx(ms_sans, "Settings", {70, 7}, 17, 1, ray::DARKGRAY);
        ray::DrawTextEx(ms_sans, "About", {150, 7}, 17, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "---->", {31, 45}, 17, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "Copy", {173, 45}, 17, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "Clear", {246, 45}, 17, 1, ray::BLACK);

        ray::EndDrawing();
    }

    // unloads
    ray::UnloadImage(icon);
    ray::UnloadFont(ms_sans);
    ray::CloseWindow();
    return EXIT_SUCCESS;
}
