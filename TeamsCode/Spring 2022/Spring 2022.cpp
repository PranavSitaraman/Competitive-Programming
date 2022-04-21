#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long
void teamscodespring2022one()
{
	ll n; cin >> n;
	while (n--)
	{
		string a;
		cin >> a;
	}
	cout << "Elijah" << endl;
}
void teamscodespring2022two()
{
	ll n; cin >> n;
	while (n--)
	{
		ll a;
		cin >> a; getchar();
		ll lcount = 0, rcount = 0, ucount = 0, dcount = 0;
		ll maxx = 0, minx = 0, maxy = 0, miny = 0;
		ll x = 0, y = 0;
		for (int i = 0; i < a; i++)
		{
			char b = getchar();
			switch (b)
			{
			case 'L': x--; break;
			case 'R': x++; break;
			case 'U': y++; break;
			case 'D': y--; break;
			}
			if (x < minx) minx = x;
			if (x > maxx) maxx = x;
			if (y > maxy) maxy = y;
			if (y < miny) miny = y;
		}
		getchar();
		cout << (maxx - minx + 1) * (maxy - miny + 1) << endl;
	}
}
void teamscodespring2022three()
{
	ll n, k; cin >> n >> k;
	ll ans = 0;
	while (n--)
	{
		ll a, b; cin >> a >> b;
		ll less = a - a % k;
		ll lessx = less / k;
		ll more = less + k;
		ll morex = more / k;
		ans += min(abs(a - less) + abs(b - lessx), abs(more - a) + abs(morex - b));
	}
	cout << ans << endl;
}
void teamscodespring2022four()
{
	ll n; cin >> n;
	while (n--)
	{
		ll a, b, product = 1, val = 1; cin >> a >> b;
		for (ll i = 1; i < min(a, b); i++)
		{
			for (ll j = 0; j < i; j++)
			{
				product *= 2 + i;
				product %= 1000000007;
			}
		}
		for (ll i = 1; i < min(a, b); i++)
		{
			for (ll j = 0; j < i; j++)
			{
				product *= a + b + 2 - i;
				product %= 1000000007;
			}
		}
		for (ll i = 2 + min(a,b); i <= a + b + 2 - min(a, b); i++)
		{
			val *= i;
			val %= 1000000007;
		}
		for (ll i = 0; i < min(a, b); i++)
		{
			product *= val;
			product %= 1000000007;
		}
		cout << product << endl;
	}
}