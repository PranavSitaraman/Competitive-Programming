#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<tgmath.h>
using namespace std;
#define ll long long
void doubleoronething()
{
	ll n; cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		string in; cin >> in;
		bool* todouble = (bool*)calloc(in.length(), sizeof(bool));
		char prev = 'A';
		for (ll j = in.length() - 1; j > 0; j--)
		{
			if (in[j] != in[j - 1]) prev = in[j];
			if (prev > in[j - 1]) todouble[j - 1] = true;
		}
		cout << "Case #" << i << ": ";
		for (ll j = 0; j < in.length(); j++)
		{
			cout << in[j];
			if (todouble[j]) cout << in[j];
		}
		cout << endl;
	}
}
void equalsum()
{
	ll num; cin >> num; cin.ignore();
	while (num--)
	{
		ll n; cin >> n; cin.ignore();
		ll i = 0;
		ll sum = 0;
		vector<ll> nums;
		while (i <= 29 && i < n)
		{
			if (i != 0) cout << " ";
			ll a = (long long)(powl(2LL, i));
			cout << fixed << a;
			sum += a;
			nums.push_back(a);
			i++;
		}
		ll num = 3;
		while (i < n)
		{
			while (ceil(log2(num)) == floor(log2(num)))
			{
				num++;
			}
			cout << " " << num;
			sum += num;
			i++;
			num++;
		}
		cout << endl;
		for (ll j = 0; j < n; j++)
		{
			ll q; cin >> q; cin.ignore();
			nums.push_back(q);
			sum += q;
		}
		sort(nums.begin(), nums.end());
		sum /= 2;
		bool first = true;
		for (ll j = nums.size() - 1; j >= 0; j--)
		{
			while (nums[j] > sum) j--;
			if (first)
			{
				cout << nums[j];
				first = false;
			}
			else cout << " " << nums[j];
			sum -= nums[j];
			if (sum == 0) break;
		}
		cout << endl;
	}
}
void weightlifting()
{
	ll n; cin >> n;
	for (ll q = 1; q <= n; q++)
	{
		ll e, w; cin >> e >> w;
		ll sum = 0;
		vector<vector<ll>> weights(e + 1, vector<ll>(w, 0));
		for (ll i = 0; i < e; i++)
		{
			for (ll j = 0; j < w; j++)
			{
				cin >> weights[i][j];
			}
		}
		cout << "Case #" << q << ": ";
		for (ll j = 0; j < w; j++)
		{
			ll minimum = INT_MAX;
			for (ll i = 0; i < e; i++)
			{
				minimum = min(minimum, weights[i][j]);
			}
			weights[e][j] = minimum;
			sum += minimum;
		}
		for (ll q = 0; q < e - 1; q++)
		{
			for (ll j = 0; j < w; j++)
			{
				sum += abs(weights[q][j] - weights[e][j]);
			}
			for (ll j = 0; j < w; j++)
			{
				ll minimum = INT_MAX;
				for (ll i = q + 1; i < e; i++)
				{
					minimum = min(minimum, weights[i][j]);
				}
				weights[e][j] = minimum;
			}
			ll intsum = 0, tempsum = 0;
			for (ll j = 0; j < w; j++)
			{
				tempsum += abs(weights[q][j] - weights[e][j]);
				intsum += weights[e][j] - weights[q][j];
			}
			if (intsum >= 0)
			{
				sum += tempsum;
			}
			else
			{
				for (ll j = 0; j < w; j++)
				{
					weights[e][j] = weights[q][j];
				}
			}
		}
		for (ll j = 0; j < w; j++)
		{
			sum += weights[e][j];
		}
		cout << sum << endl;
	}
}