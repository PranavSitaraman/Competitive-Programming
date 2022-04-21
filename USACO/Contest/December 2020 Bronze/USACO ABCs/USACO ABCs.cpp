#include "USACO ABCs.h"
void usacoabcrun()
{
	long long array[7] = { 0 };
	for (int i = 0; i < 7; i++)
	{
		scanf("%lld", &array[i]);
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (array[i] > array[j])
			{
				long long temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	long long a = array[0];
	long long b = array[1];
	long long c = array[6] - a - b;
	printf("%lld %lld %lld", a, b, c);
}