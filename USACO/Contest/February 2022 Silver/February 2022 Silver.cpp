#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<bitset>
#include<climits>
#include<stack>
#include<string>
#include<algorithm>
#include<queue>
#include<list>
#include<cmath>
using namespace std;
bool sortcol(const vector<long long>& v1, const vector<long long>& v2)
{
	return v1.size() < v2.size();
}
void find(long long depth, long long n, vector<vector<long long>>& preference, vector<pair<long, long>>& used)
{
	if (depth == n + 1)
	{
		for (long long j = 1; j <= n; j++) if (used[j].second < preference[j][0]) preference[j][0] = used[j].second;
		return;
	}
	for (long long i = 1; i < preference[depth].size(); i++)
	{
		if (used[preference[depth][i]].first == 0)
		{
			used[preference[depth][i]].first = depth;
			used[depth].second = i;
			find(depth + 1, n, preference, used);
			used[preference[depth][i]].first = 0;
			used[depth].second = 0;
		}
	}
}
void redistributinggifts()
{
	long long n; cin >> n;
	vector<vector<long long>> preference(n + 1, {LLONG_MAX});
	vector<pair<long, long>> used(n + 1, { 0, 0 });
	for (long long i = 1, a = 0; i <= n; i++)
	{
		for (long long j = 1; j <= n; j++)
		{
			cin >> a; preference[i].push_back(a);
			if (a == i) { cin.ignore(LLONG_MAX, '\n'); break; }
		}
	}
	find(1, n, preference, used);
	for (long long i = 1; i <= n; i++) cout << preference[i][preference[i][0]] << endl;
}
void robotinstructions()
{
	long long n, x, y; cin >> n >> x >> y;
	vector<pair<long long, long long>> commands(n);
	vector<long long> count(n, 0);
	long long neg = 0;
	for (long long i = 0; i < n; i++)
	{
		cin >> commands[i].first >> commands[i].second;
		if (commands[i].first < 0) neg += commands[i].first;
	}
	sort(commands.begin(), commands.end());
	for (long long i = 1; i < pow(2, n); i++)
	{
		long long sumx = 0, sumy = 0, a = -1;
		for (long long j = 0; j < n; j++)
		{
			if (((i >> j) & 1))
			{
				sumx += commands[j].first;
				sumy += commands[j].second;
				a++;
			}
		}
		if (sumx == x && sumy == y) count[a]++;
	}
	for (long long i = 0; i < n; i++) cout << count[i] << endl;
}
void emailfiling()
{
	long long q; cin >> q;
	while (q--)
	{
		long long m, n, k, curfolder = 1; cin >> m >> n >> k;
		vector<long long> emails(n, 0); vector<long long> last(m + 1, 0);
		for (long long i = 0; i < n; i++) { cin >> emails[i]; last[emails[i]] = i; }
		for (long long i = 0; i < emails.size() - k + 1; i++)
		{
			for (long long j = i; j < i + k && j < emails.size(); j++)
			{
				if (emails[j] >= curfolder && emails[j] <= curfolder + k - 1)
				{
					emails.erase(emails.begin() + j);
					if (last[curfolder] == j--) curfolder++;
					for (long long k = 1; k <= m; k++) if (last[k] > j + 1) last[k]--;
				}
			}
		}
		if (emails.size() > 0) curfolder = max(curfolder, emails[0] - k + 1);
		else { cout << "YES" << endl; continue; }
		reverse(emails.begin(), emails.end());
		for (long long i = 0; i < emails.size(); i++) last[emails[i]] = i;
		for (long long i = 0; i < k && i < emails.size(); i++)
		{
			if (emails[i] >= curfolder && emails[i] <= curfolder + k - 1)
			{
				emails.erase(emails.begin() + i);
				if (last[curfolder] == i--) curfolder++;
				for (long long j = 1; j <= m; j++) if (last[j] > i + 1) last[j]--;
			}
		}
		cout << (emails.size() ? "NO" : "YES") << endl;
	}
}