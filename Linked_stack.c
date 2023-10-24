#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType* s) {
	s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType* s) {
	return (s->top = NULL);
}

// 포화 상태 검출 함수 (필요 x)
int is_full(LinkedStackType* s) {
	return 0;
}

// 삽입 함수
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode* )malloc(sizeof(StackNode));
	if (temp = NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}
	else {
		// temp에 입력받은 item 저장
		temp->item = item;
		// temp의 link는 이전 최상단 StackNode의 주소 저장
		temp->link = s->top;
		// 최상단 StackNode를 temp로 지정
		s->top = temp;
	}
}

// 삭제 함수
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		// element 타입의 popitem을 선언하여 최상단 StackNode의 item을 저장
		element popitem = temp->item;
		// 최상단 StackNode를 현재 top의 이전 StackNode로 지정
		s->top = temp->link;
		free(temp);
		return popitem;
	}
}

// 피크 함수
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return s->top->item;
}

