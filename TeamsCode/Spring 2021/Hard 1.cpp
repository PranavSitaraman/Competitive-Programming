#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
	if (v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] < v2[0]))
	{
		return 0;
	}
	return 1;
}
int val(int pos, vector<int> values, vector<int> friends)
{
	if (values[pos] == 0)
	{
		values[pos] = int(floor(values[friends[pos]] * 0.5));
	}
	return values[pos];
}
void spring2021hard1()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> friends(n + 1, 0);
	vector<int> values(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		values[a] = b;
	}
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		friends[b] = a;
	}
	for (int i = 1; i <= n; i++)
	{
		if (friends[i] != 1)
		{
			values[i] = val(i, values, friends);
		}
	}
	vector<vector<int>> vect;
	vect.push_back({ 0,-100 });
	for (int i = 1; i <= n; i++)
	{
		vect.push_back({ i, values[i] });
	}
	sort(vect.begin(), vect.end(), sortcol);
	for (int i = 0; i < n - 1; i++)
	{
		cout << vect[i][0] << " " << vect[i][1] << "\n";
	}
}