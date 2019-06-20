#include "Maze.h"

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };


int check_map(node temp,int number) { // �̷θ� ������ �� �ִ� ������ ã�� �Լ�
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
int check_d(node temp, int number) {//  �̷θ� ������ �� �ִ� ������ ã�� �Լ�(���� ��ٷο�)
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
void modify_maze(int rand_num,node temp) { // �̷θ� �����Ҷ� �̷� ���� �Լ�
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

void create_maze() {// �̷� ���� �˰���
	int rand_num;
	int max_map = difficulty + 3; 
	srand(time(0));
	node entrance;
	entrance.x = rand()%max_map; // �̷λ����� �ù����� �����Լ��� ����
	entrance.y = rand()%max_map;
	insert_queue(entrance); // ť�� ����
	map_check[entrance.x][entrance.y] = 1;
	
	for (int i = 0; i < 2 * max_map + 1; i++) { // ������ �̷θ� �ʱ�ȭ
		for (int j = 0; j < 2 * max_map + 1; j++) {
			maze[i][j] = 1;
		}
	}
	maze[1 + 2 * entrance.x][1 + 2 * entrance.y] = 2;
	node temp;
	rand_num = rand() % 4;
	temp = pop_queue();// ��ȭ������ ������ Ǯ������ ù��° ��带 �޾Ҵ�.
	map_check[temp.x][temp.y] = 1;
	maze[1 + 2 * temp.x][1 + 2 * temp.y] = 0;
	for (int i = 0; i < 4; i++) { // ù��° ��忡�� �� �� �ִ� ���� üũ�ϰ� ť�� �����Ѵ�.
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
		temp = pop_queue(); // ���Ե� ť�� ������ ť�� ���� ���� �ݺ��Ѵ�.
		map_check[temp.x][temp.y] = 1;
		maze[1 + 2 * temp.x][1 + 2 * temp.y] = 0;// �̷� ����
		while (!check_d(temp,rand_num)) { // �̷ΰ� ������ �� �ֵ��� ������带 �̴´�.
			rand_num = rand() % 4;
		}
		modify_maze(rand_num, temp);// ���� ������带 �Ѱ� �����Ѵ�.
		for (int i = rand()%4; i < rand()%4+ 12; i+=3) {
			if (check_map(temp, i%4)) { //�̷θ� ������ �� �ִ� ��带 �˻��ϰ� ť�� �����Ѵ�.
				
				temp2.x = temp.x + dx[i%4];
				temp2.y = temp.y + dy[i%4];
				map_check[temp2.x][temp2.y] = 1;
				insert_queue(temp2);
			}
		}
	}
}