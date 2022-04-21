#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
using namespace std;
bool isPalindrome(string str)
{
	return str == string(str.rbegin(), str.rend());
}
void spring2021easy4()
{
	int n;
	cin >> n;
	string a;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		bool works = false;
		for (int q = 1; q < int(a.length()); q++)
		{
			if (isPalindrome(a.substr(0, q)) == true && isPalindrome(a.substr(q, INT_MAX)) == true)
			{
				works = true;
				break;
			}
		}
		if (works == true)
		{
			count++;
		}
	}
	cout << count;
}