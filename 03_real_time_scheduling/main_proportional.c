/**
 * A program to implement
 * proportional scheduling
 */

/**
 * Algorithm :
 * iInput: Tasks T1 to Tn, each with weight W1 to Wn
 TotalWeight = W1 + W2 + ... + Wn
 Time quantum = fixed slice of CPU time

 For each task Ti:
 Allocation[i] = Wi / TotalWeight   // Proportion of CPU share

 Loop forever:
 For each task Ti in T:
 Run Ti for (Allocation[i] * Time quantum)
 */
