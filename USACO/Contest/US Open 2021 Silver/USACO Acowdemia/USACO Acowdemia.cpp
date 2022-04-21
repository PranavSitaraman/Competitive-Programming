#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int h = 0;
int findh(vector<int> citations)
{
	while (true)
	{
		int counter = 0;
		for (int i = 0; i < citations.size(); i++)
		{
			if (citations[i] >= h)
			{
				counter++;
			}
		}
		if (counter >= h)
		{
			h++;
		}
		else
		{
			break;
		}
	}
	return h - 1;
}
void usacoacowdemiarun()
{
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> citations;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		citations.push_back(a);
	}
	h = findh(citations);
	if (l < h + 1)
	{
		for (int i = 0; i < k; i++)
		{
			sort(citations.begin(), citations.end());
			for (int j = 0; j < l; j++)
			{
				for (int a = citations.size() - 1; a > 0; a--)
				{
					if (citations[a] < h + 1)
					{
						citations[a]++;
						break;
					}
				}
			}
			h = findh(citations);
		}
	}
	else
	{
		vector<int> taken;
		for (int i = 0; i < k; i++)
		{
			sort(citations.begin(), citations.end());
			for (int j = 0; j < l; j++)
			{
				citations[j]++;
			}
		}
	}
	cout << findh(citations) << endl;
}