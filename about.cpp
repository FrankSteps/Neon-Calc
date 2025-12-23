/*
	"about" window for NeonCalc

	info:
	NeonCalc:
	Developed by:

*/

#include <iostream>
#include <string>
#include <vector>

namespace ray {
	#include <raylib.h>
}

int main(){
	ray::SetTraceLogLevel(ray::LOG_NONE);
	ray::InitWindow(310, 370, "About");
	while(!ray::WindowShouldClose()){
		ray::BeginDrawing();
        ray::ClearBackground(ray::BLACK);
        ray::EndDrawing();
	}

	// unloads and close window 
	ray::CloseWindow();
	return 0;
}