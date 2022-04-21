#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<algorithm>
#include<string.h>
int pathcount;
int changex[4] = { 1, 0, -1, 0 };
int changey[4] = { 0, 1, 0, -1 };
void findpath(int prefixx, int prefixy, int n, int k, bool used[10][10], int obstacle[10][2])
{
	if (prefixx == n && prefixy == n)
	{
		pathcount++;
		return;
	}
	bool obstaclepresent = false;
	for (int j = 0; j < k; j++)
	{
		if (obstacle[j][0] == prefixx && obstacle[j][1] == prefixy)
		{
			obstaclepresent = true;
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (used[prefixx][prefixy] == false && obstaclepresent == false && prefixx >= 1 && prefixx <= n && prefixy >= 1 && prefixy <= n)
		{
			used[prefixx][prefixy] = true;
			findpath(prefixx + changex[i], prefixy + changey[i], n, k, used, obstacle);
			used[prefixx][prefixy] = false;
		}
	}
	return;
}
void robotrecoveryrun(void)
{
	pathcount = 0;
	int n;
	printf("Enter size of dungeon: ");
	scanf("%d", &n);
	getchar();
	int k;
	printf("Enter number of obstacles: ");
	scanf("%d", &k);
	getchar();
	printf("Enter obstacles on individual lines in the form x, y:\n");
	int obstacles[10][2];
	bool used[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			used[i][j] = false;
			if (j >= 0 && j < 2)
			{
				obstacles[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		scanf("%d, %d", &obstacles[i][0], &obstacles[i][1]);
		getchar();
	}
	findpath(1, 1, n, k, used, obstacles);
	printf("Number of paths: %d", pathcount);
}