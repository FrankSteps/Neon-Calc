#include <iostream>

int main(){
    // contar até 3, 4 vezes

    //contar total
    int num_buttons = 4;

    for(int i = 0; i < num_buttons; i++){
        for (int i = 0; i < 4; i++){
            std::cout << i;
        }
        std::cout << '\n';
    }
    return 0;
}