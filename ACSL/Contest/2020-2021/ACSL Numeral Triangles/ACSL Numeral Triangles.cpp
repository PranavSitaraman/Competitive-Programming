#include "ACSL Numeral Triangles.h"
int digitsum(int num)
{
	int digitsum = num;
	while (digitsum >= 10) { num = digitsum; for (digitsum = 0; num != 0; digitsum += num % 10, num /= 10); }
	return digitsum;
}
int sumOfLastRow(int s, int d, int r)
{
	int sum = 0, num = digitsum(s + ((r * (r - 1)) / 2 - 1) * d);
	for (int i = 0; i < r; i++, num = digitsum(num + d), sum += num);
	return sum;
}
void acslnumeraltrianglesrun()
{
	printf("%d", sumOfLastRow(2468, 23, 3));
}