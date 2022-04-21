#include "Unique Products.h"
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int findPrime(int m)
{
    int count = 0;
    for (int i = 2; i <= m; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}
void printPrime(int m, int n, int each)
{
    int count = 0;
    int num = 0;
    for (int i = 2; i <= m; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
            count++;
            if (count == each)
            {
                printf("\n");
                count = 0;
                num++;
            }
            if (num == n)
            {
                return;
            }
        }
    }
}
void uniqueproductsrun()
{
	int n, m;
	scanf("%d %d", &n, &m);
    int count = 0;
    int each = 0;
    count = findPrime(m);
    each = count / n;
    printPrime(m, n, each);
}