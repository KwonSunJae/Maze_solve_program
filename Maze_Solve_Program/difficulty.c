#include "Maze.h"
void UI_difficulty() {
	gotoxy(64, 13); printf("    ��");
	gotoxy(64, 15); printf("    ��");
	gotoxy(60, 16); printf("����Ű�� �Է�");
	
}
void controler_difficulty() {// ���̵� ����
	int key;
	UI_difficulty();
	difficulty = 1;
	while (1) {
		
		gotoxy(58, 14); printf("  ���̵�: %2.d <��", difficulty);
		gotoxy(67, 14);
		if (kbhit()&&difficulty>0&&difficulty<=10) {
			key = _getch();
			if (key == 13) break;
			else if (key == 224) {
				key = _getch();
				switch (key) {

				case 72:
					difficulty++;
					break;
				case 80:
					difficulty--;
					break;
				default:
					break;
				}
			}
			switch (difficulty) {// ���̵� ���� �ֻ�ġ�� ������ 
			case 0: 
				difficulty++;
				break;
			case 11:
				difficulty--;
				break;
			default:
				break;
			}
			
			
		}
		Sleep(100);
	}
}