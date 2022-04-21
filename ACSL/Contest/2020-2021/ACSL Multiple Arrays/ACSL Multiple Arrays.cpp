#include "ACSL Multiple Arrays.h"
using namespace std;
int sumOfLargest(string a1, string a2, string a3)
{
	int sizea1 = count(a1.begin(), a1.end(), ' ') + 1;
	int sizea2 = count(a2.begin(), a2.end(), ' ') + 1;
	int sizea3 = count(a3.begin(), a3.end(), ' ') + 1;
	int size = max(sizea1, max(sizea2, sizea3));
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		int one = 0, two = 0, three = 0;
		static int p = 0, q = 0, r = 0;
		bool negative = false;
		if (i < sizea1)
		{
			while (p < int(a1.length()) && a1[p] != ' ')
			{
				if (a1[p] != '-')
				{
					one = one * 10 + int(a1[p]) - '0';
				}
				else
				{
					negative = true;
				}
				p++;
			}
			p++;
		}
		else
		{
			one = INT_MIN;
		}
		if (negative == true)
		{
			one = -one;
		}
		negative = false;
		if (i < sizea2)
		{
			while (q < int(a2.length()) && a2[q] != ' ')
			{
				if (a2[q] != '-')
				{
					two = two * 10 + int(a2[q]) - '0';
				}
				else
				{
					negative = true;
				}
				q++;
			}
			q++;
		}
		else
		{
			two = INT_MIN;
		}
		if (negative == true)
		{
			two = -two;
		}
		negative = false;
		if (i < sizea3)
		{
			while (r < int(a3.length()) && a3[r] != ' ')
			{
				if (a3[r] != '-')
				{
					three = three * 10 + int(a3[r]) - '0';
				}
				else
				{
					negative = true;
				}
				r++;
			}
			r++;
		}
		else
		{
			three = INT_MIN;
		}
		if (negative == true)
		{
			three = -three;
		}
		sum += max(one, max(two, three));
	}
	return sum;
}
void acslmultiplearraysrun()
{
	string a1 = "160 8 1 5 2 3 5 3 7 9";
	string a2 = "7 6 2 9";
	string a3 = "9 3 4 6 1 8 6 4 2 8 4";
	int result = sumOfLargest(a1, a2, a3);
	cout << result << "\n";
}