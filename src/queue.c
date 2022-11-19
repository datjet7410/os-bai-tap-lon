#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size != MAX_QUEUE_SIZE){
		q->proc[q->size++] = proc;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) return NULL;  // if queue size = 0, do nothing
	int highest_priority_idx = 0, j;
	for (j = 1; j < q->size; j++) { // traverse to find highest prior. index
 		if (q->proc[j]->priority < q->proc[highest_priority_idx]->priority) {
			highest_priority_idx = j;
		}
	}
	struct pcb_t * res = q->proc[highest_priority_idx]; // get it out
	for (j = highest_priority_idx+1; j < q->size; j++) {
		q->proc[j-1] = q->proc[j];                     // shift back to rearrange the queue
	}
	q->size--;

	return res;
}

