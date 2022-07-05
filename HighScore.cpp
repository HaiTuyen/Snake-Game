#include "HighScore.h"
#include <iomanip>
#pragma warning (disable: 6001)

void ScoreSaving(Highscore highscore[])
{
	ofstream saveScore;

	saveScore.open("Highscore.txt", ios_base::out);

	for (int i = 0; i < 5; i++)
	{
		saveScore << highscore[i].name << " " << highscore[i].score << " ";
	}

	saveScore.close();

}

//check if the file of highscores is empty or not?
bool isEmpty()
{

	int size;
	ifstream loadScore;
	loadScore.open("Highscore.txt", ios_base::in);
	if (loadScore.is_open())
	{
		loadScore.seekg(0, ios::end);
		size = loadScore.tellg();
		loadScore.close();
	}
	if (size == 0)
		return 1;
	else
		return 0;
}

//if the file is empty, initialize 5 values with name 'PLAYER' and score zero
void Score_Initialize(Highscore highscore[])
{

	if (isEmpty())
	{
		for (int i = 0; i < 5; i++)
		{
			strcpy(highscore[i].name, "PLAYER");
			highscore[i].score = 0;
		}
		ScoreSaving(highscore);
	}
	else
	{

		int count = 0;
		ifstream loadScore;
		loadScore.open("Highscore.txt", ios_base::in);

		for (int i = 0; i < 5;)
		{
			
			count++;

			if (count % 2 == 1)
			{
				loadScore >> highscore[i].name;
			}
			else
			{
				loadScore >> highscore[i].score;
				i++;
			}
			

		}
	}
}

void Score_Printer(Highscore highscore[])
{
	/*ifstream loadScore;
	loadScore.open("Highscore.txt", ios_base::in);
	for (int i = 0; i < 5; i++)
		loadScore >> highscore[i].name >> highscore[i].score;
	loadScore.close();
	color(11);*/
	int color1 = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	
	GotoXY(53, 4);
	cout << "HIGH SCORE";

	for (int i = 0; i < 5; i++)
	{
		GotoXY(38, 6 + i);
		cout << i + 1 << ".  ";
		cout << setw(20) << highscore[i].name << "\t\t" << highscore[i].score << endl;
	}
	color(16);
}

void CheckHighScore(Highscore highscore[], int score, Snake snake)
{
	char name[50];
	int color1 = 11 + CheckLevel(snake);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	for (int i = 0; i < 5; i++)
	{
		if (score > highscore[i].score)
		{
			if (i == 0)
			{
				GotoXY(65, 21);
				cout << "BEST SCORE!!" << endl;
			}
			else
			{
				GotoXY(65, 21);
				cout << " HIGH SCORE!" << endl;
			}
			GotoXY(65, 24);
			cout << " Enter player's name: ";
			cin >> name;



			for (int j = 4; j < i; j--)
			{
				strcpy(highscore[j].name, highscore[j - 1].name);
				highscore[j].score = highscore[j - 1].score;
			}
			strcpy(highscore[i].name, name);
			highscore[i].score = score;
			break;
		}

	}
	color(15);
	ScoreSaving(highscore);
}





