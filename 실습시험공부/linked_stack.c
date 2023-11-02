#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType *s) {
	s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s) {
	return (s->top == NULL);
}

// 포화 상태 검출 함수 (필요x)
int is_full(LinkedStackType *s) {
	return 0;
}

// 삽입 함수
void push(LinkedStackType *s, element item) {
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "error\n");
		return;
	}
	else {
		temp -> item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
// 삭제 함수
element pop(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "error\n");
		exit(1);
	}
	else {
		StackNode *temp = s->top;
		element popitem = s->top->item;
		s->top = temp->link;
		free(temp);
		return popitem;
	}
}
// 피크 함수
element peek(LinkedStackType *s) {
	if(is_empty(s)) {
		fprintf(stderr, "error\n");
		exit(1);
	}
	else
		return s->top->item;
}

// 주 함수
int main() {
	LinkedStackType s;

	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	printf("%d\n", is_empty(&s));
}
