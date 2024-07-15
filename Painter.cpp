#include "Painter.h"
#include <iostream>
using namespace std;

void const Painter::DrawGrid(const char (&matrix)[6][6], const int raws_count, const int columns_count)
{
	for (int i = 0; i < raws_count; i++)
	{
		for (int j = 0; j < columns_count; j++)
		{
			cout << matrix[i][j];
		}
		cout << "\n";
	}
}