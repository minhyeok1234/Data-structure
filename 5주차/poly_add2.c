#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10, 3}, {3, 2}, {1, 0} };

int avail = 6;

char compare(int a, int b) {
	if(a > b) return '>' ;
	else if (a == b) return '=' ;
	else return '<' ;
}

void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "There are too many terms in a polynomial\n");
		exit(1);
	}

	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int *Ce) {
	float tempcoef;
	*Cs = avail;

	while (As <= Ae && Bs <= Be)
		switch (compare(terms[As].expon, terms[Bs].expon)) {
			case '>':
				attach(terms[As].coef, terms[As].expon);
				As++;
				break;
			case '=':
				tempcoef = terms[As].coef + terms[Bs].coef;
				if (tempcoef)
					attach(tempcoef, terms[As].expon);
				As++; Bs++;
				break;
			case '<':
				attach(terms[Bs].coef, terms[Bs].expon);
				Bs++;
				break;
		}
	for (; As <= Ae; As++)
			attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

void print(int first, int last) {
	int i;
	for (i = first; i <= last; i++) {
		printf("%.2fx^%d", terms[i].coef, terms[i].expon);
		if(i<last)
			printf("+ ");
	}
	printf("\n");
}

void main()
{
	printf("polynomial a = ");
	print(0, 2);
	printf("polynomial b = ");
	print(3, 5);

	int Cs, Ce;
	poly_add2(0, 2, 3, 5, &Cs, &Ce);

	printf("polynomial c = ");
	print(Cs, Ce);
}
