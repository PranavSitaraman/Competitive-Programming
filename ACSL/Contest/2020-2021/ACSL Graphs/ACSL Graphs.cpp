#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int findCharacteristic(int choice, string edges)
{
	vector<vector<int>> num;
	int i = 0;
	int max = 0;
	while (i < int(edges.size()))
	{
		if (int(edges[i] - '0') > max)
		{
			max = int(edges[i] - '0');
		}
		else if (int(edges[i + 1] - '0') > max)
		{
			max = int(edges[i + 1] - '0');
		}
		num.push_back({ int(edges[i++] - '0'), int(edges[i++] - '0') });
		i++;
	}
	if (choice == 1)
	{
		int count = 0;
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i][0] == num[i][1])
			{
				count++;
			}
			for (int j = i + 1; j < num.size(); j++)
			{
				if (num[i][1] == num[j][0] && num[j][1] == num[i][0] && j != i)
				{
					count++;
				}
			}
		}
		return count;
	}
	else if (choice == 2)
	{
		int correctsum = 0;
		int maxnum = 0;
		for (int j = 0; j < max; j++)
		{
			int sum = 0;
			int match = 0;
			for (int i = 0; i < num.size(); i++)
			{
				if (num[i][0] == j)
				{
					match++;
					sum += num[i][0] * 10 + num[i][1];
				}
			}
			if (match > maxnum)
			{
				maxnum = match;
				correctsum = sum;
			}
		}
		return correctsum;
	}
	else if (choice == 3)
	{
		int count = 0;
		for (int i = 0; i < num.size(); i++)
		{
			for (int j = 0; j < num.size(); j++)
			{
				if (num[i][1] == num[j][0])
				{
					count++;
				}
			}
		}
		return count;
	}
	return 0;
}
void acslgraphsrun(void)
{
	int choice = 1;
	string edges = "12 23 34 11 21 32 45 53 95 43 99 29 91";
	cout << findCharacteristic(choice, edges);
}