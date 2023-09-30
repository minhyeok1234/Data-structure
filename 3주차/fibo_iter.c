#include <stdio.h>
#include <time.h>

int fib_iter(int n);

void main()
{
	clock_t start, finish;
	double duration;
	int n, i, result;

	printf("Input n : ");
	scanf("%d", &n);

	start = clock();

	result = fib_iter(n);
	printf("fib(%d) = %d\n", n, result);

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
}
int fib_iter(int n)
{
	if (n < 2)
		return n;
	else
	{
		int i, tmp, current = 1, last = 0;
		for(i = 2; i <= n; i++)
		{
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

