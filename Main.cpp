#include <iostream>
using namespace std;
#include "Painter.h"
#include "Detrak.h"


int main()
{
    Board board;
    board.matrix[0][0] = firstAnswer();

    Painter painter;
    painter.drawGrid(board);

    int i = 0;
    while (i != 4)
    {
        //Symbols symb1 = getRandomSymbol();
        //Symbols symb2 = getRandomSymbol();
        //cout << "You get " << symbolsToChar(symb1) << " and " << symbolsToChar(symb2) << endl;
        i++;
    }
    
    return 0;
}
