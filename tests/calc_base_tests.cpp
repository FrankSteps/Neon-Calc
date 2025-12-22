#include <iostream>

float val1, val2;
char symbol; 

int main() {
    std::cout << "first value: ";
    std::cin >> val1;

    std::cout << "operation: ";
    std::cin >> symbol;

    std::cout << "second value: ";
    std::cin >> val2;

    switch (symbol) {
        case '+':
            std::cout << '\n' << val1 + val2 << '\n';
        break;
    
        case '-':
            std::cout << '\n' << val1 - val2 << '\n';
        break;

        case '*':
            std::cout << '\n' << val1 * val2 << '\n';
        break;

        case '/':
            if (!val2 == 0) {
                std::cout << '\n' << val1 / val2 << '\n';
            } else {
                std::cerr << '\n' << "error :: 001 :: Infinito" << '\n';
                return EXIT_FAILURE;
            }
        break;

        default:
            std::cerr << '\n' << "error :: 002 :: Parâmetros inválidos" << '\n';   
        break;
    }

    return EXIT_SUCCESS;
}
