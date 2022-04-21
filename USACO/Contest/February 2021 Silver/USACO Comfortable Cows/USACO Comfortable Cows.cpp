#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define maxval 1000000
#define maxsize 1020
int arr[maxsize][maxsize] = { 0 };
int num[maxval][2] = { 0 };
int comfortable(int, int, int[maxsize][maxsize], int[maxval][2]);
int comf(int a, int b, int arr[maxsize][maxsize], int num[maxval][2])
{
	int count = 0; int need = 0; if (arr[a][b] == 0) return need;
	if (arr[a - 1][b] != 0) count++; if (arr[a + 1][b] != 0) count++; if (arr[a][b - 1] != 0) count++; if (arr[a][b + 1] != 0) count++;
	if (count == 3)
	{
		if (arr[a - 1][b] == 0)
		{
			arr[a - 1][b] = -1;
			need += comfortable(a - 1, b, arr, num);
			need += comfortable(a - 2, b, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a - 1, b + 1, arr, num);
			need += comfortable(a - 1, b - 1, arr, num);
		}
		else if (arr[a + 1][b] == 0)
		{
			arr[a + 1][b] = -1;
			need += comfortable(a + 1, b, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a + 2, b, arr, num);
			need += comfortable(a + 1, b + 1, arr, num);
			need += comfortable(a + 1, b - 1, arr, num);
		}
		else if (arr[a][b - 1] == 0)
		{
			arr[a][b - 1] = -1;
			need += comfortable(a, b - 1, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a, b - 2, arr, num);
			need += comfortable(a - 1, b - 1, arr, num);
			need += comfortable(a + 1, b - 1, arr, num);
		}
		else if (arr[a][b + 1] == 0)
		{
			arr[a][b + 1] = -1;
			need += comfortable(a, b + 1, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a, b + 2, arr, num);
			need += comfortable(a - 1, b + 1, arr, num);
			need += comfortable(a + 1, b + 1, arr, num);
		}
		need++;
	}
	return need;
}
int comfortable(int a, int b, int arr[maxsize][maxsize], int num[maxval][2])
{
	int count = 0; int need = 0; if (arr[a][b] == 0) return need;
	if (arr[a - 1][b] != 0) count++; if (arr[a + 1][b] != 0) count++; if (arr[a][b - 1] != 0) count++; if (arr[a][b + 1] != 0) count++;
	if (count == 3)
	{
		if (arr[a - 1][b] == 0)
		{
			arr[a - 1][b] = -1;
			need += comfortable(a - 1, b, arr, num);
			need += comfortable(a - 2, b, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a - 1, b + 1, arr, num);
			need += comfortable(a - 1, b - 1, arr, num);
		}
		else if (arr[a + 1][b] == 0)
		{
			arr[a + 1][b] = -1;
			need += comfortable(a + 1, b, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a + 2, b, arr, num);
			need += comfortable(a + 1, b + 1, arr, num);
			need += comfortable(a + 1, b - 1, arr, num);
		}
		else if (arr[a][b - 1] == 0)
		{
			arr[a][b - 1] = -1;
			need += comfortable(a, b - 1, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a, b - 2, arr, num);
			need += comfortable(a - 1, b - 1, arr, num);
			need += comfortable(a + 1, b - 1, arr, num);
		}
		else if (arr[a][b + 1] == 0)
		{
			arr[a][b + 1] = -1;
			need += comfortable(a, b + 1, arr, num);
			need += comfortable(a, b, arr, num);
			need += comfortable(a, b + 2, arr, num);
			need += comfortable(a - 1, b + 1, arr, num);
			need += comfortable(a + 1, b + 1, arr, num);
		}
		need++;
	}
	else
	{
		need += comf(a - 1, b, arr, num);
		need += comf(a + 1, b, arr, num);
		need += comf(a, b + 1, arr, num);
		need += comf(a, b - 1, arr, num);
	}
	return need;
}
void usacocomfortablecowsrun()
{
	int n, a, b, need = 0; scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b); num[i][0] = a + 6; num[i][1] = b + 6;
		if (arr[num[i][0]][num[i][1]] == -1) need--; else if ((arr[num[i][0]][num[i][1]] = 1) == 1) need += comfortable(num[i][0], num[i][1], arr, num);
		printf("%d\n", need);
	}
}