#include "Gate.h"
#include "system.h"

//random coordinate x of gate
int GateCoordinate_RandomX()
{
	int x = 1;
	srand(time(0));
	int r = rand() % 2 + 1;

	if (r == 1)
		x = rand() % 3 + 2;
	else
		x = 95 - (rand() % 20);
	return x;
}

//random coordinate y of gate
int GateCoordinate_RandomY()
{
	int y = 1;
	srand(time(0));
	int r = rand() % 2 + 1;
	r = 2;
	if (r == 1)
		y = rand() % 10 + 5;
	else
		y = 15 - (rand() % 9 + 6);
	return y;
}

void InitGate(Food const& food, Gate*& pGate)
{
	(*pGate).x = GateCoordinate_RandomX();
	(*pGate).y = GateCoordinate_RandomY();

	if ((*pGate).x == food.x && (*pGate).y == food.y)
	{
		(*pGate).x = rand() % 20;
		(*pGate).y = rand() % 15;
	}
}

void Gate_Drawing(Gate*& pGate, char st)
{
	color(102);
	if (pGate != NULL)
	{
		for (int i = 0; i <= 2; i++)
		{
			GotoXY((*pGate).x + i, (*pGate).y);
			cout << "*";
			GotoXY((*pGate).x + i, (*pGate).y + 1);
			cout << "*";
		}
		color(15);
		if (st == 'i')
		{
			GotoXY((*pGate).x + 1, (*pGate).y + 1);
			cout << " ";
		}
		else
		{
			GotoXY((*pGate).x + 1, (*pGate).y);
			cout << " ";
		}
	}
}

void TouchingGate_Check(Snake& snake, Gate* const pGate)
{
	if (snake.hy == (int64_t)(*pGate).y + 1 && snake.hx == (*pGate).x || snake.hy == (int64_t)(*pGate).y + 1 && snake.hx == (int64_t)(*pGate).x + 2)
		snake.alive = false;
	for (int i = 0; i <= 2; i++)
		if (snake.hy == (*pGate).y && snake.hx == (int64_t)(*pGate).x + i)
			snake.alive = false;
}

bool PassingGate_Check(Snake const& snake, Gate* pGate)
{
	bool success = false;
	if (snake.hx == (int64_t)(*pGate).x + 1 && snake.hy == (int64_t)(*pGate).y + 1)
		success = true;
	return success;
}

void Gate_Delete(Gate* pGate)
{
	for (int i = 0; i <= 2; i++)
	{
		GotoXY((*pGate).x + i, (*pGate).y);
		cout << " ";
		GotoXY((*pGate).x + i, (*pGate).y + 1);
		cout << " ";
	}
}