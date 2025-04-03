#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct Queue *create_queue(int size) {
    if (size <= 0) {
        fprintf(stderr, "Queue size must be positive\n");
        return NULL;
    }

    struct Queue *new_queue = (struct Queue *)calloc(1, sizeof(struct Queue));
    if (!new_queue) {
        perror("Failed to allocate queue");
        return NULL;
    }

    new_queue->arr = (void **)calloc(size, sizeof(void*));
    if (!new_queue->arr) {
        perror("Failed to allocate queue array");
        free(new_queue);
        return NULL;
    }

    new_queue->capacity = size;
    new_queue->items = 0;
    new_queue->front = new_queue->back = -1;
    return new_queue;
}

bool isempty_queue(struct Queue *queue) {
    return queue->front == -1;
}

bool isfull_queue(struct Queue *queue) {
    return (queue->back + 1) % queue->capacity == queue->front;
}

void enqueue_queue(struct Queue *queue, void *val) {
    if (!queue) {
        fprintf(stderr, "Queue is NULL\n");
        return;
    }
    if (isfull_queue(queue)) {
        fprintf(stderr, "Queue is full! Failed to enqueue\n");
        return;
    }

    if (isempty_queue(queue)) {
        queue->front = 0;
    }

    queue->back = (queue->back + 1) % queue->capacity;
    queue->arr[queue->back] = val;
    queue->items++;
}

void* dequeue_queue(struct Queue *queue) {
    if (!queue) {
        fprintf(stderr, "Queue is NULL\n");
        return NULL;
    }
    if (isempty_queue(queue)) {
        fprintf(stderr, "Queue is empty! Failed to dequeue\n");
        return NULL;
    }

    void* ret = queue->arr[queue->front];
    if (queue->front == queue->back) {
        queue->front = queue->back = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    queue->items--;
    return ret;
}

void display_queue(struct Queue *queue, void (*print_func)(void*)) {
    if (!queue) {
        fprintf(stderr, "Queue is NULL\n");
        return;
    }
    if (isempty_queue(queue)) {
        fprintf(stderr, "Queue is empty! Nothing to display\n");
        return;
    }
    if (!print_func) {
        fprintf(stderr, "Print function is NULL\n");
        return;
    }

    int i = queue->front;
    do {
        print_func(queue->arr[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->back + 1) % queue->capacity);
    putchar('\n');
}

void* backof_queue(struct Queue *queue) {
    if (!queue) {
        fprintf(stderr, "Queue is NULL\n");
        return NULL;
    }
    if (isempty_queue(queue)) {
        fprintf(stderr, "Queue is empty! Failed to get back\n");
        return NULL;
    }
    return queue->arr[queue->back];
}

void* frontof_queue(struct Queue *queue) {
    if (!queue) {
        fprintf(stderr, "Queue is NULL\n");
        return NULL;
    }
    if (isempty_queue(queue)) {
        fprintf(stderr, "Queue is empty! Failed to get front\n");
        return NULL;
    }
    return queue->arr[queue->front];
}

void free_queue(struct Queue *queue) {
    if (!queue) return;
    free(queue->arr);
    free(queue);
}

int itemsin_queue(struct Queue *queue) {
    if (!queue) {
        fprintf(stderr, "Queue is NULL\n");
        return 0;
    }
    return queue->items;
}