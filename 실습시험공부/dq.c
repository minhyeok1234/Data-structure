#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct DlistNode {
	struct DlistNode *rlink;
	struct DlistNode *llink;
	element data;
} DlistNode;

typedef struct DequeType {
	struct DlistNode *head;
	struct DlistNode *tail;
} DequeType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(DequeType *dq) {
	dq->head = dq->tail = NULL;
}

DlistNode * create_node(DlistNode * llink, element item, DlistNode * rlink) {
	DlistNode *new_node = (DlistNode*)malloc(sizeof(DlistNode));
	if(new_node == NULL)
		error("memory error");

	new_node->llink = llink;
	new_node->rlink = rlink;
	new_node->data = item;

	return new_node;
}

int is_empty(DequeType *dq) {
	if(dq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void add_rear(DequeType *dq, element item) {
	DlistNode * new_node = create_node(dq->tail, item, NULL);

	if(is_empty(dq))
		dq->head=new_node;
	else
		dq->tail->rlink = new_node;
	dq->tail = new_node;
}

void add_front(DequeType *dq, element item) {
	DlistNode * new_node = create_node(NULL, item, dq->head);

	if(is_empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node;
	dq->head = new_node;
}

element delete_rear(DequeType *dq) {
	element item;
	DlistNode *removed_node;

	if (is_empty(dq))
		error("stack is empty");
	else {
		removed_node = dq->tail;
		item = removed_node->data;
		dq->tail = dq->tail->llink;
		free(removed_node);

		if (dq->tail == NULL)
			dq->head = NULL;
		else
			dq->tail->rlink = NULL;
	}
	return item;
}

element delete_front(DequeType *dq) {
	DlistNode * removed_node;
	element item;

	if(is_empty(dq))
		error("error");
	else {
		removed_node = dq->head;
		item = removed_node->data;
		dq->head = dq->head->rlink;
		free(removed_node);
		if (dq->head == NULL)
			dq->tail = NULL;
		else 
			dq->head->llink = NULL;
	}
	return item;
}

void display(DequeType *dq) {
	DlistNode *p;
	printf("( ");
	for(p=dq->head; p != NULL; p= p->rlink)
		printf("%d", p->data);
	printf(")\n");
}

void main() {
	DequeType deque;
	init(&deque);

	add_front(&deque, 10);
	add_front(&deque, 20);
	add_rear(&deque, 30);
	display(&deque);

	printf("%d\n", delete_front(&deque));
	printf("%d\n", delete_rear(&deque));
	display(&deque);
}

