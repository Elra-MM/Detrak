#include <iostream>
using namespace std;
#include "Painter.h"
#include "Detrak.h"


int main()
{
    Board board;
    board.matrix[0][0] = firstAnswer();

    Painter painter;
    painter.DrawGrid(board);
    return 0;
}
