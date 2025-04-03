#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct Queue *create_queue(int size) {
	struct Queue *new_queue = (struct Queue *) calloc(1, sizeof(struct Queue));
	new_queue->back = new_queue->front = -1;
	new_queue->arr = (void **) calloc(size, sizeof(void*));
	new_queue->capacity = size;
	return new_queue;
}

bool isempty_queue(struct Queue *queue) {
	return queue->front == -1;
}

bool isfull_queue(struct Queue *queue) {
	return (queue->back + 1) % queue->capacity == queue->front;
}

void enqueue_queue(struct Queue *queue, void *val) {
	if (isfull_queue(queue)) {
		fprintf(stderr, "Queue is full! Failed to enqueue");
		return;
	}
	if (isempty_queue(queue)) {
		queue->front = 0;
	}
	queue->back = (queue->back + 1) % queue->capacity;
	queue->arr[queue->back] = val;
}

void* dequeue_queue(struct Queue *queue) {
	if (isempty_queue(queue)) {
		fprintf(stderr, "Queue is empty! Failed to dequeue, returned NULL\n");
		return NULL;
	}
	void* ret = queue->arr[queue->front];
	if (queue->front == queue->back) {
		queue->front = queue->back = -1;
	} else {
		queue->front = (queue->front + 1) % queue->capacity;
	}
	return ret;
}

// Yet to be implemented
void display_queue(struct Queue *queue, void *offset) {
	if (isempty_queue(queue)) {
		fprintf(stderr, "Queue is empty! Nothing to display\n");
		return;
	}
	int i = queue->front;
	do {
		printf("%d ", queue->arr[i]);
		i = (i + 1) % queue->capacity;
	} while (i != (queue->back + 1) % queue->capacity);
	putchar('\n');
}

void* backof_queue(struct Queue *queue) {
	if (isempty_queue(queue)) {
		fprintf(stderr, "Queue is empty! Failed to get back, returned NULL\n");
		return NULL;
	}
	return queue->arr[queue->back];
}

void* frontof_queue(struct Queue *queue) {
	if (isempty_queue(queue)) {
		fprintf(stderr, "Queue is empty! Failed to get front, returned NULL\n");
		return NULL;
	}
	return queue->arr[queue->front];
}

void free_queue(struct Queue *queue) {
	free(queue->arr);
	free(queue);
}
