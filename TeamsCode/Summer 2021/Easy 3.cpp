#include <stdio.h>
#include <stdlib.h>
int values[1000000][2] = { 0 };
void summer2021easy3()
{
	long n, x;
	scanf("%d %d", &n, &x);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &values[i][0], &values[i][1]);
		getchar();
	}
	int val = 0;
	int a = 0;
	while (val <= x)
	{
		a++;
		for (int i = 0; i < n; i++)
		{
			if (a > values[i][0] && (a - values[i][0]) % values[i][1] == 0)
			{
				val++;
			}
		}
	}
	printf("%d", a);
}