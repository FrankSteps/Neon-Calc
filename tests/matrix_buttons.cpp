#include <iostream>
#include <string>

/*
            10 - 20 - 30 - 40
    1° 100 
    2° 300 
*/

std::string matrix[2][4] = {
    {"1", "2", "3", "4"},
    {"5", "6", "7", "8"}
};

float button_pos_x[4] = {10.0f, 20.0f, 30.0f, 40.0f};
float button_pos_y[2] = {100.0f, 200.0f};

int main(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            std::cout << matrix[i][j] << " ";
            std::cout << " - " << button_pos_x[j] << "," << button_pos_y[i] << " - ";
        }
        std::cout << std::endl;
    }
    return 0;
}