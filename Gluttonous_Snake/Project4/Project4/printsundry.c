#include <stdio.h>
#include "info.h"

#define Length 10

void printsundry(int x, int y, int gamerscroe)
{
	gotoxy(x * 2 + Length, (int)y / 2);
	printf("你的得分是：%d", gamerscroe);
}