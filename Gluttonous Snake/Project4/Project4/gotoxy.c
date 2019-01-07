#include <Windows.h>
#include "info.h"

void gotoxy(int x, int y)
{
	COORD ipos;
	ipos.X = x;
	ipos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ipos);
}