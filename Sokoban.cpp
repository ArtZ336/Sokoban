#include <iostream>
#include <conio.h> 
#include <windows.h>
#include <ctime>

using namespace std;

#pragma comment(lib, "winmm.lib")

DWORD WINAPI MusicThread(void* param)
{
	PlaySoundA("menu_music.wav", NULL, SND_NODEFAULT | SND_LOOP);
	return 0;
}

void menu()
{
	system("title Sokoban");
	system("mode con cols=75 lines=40");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

	const int events_count = 256;
	INPUT_RECORD all_events[events_count];
	DWORD read_event;
	SetConsoleTextAttribute(h, 9);
	cout << "\n\t░██████╗░█████╗░██╗░░██╗░█████╗░██████╗░░█████╗░███╗░░██╗\n";
	cout << "\t██╔════╝██╔══██╗██║░██╔╝██╔══██╗██╔══██╗██╔══██╗████╗░██║\n";
	cout << "\t╚█████╗░██║░░██║█████═╝░██║░░██║██████╦╝███████║██╔██╗██║\n";
	cout << "\t░╚═══██╗██║░░██║██╔═██╗░██║░░██║██╔══██╗██╔══██║██║╚████║\n";
	cout << "\t██████╔╝╚█████╔╝██║░╚██╗╚█████╔╝██████╦╝██║░░██║██║░╚███║\n";
	cout << "\t╚═════╝░░╚════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚══╝\n";
	SetConsoleTextAttribute(h, 15);
	cout << "\n\t\t\t   █▀█ █   ▄▀█ █▄█";
	cout << "\n\t\t\t   █▀▀ █▄▄ █▀█  █\n";
	cout << "\n\t\t\t   █▀▀ ▀▄▀ █ ▀█▀";
	cout << "\n\t\t\t   ██▄ █ █ █  █ \n";
	bool click = true;
	CreateThread(0, 0, MusicThread, 0, 0, 0);
	while (click)
	{
		ReadConsoleInput(hin, all_events, events_count, &read_event);
		for (int i = 0; i < read_event; i++)
		{
			c.X = all_events[i].Event.MouseEvent.dwMousePosition.X;
			c.Y = all_events[i].Event.MouseEvent.dwMousePosition.Y;


			if (c.X >= 27 && c.X <= 41 && c.Y == 8 &&
				all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				click = false;
				system("cls");
			}
			else if (c.X >= 27 && c.X <= 41 && c.Y == 9 &&
				all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				click = false;
				system("cls");
			}
			else if (c.X >= 27 && c.X <= 39 && c.Y == 11 &&
				all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{

				exit(0);
			}
			else if (c.X >= 27 && c.X <= 39 && c.Y == 12 &&
				all_events[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{

				exit(0);
			}
			//COORD info{ 0, 0 };
			//SetConsoleCursorPosition(h, info);
			//cout << "Current cursor position:         ";
			//SetConsoleCursorPosition(h, info);
			//cout << "Current cursor position: " << c.X << " " << c.Y;
		}
	}
}
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	menu();

	int level1[8][8] = {
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,1},
		{1,0,1,0,1,4,3,1}, 
		{1,0,0,0,0,4,3,1}, 
		{1,0,1,0,1,4,3,1},
		{1,0,0,0,1,0,0,1},
		{1,1,1,1,1,5,0,1},
		{0,0,0,0,1,1,1,1} 
	};
	cout << "\n\n\n";
	for (int i = 0; i < 8; i++)
	{
		cout << "\t\t\t\t";
		for (int j = 0; j < 8; j++)
		{
			switch (level1[i][j])
			{
			case 0:
				cout << (" "); //пустота
				break;
			case 1: 
				cout << ("█"); //стена
				break;
			case 3: 
				cout << ("x"); //место для коробки
				break;
			case 4: 
				cout << ("□"); //коробки
				break;
			case 5: 
				cout << ("☺"); //персонаж
				break;
			case 7: 
				cout << ("☒"); //коробка и место совпадают
				break;
			}
		}
		cout << "\n";
	}
	Sleep(INFINITE);
}
