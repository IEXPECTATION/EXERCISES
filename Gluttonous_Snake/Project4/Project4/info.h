//macros
#define MAP_LENGTH_MAX 40
#define	MAP_WIDTH_MAX 29

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGTH 'd'

//structure
typedef struct MySnake
{
	char dire;
	int X, Y;
	struct MySnake *ptr_to_the_next_body;
}Snake;

typedef struct Food_Position
{
	int Food_Position_X;
	int Food_Position_Y;
}Food;

//func

//move the cursor
void gotoxy(int x, int y);

//print the game map
void printmap(int x, int y);

//print the sundry
void printsundry(int x, int y, int gamerscore);

//print the snake
void printsnake(void);

//judge that the snake is live or not
int islive(Snake *the_snake_head);

//show the food
Food showfood(Snake *the_snake_head);

//judge the snake eat the food or not
int iseatfood(Food food_pos, Snake *the_snake_head);

//exetcute the something after the snake eat the food
void aftereat(Snake **the_snake_head);















//TODO:判断蛇是否吃了食物
