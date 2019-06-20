#include"Maze.h"



int check_mov(node pos, int num) {// 사용자의 위치에서 이동할수 있는 방향을 조사
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int max = 2 * (3 + difficulty) + 1;
	if (pos.x + dx[num] < 0 || pos.y + dy[num] < 0) {
		return 0;
	}
	if (pos.x + dx[num] > max || pos.y + dy[num] > max) {
		return 0;
	}
	if (maze[pos.x + dx[num]][pos.y + dy[num]] == 1) {
		return 0;
	}
	if (check2[pos.x + dx[num]][pos.y + dy[num]] == 1)return 0;
	return 1;
}
int solve_maze(node pos) { // 미로 해법 알고리즘
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int suc = 0;
	int max = 2 * (3 + difficulty)+1 ;
	if (pos.x < 0 || pos.y <0 || pos.x >= max || pos.y >= max) {// 사용자의 위치가 범위를 벗어났을때 0반환
		return 0;
	}
	else if (maze[pos.x][pos.y]!= 0 ) {// 사용자의 위치가 길이 아닐때 0반환
		return 0;
	}
	else if (pos.x == max - 2 && pos.y == max - 1) {// 사용자의 위치가 목표에 도달했을때 1반환
		maze[pos.x][pos.y] = 10;
		return 1;
	}
	else {
		maze[pos.x][pos.y] = 10;
		for (int i = 0; i < 4; i++) {
			pos.x += dx[i];
			pos.y += dy[i];
			if (solve_maze(pos)) {// 재귀함수이용
				suc = 1;
			}
			pos.x -= dx[i];
			pos.y -= dy[i];
		}
		if (suc) {
			return 1;
		}
		maze[pos.x][pos.y] = 9; // 갔던 길이 목적지가 아닐경우 갈수없는 길로 막음
		return 0;

	}
	
}


void controler_user() { //사용자 위치 조정
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int max = 2 * (3 + difficulty) + 1;
	node _user;
	int key;
	_user.x = 0;
	_user.y = 1;
	maze[0][1] = 8;
	for (int i = 0; i < 4; i++) { // 갈수 있는 방향 조사후 화살표 표시
		if (check_mov(_user, i)) {
			maze[_user.x + dx[i]][_user.y + dy[i]] = i + 4;
		}
	}
	while (1){
		if (_user.x == max-2 && _user.y == max -1) {
			break;
		}
		draw_curs(); // draw_maze 대신 이용하여 프로그램 최적화
		int n = 4;
		
		while (n) { // 0.05초마다 4번 키를 입력받아 프로그램을 부드럽게 가동시킴
			
			if (kbhit()) {
				key = _getch();
				if (key == 8) {
					maze[_user.x][_user.y] = 0;
					for (int i = 0; i < 4; i++) {
						if (check_mov(_user, i)) {
							maze[_user.x + dx[i]][_user.y + dy[i]] = 0;
						}
					}
					maze[max - 2][max - 1] = 0;
					solve_maze(_user);
					draw_maze();
				}// 백스페이스를 누를시 헬프모드
				if (key == 224) {
					key = _getch();
					for (int i = 0; i < 4; i++) {
						if (check_mov(_user, i)) {
							maze[_user.x + dx[i]][_user.y + dy[i]] = 0;
							gotoxy(2 + 2*(_user.y + dy[i]), 2 + _user.x + dx[i]); printf(" ");
						}
					}
					switch (key) {
					case 72:
						
						if (check_mov(_user, 1)) {
							maze[_user.x - 1][_user.y] = 8; 
							_user.x -= 1;
						}
						break;
					case 80:
						
						if (check_mov(_user, 0)) {
							maze[_user.x + 1][_user.y] = 8; 
							_user.x += 1;
						}
						break;
					case 75:
						
						if (check_mov(_user, 3)) {
							maze[_user.x][_user.y - 1] = 8; 
							_user.y -= 1;
						}
						break;
					case 77:
						
						if (check_mov(_user, 2)) {
							maze[_user.x][_user.y + 1] = 8; 
							_user.y += 1;
						}
				 		break;
					default:
						break;
					}

				}// 방향키 입력시 커서 이동
				for (int i = 0; i < 4; i++) {
					if (check_mov(_user, i)) {
						maze[_user.x + dx[i]][_user.y + dy[i]] = i + 4;
					}
				} // 커서 초기화
				
			}
			

			n--;
		}
		Sleep(50);
		
	}
}