#include "Maze.h"

void box_main() {
	printf("������������������������������������������������������������������������������\n");
	for (int i = 0; i < 30; i++) {
		printf("��                                                      ��                  ��\n");
	}
	printf("������������������������������������������������������������������������������\n");
}

void menu_main() {
	box_main();
	gotoxy(60,4); printf("1. ���̵� ����");
	gotoxy(60, 5); printf("2. �̷λ���");
	gotoxy(60, 6); printf("3. �̷�Ǯ��");
	gotoxy(58, 8); printf("   ��     ");
	gotoxy(58, 9); printf(" ���墺  ENTER <��");
	gotoxy(57, 11); printf(" HELP => BackSpace");

	
}
