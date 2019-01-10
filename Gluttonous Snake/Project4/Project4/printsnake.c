#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "info.h"

Snake *the_snake_head;
Snake *the_snake_tail;
Food food_pos;
int gamerscore;

void printsnake(void)
{
	Snake *the_curr_snake, *the_temp_snake, *the_end_snake, * the_scp_snake;
	int X, Y;
	int Temp_X, Temp_Y;	//save previous snake

	printsundry(MAP_LENGTH_MAX, MAP_WIDTH_MAX, gamerscore);
	//initiaze the snake
	the_curr_snake = (Snake *)malloc(sizeof(Snake));
	the_snake_head = the_curr_snake;
	//set the default direction of snake
	the_curr_snake->dire = RIGTH;
	the_curr_snake->X = MAP_LENGTH_MAX / 2;
	the_curr_snake->Y = (int)MAP_WIDTH_MAX / 2;
	gotoxy(the_curr_snake->X, the_curr_snake->Y);
	printf("■");
	for (int i = 0; i < 2; i++)
	{
		the_end_snake = (Snake *)malloc(sizeof(Snake));
		the_snake_tail = the_end_snake;
		the_end_snake->dire = '\0';
		the_end_snake->X = the_curr_snake->X - 2;
		the_end_snake->Y = the_curr_snake->Y;
		gotoxy(the_end_snake->X, the_end_snake->Y);
		printf("■");
		the_curr_snake->ptr_to_the_next_body = the_end_snake;
		the_curr_snake = the_end_snake;
		the_curr_snake->ptr_to_the_next_body = NULL;
	}

	//show the food
	food_pos = showfood(the_snake_head);

	while(1)
	{
		char _dire = '\0';
		if (_kbhit())
		{
			_dire = _getch();
			switch (_dire)
			{
			case UP:
				if (the_snake_head->dire == DOWN)
				{
					break;
				}
				the_snake_head->dire = _dire;
				break;
			case DOWN:
				if (the_snake_head->dire == UP)
				{
					break;
				}
				the_snake_head->dire = _dire;
				break;
			case LEFT:
				if (the_snake_head->dire == RIGTH)
				{
					break;
				}
				the_snake_head->dire = _dire;
				break;
			case RIGTH:
				if (the_snake_head->dire == LEFT)
				{
					break;
				}
				the_snake_head->dire = _dire;
				break;
			default:
				break;
			}
		}
		switch (the_snake_head->dire)
		{
		case UP:
			gotoxy(the_snake_tail->X, the_snake_tail->Y);
			printf("  ");

			//save the previous snake body position and copy to the next snake body
			the_temp_snake = the_snake_head;
			the_scp_snake = the_snake_head;
			X = the_temp_snake->X;
			Y = the_temp_snake->Y;
			while (the_temp_snake->ptr_to_the_next_body != NULL)
			{
				the_scp_snake = the_scp_snake->ptr_to_the_next_body;
				Temp_X = the_scp_snake->X;
				Temp_Y = the_scp_snake->Y;
				the_temp_snake = the_temp_snake->ptr_to_the_next_body;
				the_temp_snake->X = X;
				the_temp_snake->Y = Y;
				X = Temp_X;
				Y = Temp_Y;
			}

			the_snake_head->Y--;
			gotoxy(the_snake_head->X, the_snake_head->Y);
			printf("■");
			break;
		case DOWN:
			gotoxy(the_snake_tail->X, the_snake_tail->Y);
			printf("  ");

			//save the previous snake body position and copy to the next snake body
			the_temp_snake = the_snake_head;
			the_scp_snake = the_snake_head;
			X = the_temp_snake->X;
			Y = the_temp_snake->Y;
			while (the_temp_snake->ptr_to_the_next_body != NULL)
			{
				the_scp_snake = the_scp_snake->ptr_to_the_next_body;
				Temp_X = the_scp_snake->X;
				Temp_Y = the_scp_snake->Y;
				the_temp_snake = the_temp_snake->ptr_to_the_next_body;
				the_temp_snake->X = X;
				the_temp_snake->Y = Y;
				X = Temp_X;
				Y = Temp_Y;
			}

			the_snake_head->Y++;
			gotoxy(the_snake_head->X, the_snake_head->Y);
			printf("■");
			break;
		case LEFT:
			gotoxy(the_snake_tail->X, the_snake_tail->Y);
			printf("  ");

			//save the previous snake body position and copy to the next snake body

			the_temp_snake = the_snake_head;
			the_scp_snake = the_snake_head;
			X = the_temp_snake->X;
			Y = the_temp_snake->Y;
			while (the_temp_snake->ptr_to_the_next_body != NULL)
			{
				the_scp_snake = the_scp_snake->ptr_to_the_next_body;
				Temp_X = the_scp_snake->X;
				Temp_Y = the_scp_snake->Y;
				the_temp_snake = the_temp_snake->ptr_to_the_next_body;
				the_temp_snake->X = X;
				the_temp_snake->Y = Y;
				X = Temp_X;
				Y = Temp_Y;
			}

			the_snake_head->X -= 2;
			gotoxy(the_snake_head->X, the_snake_head->Y);
			printf("■");
			break;
		case RIGTH:

			gotoxy(the_snake_tail->X, the_snake_tail->Y);
			printf("  ");

			//save the previous snake body position and copy to the next snake body
			the_temp_snake = the_snake_head;
			the_scp_snake = the_snake_head;
			X = the_temp_snake->X;
			Y = the_temp_snake->Y;
			while (the_temp_snake->ptr_to_the_next_body != NULL)
			{
				the_scp_snake = the_scp_snake->ptr_to_the_next_body;
				Temp_X = the_scp_snake->X;
				Temp_Y = the_scp_snake->Y;
				the_temp_snake = the_temp_snake->ptr_to_the_next_body;
				the_temp_snake->X = X;
				the_temp_snake->Y = Y;
				X = Temp_X;
				Y = Temp_Y;
			}
			
			the_snake_head->X += 2;
			gotoxy(the_snake_head->X, the_snake_head->Y);
			printf("■");
			break;
		default:
			break;
		}
		fflush(stdin);
		Sleep(300);
		if (islive(the_snake_head))
		{
			if (iseatfood(food_pos, the_snake_head))
			{
				food_pos = showfood(the_snake_head);
				aftereat(&the_snake_head);
				gamerscore++;
				printsundry(MAP_LENGTH_MAX, MAP_WIDTH_MAX, gamerscore);
				if (gamerscore == 1092)
				{
					gotoxy(MAP_LENGTH_MAX - 15, MAP_WIDTH_MAX / 2);
					printf("恭喜您通关，任意键退出游戏。");
					break;
				}
			}
		}
		else
		{
			gotoxy(MAP_LENGTH_MAX - 15, MAP_WIDTH_MAX / 2);
			printf("game over. 请按任意键退出");
			break;
		}
	}
	
}