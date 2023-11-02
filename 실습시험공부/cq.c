#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
	return (q->rear = q->front);
}

int is_full(QueueType *q) {
	return (q->front == ((q->rear+1) % MAX_QUEUE_SIZE));
}

void enqueue(QueueType *q, element item) {
	if (is_full(q))
		error("error");
	q->rear = ((q->rear+1) % MAX_QUEUE_SIZE);
	q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q))
		error("error2");	
	q->front = [(q->front + 1) % MAX_QUEUE_SIZE];
	return q->queue[q->front];
}

element peek(QueueType *q) {
	if (is_empty(q))
		error("error3");
	return q->queue[(q->rear) % MAX_QUEUE_SIZE];
}
void main() {
	QueueType q;

	init(&q);

	enqueue(&q,1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));

	printf("front=%d rear=%d\n", q.front, q.rear);
}
