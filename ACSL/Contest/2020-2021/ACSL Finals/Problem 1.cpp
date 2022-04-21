#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
int find_max_sum_of_subrect(string values)
{
	stringstream split(values);
	vector<int> num;
	string word;
	int n, m;
	int i = 0;
	while (split >> word)
	{
		if (i == 0)
		{
			n = stoi(word);
		}
		else if (i == 1)
		{
			m = stoi(word);
		}
		else
		{
			num.push_back(stoi(word));
		}
		i++;
	}
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = i; k < n; k++)
			{
				for (int l = j; l < m; l++)
				{
					int sum = 0;
					for (int a = i; a <= k; a++)
					{
						for (int b = j; b <= l; b++)
						{
							sum += num[a * m + b];
						}
					}
					if (sum > max)
					{
						max = sum;
					}
				}
			}
		}
	}
	return max;
}
void acslfinalsonerun()
{
	cout << find_max_sum_of_subrect("1 2 3 7");
}