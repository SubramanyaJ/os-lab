#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Process {
	int PID;
	int bt;
	int ival;
	int rem_bt;
	int next_release;
	int deadline;
	int weight;
	bool rtr;
};

struct Process *get_processes(int *n);
