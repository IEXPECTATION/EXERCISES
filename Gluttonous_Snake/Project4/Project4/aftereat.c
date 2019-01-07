#include <stdio.h>
#include <stdlib.h>
#include "info.h"

void aftereat(Snake **the_snake_head)
{
	Snake *the_temp_snake, *the_scp_snake;
	the_scp_snake = (*the_snake_head)->ptr_to_the_next_body;
	the_temp_snake = (Snake *)malloc(sizeof(Snake));
	
	//initilize
	the_temp_snake->X = (*the_snake_head)->X;
	the_temp_snake->Y = (*the_snake_head)->Y;
	the_temp_snake->dire = '\0';

	switch ((*the_snake_head)->dire)
	{
	case UP:
		(*the_snake_head)->Y--;
		gotoxy((*the_snake_head)->X, (*the_snake_head)->Y);
		printf("¡ö");
		(*the_snake_head)->ptr_to_the_next_body = the_temp_snake;
		break;
	case DOWN:
		(*the_snake_head)->Y++;
		gotoxy((*the_snake_head)->X, (*the_snake_head)->Y);
		printf("¡ö");
		(*the_snake_head)->ptr_to_the_next_body = the_temp_snake;
		break;
	case LEFT:
		(*the_snake_head)->X -= 2;
		gotoxy((*the_snake_head)->X, (*the_snake_head)->Y);
		printf("¡ö");
		(*the_snake_head)->ptr_to_the_next_body = the_temp_snake;
		break;
	case RIGTH:
		(*the_snake_head)->X += 2;
		gotoxy((*the_snake_head)->X, (*the_snake_head)->Y);
		printf("¡ö");
		(*the_snake_head)->ptr_to_the_next_body = the_temp_snake;
		break;
	default:
		break;
	}
	the_temp_snake->ptr_to_the_next_body = the_scp_snake;
}