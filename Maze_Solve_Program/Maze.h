/* 
C Programming Assignment 3
�Ǳ����б� ����Ʈ�����а� �Ǽ���
201911151
C���α׷���, ������ ������
�ۼ���: 2019.6.7
������Ʈ��:�̷�ã��, �̷λ����� �̷� ��ȳ� ����� ���α׷� */



#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<Windows.h>
typedef struct Node{
	int x,y;
}node;

int check2[50][50];// solve_maze ���� ����ϴ� ���� �湮�ߴ°��� ���
int maze[100][100];// �̷θ� �����Ҷ� ����ϴ� ���� ����Ʈ
int map_check[100][100];// �̷θ� �����Ҷ� �湮�ߴ°��� üũ �ϴ� ����Ʈ
int difficulty;// ���� ���̵��� ����
void swap_queue(node*p, int num);// ť�迭�� �ٲ��ִ� �Լ�
void draw_curs();// ����� ��ġ�� ���
node queue[200];// ť����Ʈ
node stack[200];// ���� ����Ʈ
int queue_front, queue_tail;// ť�� ���Ǵº�����
int stack_top;
int succed;
void controler_user();// ����� �Է��� �ް� ó���ϴ� �Լ�

int check_queue(); // ť�� ����ִ°��� üũ
void insert_queue(node _node);// ť�� ����
node pop_queue();// ť ���

int check_stack();// ������ ����ִ°��� Ȯ��
void insert_stack(node _node);// ���� ����
node pop_stack();//���� ���

void draw_maze();// �̷θ� �׸��� ����ϴ� �Լ�
void gotoxy(int x, int y);// Ŀ���̵�
void menu_main();// �޴� ȭ�� ���
void controler_difficulty();// ���̵� ���� �Լ�
void create_maze();// �̷� ���� �˰���