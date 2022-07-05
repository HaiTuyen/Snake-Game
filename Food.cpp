#include "Food.h"

int FoodCoordinate_RandomX()
{
	//return random integer
	srand(time(0));
	int a = rand() % (90 - 1 + 1) + 1;
	return a;
}

int FoodCoordinate_RandomY()
{
	//return random integer
	srand(time(0));
	int a = rand() % (28 - 1 + 1) + 1;
	return a;
}

Food Food_Generate(Snake &snake,Level &list)
{
	Food food;
	int x, y;

	//symbol of food
	food.symbol = '\3';

	//do this until we got a valid coordinate for our food
	do
	{
		//take 2 random intergers of coordinate
		x = FoodCoordinate_RandomX();
		y = FoodCoordinate_RandomY();

		//check if it is valid ?
		if (Food_ValidCoordinate_Check(x, y, snake,list))
		{
			food.x = x;
			food.y = y;
		}
	} while (!Food_ValidCoordinate_Check(x, y, snake,list));

	return food;
}




void Food_Drawing(Food const& food)
{
	//move the cursor to food.x and food.y then print it
	GotoXY(food.x, food.y);
	cout << food.symbol;
}

bool Food_ValidCoordinate_Check(int x, int y, Snake &snake, Level &list)
{
	bool valid = true;
	char a = 219;
	char b = 220;

	//check if it has same coordinate with snake's head <if not then continue to check each segment>
	if (x != snake.hx && y != snake.hy)
	{
		//loop through the segments
		for (int i = 0; i < snake.size; i++)
		{
			//if x and y have the same coordinate with any segment then bye bye :<
			if (x == snake.seg[i].x && y == snake.seg[i].y)
				valid = false;
			else if (list.level[y][x] == a || list.level[y][x] == b)
				valid = false;
		}
			
	}
	else //if x and coincides with head's coor then bye bye :<
		valid = false;

	return valid;
}

bool FoodStatus_Check(Food &food, Snake &snake)
{
	bool eaten = false;

	//if snake's head touch the food
	if (snake.hx == food.x && snake.hy == food.y)
	{
		eaten = true;
		snake.score += 10;
		Segment_Insert(snake); //increase size
	}
		
	return eaten;
}
