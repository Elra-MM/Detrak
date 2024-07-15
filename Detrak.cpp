// Detrak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Painter.h"
#include "Detrak.h"

const char symbols[6]{ 'A', 'B', 'C', 'D', 'E', 'F' };
int main()
{
    int const columns_count = 6;
    int const raws_count = 6;
    
    char matrix[raws_count][columns_count];
    matrix[0][0] = FirstAnswer();
    cout << "Matrix[0][0] = " << matrix[0][0] << endl;

    Painter painter = Painter();
    painter.DrawGrid();


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

