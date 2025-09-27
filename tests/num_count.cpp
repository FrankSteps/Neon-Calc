#include <iostream>

int main(){
    for(int row = 2; row >= 0; row--) { 
        int base = row * 3;
        for(int column = 1; column <= 3; column++) {
            std::cout << base + column;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "0";
    return 0;
}