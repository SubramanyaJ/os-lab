#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Process {
    int PID, AT, BT;
    int CT, TAT, WT;
    int PRI, RT;
};

struct Process *get_processes(int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    struct Process *parr = calloc(*n, sizeof(struct Process));
    for (int i = 0; i < *n; i++) {
        parr[i].PID = i + 1;
        printf("Enter Arrival Time, Burst Time, and Priority (0 for System, 1 for User) for Process %d: ", i + 1);
        scanf("%d %d %d", &parr[i].AT, &parr[i].BT, &parr[i].PRI);
        parr[i].RT = parr[i].BT;
    }
    return parr;
}

int ar_sort(const void *x, const void *y) {
    return ((struct Process *)x)->AT - ((struct Process *)y)->AT;
}

void classify_processes(struct Process *parr, int n, struct Queue **sys, struct Queue **usr) {
    *sys = create_queue(n);
    *usr = create_queue(n);
    
    for(int i = 0; i < n; i++) {
        if(parr[i].PRI == 0) {
            enqueue_queue(*sys, &parr[i]);
        } else {
            enqueue_queue(*usr, &parr[i]);
        }
    }
}

void fill_data(struct Process *p, int *time) {
    p->WT = *time - p->AT;
    *time += p->BT;
    p->CT = *time;
    p->TAT = p->CT - p->AT;
    p->RT = 0;
}

void scheduler_fcfs(struct Queue *sys, struct Queue *usr, int n) {
    int time = 0;
    struct Process *current = NULL;
    
    while(!isempty_queue(sys) || !isempty_queue(usr)) {
        while(!isempty_queue(sys)) {
            struct Process *sys_proc = (struct Process *)frontof_queue(sys);
            if(sys_proc->AT <= time) {
                current = dequeue_queue(sys);
                fill_data(current, &time);
                break;
            } else {
                break;
            }
        }
        
        if(current == NULL && !isempty_queue(usr)) {
            struct Process *usr_proc = (struct Process *)frontof_queue(usr);
            if(usr_proc->AT <= time) {
                current = dequeue_queue(usr);
                fill_data(current, &time);
            } else {
                time++;
            }
        }
        
        current = NULL;
    }
}

void display_process_table(struct Process *p_list, int n) {
    float avg_TAT = 0, avg_WT = 0;
    
    printf("\nPID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    printf("------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        struct Process p = p_list[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p.PID, p.AT, p.BT, p.PRI, p.CT, p.TAT, p.WT);
        avg_TAT += p.TAT;
        avg_WT += p.WT;
    }
    
    avg_TAT /= n;
    avg_WT /= n;
    printf("\nAverage Turn Around Time: %.2f\n", avg_TAT);
    printf("Average Waiting Time: %.2f\n", avg_WT);
}

int main() {
    int n;
    struct Process *p_list = get_processes(&n);
    struct Queue *sys, *usr;
    
    qsort(p_list, n, sizeof(struct Process), ar_sort);
    
    classify_processes(p_list, n, &sys, &usr);
    scheduler_fcfs(sys, usr, n);
    display_process_table(p_list, n);
    
    free_queue(sys);
    free_queue(usr);
    free(p_list);
    
    return 0;
}
