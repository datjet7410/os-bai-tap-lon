#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size < MAX_QUEUE_SIZE){
		q->proc[q->size] = proc;
		q->size++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (empty(q)) return NULL;  // if queue size = 0, do nothing

	int highest_prio_idx = 0;

	for (int i = 1; i < q->size; i++) { // traverse to find highest prior. index
 		if (q->proc[i]->prio < q->proc[highest_prio_idx]->prio) {
			highest_prio_idx = i;
		}
	}

	struct pcb_t * res = q->proc[highest_prio_idx]; // get it out
	for (int i = highest_prio_idx + 1; i < q->size; i++) {
		q->proc[i-1] = q->proc[i];  // shift back to rearrange the queue
	}
	
	q->size--;

	return res;
}

