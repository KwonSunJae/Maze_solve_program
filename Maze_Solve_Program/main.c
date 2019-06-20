#include "Maze.h"

void box_main() {
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━━┓\n");
	for (int i = 0; i < 30; i++) {
		printf("┃                                                      ┃                  ┃\n");
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void menu_main() {
	box_main();
	gotoxy(60,4); printf("1. 난이도 조절");
	gotoxy(60, 5); printf("2. 미로생성");
	gotoxy(60, 6); printf("3. 미로풀기");
	gotoxy(58, 8); printf("   ▲     ");
	gotoxy(58, 9); printf(" ◀▼▶  ENTER <┘");
	gotoxy(57, 11); printf(" HELP => BackSpace");

	
}
