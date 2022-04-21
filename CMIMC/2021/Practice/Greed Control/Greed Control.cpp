#include "Greed Control.h"
void greedcontrolrun()
{
	int n;
	int entries[10] = { 0 };
	printf("Enter number of entries: ");
	scanf("%d", &n);
	int k;
	printf("Enter k for range 0 to k: ");
	scanf("%d", &k);
	printf("Enter entries separated by spaces: ");
	float largestval = 0;
	int largest = 0;
	int counter = 0;
	float val = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &entries[i]);
		getchar();
	}
	for (int i = 1; i <= k; i++)
	{
		counter = 0;
		val = 0;
		for (int j = 0; j < n; j++)
		{
			if (entries[j] == i)
			{
				counter++;
			}
		}
		val = float(i) / float(counter + 1);
		if (val > largestval)
		{
			largestval = val;
			largest = i;
		}
	}
	printf("Optimal value: %d", largest);
}