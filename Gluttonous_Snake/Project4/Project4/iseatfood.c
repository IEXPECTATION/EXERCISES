#include <stdio.h>
#include "info.h"

int iseatfood(Food food_pos, Snake *the_snake_head)
{
	if (the_snake_head->X == food_pos.Food_Position_X && the_snake_head->Y == food_pos.Food_Position_Y)
	{
		return 1;
	}
	return 0;
}