#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<numeric>
#include<list>
#include<map>
#include<set>
using namespace std;
#define ll long long
void agrinet()
{
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");
	ll n; fin >> n;
	ll k = n * (n - 1);
	vector<vector<ll>> nodes(k, vector<ll>(3, 0));
	ll count = 0;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			ll q; fin >> q;
			if (i != j)
			{
				nodes[count][0] = i + 1;
				nodes[count][1] = j + 1;
				nodes[count][2] = q;
				count++;
			}
		}
	}
	vector<ll> dist(n + 1, INT_MAX - 1);
	vector<ll> visited(n + 1, 0);
	vector<ll> previous(n + 1, -1);
	dist[1] = 0;
	bool empty = true;
	ll v = 0;
	while (empty == true)
	{
		ll largest = INT_MAX;
		for (ll i = 1; i <= n; i++) if (visited[i] == 0 && dist[i] < largest) largest = dist[v = i];
		visited[v] = 1;
		for (ll i = 0; i < k; i++)
		{
			if (nodes[i][0] == v)
			{
				if (visited[nodes[i][1]] == 0)
				{
					if (nodes[i][2] < dist[nodes[i][1]])
					{
						dist[nodes[i][1]] = nodes[i][2];
						previous[nodes[i][1]] = v;
					}
				}
			}
		}
		empty = false;
		for (ll i = 1; i <= n; i++) if (visited[i] == 0) empty = true;
	}
	ll sum = 0;
	for (ll i = 1; i <= n; i++) sum += dist[i];
	fout << sum << endl;
}
void scoreinflation()
{
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");
	ll m, n; fin >> m >> n;
	vector<ll> points(m + 1, 0);
	for (ll i = 0; i < n; i++)
	{
		ll a, b; fin >> a >> b;
		for (ll j = b; j <= m; j++) if (points[j] < points[j - b] + a) points[j] = points[j - b] + a;
	}
	fout << points[m] << endl;
}
void humblenumbers()
{
	ifstream fin("humble.in");
	ofstream fout("humble.out");
	ll k, n;
	fin >> k >> n;
	vector<pair<ll, ll>> p(k, { 0,  0 });
	for (ll i = 0; i < k; i++) fin >> p[i].first;
	vector<ll> humble;
	humble.push_back(1);
	for (ll i = 0; i < n; i++)
	{
		ll minimum = INT_MAX;
		for (ll j = 0; j < k; j++)
		{
			for (ll k = p[j].second; k < humble.size(); k++)
			{
				if (humble[k] * p[j].first > humble[humble.size() - 1])
				{
					minimum = min(minimum, humble[k] * p[j].first);
					p[j].second = k;
					break;
				}
			}
		}
		humble.push_back(minimum);
	}
	fout << humble[humble.size() - 1] << endl;
}
struct comp
{
	template <typename T>
	bool operator()(const T& l,	const T& r) const
	{
		if (l.second != r.second) return l.second > r.second;
		return l.first < r.first;
	}
};
void contact()
{
	ifstream fin("contact.in");
	ofstream fout("contact.out");
	ll a, b, n, count = 0, count2 = 0, prev = 0;
	fin >> a >> b >> n;
	vector<bool> pattern;
	map<ll, ll, greater<ll>> values;
	while (!fin.eof())
	{
		char p = fin.get();
		if (p == '0' || p == '1') pattern.push_back(p - '0');
	}
	ll mod = powl(2, a - 1);
	for (ll i = a; i <= b; i++)
	{
		mod *= 2;
		ll num = 0;
		for (ll k = 0; k < i - 1; k++) num = (num << 1) + pattern[k];
		for (ll j = i - 1; j < pattern.size(); j++)
		{
			num = (num << 1) % mod + pattern[j];
			if (values.find(mod + num) == values.end()) values[mod + num] = 1;
			else values[mod + num]++;
		}
	}
	set<pair<ll, ll>, comp> s(values.begin(), values.end());
	for (auto& it : s)
	{
		if (it.second != prev)
		{
			count2 = 0;
			prev = it.second;
			if ((++count) == n + 1) break;
			if (count != 1) fout << endl;
			fout << it.second << endl;
		}
		else if ((++count2) % 6 == 0) fout << endl;
		else fout << " ";
		ll size = floor(log(it.first) / log(2));
		ll n = it.first - powl(2, size);
		for (ll i = size - 1; i >= 0; i--)
		{
			if ((n >> i) & 1) fout << "1";
			else fout << "0";
		}
	}
	fout << endl;
}
void stamps()
{
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");
	ll k, n; fin >> k >> n;
	vector<ll> s(n);
	for (ll i = 0; i < n; i++) fin >> s[i];
	sort(s.begin(), s.end());
	int* pos = new int[k * s[n - 1] + 2];
	for (ll i = 0; i < k * s[n - 1] + 2; i++) pos[i] = INT_MAX;
	if (s[0] != 1) fout << 0 << endl;
	else
	{
		for (ll i : s) pos[i] = 1;
		for (ll j = 1; j <= k * s[n - 1] + 1; j++)
		{
			for (ll i : s)
			{
				if (i == j) break;
				if (i < j) if (pos[j - i] < k) pos[j] = min(pos[j], pos[j - i] + 1);
			}
			if (pos[j] == INT_MAX)
			{
				fout << j - 1 << endl;
				break;
			}
		}
	}
}
void threepointone()
{
	char funcNames[][100] =
	{
		"Agri-Net",
		"Score Inflation",
		"Humble Numbers",
		"Contact",
		"Stamps"
	};
	void (*funcs[])() =
	{
		agrinet,
		scoreinflation,
		humblenumbers,
		contact,
		stamps
	};
	int choice;
	int maxFuncs = sizeof(funcs) / sizeof(funcs)[0];
	for (int i = 0; i < maxFuncs; i++)
	{
		printf("%d: %s:\n", i + 1, funcNames[i]);
	}
	while (true)
	{
		printf("Enter selection: ");
		scanf("%d", &choice);
		getchar();
		if (choice > maxFuncs || choice <= 0)
		{
			break;
		}
		printf("%s : Output below\n", funcNames[choice - 1]);
		funcs[choice - 1]();
		printf("\n");
	}
}