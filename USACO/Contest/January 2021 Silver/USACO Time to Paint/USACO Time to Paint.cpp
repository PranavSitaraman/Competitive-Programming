#include "USACO Time to Paint.h"
int findpaint(char* colors, int left, int right)
{
	char lowest = 'Z';
	char secondlowest = 'Z';
	char nextlowest = 'Z';
	int count = 1;
	bool contiguous = false;
	for (int i = left; i <= right; i++)
	{
		if (*(colors + i) < lowest)
		{
			secondlowest = lowest;
			lowest = *(colors + i);
		}
		else if (*(colors + i) > lowest && *(colors + i) < secondlowest)
		{
			secondlowest = *(colors + i);
		}
	}
	for (int num = 0; num < 26; num++)
	{
		contiguous = false;
		for (int i = left; i <= right; i++)
		{
			if (*(colors + i) <= lowest)
			{
				contiguous = false;
			}
			else if (*(colors + i) == secondlowest && i >= left && contiguous == false)
			{
				count++;
				contiguous = true;
			}
			if (*(colors + i) < nextlowest && *(colors + i) > secondlowest)
			{
				nextlowest = *(colors + i);
			}
		}
		lowest = secondlowest;
		secondlowest = nextlowest;
		nextlowest = 'Z';
	}
	return count;
}
void usacotimetopaintrun()
{
	int n, q;
	scanf("%d %d", &n, &q);
	char* colors = (char*)malloc(n * sizeof(char));
	int val1, val2;
	int count1, count2;
	scanf("%s", colors);
	char letters[26] = { 0 };
	for (int i = 0; i < q; i++)
	{
		count1 = 0, count2 = 0;
		scanf("%d %d", &val1, &val2);
		if (val1 > 1)
		{
			count1 = findpaint(colors, 0, val1 - 2);
		}
		if (val2 < n)
		{
			count2 = findpaint(colors, val2, n - 1);
		}
		printf("%d\n", count1 + count2);
	}
}