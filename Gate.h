#pragma once

#pragma once
#include "System.h"
#include "Snake.h"
#include "Food.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

struct Gate
{
	int x; //should we change it to short, less byte
	int y;
};

int GateCoordinate_RandomX();
int GateCoordinate_RandomY();
void InitGate(Food const& food, Gate*& pGate);
void Gate_Drawing(Gate*& pGate, char st);
void TouchingGate_Check(Snake& snake, Gate* const pGate);
bool PassingGate_Check(Snake const& snake, Gate* pGate);
void Gate_Delete(Gate* pGate);
