#include <stdio.h>
#include <stdlib.h>

typedef int el;
typedef struct Dnode {
	el data;
	struct Dnode *llink;
	struct Dnode *rlink;
} Dnode;
static el count = 0;

void error(char* mes) {
	fprintf(stderr, "%s\n", mes);
	exit(1);
}

void init(Dnode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void display(Dnode* phead) {
	Dnode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<- %d ->", p->data);
	printf("\n");
}
Dnode* create(el data) {
	Dnode* new_node;
	new_node = (Dnode* )malloc(sizeof(Dnode));
	new_node->data = data;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	return new_node;
}
Dnode* node_which(Dnode* pnode, int num) {
	int i;
	if (num == (count + 1)) {
		pnode = pnode->llink;
	}
	else if (num <= (count + 1) / 2) {
		for (i = 0; i < num -1; i++)
			pnode = pnode->rlink;
	}
	else {
		for (i = 0; i < 2- 
