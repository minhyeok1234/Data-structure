#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)
		printf("Circle 1 moves from %c to %c.\n", from, to);

	else
	{
		hanoi_tower(n-1, from, to, tmp);
		printf("Circle %d moves from %c to %c.\n", n, from, to);
		hanoi_tower(n-1, tmp, from, to);
	}
}

void main()
{
	hanoi_tower(3, 'A', 'B', 'C');
}

