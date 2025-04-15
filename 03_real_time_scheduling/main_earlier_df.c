/*
 * A program to implement
 * earliest deadline
 * first scheduling
 * */


/* Algorithm :
* Input: Task set T = {T1, T2, ..., Tn}
Each task Ti has (Deadline Di, Execution Time Ci)

1. At each time unit t:
   a. For all ready tasks, calculate the absolute deadline
   b. Select the task with the earliest deadline
   c. If a task is running, preempt it if another task has an earlier deadline
   d. Run the selected task for 1 time unit
   e. Update execution time and check for completion
   f. Repeat
*/
