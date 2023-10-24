#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
		element stack[MAX_STACK_SIZE];
		int top;
} StackType;

// 초기화 함수
void init(StackType* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType* s, element item) {
	if(is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		exit(1);
	}
	else
		s->stack[++(s->top)] = item;
}
