#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
void punchedcards()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << "Case #" << i << ":" << endl;
		cout << "..+";
		for (int i = 1; i < b; i++)
		{
			cout << "-+";
		}
		cout << endl << "..|";
		for (int i = 1; i < b; i++)
		{
			cout << ".|";
		}
		cout << endl;
		for (int i = 0; i < b; i++)
		{
			cout << "+-";
		}
		cout << "+" << endl;
		for (int i = 1; i < a; i++)
		{
			for (int i = 0; i < b; i++)
			{
				cout << "|.";
			}
			cout << "|" << endl;
			for (int i = 0; i < b; i++)
			{
				cout << "+-";
			}
			cout << "+" << endl;
		}
	}
}
void threedprinting()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long arr[4][4] = { 0 };
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> arr[i][j];
			}
		}
		cout << "Case #" << i << ":";
		for (int i = 0; i < 4; i++)
		{
			arr[3][i] = min(min(arr[0][i], arr[1][i]), arr[2][i]);
		}
		long long sum = 0;
		for (int i = 0; i < 4; i++)
		{
			sum += arr[3][i];
		}
		if (sum < 1000000L)
		{
			cout << " IMPOSSIBLE" << endl;
		}
		else
		{
			long long diff = sum - 1000000L;
			int j = 0;
			for (int i = 0; i < 4; i++)
			{
				if (arr[3][i] <= diff)
				{
					diff -= arr[3][i];
					arr[3][i] = 0;
				}
				else
				{
					arr[3][i] -= diff;
					diff = 0;
				}
				if (diff == 0) break;
			}
			for (int i = 0; i < 4; i++)
			{
				cout << " " << arr[3][i];
			}
			cout << endl;
		}
	}
}
void d1000000()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a; cin >> a;
		vector<int> dice;
		for (int i = 0; i < a; i++)
		{
			int b;
			cin >> b;
			dice.push_back(b);
		}
		sort(dice.begin(), dice.end());
		int max = 0;
		for (int j = 0; j <= a; j++)
		{
			int ans = 0;
			for (int i = 1; i + j <= a; i++)
			{
				if (i > dice[i - 1 + j])
				{
					ans = i - 1;
					break;
				}
			}
			if (ans == 0)
			{
				max = a - j;
				break;
			}
			if (ans > max) max = ans;
		}
		cout << "Case #" << i << ": " << max << endl;
	}
}
#define LL long long
LL operate(LL index, vector<LL>& val, vector<vector<LL>>& prev, LL& totalval)
{
	if (prev[index].size() == 0) return val[index];
	else
	{
		LL minimum = INT_MAX;
		LL total = 0;
		for (LL i = 0; i < prev[index].size(); i++)
		{
			LL next = operate(prev[index][i], val, prev, totalval);
			total += next;
			if (next < minimum) minimum = next;
		}
		totalval += total - minimum;
		return max(val[index], minimum);
	}
}
void chainreactions()
{
	LL n; cin >> n;
	for (LL i = 1; i <= n; i++)
	{
		LL num, totalval = 0;
		cin >> num;
		vector<LL> val(num + 1);
		vector<vector<LL>> prev(num + 1);
		vector<LL> queue;
		for (LL i = 1; i <= num; i++) cin >> val[i];
		for (LL i = 1; i <= num; i++)
		{
			LL a; cin >> a;
			if (a == 0) queue.push_back(i);
			else prev[a].push_back(i);
		}
		for (int i = 0; i < queue.size(); i++)
		{
			LL a = operate(queue[i], val, prev, totalval);
			totalval += a;
		}
		cout << "Case #" << i << ": " << totalval << endl;
	}
}
void twistylittlepassages()
{
	LL num; cin >> num;
	while (num--)
	{
		LL n, k, x, y, total = 0, count = 0; cin >> n >> k >> x >> y;
		vector<LL> visited(n + 1, 0);
		visited[x] = y;
		for (LL j = 0; j < k; j++)
		{
			bool works = false;
			while (true)
			{
				int i = rand() % n + 1;
				if (visited[i] == 0)
				{
					cout << "T " << i << endl;
					works = true;
					break;
				}
			}
			cin >> x >> y;
			visited[x] = y;
		}
		for (LL i = 1; i <= n; i++)
		{
			total += visited[i];
			if (visited[i] != 0) count++;
		}
		total = total + (n - count) * float(total) / float(count);
		total /= 2.0;
		cout << "E " << total << endl;;
	}
}