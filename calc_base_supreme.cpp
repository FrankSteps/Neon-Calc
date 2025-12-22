/*
    Aqui se encontra o que se aproxima mais de uma calculadora de terminal funcional
*/

#include <iostream>
#include <vector>

namespace {
    #include <raylib.h>
}

// 2 + 3 - 7 + 2 = -2

int main(){
    std::vector<float> numbers;
    std::vector<char>  opertns;

    for(int i = 0; i < sizeof(numbers) + sizeof(opertns); i++){
        std::cout << numbers[i] << opertns[i];
    }

    return 0;
}