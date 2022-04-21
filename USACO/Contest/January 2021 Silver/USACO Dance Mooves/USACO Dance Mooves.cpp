#include "USACO Dance Mooves.h"
void usacodancemoovesrun(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	int* positions = (int*)malloc((n+1) * sizeof(int));
	int* cows = (int*)calloc((n + 1) * (n + 1), sizeof(int));
	for (int i = 1; i <= n; i++)
	{
		*(positions + i) = i;
		*(cows + i * (n + 1) + i) = 1;
	}
	int* moves = (int*)malloc(k * 2 * sizeof(int));
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", moves + i * 2, moves + i * 2 + 1);
	}
	for (int i = 0; i < 10000000; i++)
	{
		int temp = *(positions + *(moves + (i % k) * 2));
		*(positions + *(moves + (i % k) * 2)) = *(positions + *(moves + (i % k) * 2 + 1));
		*(positions + *(moves + (i % k) * 2 + 1)) = temp;
		*(cows + *(positions + *(moves + (i % k) * 2)) * (n + 1) + *(moves + (i % k) * 2)) = 1;
		*(cows + *(positions + *(moves + (i % k) * 2 + 1)) * (n + 1) + *(moves + (i % k) * 2 + 1)) = 1;
	}
	int sum;
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += *(cows + i * (n + 1) + j);
		}
		printf("%d\n", sum);
	}
}