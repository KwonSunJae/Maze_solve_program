#include "Maze.h"


int main() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); // 커서 없애기
	
	menu_main();// 메인화면 출력
	controler_difficulty();// 난이도 조절 
	create_maze();// 난이도조절을 통해 미로 생성
	maze[0][1] = 2;
	draw_maze();// 미로그리기
	controler_user();// 사용자를 미로에서 이동시킴
	system("pause");
}