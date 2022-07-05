#pragma comment(lib, "winmm.lib")
#include <cstdio>
#include <stdio.h>
#include "Snake.h"
#include "System.h"
#include "Food.h"
#include "Level.h"
#include "windows.h"
#include "Gate.h"
#include "SaveLoad.h"
#include "HighScore.h"

int nScreenWidth = 120;
int nScreenHeight = 30;
using namespace std;

int main()
{
	FixConsoleWindow();
	ShowCur(0);
	Snake snake;
	Food food;
	Level myLevelList;
	Level ending;
	Level begin;
	Level levelUp;

	Level blank;
	Gate* pGate = nullptr;
	Level last;	int foodx, foody;
	Highscore highscore[5];
	ListName listname[20];
	Draw_StartScreen();

Reset:
	InitLevel("LevelUp.txt", levelUp);
	system("cls");
	bool gateOn = 0;
	short count = 0;
	char st;
	
	char name[50];
	char a;

	Score_Initialize(highscore);
	initListname(listname);
	Snake_Initialize(snake);
	InitLevel("MyList.txt", myLevelList);
	InitLevel("Ending.txt", ending);
	InitLevel("Starting.txt", begin);
	InitLevel("Starting.txt", blank);
	InitLevel("Won.txt", last);
	

	int choice = DrawMenu();
	
		switch (choice)
		{
		case 1:

			food = Food_Generate(snake, myLevelList);
			foodx = food.x;
			foody = food.y;

			while (1)
			{
			Run:
				if (!gateOn)
				{
					color(9 + count);
					DrawLevel(myLevelList, snake);
					get_time(snake);
					color(15);
				}
				
				short oldx = snake.seg[snake.size - 1].x;
				short oldy = snake.seg[snake.size - 1].y;

				Snake_Moving(snake, foodx, foody, listname);
				CheckCollision(snake, myLevelList);
				Snake_TouchingBody_Check(snake);
				
				if (!snake.alive)
				{
					PlaySound(TEXT("gameover.wav"), NULL, SND_ASYNC);
					CheckHighScore(highscore, snake.score, snake);
					int color1 = 11 + CheckLevel(snake);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
					DrawScreen(ending);
					color(15);
					a = _getch();

					if (a == 'y' || a == 'Y')
						goto Reset;
					else
						return 0;

				}
				

				if (snake.score == 200)
				{
					CheckHighScore(highscore, snake.score, snake);
					int color1 = 11 + CheckLevel(snake);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
					DrawScreen(last);
					color(15);

					a = _getch();
					if (a == 'y' || a == 'Y')
						goto Reset;
					else
						return 0;
				}

				if (FoodStatus_Check(food, snake))
				{
					food = Food_Generate(snake, myLevelList);
					foodx = food.x;
					foody = food.y;
					PlaySound(TEXT("eat1.wav"), NULL, SND_ASYNC);

					if (snake.score == 40 || snake.score == 80 || snake.score == 120 || snake.score == 160)
					{
						//pGate = new Gate;
						pGate = (Gate*)malloc(sizeof(Gate));
						if (pGate != NULL)
						{
							InitGate(food, pGate);
							st = 'i';
							gateOn = 1;
							PlaySound(TEXT("lvup.wav"), NULL, SND_ASYNC);
							count++;
						}
					}

				}

				if (gateOn)
				{
					DrawLevel(myLevelList, snake);
					get_time(snake);
					Gate_Drawing(pGate, st);
					TouchingGate_Check(snake, pGate);

					if (PassingGate_Check(snake, pGate))
					{
						Gate_Delete(pGate);
						InitGate(food, pGate);
						st = 'o';

						Gate_Drawing(pGate, st);
						snake.hx = (int64_t)(*pGate).x + 1;
						snake.hy = (*pGate).y;
						Segment_Update(snake);
					}

					if (snake.seg[snake.size - 1].x == (*pGate).x + 1 && snake.seg[snake.size - 1].y == (*pGate).y)
					{
						Gate_Delete(pGate);	
						std::free(pGate); 
						pGate = NULL;
						gateOn = 0;
					}
				}
				else
				{
					int color1 = 11 + CheckLevel(snake);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
					Food_Drawing(food);
					color(15);
				}
					
				int color1 = 11 + CheckLevel(snake);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
				//print snake snake's head coordinate on console window
				GotoXY(109, 6);
				std::cout << "<" << snake.hx << "," << snake.hy << ">";
				//print the score player gained on console winoow
				GotoXY(109, 4);
				std::cout << snake.score;
				color(15);

				Snake_Drawing(snake);
				//delete snake tail	
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
				GotoXY(oldx, oldy);
				std::cout << " ";
				color(15);

				if (snake.alive == false)
				{
					color(13);
					Snake_Drawing(snake);
					Sleep(300);
				}
				//the snake seems to be faster when level is up
				Sleep(80 - CheckLevel(snake) * 5);
			}

			std::free(pGate);
			std::free(snake.seg);
			break;

		case 2:
			
			color(15);
			DrawScreen(blank);
			ShowListname(listname);
			
			GotoXY(25, 18);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			std::cout << "Enter your loadfile's name (ending with .txt): ";

			//GotoXY(20, 17);
			std::cin >> name;
			color(15);
			food.symbol = '\3';
			food = Food{ 6, 6, 0, food.symbol };
			count = CheckLevel(snake) +1;

			LoadGame(name, snake, food);
			foodx = food.x;
			foody = food.y; 

			goto Run;
			break;


		case 3: 
			DrawScreen(blank);
			color(15);
			Score_Printer(highscore);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			GotoXY(47, 15);
			std::cout << "PRESS Y TO RETURN TO MENU";
			color(15);
			a = _getch();

			if (a == 'y' || a == 'Y')
				goto Reset;
			else
				return 0;
			
			break;


		case 4:
			GotoXY(0, 31);
			color(15);
			break;
		}

	return 0;
}
