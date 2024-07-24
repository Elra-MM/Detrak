#include <iostream>

#include "Painter.h"
#include "Detrak.h"


int main()
{
    Board board;
    board.matrix[0][0] = firstSymbol();

    Painter painter;
    painter.drawGrid(board);

    do
    {

    Symbols symb1 = getRandomSymbol();
    Symbols symb2 = getRandomSymbol();
    std::cout << "You get " << symbolsToChar(symb1) << " and " << symbolsToChar(symb2) << std::endl;
    
    board.drawSymbols(symb1, symb2);
    painter.drawGrid(board);
    
    }
    while(board.canTheGameContinue());

    std::cout << "The game ends here. You need to implement the score's code now ;)" << std::endl;
    //Score
    return 0;
}
