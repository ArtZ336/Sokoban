#include "Menu.h"
#include "Game.h"

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);
	
	menu();
	GamePlay();

	Sleep(INFINITE);
}                                                                                                                                                                                                                                                                                                                                                                                                                                        