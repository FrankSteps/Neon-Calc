#include <iostream>
#include <string>

namespace ray {
    #include <raylib.h>
}

int main(){
    ray::InitWindow(300, 400, "Neon Calculator");
    bool show_button = false;

    ray::Image icon = ray::LoadImage("images/neon.png");
    ray::SetWindowIcon(icon); // 175 + 50 + 5 = 180 + 50 = 230

    //buttons
    ray::Rectangle button7 = {5, 120, 94, 50 };
    ray::Rectangle button8 = {105, 120, 94, 50 };
    ray::Rectangle button9 = {205, 120, 90, 50 };

    ray::Rectangle button6 = {5, 175, 94, 50 };
    ray::Rectangle button5 = {105, 175, 94, 50 };
    ray::Rectangle button4 = {205, 175, 90, 50 };

    ray::Rectangle button3 = {5, 230, 94, 50 };
    ray::Rectangle button2 = {105, 230, 94, 50 };
    ray::Rectangle button1 = {205, 230, 90, 50 };

    (void)button9;
    (void)button8;
    (void)button7;
    (void)button6;
    (void)button5;
    (void)button4;
    (void)button3;
    (void)button2;
    (void)button1;


    while(!ray::WindowShouldClose()){
        ray::BeginDrawing();
        ray::ClearBackground(ray::BLACK);

        // visor

        /* buttons
        ray::DrawRectangleRec(button9, ray::GRAY);
        ray::DrawRectangleRec(button8, ray::GRAY);
        ray::DrawRectangleRec(button7, ray::GRAY);
        ray::DrawRectangleRec(button6, ray::GRAY);
        ray::DrawRectangleRec(button5, ray::GRAY);
        ray::DrawRectangleRec(button4, ray::GRAY);
        ray::DrawRectangleRec(button9, ray::GRAY);
        ray::DrawRectangleRec(button3, ray::GRAY);
        ray::DrawRectangleRec(button2, ray::GRAY);
        ray::DrawRectangleRec(button1, ray::GRAY);
        */

        if (show_button == false) {
            show_button = true;
            for (int i = 0; i < 10; i++) {
                std::string result = "button" + std::to_string(i);
                std::cout << result << '\n';
            }  
        } 

        ray::EndDrawing();

    }

    // unloads
    ray::UnloadImage(icon);
    ray::CloseWindow();
    return EXIT_SUCCESS;
}
