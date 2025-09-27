/*
    linha 1: 162          coluna1: 36
    linha 2: 230          coluna2: 110
    linha 3: 298   +3     coluna3: 184  


        +74  +74  +74
    162: 36, 110, 184
    230: 36, 110, 184 +68
    298: 36, 110, 184 +68

*/

#include <iostream>
#include <vector>

std::vector<int> row_v;
std::vector<int> col_v;

int main() {
    int row_p = 162;
    int col_p = 36;

    for(int row = 0; row < 3; row++){
        col_p = 36;
        row_v.push_back(row_p); 
        std::cout << row_p << ": ";
        for(int col = 0; col < 3; col++){
            col_v.push_back(col_p);
            std::cout << col_p;
            std::cout << " ";
            col_p = col_p + 74;
        }
        row_p = row_p + 68; 
        std::cout << "\n";
    }
    return 0;
}
