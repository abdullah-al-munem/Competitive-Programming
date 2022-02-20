#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b);

int main()
{

	unsigned long long i;
	unsigned long long n;

	while (true)
	{

		scanf("%llu", &n);

		if (n == 0)
			break;

		unsigned long long set[n];

		for (i = 0; i < n; ++i)
			scanf("%llu", &set[i]);

		qsort(set, n, sizeof(unsigned long long), compare);

		for (i = 0; i < n; i += 2)
			if (set[i] != set[i + 1])
				break;

		printf("%llu\n", set[i]);

	}

	return 0;

}

int compare(const void *a, const void *b)
{

	if (*(int *)a == *(int *)b)
		return 0;
	else if (*(int *)a > *(int *)b)
		return 1;
	else
		return -1;

}

