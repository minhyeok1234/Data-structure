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
	q->rear = q->front = 0;
}

int is_empty(QueueType *q) {
	return (q->rear == q->front);
}

int is_full(QueueType *q) {
	return (q->front == (q->rear+1) % MAX_QUEUE_SIZE);
}

void enqueue(QueueType *q, element item) {
	if (is_full(q))
		error("queue is full");
	q->rear = ((q->rear+1) % MAX_QUEUE_SIZE);
	q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q))
		error("queue is empty");
	q->front = ((q->front+1) % MAX_QUEUE_SIZE);
	return q->queue[q->front];
}

element peek(QueueType *q) {
	if (is_empty(q))
		error("queue os empty");
	return q->queue[(q->rear) % MAX_QUEUE_SIZE];
}

int main() {
	QueueType q;

	init(&q);
	
	printf("front=%d rear=%d\n", q.front, q.rear);
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));

	printf("front=%d rear=%d\n", q.front, q.rear);
}
