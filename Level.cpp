#include "Level.h"



void InitLevel(string text, Level &list)
{
	ifstream file(text);

	if (!file.fail())
	{
		string line;

		while (getline(file, line))
			list.level.push_back(line);
	}



	char symbol_1 = 220;
	char symbol_2 = 219;
	char symbol_3 = 176;

	for (int i = 0; i < list.level.size(); i++)
	{
		for (int j = 0; j < list.level[i].size(); j++)
		{
			if (list.level[i][j] == '1')
				list.level[i][j] = symbol_1;
			else if (list.level[i][j] == '2')
		 		list.level[i][j] = symbol_2;
			else if (list.level[i][j] == '3')
				list.level[i][j] = symbol_3;
		}
	}

	file.close();

}

int CheckLevel(Snake& snake)
{
	//return the number of level based on snake's score 
	//0 - Level 1, 1 - Level 2 ....
	if (snake.score >= 0 && snake.score < 40)
		return 0;
	else if (snake.score >= 40 && snake.score < 80)
		return 1;
	else if (snake.score >= 80 && snake.score < 120)
		return 2;
	else if (snake.score >= 120 && snake.score < 160)
		return 3;
	else
		return 4;
}

void DrawLevel(Level& list, Snake& snake)
{
	int level = CheckLevel(snake);
	int score[5] = {0,40,80,120,160};
	static int counter = 0;
	char a;



	if (!snake.alive)
		counter = 0;

	if (snake.score % 40 == 0 && snake.score != score[counter])
		counter++;

	int color1 = 11 + CheckLevel(snake);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	for (int i = level * HEIGHT; i < level * HEIGHT + HEIGHT; i++)
	{
		//
		GotoXY(0, i - level * HEIGHT);
		printf("%s", list.level[i].c_str());

	}
	color(15);
}

void CheckCollision(Snake& snake, Level& list)
{
	char a = 219;
	char b = 220;

	//if snake's head coordinate is the same coordinate with character 219 or 220 then collision happens
	if (list.level[snake.hy][snake.hx] == a || list.level[snake.hy][snake.hx] == b)
	{
		snake.alive = false; //die
	}
		
}


void DrawScreen(Level& screen)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		GotoXY(0, i);                          
		printf("%s", screen.level[i].c_str()); //faster than cout
	}
	cout << endl;
}


void titleSnake(int x, int y) 
{
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, FULL, FULL, FULL, FULL, FULL, FULL, FULL, ESD, FULL, FULL, FULL, ESD, EMPTY, EMPTY, EMPTY, FULL, FULL, ESD, EMPTY, FULL, FULL, FULL, FULL, FULL, ESD, EMPTY, FULL, FULL, ESD, EMPTY, EMPTY, FULL, FULL, ESD, FULL, FULL, FULL, FULL, FULL, FULL, FULL, ESD);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, FULL, FULL, ESI, HOR, HOR, HOR, HOR, EID, FULL, FULL, FULL, FULL, ESD, EMPTY, EMPTY, FULL, FULL, VER, FULL, FULL, ESI, HOR, HOR, FULL, FULL, ESD, FULL, FULL, VER, EMPTY, FULL, FULL, ESI, EID, FULL, FULL, ESI, HOR, HOR, HOR, HOR, EID);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, FULL, FULL, FULL, FULL, FULL, FULL, FULL, ESD, FULL, FULL, ESI, FULL, FULL, ESD, EMPTY, FULL, FULL, VER, FULL, FULL, FULL, FULL, FULL, FULL, FULL, VER, FULL, FULL, FULL, FULL, FULL, ESI, EID, EMPTY, FULL, FULL, FULL, FULL, FULL, ESD, EMPTY, EMPTY);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, EII, HOR, HOR, HOR, HOR, FULL, FULL, VER, FULL, FULL, VER, EII, FULL, FULL, ESD, FULL, FULL, VER, FULL, FULL, ESI, HOR, HOR, FULL, FULL, VER, FULL, FULL, ESI, HOR, FULL, FULL, ESD, EMPTY, FULL, FULL, ESI, HOR, HOR, EID, EMPTY, EMPTY);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, FULL, FULL, FULL, FULL, FULL, FULL, FULL, VER, FULL, FULL, VER, EMPTY, EII, FULL, FULL, FULL, FULL, VER, FULL, FULL, VER, EMPTY, EMPTY, FULL, FULL, VER, FULL, FULL, VER, EMPTY, EMPTY, FULL, FULL, ESD, FULL, FULL, FULL, FULL, FULL, FULL, FULL, ESD);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, EII, HOR, HOR, HOR, HOR, HOR, HOR, EID, EII, HOR, EID, EMPTY, EMPTY, EII, HOR, HOR, HOR, EID, EII, HOR, EID, EMPTY, EMPTY, EII, HOR, EID, EII, HOR, EID, EMPTY, EMPTY, EII, HOR, EID, EII, HOR, HOR, HOR, HOR, HOR, HOR, EID);
}

void titleGame(int x, int y) 
{
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, EMPTY, FULL, FULL, FULL, FULL, FULL, FULL, ESD, EMPTY, EMPTY, FULL, FULL, FULL, FULL, FULL, ESD, EMPTY, FULL, FULL, FULL, ESD, EMPTY, EMPTY, EMPTY, FULL, FULL, FULL, ESD, FULL, FULL, FULL, FULL, FULL, FULL, FULL, ESD);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, FULL, FULL, ESI, HOR, HOR, HOR, HOR, EID, EMPTY, FULL, FULL, ESI, HOR, HOR, FULL, FULL, ESD, FULL, FULL, FULL, FULL, ESD, EMPTY, FULL, FULL, FULL, FULL, VER, FULL, FULL, ESI, HOR, HOR, HOR, HOR, EID);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, FULL, FULL, VER, EMPTY, EMPTY, FULL, FULL, FULL, ESD, FULL, FULL, FULL, FULL, FULL, FULL, FULL, VER, FULL, FULL, ESI, FULL, FULL, FULL, FULL, ESI, FULL, FULL, VER, FULL, FULL, FULL, FULL, FULL, ESD, EMPTY, EMPTY);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, FULL, FULL, VER, EMPTY, EMPTY, EMPTY, FULL, FULL, VER, FULL, FULL, ESI, HOR, HOR, FULL, FULL, VER, FULL, FULL, VER, EII, FULL, FULL, ESI, EID, FULL, FULL, VER, FULL, FULL, ESI, HOR, HOR, EID, EMPTY, EMPTY);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, EII, FULL, FULL, FULL, FULL, FULL, FULL, ESI, EID, FULL, FULL, VER, EMPTY, EMPTY, FULL, FULL, VER, FULL, FULL, VER, EMPTY, EII, HOR, EID, EMPTY, FULL, FULL, VER, FULL, FULL, FULL, FULL, FULL, FULL, FULL, ESD);
	GotoXY(x, y);
	y++;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
		, EMPTY, EII, HOR, HOR, HOR, HOR, HOR, EID, EMPTY, EII, HOR, EID, EMPTY, EMPTY, EII, HOR, EID, EII, HOR, EID, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EII, HOR, EID, EII, HOR, HOR, HOR, HOR, HOR, HOR, EID);
}

void title(int x, int y) 
{
	color(15);
	titleSnake(x, y);
	titleGame(x + 2, y + 7);

}

void border(int x, int y, int startX, int startY) 
{
	int i, j;
	GotoXY(startX, startY);
	printf("%c", ESI);
	GotoXY(startX, y);
	printf("%c", EII);
	GotoXY(x, startY);
	printf("%c", ESD);
	GotoXY(x, y);
	printf("%c", EID);
	for (j = 1; j < x - startX; j++) 
	{
		GotoXY(startX + j, startY);
		printf("%c", HOR);
	}
	for (j = 1; j < x - startX; j++) 
	{
		GotoXY(startX + j, y);
		printf("%c", HOR);
	}
	for (i = 1; i < y - startY; i++) 
	{
		GotoXY(startX, startY + i);
		printf("%c", VER);
	}
	for (i = 1; i < y - startY; i++) 
	{
		GotoXY(x, startY + i);
		printf("%c", VER);
	}
}

void GameLoading()
{
	int x = 26, y = 25, i, D = 66;
	color(15);
	GotoXY(x, y);
	printf("%c", ESI);
	GotoXY(x, y + 1);
	printf("%c", VER);

	GotoXY(x, y + 2);
	printf("%c", EII);
	GotoXY(x + D, y);
	printf("%c", ESD);
	GotoXY(x + D, y + 1);
	printf("%c", VER);
	GotoXY(x + D, y + 2);
	printf("%c", EID);
	GotoXY(50, 23);
	printf("Game loading...");

	for (i = 1; i < D; i++)
	{
		GotoXY(x + i, y);
		printf("%c", HOR);
		GotoXY(x + i, y + 2);
		printf("%c", HOR);
	}
	color(10);
	for (i = 1; i < D; i++)
	{
		Sleep(50);
		GotoXY(x + i, y + 1);
		printf("%c", 219);
	}
	GotoXY(50, 23);
	printf("                      ");
	color(15);
	GotoXY(46, 23);
	printf("Press enter to continue.");
	color(15);
	_getch();

}

void Draw_StartScreen()
{
	HideCursor();
	title(38, 5); //print the title "SNAKE GAME"
	border(118, 29, 0, 0);
	GameLoading();
	//PlaySound(TEXT("menus.wav"), NULL, SND_SYNC);
	system("cls");
}

int DrawMenu()
{
	HideCursor();
	system("cls");
	border(118, 29, 0, 0);
	title(40, 2);
	int counter = 1;
	char option;
	color(10);
	border(74, 18, 44, 16);
	GotoXY(55, 17);
	printf("Start game");
	color(15);
	border(74, 21, 44, 19);
	GotoXY(55, 20);
	printf("Load game");
	border(74, 24, 44, 22);
	GotoXY(55, 23);
	printf("Highscore");
	border(74, 27, 44, 25);
	GotoXY(55, 26);
	printf("Quit game");
	do
	{
		option = _getch();
		if (counter > 1 && (option == 'w' || option == 'W'))
		{
			counter--;
		}
		if (counter < 4 && (option == 's' || option == 'S'))
		{
			counter++;
		}

		switch (counter)
		{
		case 1:
			color(10);
			border(74, 18, 44, 16);
			GotoXY(55, 17);
			printf("Start game");

			color(15);
			border(74, 21, 44, 19);
			GotoXY(55, 20);
			printf("Load game");

			color(15);
			border(74, 24, 44, 22);
			GotoXY(55, 23);
			printf("Highscore");

			color(15);
			border(74, 27, 44, 25);
			GotoXY(55, 26);
			printf("Quit game");
			break;
		case 2:
			color(15);
			border(74, 18, 44, 16);
			GotoXY(55, 17);
			printf("Start game");

			color(10);
			border(74, 21, 44, 19);
			GotoXY(55, 20);
			printf("Load game");

			color(15);
			border(74, 24, 44, 22);
			GotoXY(55, 23);
			printf("Highscore");

			color(15);
			border(74, 27, 44, 25);
			GotoXY(55, 26);
			printf("Quit game");
			break;
		case 3:
			color(15);
			border(74, 18, 44, 16);
			GotoXY(55, 17);
			printf("Start game");

			color(15);
			border(74, 21, 44, 19);
			GotoXY(55, 20);
			printf("Load game");

			color(10);
			border(74, 24, 44, 22);
			GotoXY(55, 23);
			printf("Highscore");

			color(15);
			border(74, 27, 44, 25);
			GotoXY(55, 26);
			printf("Quit game");
			break;
		case 4:
			color(15);
			border(74, 18, 44, 16);
			GotoXY(55, 17);
			printf("Start game");

			color(15);
			border(74, 21, 44, 19);
			GotoXY(55, 20);
			printf("Load game");

			color(15);
			border(74, 24, 44, 22);
			GotoXY(55, 23);
			printf("Highscore");

			color(10);
			border(74, 27, 44, 25);
			GotoXY(55, 26);
			printf("Quit game");
			break;
		}
	} while (option != enter);
	/*PlaySound(TEXT("menus.wav"), NULL, SND_SYNC);*/
	return counter;
}

void get_time(Snake& snake) {
	int color1 = 11 + CheckLevel(snake);
	char str[10], * ptr;
	ptr = str;
	time_t end_t = clock();
	time_t begin_t = 0;
	int hrs, mins, secs, temp = 0, t1, t2;
	if (end_t - begin_t > 3599999) {
		hrs = (int)((end_t - begin_t) / 3600000);
		mins = (int)((end_t - begin_t) % 3600000 / 60000);
		secs = (int)((end_t - begin_t) % 3600000 / (double)CLK_TCK) % 60;
		if (hrs > 9) {
			t1 = hrs;
			t2 = hrs % 10;
			hrs /= 10;
			str[0] = 48 + hrs;
			str[1] = 48 + t2;
			str[2] = '\0';
		}
		else {
			str[0] = 48;
			str[1] = 48 + hrs;
			str[2] = '\0';
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
		GotoXY(109, 8);
		std::cout << ptr;
		GotoXY(111, 8);
		std::cout << ":";

		if (mins > 9) {
			t1 = mins;
			t2 = mins % 10;
			mins /= 10;
			str[0] = 48 + mins;
			str[1] = 48 + t2;
			str[2] = '\0';
		}
		else {
			str[0] = 48;
			str[1] = 48 + mins;
			str[2] = '\0';
		}
		GotoXY(112, 8);
		std::cout << ptr;
		GotoXY(114, 8);
		std::cout << ":";
		if (secs > 9) {
			t1 = secs;
			t2 = secs % 10;
			while (secs) {
				temp = secs % 10;
				secs /= 10;
			}
			secs = temp;
			str[0] = 48 + secs;
			str[1] = 48 + t2;
			str[2] = '\0';
		}
		else {
			str[0] = 48;
			str[1] = 48 + secs;
			str[2] = '\0';
		}
		GotoXY(115, 8);
		std::cout << ptr;

	}
	else if (end_t - begin_t > 59999 && end_t - begin_t <= 3599999) {
		hrs = 0;
		str[0] = 48;
		str[1] = 48;
		str[2] = '\0';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
		GotoXY(109, 8);
		std::cout << ptr;
		GotoXY(111, 8);
		std::cout << ":";
		mins = (int)((end_t - begin_t) / 60000);
		secs = (int)((end_t - begin_t) / (double)CLK_TCK) % 60;
		if (mins > 9) {
			t1 = mins;
			t2 = mins % 10;
			mins /= 10;
			str[0] = 48 + mins;
			str[1] = 48 + t2;
			str[2] = '\0';
		}
		else {
			str[0] = 48;
			str[1] = 48 + mins;
			str[2] = '\0';
		}
		GotoXY(112, 8);
		std::cout << ptr;
		GotoXY(114, 8);
		std::cout << ":";
		if (secs > 9) {
			t1 = secs;
			t2 = secs % 10;

			while (secs) {
				temp = secs % 10;
				secs /= 10;
			}
			secs = temp;
			str[0] = 48 + secs;
			str[1] = 48 + t2;
			str[2] = '\0';
		}
		else {
			str[0] = 48;
			str[1] = 48 + secs;
			str[2] = '\0';
		}
		GotoXY(115, 8);
		std::cout << ptr;
	}
	else {
		hrs = 0;
		str[0] = 48;
		str[1] = 48;
		str[2] = '\0';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
		GotoXY(109, 8);
		std::cout << ptr;
		GotoXY(111, 8);
		std::cout << ":";
		mins = 0;
		secs = (end_t - begin_t) / (double)CLK_TCK;
		str[0] = 48;
		str[1] = 48;
		str[2] = '\0';
		GotoXY(112, 8);
		std::cout << ptr;
		GotoXY(114, 8);
		std::cout << ":";
		if (secs > 9) {
			t1 = secs;
			t2 = secs % 10;
			secs /= 10;
			str[0] = 48 + secs;
			str[1] = 48 + t2;
			str[2] = '\0';
		}
		else {
			str[0] = 48;
			str[1] = 48 + secs;
			str[2] = '\0';
		}
		GotoXY(115, 8);
		std::cout << ptr;
	}
}