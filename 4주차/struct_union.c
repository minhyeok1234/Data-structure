#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct gender_type {
	enum tagField{female, male} gender;
	union {
		int children;
		int beard;
	} u;
} gender_type;

typedef struct person_info {
	char name[10];
	int age;
	float salary;
	gender_type gender_info;
} person_info;

int humansEqual (person_info person1, person_info person2) {
	if(strcmp(person1.name, person2.name))
		return FALSE;
	if(person1.age != person2.age)
		return FALSE;
	if(person1.salary != person2.salary)
		return FALSE;
	return TRUE;
}

int main(void) {
	person_info person1, person2;

	person1.gender_info.gender = male;
	person1.gender_info.u.beard = FALSE;

	person2.gender_info.gender = female;
	person2.gender_info.u.children = 4;

	printf("Person1's name : ");
	scanf("%s", person1.name);
	printf("Person1's age : ");
	scanf("%d", &person1.age);
	printf("Person1's salary : ");
	scanf("%f", &person1.salary);

	printf("\n");

	printf("Person2's name : ");
	scanf("%s", person2.name);
	printf("Person2's age : ");
	scanf("%d", &person2.age);
	printf("Person2's salary : ");
	scanf("%f", &person2.salary);

	printf("\n");

	if(humansEqual(person1, person2))
		printf("The two person are the same.\n");
	else
		printf("The two person are different.\n");
}

