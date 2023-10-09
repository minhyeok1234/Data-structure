#include <stdio.h>

typedef struct list {
	char data;
	struct list* link;
} list;

int main(void) {
	list item1, item2, item3;

	item1.data = 'a';
	item2.data = 'b';
	item3.data = 'c';

	item1.link = item2.link = item3.link = NULL;

	item1.link = &item2;
	item2.link = &item3;

	printf("item1.data = %d\n", item1.data);
	printf("item2.data = %d\n", item2.data);
	printf("item3.data = %d\n", item3.data);

	printf("\n");

	printf("item1.data = %d\n", item1.data);
	printf("item1.link->data = %d\n", item1.link->data);
	printf("item2.link->data = %d\n", item2.link->data);
	printf("item1.link->link->data = %d\n", item1.link->link->data);
}
