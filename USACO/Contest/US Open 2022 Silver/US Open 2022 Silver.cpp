#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define LL long long
void usacovisits()
{
	LL num, totalmoo = 0, index = 0;
	cin >> num;
	LL(*next)[2] = (LL(*)[2])calloc(num + 1, 2 * sizeof(LL));
	LL* prev = (LL*)calloc(num + 1, sizeof(LL));
	vector<LL> queue;
	for (LL i = 1; i <= num; i++)
	{
		cin >> next[i][0] >> next[i][1];
		prev[next[i][0]]++;
	}
	for (LL i = 1; i <= num; i++)
	{
		if (prev[i] == 0)
		{
			queue.push_back(i);
		}
	}
	while (true)
	{
		while (index < queue.size())
		{
			if (next[queue[index]][0] == -1)
			{
				index++;
				continue;
			}
			totalmoo += next[queue[index]][1];
			prev[next[queue[index]][0]]--;
			if (prev[next[queue[index]][0]] == 0)
			{
				queue.push_back(next[queue[index]][0]);
			}
			next[queue[index++]][0] = -1;
		}
		LL minval = INT_MAX, minindex = -1;
		for (LL i = 1; i <= num; i++)
		{
			if (next[i][1] < minval && next[i][0] != -1)
			{
				minval = next[i][1];
				minindex = i;
			}
		}
		if (minindex == -1) break;
		queue.push_back(next[minindex][0]);
		next[minindex][0] = -1;
	}
	cout << totalmoo << endl;
}
struct query
{
	string filter;
	char works;
	LL bitmask;
};
void usacosubsetequality()
{
	string s, t; cin >> s >> t;
	LL p = s.length(), q = t.length();
	vector<vector<bool>> one(18, vector<bool>(max(p, q), false));
	vector<vector<bool>> two(18, vector<bool>(max(p, q), false));
	for (long long i = 0; i < p; i++) one[s[i] - 'a'][i] = true;
	for (long long i = 0; i < q; i++) two[t[i] - 'a'][i] = true;
	LL n = 0;
	cin >> n;
	vector<query> queries;
	for (int i = 0; i < n; i++)
	{
		string filter; cin >> filter;
		long long bitmask = 0;
		for (long long i = 0; i < filter.length(); i++) bitmask += (1 << (filter[i] - 'a'));
		queries.push_back({ filter, ' ', bitmask });
	}
	for (long long i = 0; i < n; i++)
	{
		if (queries[i].works != ' ') continue;
		string filter = queries[i].filter, a1 = "", a2 = "";
		long long len1 = 0, len2 = 0;
		for (LL i = 0; i < max(p, q); i++)
		{
			char sum = 0;
			for (char q : filter)
			{
				sum += q * one[q - 'a'][i];
				if (sum != 0) break;
			}
			if (sum != 0)
			{
				len1++;
				a1 += sum;
			}
			sum = 0;
			for (char q : filter)
			{
				sum += q * two[q - 'a'][i];
				if (sum != 0) break;
			}
			if (sum != 0)
			{
				len2++;
				a2 += sum;
			}
			if (len1 == len2 && a1 != a2) break;
		}
		if (a1 == a2)
		{
			queries[i].works = 'Y';
			continue;
		}
		queries[i].works = 'N';
		for (int j = i + 1; j < n; j++)
		{
			if ((queries[j].bitmask & queries[i].bitmask) == queries[i].bitmask)
			{
				queries[j].works = 'N';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << queries[i].works;
	}
	cout << endl;
}
LL C[200001] = { 0 };
LL O[200001] = { 0 };
LL W[200001] = { 0 };
void usacocowoperations()
{
	char ch;
	long long i = 1;
	while ((ch = getchar()) != '\n')
	{
		C[i] = C[i - 1];
		O[i] = O[i - 1];
		W[i] = W[i - 1];
		if (ch == 'C') C[i]++;
		else if (ch == 'O') O[i]++;
		else if (ch == 'W') W[i]++;
		i++;
	}
	LL n;
	cin >> n;
	while (n--)
	{
		LL a, b;
		cin >> a >> b;
		long long c = (C[b] - C[a - 1]) % 2;
		long long o = (O[b] - O[a - 1]) % 2;
		long long w = (W[b] - W[a - 1]) % 2;
		if (c != o && o == w)
		{
			cout << "Y";
		}
		else cout << "N";
	}
	cout << endl;
}