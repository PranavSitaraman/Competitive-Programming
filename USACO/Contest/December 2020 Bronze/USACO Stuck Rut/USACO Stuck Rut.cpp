#include "USACO Stuck Rut.h"
void usacostuckrutrun()
{
	int n;
	scanf("%d", &n);
	getchar();
	cow cows[50] = { 0 };
	char field[size][size] = { 0 };
	bool large = false;
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &cows[i].d);
		scanf("%lld", &cows[i].x);
		scanf("%lld", &cows[i].y);
		cows[i].stuck = false;
		cows[i].ate = 1;
		getchar();
		if (cows[i].x > 10000 || cows[i].y > 10000)
		{
			large = true;
		}
	}
	if (large == false)
	{
		for (int j = 0; j < 1000; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (cows[i].stuck == false)
				{
					if ((cows[i].x == size - 1 && cows[i].d == 'E') || (cows[i].y == size - 1 && cows[i].d == 'N'))
					{
						goto label;
					}
					field[cows[i].x][cows[i].y] = -1;
					if (cows[i].d == 'N')
					{
						cows[i].y += 1;
					}
					else if (cows[i].d == 'E')
					{
						cows[i].x += 1;
					}
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (cows[i].stuck == false)
				{
					if (field[cows[i].x][cows[i].y] == 0 || field[cows[i].x][cows[i].y] == 1)
					{
						field[cows[i].x][cows[i].y] = 1;
						cows[i].ate++;
					}
					else if (field[cows[i].x][cows[i].y] == -1)
					{
						cows[i].stuck = true;
					}
				}
			}
		}
	label:
		for (int i = 0; i < n; i++)
		{
			if (cows[i].stuck == false)
			{
				printf("Infinity\n");
			}
			else
			{
				printf("%lld\n", cows[i].ate);
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			cows[i].ate = 1000000000;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cows[i].d == 'E' && cows[j].d == 'N' && cows[j].x > cows[i].x && cows[j].y < cows[i].y)
				{
					long long intersectionx = cows[j].x;
					long long intersectiony = cows[i].y;
					long long itravel = cows[j].x - cows[i].x;
					long long jtravel = cows[i].y - cows[j].y;
					if (itravel > jtravel && cows[j].ate >= jtravel)
					{
						if (itravel < cows[i].ate)
						{
							cows[i].ate = itravel;
						}
					}
					else if (jtravel > itravel && cows[i].ate >= itravel)
					{
						if (jtravel < cows[j].ate)
						{
							cows[j].ate = jtravel;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (cows[i].d == 'E')
			{
				cows[i].ate = 1000000000;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cows[i].d == 'E' && cows[j].d == 'N' && cows[j].x > cows[i].x && cows[j].y < cows[i].y)
				{
					long long intersectionx = cows[j].x;
					long long intersectiony = cows[i].y;
					long long itravel = cows[j].x - cows[i].x;
					long long jtravel = cows[i].y - cows[j].y;
					if (itravel > jtravel && cows[j].ate >= jtravel)
					{
						if (itravel < cows[i].ate)
						{
							cows[i].ate = itravel;
						}
					}
					else if (jtravel > itravel && cows[i].ate >= itravel)
					{
						if (jtravel < cows[j].ate)
						{
							cows[j].ate = jtravel;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (cows[i].ate == 1000000000)
			{
				printf("Infinity\n");
			}
			else
			{
				printf("%lld\n", cows[i].ate);
			}
		}
	}
}