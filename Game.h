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

int map6[9][12] = {
	{1,1,1,1,1,1,1,0,0,0,0,0},
	{1,0,0,0,0,0,1,1,1,1,1,1},
	{1,0,1,4,1,4,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,1,0,1,0,1},
	{1,3,1,3,1,4,4,4,4,4,5,1},
	{1,0,3,0,0,0,0,0,0,0,1,1},
	{1,3,1,3,1,1,1,1,1,1,1,0},
	{1,3,0,3,1,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0}
};

int map7[5][8] = {
	{1,1,1,1,1,1,1,1},
	{1,3,0,0,4,0,3,1},
	{1,3,4,4,4,4,3,1},
	{1,3,0,5,4,0,3,1},
	{1,1,1,1,1,1,1,1},
};

int map8[9][9] = {
	{1,1,1,1,1,1,1,1,1},
	{1,3,1,1,3,1,1,3,1},
	{1,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,0,0,1},
	{1,3,0,4,5,4,0,3,1},
	{1,0,0,4,4,4,0,0,1},
	{1,0,0,0,0,0,0,0,1},
	{1,3,1,1,3,1,1,3,1},
	{1,1,1,1,1,1,1,1,1}
};

int map9[10][12] = {
	{1,1,1,1,0,0,0,0,0,0,0,0},
	{1,5,0,1,1,0,0,0,0,0,0,0},
	{1,0,4,0,1,1,0,0,0,0,0,0},
	{1,4,0,0,0,1,1,1,1,1,1,1},
	{1,3,0,0,4,0,4,0,4,0,3,1},
	{1,1,1,0,0,0,0,4,0,0,3,1},
	{0,0,1,0,0,0,4,0,0,0,1,1},
	{0,0,1,0,0,1,1,1,0,0,1,0},
	{0,0,1,3,3,1,0,1,3,3,1,0},
	{0,0,1,1,1,1,0,1,1,1,1,0}
};

int map10[8][8] = {
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
void LevelGenerator(int(&map)[y][x])
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
				cout << ("☺"); //место для коробки и персонаж в одном блоке
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
		cout << "\n    █▄█ █▀█ █ █   █   █▀▀ █▀▀ ▀█▀   ▀█▀ █ █ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀ █\n";
		cout << "     █  █▄█ █▄█   █▄▄ ██▄ █▀   █     █  █▀█ ██▄   █▄█ █▀█ █ ▀ █ ██▄ ▄\n";
		exit(0);
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

void Level7()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 7";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map7);
	Movement(map7);
}

void Level8()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 8";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map8);
	Movement(map8);
}

void Level9()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 9";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map9);
	Movement(map9);
}

void Level10()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t\tLevel 10";
	SetConsoleTextAttribute(h, 15);
	LevelGenerator(map10);
	Movement(map10);
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
				if (map2[i][j] == 7 && map2[i][j + 4] == 7 && map2[i + 4][j] == 7 && 
					map2[i + 4][j + 4] == 7)
				{
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
				if (map3[i][j] == 7 && map3[i][j + 4] == 7 && map3[i + 4][j] == 7 && 
					map3[i + 4][j + 4] == 7)
				{
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
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (map6[i][j] == 7 && map6[i][j + 2] == 7 && map6[i + 1][j + 1] == 7 && 
					map6[i + 2][j] == 7 && map6[i + 2][j + 2] == 7 && map6[i + 3][j] == 7 && 
					map6[i + 3][j + 2] == 7)
				{
					status6 = false;
				}
			}
		}
	}
	int status7 = true;
	while (status7)
	{
		system("cls");
		Level7();
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (map7[i][j] == 7 && map7[i + 1][j] && map7[i + 2][j] == 7 &&
					map7[i][j + 5] == 7 && map7[i + 1][j + 5] == 7 && 
					map7[i + 2][j + 5] == 7)
				{
					status7 = false;
				}
			}
		}
	}
	int status8 = true;
	while (status8)
	{
		system("cls");
		Level8();
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (map8[i][j] == 7 && map8[i][j + 3] == 7 && map8[i][j + 6] == 7 &&
					map8[i + 3][j] && map8[i + 3][j + 6] == 7 && map8[i + 6][j] == 7 &&
					map8[i  + 6][j + 3] == 7 && map8[i + 6][j + 6] == 7)
				{
					status8 = false;
				}
			}
		}
	}
	int status9 = true;
	while (status9)
	{
		system("cls");
		Level9();
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (map9[i][j] == 7 && map9[i + 4][j + 2] && map9[i + 4][j + 3] &&
					map9[i + 4][j + 7] == 7 && map9[i + 4][j + 8] == 7 &&
					map9[i][j + 9] == 7 && map9[i + 1][j + 9] == 7)
				{
					status9 = false;
				}
			}
		}
	}
	int status10 = true;
	while (status10)
	{
		system("cls");
		Level10();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (map10[i][j] == 7 && map10[i + 1][j] == 7 && map10[i + 1][j - 1] == 7 && 
					map10[i + 2][j] == 7 && map10[i + 2][j - 1])
				{
					status10 = false;
				}
			}
		}
	}
	system("cls");
	cout << "\n     █▄█ █▀█ █ █   █ █ █ █▀█ █▄ █   ▀█▀ █ █ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀ █\n";
	cout << "      █  █▄█ █▄█   ▀▄▀▄▀ █▄█ █ ▀█    █  █▀█ ██▄   █▄█ █▀█ █ ▀ █ ██▄ ▄\n";
	exit(0);
}