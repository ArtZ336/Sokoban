#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

#pragma comment(lib, "winmm.lib")

DWORD WINAPI MusicThread(void* param)
{
	while (true)
	{
		PlaySoundA("menu_music.wav", NULL, SND_NODEFAULT | SND_LOOP);
	}
	return 0;
}

void menu()
{
	system("title Sokoban");
	system("mode con cols=75 lines=25"); 
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

	const int events_count = 256;
	INPUT_RECORD all_events[events_count];
	DWORD read_event;
	SetConsoleTextAttribute(h, 14);
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
		}
	}
}