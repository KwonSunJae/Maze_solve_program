#include "Maze.h"

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };


int check_map(node temp,int number) { // 미로를 생성할 수 있는 방향을 찾는 함수
	int max_map = difficulty + 3;
	if (map_check[temp.x + dx[number]][temp.y + dy[number]] == 1)return 0;
	if (temp.x + dx[number] >= max_map || temp.x + dx[number] < 0) {
		return 0;
	}
	if (temp.y + dy[number] >= max_map || temp.y + dy[number] < 0) {
		return 0;
	}

	return 1;
}
int check_d(node temp, int number) {//  미로를 생성할 수 있는 방향을 찾는 함수(좀더 까다로움)
	int max_map = difficulty + 3;
	if (temp.x + dx[number] >= max_map || temp.x + dx[number] < 0) {
		return 0;
	}
	if (temp.y + dy[number] >= max_map || temp.y + dy[number] < 0) {
		return 0;
	}
	if (maze[1+2*(temp.x + dx[number])][1+2*(temp.y + dy[number])] == 0) {
		return 1;
	}
	return 0;
}
void modify_maze(int rand_num,node temp) { // 미로를 생성할때 미로 수정 함수
	switch (rand_num) {
	case 0:
		maze[2 + 2*temp.x][1 +2* temp.y] = 0;
		maze[3 + 2*temp.x][1 + 2*temp.y] = 0;
		map_check[temp.x + 1][temp.y] = 1;
		break;
	case 1:
		maze[2*temp.x][1 + 2*temp.y] = 0;
		maze[2*temp.x - 1][1 + 2*temp.y] = 0;
		map_check[temp.x - 1][temp.y] = 1;
		break;
	case 2:
		maze[1 + 2*temp.x][2*temp.y] = 0;
		maze[1 + 2*temp.x][2*temp.y - 1] = 0;
		map_check[temp.x][temp.y-1] = 1;
		break;
	case 3:
		maze[1 + 2*temp.x][2*temp.y + 2] = 0;
		maze[1 + 2*temp.x][2*temp.y + 3] = 0;
		map_check[temp.x][temp.y+1] = 1;
		break;
	default:
		break;
	}
}

void create_maze() {// 미로 생성 알고리즘
	int rand_num;
	int max_map = difficulty + 3; 
	srand(time(0));
	node entrance;
	entrance.x = rand()%max_map; // 미로생성의 시발점을 랜덤함수로 설정
	entrance.y = rand()%max_map;
	insert_queue(entrance); // 큐에 저장
	map_check[entrance.x][entrance.y] = 1;
	
	for (int i = 0; i < 2 * max_map + 1; i++) { // 벽으로 미로를 초기화
		for (int j = 0; j < 2 * max_map + 1; j++) {
			maze[i][j] = 1;
		}
	}
	maze[1 + 2 * entrance.x][1 + 2 * entrance.y] = 2;
	node temp;
	rand_num = rand() % 4;
	temp = pop_queue();// 점화적으로 문제를 풀기위해 첫번째 노드를 받았다.
	map_check[temp.x][temp.y] = 1;
	maze[1 + 2 * temp.x][1 + 2 * temp.y] = 0;
	for (int i = 0; i < 4; i++) { // 첫번째 노드에서 갈 수 있는 곳을 체크하고 큐에 삽입한다.
		if (check_map(temp, i)) {
			node temp2;
			temp2.x = temp.x + dx[i];
			temp2.y = temp.y + dy[i];
			map_check[temp2.x][temp2.y] = 1;
			insert_queue(temp2);
		}
	}
	node temp2;
	while (!check_queue()) {
		rand_num = rand() % 4;
		temp = pop_queue(); // 삽입된 큐를 꺼내어 큐가 빌때 까지 반복한다.
		map_check[temp.x][temp.y] = 1;
		maze[1 + 2 * temp.x][1 + 2 * temp.y] = 0;// 미로 생성
		while (!check_d(temp,rand_num)) { // 미로가 생성될 수 있도록 랜덤노드를 뽑는다.
			rand_num = rand() % 4;
		}
		modify_maze(rand_num, temp);// 뽑은 랜덤노드를 넘겨 수정한다.
		for (int i = rand()%4; i < rand()%4+ 12; i+=3) {
			if (check_map(temp, i%4)) { //미로를 생성할 수 있는 노드를 검사하고 큐에 삽입한다.
				
				temp2.x = temp.x + dx[i%4];
				temp2.y = temp.y + dy[i%4];
				map_check[temp2.x][temp2.y] = 1;
				insert_queue(temp2);
			}
		}
	}
}