#include "Painter.h"
#include <iostream>
using namespace std;



void const Painter::DrawGrid() 
{
	for (int i = 0; i < Painter::raws_count; i++)
	{
		for (int j = 0; j < Painter::columns_count; j++)
		{
			cout << "I ";
		}
		cout << "\n";
	}
}