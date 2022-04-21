#include "ACSL Fibonacci and Pascal.h"
using namespace std;
long long longFactorial(long long a, long long b, long long c)
{
	long long q = 1;
	if (c != 0) q = longFactorial(c, 0, 0);
	long long product = 1;
	for (long long i = b + 1; i <= a; i++) { product *= i; if (product % q == 0) product /= q; }
	return product;
}
bool evenOrOdd(long long a, long long b, long long c)
{
	long long a1 = 0, b1 = 0, c1 = 0;
	while (a > 0) { a /= 2; a1 += a; }
	while (b > 0) { b /= 2; b1 += b; }
	while (c > 0) { c /= 2; c1 += c; }
	return (a1 > b1 + c1);
}
string findOddEvenMax(int fibNumber)
{
	long long prev0 = 1, prev1 = 1, n = 1;
	while (prev1 != fibNumber) { long long next = prev0 + prev1; prev0 = prev1; prev1 = next; n++; }
	long long odd = 0, even = 0, max = 0;
	for (long long i = 0; i <= n / 2; i++)
	{
		if (evenOrOdd(n - i, n - 2 * i, i)) even++; else odd++;
		long long a = longFactorial(n - i, n - 2 * i, i);
		if (a < 10000000000L && a > 0 && a > max) max = a;
	}
	return to_string(odd) + " " + to_string(even) + " " + to_string(max);
}
void acslfibandpascal()
{
	cout << findOddEvenMax(1);
}