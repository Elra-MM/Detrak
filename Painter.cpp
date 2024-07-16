#include "Painter.h"
#include "Detrak.h"
#include <iostream>
using namespace std;

void Painter::DrawGrid(const Board& Board) const
{
	for (auto& row : Board.matrix)
	{
		for (auto& symb : row)
		{
			cout << symbolsToChar(symb);
		}
		cout << "\n";
	}
}