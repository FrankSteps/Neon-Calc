#include <iostream>

int main() {
    for(int i = 1; i <= 9; i++){
        std::cout << i; 
        if(i % 3 == 0) { 
            std::cout << '\n';
        }
    }
    return 0;
}
