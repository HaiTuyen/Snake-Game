#pragma once
#include "System.h"
#include "Snake.h"
#include "Level.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Food
{
	int x;
	int y;
	bool eaten;
	char symbol;
};


Food Food_Generate(Snake& snake,Level &list);   //initialize food's data 
void Food_Drawing(Food const& food); //draw food on the screen
int FoodCoordinate_RandomX();                //return random integer <is used to creat food's coordinate>
int FoodCoordinate_RandomY();

bool Food_ValidCoordinate_Check(int x, int y, Snake &snake, Level &list);  //<make sure the food is not at the same place with snake's head and its body>
bool FoodStatus_Check(Food& food, Snake& snake);        //check if the food is eaten yet ? if it is eaten then create a new one
