// Detrak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Painter.h"
#include "Detrak.h"

//I don't know where and how to put it and make it work
const char symbols[6]{ 'A', 'B', 'C', 'D', 'E', 'F' }; 
int main()
{
    int const columns_count = 6;
    int const raws_count = 6;
    
    char matrix[raws_count][columns_count];
    InitMatrix(matrix, raws_count, columns_count);
    
    matrix[0][0] = FirstAnswer();
    
    Painter painter = Painter();
    painter.DrawGrid(matrix, raws_count, columns_count);


}

void InitMatrix(char(&matrix)[6][6], const int raws_count, const int columns_count) {
    for (int i = 0; i < raws_count; i++)
    {
        for (int j = 0; j < columns_count; j++)
        {
            matrix[i][j] = '_';
        }
    }
}

char FirstAnswer() {
    cout << "Choose your first symbol within { 'A', 'B', 'C', 'D', 'E', 'F' }" << endl;
    char firstAnswer;
    std::cin >> firstAnswer;

    if (std::find(begin(symbols), end(symbols), firstAnswer) != std::end(symbols))
        return firstAnswer;
    else
        return FirstAnswer();
}

