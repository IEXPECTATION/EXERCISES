#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "info.h"

//judge the food position
int isexist(Food a_food, Snake *the_temp_snake);

//creatre the food and show the food at screen
Food showfood(Snake *the_snake_head)
{
	Food a_food;
	Snake *the_temp_snake;
	the_temp_snake = the_snake_head;
	do
	{
		srand((int)time(NULL));
		a_food.Food_Position_X = rand() % MAP_LENGTH_MAX;
		a_food.Food_Position_Y = rand() % MAP_WIDTH_MAX;
		if (a_food.Food_Position_X % 2 != 0)
		{
			a_food.Food_Position_X += 1;
		}
	} while (isexist(a_food, the_temp_snake));
	gotoxy(a_food.Food_Position_X, a_food.Food_Position_Y);
	printf("○");
	return a_food;
}

int isexist(Food a_food, Snake *the_temp_snake)
{
	while (the_temp_snake->ptr_to_the_next_body != NULL)
	{
		if (a_food.Food_Position_X == the_temp_snake->X || a_food.Food_Position_Y == the_temp_snake->Y || a_food.Food_Position_X == 0 || a_food.Food_Position_Y == 0 || a_food.Food_Position_X >= MAP_LENGTH_MAX || a_food.Food_Position_Y >= MAP_WIDTH_MAX)
		{
			return 1;
		}
		the_temp_snake = the_temp_snake->ptr_to_the_next_body;
	}
	return 0;
}