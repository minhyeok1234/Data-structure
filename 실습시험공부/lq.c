#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element item;
	struct QueueNode *link;
} QueueNode;

typedef struct {
	QueueNode *front, *rear;
} QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q) {
	q->front = q->rear = NULL;
}

int is_empty(QueueType *q) {
	return q->front == NULL;
}

int is_full(QueueType *q) {
	return 0;
}

void enqueue(QueueType *q, element item) {
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("error");
	else {
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}


element dequeue(QueueType *q) {
	element item;
	QueueNode *temp = q->front;

	if (is_empty(q))
		error("error");
	else {
		item = temp->item;
		q->front = q->front->link;

		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}
}

element peek(QueueType *q) {
	element item;
	if(is_empty(q))
		error("error3");
	else {
		item = q->front->item;
		return item;
	}
}

void printqueues(QueueType q) {
	QueueNode *temp = q.front;
	printf("printing all item");
	while(temp != NULL) {
		printf("%d", temp->item);
		temp = temp->link;
	}
	printf("\n");
}

void main() {
	QueueType q;
	init(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	
	printqueues(q);

	printf("deq()=%d\n", dequeue(&q));
	printf("deq()=%d\n", dequeue(&q));
	printf("deq()=%d\n", dequeue(&q));
}	
