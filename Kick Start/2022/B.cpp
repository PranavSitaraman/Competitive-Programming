#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
#define ll long long
void infinityarea()
{
	ll n; cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		ll r, a, b;
		cin >> r >> a >> b;
		long double total = pow(r, 2);
		ll num = 0;
		while (r > 0)
		{
			if (num % 2 == 0)
			{
				r *= a;
			}
			else
			{
				r /= b;
			}
			total += pow(r, 2);
			num++;
		}
		total *= 3.141592653589793238462643383279502884;
		cout << fixed << "Case #" << i << ": " << total << endl;
	}
}
ll nextpalindrome(ll digit, bool length)
{
	ll n = digit;
	ll palindrome = digit;
	if (length) n /= 10;
	while (n > 0)
	{
		palindrome = palindrome * 10 + (n % 10);
		n /= 10;
	}
	return palindrome;
}
void palindromicfactors()
{
	ll n; cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		ll a; cin >> a;
		ll number;
		ll count = 0;
		for (ll j = 0; j < 2; j++)
		{
			ll i = 1;
			while ((number = nextpalindrome(i, j % 2)) <= a)
			{
				if (a % number == 0) count++;
				i++;
			}
		}
		cout << "Case #" << i << ": " << count << endl;
	}
}
ll mincount = INT_MAX;
void dfspadlock(int count, vector<ll> dials, ll n, ll d, ll mid)
{
	vector<ll> compare(dials.size(), 0);
	if (dials == compare)
	{
		if (count < mincount) mincount = count;
		return;
	}
	ll start = 1, end = dials.size() - 1;
	if (mid != -1)
	{
		start = max(1LL, mid - 1);
		end = min(mid + 1, (long long)(dials.size() - 1));
	}
	bool works = false;
	for (ll j = start; j < end; j++)
	{
		if (dials[j - 1] == dials[j + 1])
		{
			works = true;
			ll diff = min(abs(dials[j] - dials[j - 1]), abs(d - dials[j] + dials[j - 1]));
			vector<ll> copy = dials;
			dials.erase(dials.begin() + j);
			dials.erase(dials.begin() + j);
			dfspadlock(count + diff, dials, n, d, j - 1);
			dials = copy;
		}
	}
	if (!works)
	{
		for (ll j = start; j < end; j++)
		{
			if (abs(dials[j] - dials[j - 1]) < abs(dials[j] - dials[j + 1]))
			{
				vector<ll> copy = dials;
				ll diff = min(abs(dials[j] - dials[j - 1]), abs(d - dials[j] + dials[j - 1]));
				dials.erase(dials.begin() + j);
				dfspadlock(count + diff, dials, n, d, j - 1);
				dials = copy;
			}
			else
			{
				vector<ll> copy = dials;
				ll diff = min(abs(dials[j] - dials[j + 1]), abs(d - dials[j] + dials[j + 1]));
				dials.erase(dials.begin() + j);
				dfspadlock(count + diff, dials, n, d, j);
				dials = copy;
			}
		}
	}
}
void unlockthepadlock()
{
	ll num; cin >> num;
	for (ll i = 1; i <= num; i++)
	{
		vector<ll> dials;
		mincount = INT_MAX;
		ll n, d; cin >> n >> d;
		ll prev = 0, count = 0, a = 0;
		dials.push_back(0);
		for (ll j = 0; j < n; j++)
		{
			cin >> a;
			if (a != prev)
			{
				dials.push_back(a);
				prev = a;
			}
		}
		if (dials[dials.size() - 1] != 0) dials.push_back(0);
		dfspadlock(0, dials, n, d, -1);
		cout << "Case #" << i << ": " << mincount << endl;
	}
}