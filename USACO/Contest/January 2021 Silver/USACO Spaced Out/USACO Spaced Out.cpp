#include "USACO Spaced Out.h"
int largest = 0;
void findchoice(int depth, int n, int* choice, int* beauty, int count)
{
	if (depth == n * n)
	{
		int sum = 0;
		bool correct = true;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (*(choice + (i)*n + j) + *(choice + (i + 1) * n + j) + *(choice + (i)*n + j + 1) + *(choice + (i + 1) * n + j + 1) != 2)
				{
					correct = false;
					break;
				}
			}
		}
		if (correct == false)
		{
			return;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sum += *(choice + i * n + j) * *(beauty + i * n + j);
			}
		}
		if (sum > largest)
		{
			largest = sum;
		}
		return;
	}
	for (int i = 0; i <= 1; i++)
	{
		*(choice + depth) = i;
		count += 1 - i;
		if (count < 0.6 * n * n)
		{
			findchoice(depth + 1, n, choice, beauty, count);
		}
		count -= 1 - i;
	}
}
void usacospacedoutrun()
{
	int n;
	scanf("%d", &n);
	int* beauty = (int*)malloc(n * n * sizeof(int));
	int* choice = (int*)malloc(n * n * sizeof(int));
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", beauty + i * n + j);
		}
	}
	findchoice(0, n, choice, beauty, 0);
	printf("%d\n", largest);
}