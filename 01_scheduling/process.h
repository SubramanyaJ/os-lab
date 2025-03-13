#ifndef _PROCESS_H_
#define _PROCESS_H_

/* When there are pnum processes,
 * Return a 2-D array of dimension
 * pnum x 7 
 * */
int **create_process_table(int pnum);

/* The index to column mapping is :
 * 0 : Process ID
 * 1 : Arrival Time
 * 2 : Burst Time
 * 3 : Completion Time
 * 4 : Turnaround Time
 * 5 : Waiting Time
 * 6 : Response Time 
 * */

void get_pid_data(int **arr, int pnums);

void sort_index(int **arr, int pnums, int index);

void display_process_table(int **arr, int pnums);

void calculate_params(int **arr, int pnums);

void free_table(int **arr, int pnums);

#endif
