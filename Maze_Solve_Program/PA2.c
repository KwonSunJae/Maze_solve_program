#include "Maze.h"


int main() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); // Ŀ�� ���ֱ�
	
	menu_main();// ����ȭ�� ���
	controler_difficulty();// ���̵� ���� 
	create_maze();// ���̵������� ���� �̷� ����
	maze[0][1] = 2;
	draw_maze();// �̷α׸���
	controler_user();// ����ڸ� �̷ο��� �̵���Ŵ
	system("pause");
}