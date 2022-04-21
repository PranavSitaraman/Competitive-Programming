#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int dfs(int pos, vector<bool> hidden, vector<vector<int>> flights, vector<int> scores)
{
	int val = 1;
	for (int i = 0; i < flights.size(); i++)
	{
		if (flights[i][0] == pos && hidden[flights[i][1]] == false)
		{
			hidden[pos] = true;
			hidden[flights[i][1]] = true;
			int a = dfs(flights[i][1], hidden, flights, scores);
			val += a;
			scores[flights[i][1]] = a;
			hidden[flights[i][1]] = false;
			hidden[pos] = false;
		}
		else if (flights[i][1] == pos && hidden[flights[i][0]] == false)
		{
			hidden[pos] = true;
			hidden[flights[i][0]] = true;
			int a = dfs(flights[i][0], hidden, flights, scores);
			val += a;
			scores[flights[i][0]] = a;
			hidden[pos] = false;
			hidden[flights[i][0]] = false;
		}
	}
	return val;
}
void spring2021hard2()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> flights;
	vector<vector<int>> multiple;
	vector<bool> hidden;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<int> start = { a, b };
		vector<int> end = { c, d };
		int p = -1, q = -1;
		for (int i = 0; i < multiple.size(); i++)
		{
			if (start == multiple[i])
			{
				p = i;
			}
			else if (end == multiple[i])
			{
				q = i;
			}
			if (p != -1 && q != -1)
			{
				break;
			}
		}
		if (p == -1)
		{
			multiple.push_back(start);
			hidden.push_back(false);
			p = multiple.size() - 1;
		}
		if (q == -1)
		{
			multiple.push_back(end);
			hidden.push_back(false);
			q = multiple.size() - 1;
		}
		flights.push_back({ p, q });
	}
	vector<int> scores(multiple.size(), 0);
	int value = n * n - multiple.size();
	for (int i = 0; i < multiple.size(); i++)
	{
		if (scores[i] == 0)
		{
			int a = dfs(i, hidden, flights, scores);
			scores[i] = a;
			value += a;
		}
	}
	cout << value;
}