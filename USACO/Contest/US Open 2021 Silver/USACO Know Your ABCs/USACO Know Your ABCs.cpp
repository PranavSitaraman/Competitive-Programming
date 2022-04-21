#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check(vector<int> arr, int a, int b, int c)
{
	int newarr[7] = { a, b, c, a + b, a + c, b + c, a + b + c };
	bool good = true;
	for (int i = 0; i < 7; i++)
	{
		if (find(arr.begin(), arr.end(), newarr[i]) == arr.end())
		{
			good = false;
			break;
		}
	}
	return good;
}
bool check(vector<int> arr, int a, int b, int c, int not1)
{
	int newarr[7] = { a, b, c, a + b, a + c, b + c, a + b + c };
	bool good = true;
	for (int i = 0; i < 7; i++)
	{
		if (newarr[i] != not1)
		{
			if (find(arr.begin(), arr.end(), newarr[i]) == arr.end())
			{
				good = false;
				break;
			}
		}
	}
	return good;
}
bool check(vector<int> arr, int a, int b, int c, int not1, int not2)
{
	int newarr[7] = { a, b, c, a + b, a + c, b + c, a + b + c };
	bool good = true;
	for (int i = 0; i < 7; i++)
	{
		if (i != not1 && i != not2)
		{
			if (find(arr.begin(), arr.end(), newarr[i]) == arr.end())
			{
				good = false;
				break;
			}
		}
	}
	return good;
}
bool check(vector<int> arr, int a, int b, int c, int not1, int not2, int not3)
{
	int newarr[7] = { a, b, c, a + b, a + c, b + c, a + b + c };
	bool good = true;
	for (int i = 0; i < 7; i++)
	{
		if (i != not1 && i != not2 && i != not3)
		{
			if (find(arr.begin(), arr.end(), newarr[i]) == arr.end())
			{
				good = false;
				break;
			}
		}
	}
	return good;
}
void usacoknowyourabcsrun()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		vector<int>arr;
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		if (k == 7)
		{
			int a = arr[0];
			int b = arr[1];
			int c = arr[6] - a - b;
			if (check(arr, a, b, c))
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (k == 6)
		{
			int counter = 0;
			{
				int a = arr[0];
				int b = arr[1];
				int c = arr[5] - b;
				if (check(arr, a, b, c, a + b + c))
				{
					counter++;
				}
			}
			{
				int a = arr[0];
				int b = arr[1];
				int c = arr[5] - b - a;
				if (check(arr, a, b, c, b + c))
				{
					counter++;
				}
			}
			{
				int a = arr[0];
				int b = arr[1];
				int c = arr[5] - b - a;
				if (check(arr, a, b, c, a + c))
				{
					counter++;
				}
			}
			{
				int a = arr[0];
				int b = arr[1];
				int c = arr[5] - b - a;
				if (check(arr, a, b, c, a + b))
				{
					counter++;
				}
			}
			{
				int a = arr[0];
				int b = arr[1];
				int c = arr[5] - b - a;
				if (check(arr, a, b, c, c))
				{
					counter++;
				}
			}
			{
				int a = arr[0];
				int b = arr[4] - arr[3] + a;
				int c = arr[5] - b - a;
				if (check(arr, a, b, c, b))
				{
					counter++;
				}
			}
			{
				int b = arr[0];
				int c = arr[4] - b;
				int a = arr[5] - arr[4];
				if (check(arr, a, b, c, a))
				{
					counter++;
				}
			}
			cout << counter << endl;
		}
		else if (k == 5)
		{
			int counter = 0;
			for (int p = 0; p < 7; p++)
			{
				for (int q = p + 1; q < 7; q++)
				{
					int a = 0, b = 0, c = 0;
					if (p != 0 && p != 1 && p != 6 && q != 0 && q != 1 && q != 6)
					{
						a = arr[0];
						b = arr[1];
						c = arr[4] - a - b;
					}
					else if (p == 0 && (q == 1 || q == 2))
					{
						a = arr[4] - arr[3];
						b = arr[4] - arr[2];
						c = arr[4] - a - b;
					}
					else if (p == 0 && q == 3)
					{
						b = arr[0];
						c = arr[1];
						a = arr[4] - a - b;
					}
					else if (p == 0 && q == 4)
					{
						b = arr[0];
						c = arr[3] - b;
						a = arr[4] - a - b;
					}
					else if (p == 0 && q == 5)
					{
						b = arr[0];
					}
					else if (p == 0 && q == 6)
					{
						b = arr[0];
						c = arr[4] - arr[0];
						a = arr[3] - c;
					}
					else if (p == 1 && q == 6)
					{
						a = arr[0];
						c = arr[3] - a;
						b = arr[4] - c;
					}
					if (check(arr, a, b, c, p, q))
					{
						counter++;
					}
				}
			}
		}
		else if (k == 4)
		{
			for (int p = 0; p < 7; p++)
			{
				for (int q = p + 1; q < 7; q++)
				{
					for (int r = q + 1; r < 7; r++)
					{
						int a = 0, b = 0, c = 0;
						check(arr, a, b, c, p, q, r);
					}
				}
			}
		}
	}
}