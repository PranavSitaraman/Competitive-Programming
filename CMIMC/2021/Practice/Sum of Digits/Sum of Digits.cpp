#include "Sum of Digits.h"
void sumofdigitsrun()
{
	int t;
	printf("Enter number of integers: ");
	scanf("%d", &t);
	int k[10];
	int sum = 0;
	int digitsum = 0;
	int smallestval = 10000;
	int smallest = 0;
	printf("Enter integers space-separated: ");
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &k[i]);
		getchar();
	}
	for (int i = 0; i < t; i++)
	{
		smallest = 0;
		sum = 0;
		digitsum = 0;
		smallestval = 10000;
		for (int j = 1; j < 1000; j++)
		{
			sum = k[i] * j;
			for (digitsum = 0; sum != 0; digitsum += sum % 10, sum /= 10);
			if (digitsum < smallestval)
			{
				smallestval = digitsum;
				smallest = j;
			}
		}
		printf("Smallest value: %d\n", smallest);
	}
}