#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

struct Queue {
	int capacity;
	int *arr;
	int front, back;
};

struct Queue *create_queue(int size);

bool isempty_queue(struct Queue *queue);

bool isfull_queue(struct Queue *queue);

void enqueue_queue(struct Queue *queue, int val);

int dequeue_queue(struct Queue *queue);

void display_queue(struct Queue *queue);

int backof_queue(struct Queue *queue);

int frontof_queue(struct Queue *queue);

void free_queue(struct Queue *queue);

#endif /* queue.h included */
