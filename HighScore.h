#pragma once
#pragma warning (disable: 4996)
#include <fstream>
#include <string>

#include "Snake.h"
#include "Food.h"
using namespace std;

struct Highscore
{
	int score;
	char name[30];
};
void ScoreSaving(Highscore highscore[]);
void Score_Initialize(Highscore highscore[]);
void CheckHighScore(Highscore highscore[], int score, Snake snake);
void Score_Printer(Highscore highscore[]);