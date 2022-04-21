#include "USACO Cowntagion.h"
void usacocowntagionrun()
{
	int n;
	int tree[cowsize] = { 0 };
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n - 1 && i < cowsize - 1; i++)
	{
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		tree[--a]++, tree[--b]++;
		getchar();
	}
	int answer = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (tree[i] > 1 || i == 0)
		{
			int child = tree[i];
			if (i != 0)
			{
				child--;
			}
			int log = 0;
			int pow = 1;
			while (pow < child + 1)
			{
				log++, pow *= 2;
			}
			answer += log;
		}
	}
	printf("%d", answer);
}