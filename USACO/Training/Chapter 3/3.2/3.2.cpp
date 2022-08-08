#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define ll long long
void factorials4()
{
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");
	ll n, prod = 1; fin >> n;
	for (ll i = 1; i <= n; i++)
	{
		prod *= i;
		while (prod % 10 == 0) prod /= 10;
		prod %= 1000;
	}
	fout << prod % 10 << endl;
}
ll countSet[32][32];
void dfsbits(ll n, ll l, ll i, ofstream& fout)
{
	if (!n) return;
	fout << (countSet[n - 1][l] <= i);
	dfsbits(n - 1, l - (countSet[n - 1][l] <= i), i - countSet[n - 1][l] * (countSet[n - 1][l] <= i), fout);
}
void stringsobits()
{
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");
	ll n, l, i; fin >> n >> l >> i;
	for (ll i = 0; i < 32; i++)
	{
		countSet[0][i] = 1;
		countSet[i][0] = 1;
	}
	for (ll i = 1; i < 32; i++) for (ll j = 1; j < 32; j++) countSet[i][j] = countSet[i - 1][j - 1] + countSet[i - 1][j];
	dfsbits(n, l, i - 1, fout);
	fout << endl;
}
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
void spinningwheels()
{
	ifstream fin("spin.in");
	ofstream fout("spin.out");
	ll max = 1;
	vector<pair<ll, vector<pair<ll, ll>>>> wheels(5);
	for (ll i = 0; i < 5; i++)
	{
		ll a, b; fin >> a >> b;
		vector<pair<ll, ll>> num;
		for (ll j = 0; j < b; j++)
		{
			ll p, q; fin >> p >> q;
			num.push_back({ p, q });
		}
		wheels[i] = {a, num};
		max = lcm(max, lcm(a, 360) / a);
	}
	bool works = false;
	for (ll i = 0; i <= max; i++)
	{
		ll lights[360] = { 0 };
		for (ll j = 0; j < 5; j++)
		{
			for (ll k = 0; k < wheels[j].second.size(); k++)
			{
				for (ll m = wheels[j].second[k].first; m <= wheels[j].second[k].first + wheels[j].second[k].second; m++)
				{
					lights[m % 360]++;
				}
			}
		}
		for (ll j = 0; j < 360; j++)
		{
			if (lights[j] == 5)
			{
				works = true;
				break;
			}
		}
		if (works)
		{
			fout << i << endl;
			break;
		}
		for (ll j = 0; j < 5; j++)
		{
			for (ll k = 0; k < wheels[j].second.size(); k++)
			{
				wheels[j].second[k].first += wheels[j].first;
				wheels[j].second[k].first %= 360;
			}
		}
	}
	if (!works) fout << "none" << endl;
}
void feedratios()
{
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");
	ll a, b, c;
	fin >> a >> b >> c;
	int ratios[3][3];
	for (ll i = 0; i < 3; i++) for (ll j = 0; j < 3; j++) fin >> ratios[i][j];
	ll m = (a == 0 ? 1 : a) * (b == 0 ? 1 : b) * (c == 0 ? 1 : c);
	if (a != 0) m = gcd(m, a);
	if (b != 0) m = gcd(m, b);
	if (c != 0) m = gcd(m, c);
	ll min = INT_MAX;
	ll mina, minb, minc, minm;
	for (ll i = 0; i < 100; i++)
	{
		for (ll j = 0; j < 100; j++)
		{
			for (ll k = 0; k < 100; k++)
			{
				ll p = ratios[0][0] * i + ratios[1][0] * j + ratios[2][0] * k;
				ll q = ratios[0][1] * i + ratios[1][1] * j + ratios[2][1] * k;
				ll r = ratios[0][2] * i + ratios[1][2] * j + ratios[2][2] * k;
				ll n = (p == 0 ? 1 : p) * (q == 0 ? 1 : q) * (r == 0 ? 1 : r);
				if (p != 0) n = gcd(n, p);
				if (q != 0) n = gcd(n, q);
				if (r != 0) n = gcd(n, r);
				if ((a == 0 && p == 0) || (a != 0 && p/n == a/m))
				{
					if ((b == 0 && q == 0) || (b != 0 && q/n == b/m))
					{
						if ((c == 0 && r == 0) || (c != 0 && r/n == c/m))
						{
							if (i + j + k != 0 && i + j + k < min && p + q + r >= a + b + c)
							{
								min = i + j + k;
								mina = i;
								minb = j;
								minc = k;
								minm = n;
							}
						}
					}
				}
			}
		}
	}
	if (min != INT_MAX) fout << mina << " " << minb << " " << minc << " " << minm/m << endl;
	else fout << "NONE" << endl;
}
void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
int* operationA(int* config1)
{
	int* config = new int[8];
	for (ll i = 0; i < 8; i++) config[i] = config1[i];
	swap(&config[0], &config[7]);
	swap(&config[1], &config[6]);
	swap(&config[2], &config[5]);
	swap(&config[3], &config[4]);
	return config;
}
int* operationB(int* config1)
{
	int* config = new int[8];
	for (ll i = 0; i < 8; i++) config[i] = config1[i];
	swap(&config[2], &config[3]);
	swap(&config[1], &config[2]);
	swap(&config[0], &config[1]);
	swap(&config[4], &config[5]);
	swap(&config[5], &config[6]);
	swap(&config[6], &config[7]);
	return config;
}
int* operationC(int* config1)
{
	int* config = new int[8];
	for (ll i = 0; i < 8; i++) config[i] = config1[i];
	swap(&config[1], &config[2]);
	swap(&config[1], &config[6]);
	swap(&config[6], &config[5]);
	return config;
}
struct transformationsquare
{
	string transformation;
	int* config;
};
queue<transformationsquare> bfsqueue;
set<int> seen;
void magicsquares()
{
	ifstream fin("msquare.in");
	ofstream fout("msquare.out");
	int config[8], initial[8];
	for (ll i = 0; i < 8; i++) fin >> config[i];
	for (ll i = 0; i < 8; i++) initial[i] = i + 1;
	bool same = true;
	for (ll i = 0; i < 8; i++)
	{
		if (config[i] != initial[i])
		{
			same = false;
			break;
		}
	}
	if (same)
	{
		fout << 0 << endl << endl;
		exit(0);
	}
	bfsqueue.push({ "A", operationA(initial) });
	bfsqueue.push({ "B", operationB(initial) });
	bfsqueue.push({ "C", operationC(initial) });
	while (bfsqueue.size())
	{
		transformationsquare next = bfsqueue.front();
		bfsqueue.pop();
		bool same = true;
		ll num = 0;
		for (ll i = 0; i < 8; i++)
		{
			num *= 10;
			num += next.config[i];
			if (config[i] != next.config[i])
			{
				same = false;
			}
		}
		if (same)
		{
			fout << next.transformation.length() << endl;
			ll count = 0;
			for (char a : next.transformation)
			{
				fout << a;
				count++;
				if (count % 60 == 0) fout << endl;
			}
			if (count % 60 != 0) fout << endl;
			break;
		}
		if (seen.find(num) != seen.end()) continue;
		seen.insert(num);
		bfsqueue.push({ next.transformation + "A", operationA(next.config) });
		bfsqueue.push({ next.transformation + "B", operationB(next.config) });
		bfsqueue.push({ next.transformation + "C", operationC(next.config) });
	}
}
void sweetbutter()
{
	ifstream fin("butter.in");
	ofstream fout("butter.out");
	int n, p, c, minimum = INT_MAX; fin >> n >> p >> c; c *= 2;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distance;
	int* cows = new int[n], * dist = new int[p + 1];
	vector<pair<int, int>>* nodes = new vector<pair<int, int>> [p + 1];
	for (int i = 0; i < n; i++) fin >> cows[i];
	for (int i = 0; i < c/2; i++)
	{
		ll a, b, d;
		fin >> a >> b >> d;
		nodes[a].push_back({ b, d });
		nodes[b].push_back({ a, d });
	}
	for (int i = 1; i <= p; i++)
	{
		distance.push({ 0, i });
		for (int i = 0; i <= p; i++) dist[i] = INT_MAX;
		dist[i] = 0;
		while (!distance.empty())
		{
			int v = distance.top().second;
			distance.pop();
			for (pair<int, int> k : nodes[v]) if (dist[v] + k.second < dist[k.first]) distance.push({(dist[k.first] = dist[v] + k.second), k.first});
		}
		int sum = 0;
		for (int i = 0; i < n; i++) sum += dist[cows[i]];
		if (sum < minimum) minimum = sum;
	}
	fout << minimum << endl;
}
void threepointtwo()
{
	char funcNames[][100] =
	{
		"Factorials 4",
		"Stringsobits",
		"Spinning Wheels",
		"Feed Ratios",
		"Magic Squares",
		"Sweet Butter"
	};
	void (*funcs[])() =
	{
		factorials4,
		stringsobits,
		spinningwheels,
		feedratios,
		magicsquares,
		sweetbutter
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