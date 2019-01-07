#include <stdio.h>
#include "info.h"

int islive(Snake *the_snake_head)
{
	Snake *the_temp_snake, *the_curr_snake_head;
	the_temp_snake = the_curr_snake_head = the_snake_head;
	if (the_temp_snake->X == 0 || the_temp_snake->Y == 0 || the_temp_snake->X == MAP_LENGTH_MAX * 2 || the_temp_snake->Y == MAP_WIDTH_MAX)
	{
		return 0;
	}
	the_temp_snake = the_snake_head->ptr_to_the_next_body;
	while (the_temp_snake->ptr_to_the_next_body != NULL)
	{
		if (the_curr_snake_head->X == the_temp_snake->X && the_curr_snake_head->Y == the_temp_snake->Y)
		{
			return 0;
		}
		the_temp_snake = the_temp_snake->ptr_to_the_next_body;
	}
	return 1;
}