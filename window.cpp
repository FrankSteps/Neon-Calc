/*
    Developed by: Francisco Passos | Frank Steps
    Developed in: 25/09/2025
    Modifield in: 23/12/2025

    [PT-BR]
        Este programa é um teste de capacidade do uso de C++ e raylib. Com exceção das fontes,
    este projeto é 100% autoral. A interface apenas foi inspirada no visual antigo do windows.
    O projeto consiste em uma calculadora simples que realiza operações básicas

    [EN-US]
        This program is a capacity test for using C++ and Raylib. This project is 100% original.
    The interface was inspired by the old Windows visual style and consists of a simple 
    calculator that performs basic operations.
*/

// ---------------------------------   libraries   ---------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>

namespace ray {
    #include <raylib.h>
}

// ---------------------------------    visuals    ---------------------------------
const int num_row = 4;
const int num_col = 4;
const int num_buttons = num_row  * num_col;

std::vector<ray::Rectangle> controlButton(3);

std::vector<ray::Rectangle> bnt_up(4);
std::vector<ray::Rectangle> bnt_sh(4);
std::vector<ray::Rectangle> bnt_br(4);

std::vector<ray::Rectangle> button(num_buttons);
std::vector<ray::Rectangle> shadow(num_buttons);
std::vector<ray::Rectangle> bright(num_buttons);


ray::Vector2 pos_textButtons[num_buttons + 7] = {
    {10,7},{70,7},{150,7},
    {31,45},{173,45},{246,45},
    {36,162},{110,162},{183,162},{258,162},
    {36,230},{110,230},{183,230},{258,234},
    {36,295},{110,295},{183,295},{260,296},
    {36,360},{144,360},{144,360},{256,360},
    {14,424} 
};

std::string textButtons[num_buttons + 6] = { 
    "Main", "Settings", "About",
    "---->", "Copy", "Clear",
    "7", "8", "9", "/",
    "4", "5", "6", "*",
    "1", "2", "3", "-",
    "0", "=", "=", "+"
};


// define colors
ray::Color background      = {224, 224, 224, 255};  
ray::Color background_Alt  = {240, 240, 240, 255}; 
ray::Color border_c        = {0, 0, 0, 155};  
ray::Color shadow_c        = {148, 148, 148, 70}; 
ray::Color inactive        = {0, 0, 0, 70};
ray::Color active          = ray::BLACK;
ray::Color translucid      = {0, 0, 0, 0};

// --------------------------------- state buttons ---------------------------------
enum class ButtonState {
    Disabled,
    Enabled,
};

std::vector<ButtonState> buttonState = {
    ButtonState::Disabled,
    ButtonState::Disabled, 
    ButtonState::Enabled      
};

ray::Color returnColor(ButtonState state){
    return (state == ButtonState::Enabled)? active : inactive;  
}
// ---------------------------------     error     ---------------------------------

enum class Messenger {
    Void, Inactive, Copied, Cleared, Unknown
};


std::string messenger(Messenger message){
    switch(message){
        case Messenger::Void: 
            return " "; 
        case Messenger::Inactive: 
            return "Error or inactive";
        case Messenger::Copied:
            return "Copied!"; 
        case Messenger::Cleared:
            return "Cleared!";
        case Messenger::Unknown:
            return "Unknown error";
    }
}


// --------------------------------- main function ---------------------------------
int main() {
    ray::InitWindow(310, 450, "Neon Calculator");
    std::string messengerText = messenger(Messenger::Void); 

    // icon
    ray::Image icon = ray::LoadImage("images/neon.png");
    ray::SetWindowIcon(icon);

    // fonts
    ray::Font ms_sans = ray::LoadFont("fonts/ms-sans-serif.otf");
    ray::Font tahoma = ray::LoadFont("fonts/tahomabd.ttf");

    // menu bar
    ray::Rectangle menuBar = {0, 0, 310, 30};

    //visor
    ray::Rectangle visor = {10, 80, 290, 60};

    // control buttons generator 
    for(int i = 0; i < 3; i++){
        controlButton[i] = {10.0f + i*(68+6), 0, 50, 20};
    }

    // command buttons generator 
    for(int i = 0; i < 4; i++){
        bnt_up[i] = {10.0f + i*(68+6), 40, 68, 30};
        bnt_sh[i] = {10.0f + i*(68+6), 40 + 26, 68, 4};
        bnt_br[i] = {10.0f + i*(68+6), 40, 68, 4}; 
    }
    bnt_up.erase(bnt_up.begin() + 1);
    bnt_sh.erase(bnt_sh.begin() + 1);
    bnt_br.erase(bnt_br.begin() + 1);


    // number buttons and operation buttons generator 
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

    // jury-rig button :/ (Gambiarra) -> Junction 
    ray::Rectangle Jury_rig    = {84, 348, 142, 60};
    ray::Rectangle Jury_rig_sh = {84, 404, 142, 4};
    ray::Rectangle Jury_rig_br = {84, 348, 142, 4};

    //output
    ray::Rectangle output    = {10, 420, 290, 25};
    ray::Rectangle output_sh = {10, 420, 290, 3};

    ray::Vector2 pos_button = {0.0f, 0.0f};


    while (!ray::WindowShouldClose()) {
        ray::Vector2 mousepos = ray::GetMousePosition();

        ray::BeginDrawing();
        ray::ClearBackground(background);


        // menu bar interface
        ray::DrawRectangleRec(menuBar, background_Alt); 

        // render command buttons
        for(int i = 0; i < 3; i++){
            ray::DrawRectangleRec(bnt_up[i], background_Alt);
            ray::DrawRectangleRec(bnt_sh[i], shadow_c);
            ray::DrawRectangleRec(bnt_br[i], ray::WHITE);
            ray::DrawRectangleLinesEx(bnt_up[i], 1, border_c);

            // colision to commands buttons 
            if (ray::CheckCollisionPointRec(mousepos, bnt_up[i]) && ray::IsMouseButtonPressed(ray::MOUSE_BUTTON_LEFT)){
                std::cout << "Command button pressed: " << textButtons[i + 3] << std::endl;
                if(textButtons[i + 3] == "Copy"){
                    ray::SetClipboardText("I love you, my Frank <3"); // bruh haha. Send it to me: franksteps.contato@gmail.com
                    messengerText = messenger(Messenger::Copied); 
                }else if(textButtons[i + 3] == "Clear"){
                    messengerText = messenger(Messenger::Cleared); 
                } else {
                    // nothing yet...
                }
            }
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

            // colision to arithmetic buttons -> logic to calculator here   
            if (ray::CheckCollisionPointRec(mousepos, button[i]) && ray::IsMouseButtonPressed(ray::MOUSE_BUTTON_LEFT)){
                std::cout << "Arithmetic button pressed: " << textButtons[i+6] << std::endl;


                // here 


            }
        }
        // junction 
        ray::DrawRectangleRec(Jury_rig, background_Alt);
        ray::DrawRectangleRec(Jury_rig_sh, shadow_c);
        ray::DrawRectangleRec(Jury_rig_br, ray::WHITE);
        ray::DrawRectangleLinesEx(Jury_rig, 1, border_c);

        // draw control buttons and command buttons text 
        for(int i = 0; i < 3; i++){
            ray::DrawTextEx(ms_sans, textButtons[i].c_str(), pos_textButtons[i], 17, 1, returnColor(buttonState[i]));
            ray::DrawTextEx(ms_sans, textButtons[i+3].c_str(), pos_textButtons[i+3], 17, 1, ray::BLACK); 
        }

        // draw arithmetic buttons text
        for(int i = 0; i < num_buttons; i++){
            ray::DrawTextEx(tahoma, textButtons[i+6].c_str(), pos_textButtons[i+6], 32, 1, ray::BLACK);
        }

        // control buttons colision 
        for(int i = 0; i < 3; i++){
            ray::DrawRectangleRec(controlButton[i], translucid);
            if(ray::CheckCollisionPointRec(mousepos, controlButton[i]) && ray::IsMouseButtonPressed(ray::MOUSE_BUTTON_LEFT)){
                bool buttonEnabled = buttonState[i] == ButtonState::Enabled;
                if(textButtons[i] == "Main" && buttonEnabled){
                    messengerText = messenger(Messenger::Void);
                    //
                } else if(textButtons[i] == "Settings" && buttonEnabled) {
                    messengerText = messenger(Messenger::Void);
                    //
                } else if(textButtons[i] == "About" && buttonEnabled) {
                    // Opens the "About" window for Neon Calc
                    messengerText = messenger(Messenger::Void);
                    if (fork() == 0) {
                        execl("./about", "./about", nullptr); // a beautiful code... 
                    }
                } else { 
                    messengerText = messenger(Messenger::Inactive);
                }
            }
        }
        // output
        ray::DrawRectangleLinesEx(output, 1, border_c);
        ray::DrawRectangleRec(output_sh, shadow_c);
        ray::DrawTextEx(ms_sans, messengerText.c_str(), pos_textButtons[22], 17, 1, ray::RED);
        ray::EndDrawing();
    }

    // end
    ray::UnloadImage(icon);
    ray::UnloadFont(ms_sans);
    ray::UnloadFont(tahoma);
    ray::CloseWindow();
    return EXIT_SUCCESS;
}