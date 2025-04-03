#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

struct Queue {
    void **arr;
    int capacity;
    int items;
    int front, back;
};

struct Queue *create_queue(int size);
bool isempty_queue(struct Queue *queue);
bool isfull_queue(struct Queue *queue);
void enqueue_queue(struct Queue *queue, void *val);
void* dequeue_queue(struct Queue *queue);
void display_queue(struct Queue *queue, void (*print_func)(void*));
void* backof_queue(struct Queue *queue);
void* frontof_queue(struct Queue *queue);
void free_queue(struct Queue *queue);
int itemsin_queue(struct Queue *queue);

#endif /* queue.h */