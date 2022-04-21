#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<fstream>
using namespace std;
struct location
{
	long long x;
	long long val;
	long long min;
	long long max;
};
bool sortnumberline(location a, location b)
{
	return (a.x < b.x);
}
bool sortcow(long long a, long long b)
{
	return (a < b);
}
bool arrangemin(location a, location b)
{
	return (a.min < b.min);
}
bool sortdescending(location a, location b)
{
	return (a.val > b.val);
}
vector<location> patch;
vector<long long> nhoj;
void closestcow()
{
	long long k, m, n;
	ifstream in;
	cin >> k >> m >> n;
	for (long long i = 0; i < k; i++)
	{
		long long a, b;
		cin >> a >> b;
		patch.push_back({ a, b, 0, 0 });
	}
	for (long long i = 0; i < m; i++)
	{
		long long a;
		cin >> a;
		nhoj.push_back(a);
	}
	sort(patch.begin(), patch.end(), sortnumberline);
	sort(nhoj.begin(), nhoj.end(), sortcow);
	long long prev = 0;
	for (long long i = 0; i < k; i++)
	{
		long long min = LLONG_MAX;
		for (long long j = prev; j < m; j++)
		{
			if (abs(nhoj[j] - patch[i].x) < min)
			{
				min = abs(nhoj[j] - patch[i].x);
			}
			else
			{
				prev = j - 1;
				break;
			}
		}
		patch[i].min = patch[i].x - min;
		patch[i].max = patch[i].x + min;
	}
	sort(patch.begin(), patch.end(), arrangemin);
	for (long long i = 0; i < (long long) patch.size() - 1; i++)
	{
		long long j = i + 1;
		while (true)
		{
			long long maximum = 0;
			long long minimum = 0;
			if (j >= (long long) patch.size())
			{
				break;
			}
			if (patch[i].max > patch[j].min)
			{
				maximum = min(patch[i].max, patch[j].max);
				minimum = max(patch[i].min, patch[j].min);
			}
			else
			{
				break;
			}
			patch[j].val += patch[i].val;
			patch[j].min = minimum;
			patch[j].max = maximum;
			patch[i].x = LLONG_MIN;
			i++;
			j++;
		}
	}
	sort(patch.begin(), patch.end(), sortdescending);
	long long total = 0;
	for (long long i = 0; i < n; i++)
	{
		if (patch[i].x != LLONG_MIN && patch[i].min != patch[i].max)
		{
			total += patch[i].val;
		}
		else
		{
			n++;
		}
	}
	cout << total << endl;
}