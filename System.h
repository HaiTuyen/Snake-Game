#pragma once
//contains functions to deal with graphic on console <or functions in the instruction>
#define MAX_LENGTH 32
#define enter  13
#define ESD 187
#define ESI 201
#define EID 188
#define EII 200
#define HOR 205
#define VER 186
#define FULL 219
#define EMPTY 32

const char symbolArr[MAX_LENGTH] = {'2','1','1','2','7','0','5','4',
									'2','1','1','2','7','0','6','8', 
									'2','1','1','2','7','4','1','4', 
									'2','1','1','2','7','4','7','4',};
void GotoXY(int x, int y);
void FixConsoleWindow();
void color(int color);
void ShowCur(bool CursorVisibility);
void HideCursor();
void BackColor();