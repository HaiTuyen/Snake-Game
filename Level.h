#pragma once


#include <vector>
#include <string>
#include <fstream>

#include "System.h"
#include "Snake.h"

#define MAX_LEVEL 5
#define HEIGHT 30
#define WIDTH 120

using namespace std;

struct Level
{
	vector <string> level;
};

void InitLevel(string text, Level& list);
void DrawLevel(Level& list, Snake& snake);
int CheckLevel(Snake& snake);
void CheckCollision(Snake& snake, Level& list);
void DrawScreen(Level& screen);
void get_time(Snake& snake);
void titleSnake(int x, int y);
void titleGame(int x, int y);
void title(int x, int y);
void border(int x, int y, int startX, int startY);
void GameLoading();
void Draw_StartScreen();
int DrawMenu();