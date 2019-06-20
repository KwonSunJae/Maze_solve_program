#include "Maze.h"

int check_stack() {
	return stack_top == 0;
}

node pop_stack() {
	if (stack_top == 0)return;
	return stack[stack_top--];
}

void insert_stack(node _node) {
	stack[stack_top++] = _node;
}