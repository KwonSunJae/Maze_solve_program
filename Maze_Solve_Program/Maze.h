/* 
C Programming Assignment 3
건국대학교 소프트웨어학과 권순재
201911151
C프로그래밍, 정병진 교수님
작성일: 2019.6.7
프로젝트명:미로찾기, 미로생성및 미로 길안내 도우미 프로그램 */



#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<Windows.h>
typedef struct Node{
	int x,y;
}node;

int check2[50][50];// solve_maze 에서 사용하는 변수 방문했는가를 기록
int maze[100][100];// 미로를 생성할때 사용하는 변수 리스트
int map_check[100][100];// 미로를 생성할때 방문했는가를 체크 하는 리스트
int difficulty;// 게임 난이도를 결정
void swap_queue(node*p, int num);// 큐배열을 바꿔주는 함수
void draw_curs();// 사용자 위치를 출력
node queue[200];// 큐리스트
node stack[200];// 스택 리스트
int queue_front, queue_tail;// 큐에 사용되는변수들
int stack_top;
int succed;
void controler_user();// 사용자 입력을 받고 처리하는 함수

int check_queue(); // 큐가 비어있는가를 체크
void insert_queue(node _node);// 큐에 삽입
node pop_queue();// 큐 출력

int check_stack();// 스택이 비어있는가를 확인
void insert_stack(node _node);// 스택 삽입
node pop_stack();//스택 출력

void draw_maze();// 미로를 그릴때 사용하는 함수
void gotoxy(int x, int y);// 커서이동
void menu_main();// 메뉴 화면 출력
void controler_difficulty();// 난이도 조절 함수
void create_maze();// 미로 생성 알고리즘