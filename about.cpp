/*
	"about" window for NeonCalc

	Neon Calculator 

	|description|
		This simple calculator was developed as a demonstration 
		of C++ with Raylib. The interface is inspired by classic 
		Windows design. 
	|version| 1.0.0
	|credits| 
		e-mail: contato@franksteps.com 
		github: github.com/franksteps
	
	developed by: Francisco Passos (FrankSteps) | 2025
*/

#include <iostream>
#include <string>
#include <vector>

namespace ray {
	#include <raylib.h>
}

// define colors
ray::Color background      = {224, 224, 224, 255};  
ray::Color background_Alt  = {240, 240, 240, 255}; 
ray::Color border_c        = {0, 0, 0, 155};  
ray::Color shadow_c        = {148, 148, 148, 70}; 
ray::Color bright_c        = ray::WHITE;
ray::Color inactive        = {0, 0, 0, 70};
ray::Color active          = ray::BLACK;
ray::Color translucid      = {0, 0, 0, 0};

int main(){
	ray::SetTraceLogLevel(ray::LOG_NONE);
	ray::InitWindow(310, 370, "About");

	// fonts
    ray::Font ms_sans = ray::LoadFont("fonts/ms-sans-serif.otf");
    ray::Font tahoma = ray::LoadFont("fonts/tahomabd.ttf");

    // background 
    ray::Rectangle det = {10, 10, 290, 300};
    ray::Rectangle bac = {10, 70, 290, 240};
    ray::Rectangle ico = {15, 15, 50, 50};

    // generate button 
    ray::Rectangle okButton    = {105, 322, 100, 36};
    ray::Rectangle okButton_sh = {105, 322 + 32, 100, 4};
    ray::Rectangle okButton_br = {105, 322, 100, 4};

	while(!ray::WindowShouldClose()){
		ray::Vector2 mousepos = ray::GetMousePosition();

		ray::BeginDrawing();
        ray::ClearBackground(background);
        ray::DrawRectangleRec(bac, background_Alt);
        ray::DrawRectangleLinesEx(det, 1, border_c);


        // title
        ray::DrawRectangleLinesEx(ico, 1, border_c);
        ray::DrawTextEx(tahoma, "Neon Calculator", ray::Vector2{70, 25}, 32, 1, ray::BLACK);

        // description 
        ray::DrawTextEx(ms_sans, "This simple calculator was developed as a ", ray::Vector2{15, 75}, 15, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "demonstration of C++  with Raylib. The in- ", ray::Vector2{15, 92}, 15, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "terface in  inspired by classic Windows 95.", ray::Vector2{15, 108}, 15, 1, ray::BLACK);

        // version
        ray::DrawTextEx(tahoma, "Version:", ray::Vector2{15, 140}, 17, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "1.0.0", ray::Vector2{90, 142}, 15, 1, ray::BLACK);


        // credits
        ray::DrawTextEx(tahoma, "Credits:",  ray::Vector2{15, 170}, 15, 1, ray::BLACK);

        ray::DrawTextEx(ms_sans, "e-mail: ", ray::Vector2{30, 190}, 15, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "contato@franksteps.com.br", ray::Vector2{90, 190}, 15, 1, ray::BLUE);

        ray::DrawTextEx(ms_sans, "github: ", ray::Vector2{30, 205}, 15, 1, ray::BLACK);
        ray::DrawTextEx(ms_sans, "https://github.com/franksteps", ray::Vector2{90, 205}, 15, 1, ray::BLUE);

        // footer
        ray::DrawTextEx(ms_sans, "Developed by: Frank Steps | 2025", ray::Vector2{15, 290}, 15, 1, ray::BLACK);


        // render button with text
        ray::DrawRectangleRec(okButton,     background_Alt);
        ray::DrawRectangleRec(okButton_sh,  shadow_c);
        ray::DrawRectangleRec(okButton_br,  bright_c);
        ray::DrawRectangleLinesEx(okButton, 1, border_c);
        ray::DrawTextEx(ms_sans, "Ok", ray::Vector2{142, 331}, 20, 1, active);

        if(ray::CheckCollisionPointRec(mousepos, okButton) && ray::IsMouseButtonPressed(ray::MOUSE_BUTTON_LEFT)){
        	return EXIT_SUCCESS;
        }
        ray::EndDrawing();
	}

	// unloads and close window 
	ray::CloseWindow();
	return EXIT_SUCCESS;
}