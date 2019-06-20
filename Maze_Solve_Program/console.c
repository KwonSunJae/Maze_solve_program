#include"Maze.h"


void gotoxy(int x, int y) {
	COORD curs;
	curs.X = x;
	curs.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curs);
}