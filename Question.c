#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OCCUPIED 1
#define IDLE 0


int nop = 0;
int totaltime = 0;
int CPU_STATE = IDLE;
process_struct *datapro;

typedef struct process_data {
	int pid;
    int bTime;//bursttime
	int aTime;//arrival time
	int priorityQ;//priority for the process
	int finishT;//finishing time
	int response;//response time
	int wait;//waiting time
} process_struct;

// fixed priority queue

typedef struct node {
	process_struct* process;
	struct node* next;
} NODE;

process_struct* prQ_topE(NODE** root) {
	if((*root) == NULL) {
		printf("\ntop on empty priority queue!\n");
		exit(-1);
	}
	return (*root)->process;
}

process_struct* prQ_popE(NODE** root) {
	if((*root) == NULL) {
		printf("\npop on empty priority queue!\n");
		exit(-1);
	}
	NODE* temp = *root;
	*root = (*root)->next;
	process_struct* retProcess = temp->process;
	free(temp);
	return retProcess;
}
