#include <iostream>

#include "Painter.h"
#include "Detrak.h"


int main()
{
    Board board;
    board.matrix[0][0] = firstSymbol();

    Painter painter;
    painter.drawGrid(board);

    //Do{
    Symbols symb1 = getRandomSymbol();
    Symbols symb2 = getRandomSymbol();
    std::cout << "You get " << symbolsToChar(symb1) << " and " << symbolsToChar(symb2) << std::endl;
    
    board.drawSymbols(symb1, symb2);
    painter.drawGrid(board);
    
    //}While(StopCondition)
    //Score
    return 0;
}
