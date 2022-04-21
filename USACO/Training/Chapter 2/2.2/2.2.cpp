#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<numeric>
using namespace std;
void prefacenumbering()
{
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	int n;
	fin >> n;
	vector<int> num = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	vector<string> sym = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	vector<int> count;
	for (int i = 0; i < num.size(); i++)
	{
		count.push_back(0);
	}
	for (int j = 1; j <= n; j++)
	{
		int number = j;
		int i = 12;
		while (number > 0)
		{
			int div = number / num[i];
			number = number % num[i];
			while (div--)
			{
				count[i]++;
			}
			i--;
		}
	}
	for (int i = 0; i < sym.size(); i++)
	{
		if (sym[i].length() > 1)
		{
			for (int j = 0; j < sym[i].length(); j++)
			{
				for (int k = 0; k < sym.size(); k++)
				{
					if (sym[k].length() == 1 && sym[k][0] == sym[i][j])
					{
						count[k] += count[i];
					}
				}
			}
		}
	}
	for (int i = 0; i < count.size(); i++)
	{
		if (sym[i].length() == 1 && count[i] != 0)
		{
			fout << sym[i] << " " << count[i] << endl;
		}
	}
}
int subsetcount = 0;
long long iterate(int n, int k, vector<vector<long long>>& buckets)
{
	if (n < 0 || k < 0)
	{
		return 0;
	}
	if (buckets[n][k] != -1)
	{
		return buckets[n][k];
	}
	if (n == 0 && k == 0) {
		return 1;
	}
	return (buckets[n][k] = iterate(n, k - 1, buckets) + iterate(n - k, k - 1, buckets));
}
void subsetsums()
{
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	int n;
	fin >> n;
	vector<vector<long long>> buckets;
	int sum = n * (n + 1) / 2;
	for (int i = 0; i <= sum/2; i++)
	{
		buckets.push_back({});
		for (int j = 0; j <= n; j++)
		{
			buckets[i].push_back(-1);
		}
	}
	if (sum % 2 == 1) fout << "0" << endl;
	else
	{
		fout << iterate(sum / 2, n, buckets) / 2 << endl;
	}
}
bool isrunaround(string s)
{
	int oi, i, j, len;
	string t = s;
	len = t.length();
	i = 0;
	while (t[i] != 'X')
	{
		oi = i;
		i = (i + t[i] - '0') % len;
		t[oi] = 'X';
	}
	if (i != 0)
		return false;
	for (j = 0; j < len; j++)
		if (t[j] != 'X')
			return false;
	return true;
}
void permutation(string s, vector<bool>& used, int nd, int md, int m, ofstream& fout)
{
	int i;
	if (nd == md)
	{
		if (stoi(s) > m && isrunaround(s))
		{
			fout << s << endl;
			exit(0);
		}
		return;
	}
	for (i = 1; i <= 9; i++)
	{
		if (!used[i]) {
			s[nd] = i + '0';
			used[i] = 1;
			permutation(s, used, nd + 1, md, m, fout);
			used[i] = 0;
		}
	}
}
void runaroundnumbers()
{
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	long long a;
	fin >> a;
	vector<bool> used(10, 0);
	for (int i = 1; i <= 9; i++)
	{
		string s;
		for (int j = 0; j < i; j++)
		{
			s += '0';
		}
		permutation(s, used, 0, i, a, fout);
	}
}
bool poss[64];
int flip[4] = { 63, 42, 21, 36 };
void searchlights(int lights, int i, int n, int known, int ison)
{
	if (n == 0)
	{
		if ((lights & known) == ison) poss[lights] = true;
		return;
	}
	for (; i < 4; i++) searchlights(lights ^ flip[i], i + 1, n - 1, known, ison);
}
void partylamps()
{
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	int n, c, ison = 0, known = 0;
	fin >> n >> c;
	while (true)
	{
		int a;
		fin >> a;
		if (a == -1) break;
		a = 5 - (a - 1) % 6;
		ison |= 1 << a;
		known |= 1 << a;
	}
	while (true)
	{
		int a;
		fin >> a;
		if (a == -1) break;
		a = 5 - (a - 1) % 6;
		known |= 1 << a;
	}
	if (c > 4) c = 4 - (c % 2);
	for (; c >= 0; c -= 2) searchlights(63, 0, c, known, ison);
	bool impossible = true;
	for (int i = 0; i < 64; i++)
	{
		if (poss[i])
		{
			string s = "";
			for (int j = 0; j < n; j++) s += (i & (1 << (5 - j % 6))) ? '1' : '0';
			fout << s << endl;
			impossible = false;
		}
	}
	if (impossible) fout << "IMPOSSIBLE" << endl;
}
void twopointtwo()
{
	char funcNames[][100] =
	{
		"Preface Numbering",
		"Subset Sums",
		"Runaround Numbers",
		"Party Lamps"
	};
	void (*funcs[])() =
	{
		prefacenumbering,
		subsetsums,
		runaroundnumbers,
		partylamps
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