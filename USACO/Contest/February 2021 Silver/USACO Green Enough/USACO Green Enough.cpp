#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#define maxsize 200
using namespace std;
void usacogreenenoughrun(void)
{
	vector<vector<int>> arr(maxsize, vector<int>(maxsize));
	vector<int> badx;
	vector<int> bady;
	vector<int> hundredx;
	vector<int> hundredy;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
			if (temp == 100)
			{
				hundredx.push_back(i);
				hundredy.push_back(j);
			}
			else if (temp < 100)
			{
				badx.push_back(i);
				bady.push_back(j);
			}
		}
	}
	bool shouldcontinue = false;
	long long total = 0;
	for (int i = 0; i < n; i++)
	{
		shouldcontinue = false;
		for (int x = 0; x < hundredx.size(); x++)
		{
			if (hundredx[x] >= i)
			{
				shouldcontinue = true;
				break;
			}
		}
		if (shouldcontinue == false)
		{
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			if (find(badx.begin(), badx.end(), i) != badx.end() && find(bady.begin(), bady.end(), j) != bady.end())
			{
				if (find(badx.begin(), badx.end(), i) - badx.begin() == find(bady.begin(), bady.end(), j) - bady.begin())
				{
					continue;
				}
			}
			shouldcontinue = false;
			for (int x = 0; x < hundredx.size(); x++)
			{
				if (hundredx[x] >= i && hundredy[x] >= j)
				{
					shouldcontinue = true;
					break;
				}
			}
			if (shouldcontinue == false)
			{
				continue;
			}
			for (int k = i; k < n; k++)
			{
				shouldcontinue = false;
				for (int x = 0; x < hundredx.size(); x++)
				{
					if (hundredx[x] >= i && hundredx[x] <= k)
					{
						shouldcontinue = true;
						break;
					}
				}
				if (shouldcontinue == false)
				{
					continue;
				}
				for (int l = j; l < n; l++)
				{
					if (find(badx.begin(), badx.end(), k) != badx.end() && find(bady.begin(), bady.end(), l) != bady.end())
					{
						if (find(badx.begin(), badx.end(), k) - badx.begin() == find(bady.begin(), bady.end(), l) - bady.begin())
						{
							continue;
						}
					}
					bool correct = true;
					bool hundred = false;
					for (int x = 0; x < badx.size(); x++)
					{
						if (badx[x] >= i && badx[x] <= k && bady[x] >= j && bady[x] <= l)
						{
							correct = false;
							break;
						}
					}
					for (int x = 0; x < hundredx.size(); x++)
					{
						if (hundredx[x] >= i && hundredx[x] <= k && hundredy[x] >= j && hundredy[x] <= l)
						{
							hundred = true;
							break;
						}
					}
					if (correct == true && hundred == true)
					{
						total++;
					}
				}
			}
		}
	}
	cout << total << endl;
}