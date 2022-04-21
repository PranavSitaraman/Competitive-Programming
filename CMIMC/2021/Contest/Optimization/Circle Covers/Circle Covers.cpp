#include "Circle Covers.h"
/*
void circlecoversrun()
{
	int n;
	scanf("%d", &n);
	int* peoplex = (int*)malloc(sizeof(int) * n);
	int* peopley = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", peoplex + i, peopley + i);
	}
	int m;
	scanf("%d", &m);
	int* circle = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", circle + i);
	}
	std::sort(peoplex, peoplex + n);
	std::sort(peopley, peopley + n);
	for (int i = m; i >= 1; i--)
	{
		printf("%lf %lf\n", i * float(*(peoplex + n - 1) - *peoplex) / float(m + 1), i * float(*(peopley + n - 1) - *peopley) / float(m + 1));
	}
}
*/
int most = 0;
void findcircle(int depth, int m, int n, int* peoplex, int* peopley, int* circle, float* choicesx, float* choicesy, bool* covered, int count, int min, int max, float* finalx, float* finaly)
{
	if (depth == m)
	{
		for (int i = 0; i < n; i++)
		{
			covered[i] = false;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (sqrt(pow(choicesx[i] - peoplex[j], 2) + pow(choicesy[i] - peopley[j], 2)) <= circle[i])
				{
					covered[j] = true;
				}
			}
		}
		count = 0;
		for (int i = 0; i < n; i++)
		{
			if (covered[i] == true)
			{
				count++;
			}
		}
		if (count > most)
		{
			most = count;
			for (int i = 0; i < m; i++)
			{
				finalx[i] = choicesx[i];
				finaly[i] = choicesy[i];
			}
		}
		if (most == n)
		{
			for (int i = 0; i < m; i++)
			{
				printf("%f %f\n", finalx[i], finaly[i]);
			}
			exit(0);
		}
		return;
	}
	bool good;
	for (float i = min + circle[depth] / (max - min); i <= max - circle[depth] / (max - min); i += 0.1)
	{
		good = true;
		for (int q = 0; q < depth; q++)
		{
			if (circle[depth] / (max - min) > fabs(i - choicesx[q]))
			{
				good = false;
			}
		}
		if (good == true)
		{
			choicesx[depth] = i;
			for (float j = min + circle[depth] / (max - min); j <= max - circle[depth] / (max - min); j += 0.1)
			{
				good = true;
				for (int q = 0; q < depth; q++)
				{
					if (circle[depth] / (max - min) > fabs(j - choicesy[q]))
					{
						good = false;
					}
				}
				if (good == true)
				{
					choicesy[depth] = j;
					findcircle(depth + 1, m, n, peoplex, peopley, circle, choicesx, choicesy, covered, count, min, max, finalx, finaly);
				}
			}
		}
	}
}
void circlecoversrun()
{
	int n;
	scanf("%d", &n);
	int* peoplex = (int*)malloc(sizeof(int) * n);
	int* peopley = (int*)malloc(sizeof(int) * n);
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", peoplex + i, peopley + i);
		if (*(peoplex + i) < min)
		{
			min = *(peoplex + i);
		}
		if (*(peopley + i) < min)
		{
			min = *(peopley + i);
		}
		if (*(peoplex + i) > max)
		{
			max = *(peoplex + i);
		}
		if (*(peopley + i) > max)
		{
			max = *(peopley + i);
		}
	}
	int m;
	scanf("%d", &m);
	int* circle = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", circle + i);
	}
	bool* covered = (bool*)malloc(sizeof(bool) * n);
	for (int i = 0; i < n; i++)
	{
		covered[i] = false;
	}
	float* choicesx = (float*)malloc(sizeof(float) * m);
	float* choicesy = (float*)malloc(sizeof(float) * m);
	float* finalx = (float*)malloc(sizeof(float) * m);
	float* finaly = (float*)malloc(sizeof(float) * m);
	int count = 0;
	findcircle(0, m, n, peoplex, peopley, circle, choicesx, choicesy, covered, count, min, max, finalx, finaly);
	for (int i = 0; i < m; i++)
	{
		printf("%f %f\n", finalx[i], finaly[i]);
	}
}