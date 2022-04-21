#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
void convolutedintervals()
{
	long long n, m;
	cin >> n >> m;
	long long* freqA = new long long[m + 1];
	long long* freqB = new long long[m + 1];
	long long* sumfreqA = new long long[2 * m + 1];
	long long* sumfreqB = new long long[2 * m + 1];
	for (long long i = 0; i < n; i++)
	{
		long long a, b;
		cin >> a >> b;
		freqA[a]++;
		freqB[b]++;
	}
	for (long long i = 0; i <= m; i++)
	{
		for (long long j = 0; j <= m; j++)
		{
			sumfreqA[i + j] += freqA[i] * freqA[j];
			sumfreqB[i + j] += freqB[i] * freqB[j];
		}
	}
	long long less = sumfreqA[0];
	long long more = n * n;
	for (long long k = 0; k <= 2 * m; k++)
	{
		if (k != 0)
		{
			less += sumfreqA[k];
			more -= sumfreqB[k - 1];
		}
		cout << more + less - n * n << endl;
	}
}