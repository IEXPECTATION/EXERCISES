#include <stdio.h>
#include "info.h"

void printmap(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		printf("■");
	}
	for (int j = 0; j < y; j++)
	{
		printf("■\n");
	}
	gotoxy(0, y);
	for (int i = 0; i < x + 1; i++)
	{
		printf("■");
	}
	gotoxy(x * 2, 0);
	for (int j = 0; j < y; j++)
	{
		gotoxy(x * 2, j);
		printf("■\n");
	}
}