// 2022008522 박민혁 데이터구조론 과제
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ListNode {
	char data[20];
	int d;
	struct ListNode * link;
} ListNode;

ListNode * create_node(char data[20], int d) {
	ListNode * new_node = (ListNode * )malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "error\n");
		exit(1); }
	strcpy(new_node->data, data);
	new_node->d = d;
	new_node->link = NULL;
	return new_node;}
	
void insert_node(ListNode ** phead, ListNode * p, ListNode * new_node, int d) {
	if ((* phead) == NULL) {
		new_node->link = NULL;
		* phead = new_node; }
	else if (p == NULL) {
		new_node->link = *phead;
		* phead = new_node; }
	else {
		new_node->link = p->link;
		p->link = new_node; p->d = d; } }
		
void remove_node(ListNode ** phead, ListNode * p, ListNode * removed, int d) {
	if (p == NULL) {
		* phead = (* phead)->link;
	}
	else {
		p->link = removed->link;
		p->d = d;
	}
	free(removed);}
	
ListNode * search(ListNode * head, char data[20]) {
	ListNode * p = head;
	while (p != NULL) {
		if (!strcmp(p->data, data)) return p;
		p = p->link; }
	return p;}
	
void time(ListNode ** phead, ListNode * s, ListNode * f) {
	ListNode* q = s;
	int t = 0; 
	while (q != f) {
		t += (q->d);
		q = q->link;}
	printf("From %s to %s: %d\n", s->data, f->data, t); }
	
void display(ListNode * head) {
	ListNode * p = head;
	while (p != NULL) {
		printf("%s(%d) ", p->data, p->d);
		p = p->link;
		if (p != NULL)
			printf("-> ");}
	printf("\n");}
	
void main(){
	ListNode* a = NULL;
	insert_node(&a, a, create_node("Airport", 0), 0);
	display(a);
	insert_node(&a, search(a, "Airport"), create_node("Aewol", 0), 20);
	display(a);
	insert_node(&a, search(a, "Aewol"), create_node("Seogwipo", 0), 40);
	display(a);
	insert_node(&a, search(a, "Seogwipo"), create_node("Seongsan", 0), 30);
	display(a);
	time(&a, search(a, "Aewol"), search(a, "Seongsan"));
	insert_node(&a, search(a, "Aewol"), create_node("Moseulpo", 30), 30);
	display(a);
	time(&a, search(a, "Aewol"), search(a, "Seongsan"));
	remove_node(&a, search(a, "Aewol"), search(a, "Moseulpo"), 40);
	display(a);
	}

