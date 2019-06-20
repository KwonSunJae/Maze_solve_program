#include "Maze.h"

node pop_queue() {
	return queue[queue_front++];
}
int check_queue() {
	return queue_front == queue_tail;
}
void insert_queue(node _node) {
	queue[queue_tail++] = _node;
}

void swap_queue(node * p, int num) {
	node copy;
	copy =*( p + queue_front);
	p += queue_front;

	
	*p =* (p-queue_front + num);
	p = p - num + queue_front;
	*p = copy;



}