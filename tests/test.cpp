#include <iostream>

int main(){
    // contar até 3, 4 vezes

    //contar total
    int num_row = 4;
    int column = 4;

    for(int i = 0; i < num_row; i++){
        for (int i = 0; i < column; i++){
            std::cout << i;
        }
        std::cout << '\n';
    }
    return 0;
}