#include "USACO Daisy Chains.h"
void usacodaisychainsrun()
{
	int n;
	scanf("%d", &n);
	long long num = n;
	int sum;
	bool match;
	int petals[100] = { 0 };
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &petals[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum = 0;
			match = false;
			for (int k = i; k <= j; k++)
			{
				sum += petals[k];
			}
			for (int k = i; k <= j; k++)
			{
				if (petals[k] == float(float(sum) / float ((j - i + 1))))
				{
					match = true;
					break;
				}
			}
			if (match == true)
			{
				num++;
			}
		}
	}
	printf("%lld", num);
}