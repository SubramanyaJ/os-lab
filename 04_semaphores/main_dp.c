#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t chop[N];

void *philosopher(void *num) {
    int id = *(int *)num;
    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);
        sem_wait(&chop[id]);
        sem_wait(&chop[(id + 1) % N]);
        printf("Philosopher %d is eating.\n", id);
        sleep(1);
        sem_post(&chop[id]);
        sem_post(&chop[(id + 1) % N]);
        printf("Philosopher %d finished eating.\n", id);
        sleep(1);
    }
}

int main() {
    pthread_t phil[N];
    int i, ids[N];
    for (i = 0; i < N; i++) sem_init(&chop[i], 0, 1);
    for (i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &ids[i]);
    }
    for (i = 0; i < N; i++) pthread_join(phil[i], NULL);
    for (i = 0; i < N; i++) sem_destroy(&chop[i]);
    return 0;
}
