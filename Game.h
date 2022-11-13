#pragma once
#include <iostream>
#include <conio.h> 
#include <windows.h>

using namespace std;

int map1[5][7] = {
{1,1,1,1,1,0,0},
{1,5,0,0,1,0,0},
{1,0,1,4,1,1,1},
{1,0,4,0,3,3,1},
{1,1,1,1,1,1,1}
};

int map2[7][7] = {
{1,1,1,1,1,1,1},
{1,3,0,0,0,3,1},
{1,0,0,4,0,0,1},
{1,0,4,5,4,0,1},
{1,0,0,4,0,0,1},
{1,3,0,0,0,3,1},
{1,1,1,1,1,1,1}
};

int map3[7][7] = {
{1,1,1,1,1,1,1},
{1,3,0,0,0,3,1},
{1,0,4,5,4,0,1},
{1,0,1,1,1,0,1},
{1,0,4,0,4,0,1},
{1,3,0,0,0,3,1},
{1,1,1,1,1,1,1}
};

int map4[8][8] = {
{1,1,1,1,1,1,1,1},
{1,0,0,0,1,0,0,1},
{1,0,1,0,1,4,3,1},
{1,0,0,0,0,4,3,1},
{1,0,1,0,1,4,3,1},
{1,0,0,0,1,0,0,1},
{1,1,1,1,1,5,0,1},
{0,0,0,0,1,1,1,1}
};

int map5[7][7] = {
{1,1,1,1,1,1,1},
{1,0,0,0,3,0,1},
{1,0,1,0,1,0,1},
{1,0,4,5,4,0,1},
{1,0,1,4,1,3,1},
{1,0,0,3,0,0,1},
{1,1,1,1,1,1,1}
};

int map6[8][8] = {
{1,1,1,1,1,1,0,0},
{1,0,0,0,0,1,0,0},
{1,0,1,1,0,1,1,1},
{1,0,0,4,0,0,0,1},
{1,4,3,4,0,4,0,1},
{1,3,3,1,1,4,1,1},
{1,3,3,5,0,0,1,0},
{1,1,1,1,1,1,1,0}
};


template <size_t y, size_t x>
void LevelGenerator(int (&map)[y][x])
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n";
	for (int i = 0; i < y; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 0; j < x; j++)
		{
			switch (map[i][j])
			{
			case 0:
				cout << (" "); //пустота
				break;
			case 1:
				SetConsoleTextAttribute(h, 1);
				cout << ("█"); //стена
				SetConsoleTextAttribute(h, 15);
				break;
			case 3:
				cout << ("x"); //место для коробки
				break;
			case 4:
				SetConsoleTextAttribute(h, 4);
				cout << ("□"); //коробки
				SetConsoleTextAttribute(h, 15);
				break;
			case 5:
				SetConsoleTextAttribute(h, 5);
				cout << ("☺"); //персонаж
				SetConsoleTextAttribute(h, 15);
				break;
			case 7:
				SetConsoleTextAttribute(h, 2);
				cout << ("*"); //коробка и место совпадают
				SetConsoleTextAttribute(h, 15);
				break;
			case 8:
				SetConsoleTextAttribute(h, 5);
				cout << ("☺"); //направление
				SetConsoleTextAttribute(h, 15);
				break;
			}
		}
		cout << "\n";
	}
}

template <size_t height, size_t width>
void Movement(int(&map)[height][width])
{
	int r, c;
	int flag = 0;
	for (r = 0; r < height; r++)
	{
		for (c = 0; c < width; c++)
		{
			if (map[r][c] == 5 || map[r][c] == 8)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}

	char key;
	key = _getch();
	switch (key)
	{
	case 'w':
		if (map[r - 1][c] == 0 || map[r - 1][c] == 3)
		{
			map[r - 1][c] += 5;
			map[r][c] -= 5;
		}
		else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)
		{
			if (map[r - 2][c] == 0 || map[r - 2][c] == 3)
			{
				map[r - 2][c] += 4;
				map[r - 1][c] += 1;
				map[r][c] -= 5;
			}
		}

		break;

	case 's':
		if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
		{
			map[r + 1][c] += 5;
			map[r][c] -= 5;
		}
		else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)
		{
			if (map[r + 2][c] == 0 || map[r + 2][c] == 3)
			{
				map[r + 2][c] += 4;
				map[r + 1][c] += 1;
				map[r][c] -= 5;
			}
		}
		break;

	case 'a':
		if (map[r][c - 1] == 0 || map[r][c - 1] == 3)
		{
			map[r][c - 1] += 5;
			map[r][c] -= 5;
		}
		else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)
		{
			if (map[r][c - 2] == 0 || map[r][c - 2] == 3)
			{
				map[r][c - 2] += 4;
				map[r][c - 1] += 1;
				map[r][c] -= 5;
			}
		}
		break;

	case 'd':
		if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
		{
			map[r][c + 1] += 5;
			map[r][c] -= 5;
		}
		else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)
		{
			if (map[r][c + 2] == 0 || map[r][c + 2] == 3)
			{
				map[r][c + 2] += 4;
				map[r][c + 1] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	case 'e':
		system("cls");
		cout << "\n\t█▄█ █▀█ █ █   █   █▀▀ █▀▀ ▀█▀   ▀█▀ █ █ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀ █\n";
		cout << "\t █  █▄█ █▄█   █▄▄ ██▄ █▀   █     █  █▀█ ██▄   █▄█ █▀█ █ ▀ █ ██▄ ▄\n";
		exit(0);
		break;
	case 'r':
		break;
	}
}
void Level1()
{
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 1";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map1);
	Movement(map1);
}



void Level2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 2";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map2);
	Movement(map2);
}

void Level3()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 3";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map3);
	Movement(map3);
}

void Level4()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 4";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map4);
	Movement(map4);
}

void Level5()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 5";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map5);
	Movement(map5);
}

void Level6()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 6";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map6);
	Movement(map6);
}

void GamePlay()
{
	bool status1 = true;
	while (status1)
	{
		system("cls");
		Level1();
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (map1[i][j] == 7 && map1[i][j + 1] == 7)
				{
					system("cls");
					status1 = false;
				}
			}
		}
	}
	int status2 = true;
	while (status2)
	{
		system("cls");
		Level2();
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (map2[i][j] == 7 && map2[i][j + 4] == 7 && map2[i + 4][j] == 7 && map2[i + 4][j + 4] == 7)
				{
					system("cls");
					status2 = false;
				}
			}
		}
	}
	int status3 = true;
	while (status3)
	{
		system("cls");
		Level3();
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (map3[i][j] == 7 && map3[i][j + 4] == 7 && map3[i + 4][j] == 7 && map3[i + 4][j + 4] == 7)
				{
					system("cls");
					status3 = false;
				}
			}
		}
	}
	int status4 = true;
	while (status4)
	{
		system("cls");
		Level4();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (map4[i][j] == 7 && map4[i + 1][j] == 7 && map4[i + 2][j] == 7)
				{
					system("cls");
					status4 = false;
				}
			}
		}
	}
	int status5 = true;
	while (status5)
	{
		system("cls");
		Level5();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (map5[i][j] == 7 && map5[i + 3][j + 1] == 7 && map5[i + 4][j - 1 == 7])
				{
					system("cls");
					status5 = false;
				}
			}
		}
	}
	int status6 = true;
	while (status6)
	{
		system("cls");
		Level6();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (map6[i][j] == 7 && map6[i + 1][j] == 7 && map6[i + 1][j - 1] == 7 && map6[i + 2][j] == 7 && map6[i + 2][j - 1])
				{
					system("cls");
					status6 = false;
				}
			}
		}
	}

}
