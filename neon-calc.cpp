#include <iostream>

float val1, val2;
char simbol; 

int main() {
    std::cout << "first value: ";
    std::cin >> val1;

    std::cout << "second value: ";
    std::cin >> val2;

    std::cout << "operation: ";
    std::cin >> simbol;

    switch (simbol) {
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
                std::cout << '\n' << val1 + val2 << '\n';
            } else {
                std::cout << '\n' << "error" << '\n';
                return EXIT_FAILURE;
            }
        break;

        default:
            std::cout << '\n' << "error" << '\n';   
        break;
    }
}
