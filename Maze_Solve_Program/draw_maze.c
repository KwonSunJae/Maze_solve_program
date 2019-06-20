#include "Maze.h"


void draw_maze(){ // 미로 그리기
	int max = 2 * (difficulty+3) + 1;
	
	
	maze[max - 2][max -1] = 3;
	for (int x = 0; x < max; x++) {// 미로 값 조사
		gotoxy(2, x + 2);
		for (int y = 0; y < max; y++) {
			switch (maze[x][y]) {
			case 1:
				printf("■");
				break;
			case 2:
				printf("※");
				break;

			case 3:
				printf("★");
				break;
			case 4:
				printf("↓");
				break;

			case 5:
				printf("↑");
				break;
			case 6:
				printf("→");
				break;
			case 7:
				printf("←");
				break;
			case 8:
				printf("○");
				break;
			case 9:
				printf("▦");
				break;
			case 10:
				printf("★");
				break;
			default:
				printf("  ");
				break;
			}
		}
		printf("\n");
	}
}
void draw_curs() {
	int max = 2 * (difficulty + 3) + 1;


	
	for (int x = 0; x < max; x++) {
		
		for (int y = 0; y < max; y++) {
			gotoxy(2 + 2*y, 2 + x);
			switch (maze[x][y]) {
			case 4:
				
				 printf("↓");
				 if (maze[x + 1][y] !=0) continue;
				 
				break;

			case 5:
				
				printf("↑");
				if (maze[x - 1][y] != 0) continue;
				
				break;
			case 6:
				 
				printf("→");
				if (maze[x][y + 1] != 0) continue;
				 
				break;
			case 7:
				
				 printf("←");
				 if (maze[x][y - 1] != 0) continue;
				
				break;
			case 8:
				 printf("○");
				break;
			}
		}
		printf("\n");
	}
}