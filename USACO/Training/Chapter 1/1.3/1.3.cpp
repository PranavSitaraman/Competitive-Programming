/*
ID: sitaram1
LANG: C++
TASK: dualpal
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
void milkingcows()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int n;
	fin >> n;
	vector<pair<int, int>> times;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		times.push_back({ a, b });
	}
	sort(times.begin(), times.end());
	for (int i = 0; i < times.size() - 1; i++)
	{
		int j = i + 1;
		while (true)
		{
			int maximum = 0;
			int minimum = 0;
			if (j >= times.size())
			{
				break;
			}
			if (times[i].second >= times[j].first)
			{
				maximum = max(times[i].second, times[j].second);
				minimum = min(times[i].first, times[j].first);
			}
			else
			{
				break;
			}
			times[j].first = minimum;
			times[j].second = maximum;
			times[i].first = INT_MIN;
			i++;
			j++;
		}
	}
	int maxyesmilk = 0;
	int maxnotmilk = 0;
	for (int i = 0; i < times.size() - 1; i++)
	{
		if (times[i].first == INT_MIN)
		{
			continue;
		}
		int j = i + 1;
		if (times[i].second - times[i].first > maxyesmilk)
		{
			maxyesmilk = times[i].second - times[i].first;
		}
		while (times[j].first == INT_MIN && j < times.size())
		{
			j++;
		}
		if (j == times.size())
		{
			break;
		}
		else if (times[j].first - times[i].second > maxnotmilk)
		{
			maxnotmilk = times[j].first - times[i].second;
		}
		i = j - 1;
	}
	if (times[times.size() - 1].first != INT_MIN)
	{
		if (times[times.size() - 1].second - times[times.size() - 1].first > maxyesmilk)
		{
			maxyesmilk = times[times.size() - 1].second - times[times.size() - 1].first;
		}
	}
	fout << maxyesmilk << " " << maxnotmilk << endl;
}
void transform()
{
	int n;
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	fin >> n;
	fin.ignore();
	vector<vector<bool>> in;
	vector<vector<bool>> out;
	for (int i = 0; i < n; i++)
	{
		in.push_back({});
		for (int j = 0; j < n; j++)
		{
			char a = fin.get();
			if (a == '@') in[i].push_back(true);
			else in[i].push_back(false);
		}
		fin.ignore();
	}
	for (int i = 0; i < n; i++)
	{
		out.push_back({});
		for (int j = 0; j < n; j++)
		{
			char a = fin.get();
			if (a == '@') out[i].push_back(true);
			else out[i].push_back(false);
		}
		fin.ignore();
	}
	bool same = true;
	vector<vector<bool>> copy;
	for (int i = 0; i < n; i++)
	{
		copy.push_back({});
		for (int j = 0; j < n; j++)
		{
			copy[i].push_back(in[i][j]);
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			bool temp = copy[i][j];
			copy[i][j] = copy[n - 1 - j][i];
			copy[n - 1 - j][i] = copy[n - 1 - i][n - 1 - j];
			copy[n - 1 - i][n - 1 - j] = copy[j][n - 1 - i];
			copy[j][n - 1 - i] = temp;
		}
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (copy[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "1" << endl;
		return;
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			bool temp = copy[i][j];
			copy[i][j] = copy[n - 1 - j][i];
			copy[n - 1 - j][i] = copy[n - 1 - i][n - 1 - j];
			copy[n - 1 - i][n - 1 - j] = copy[j][n - 1 - i];
			copy[j][n - 1 - i] = temp;
		}
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (copy[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "2" << endl;
		return;
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			bool temp = copy[i][j];
			copy[i][j] = copy[n - 1 - j][i];
			copy[n - 1 - j][i] = copy[n - 1 - i][n - 1 - j];
			copy[n - 1 - i][n - 1 - j] = copy[j][n - 1 - i];
			copy[j][n - 1 - i] = temp;
		}
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (copy[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "3" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			copy[i][j] = in[i][n - 1 - j];
		}
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (copy[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "4" << endl;
		return;
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			bool temp = copy[i][j];
			copy[i][j] = copy[n - 1 - j][i];
			copy[n - 1 - j][i] = copy[n - 1 - i][n - 1 - j];
			copy[n - 1 - i][n - 1 - j] = copy[j][n - 1 - i];
			copy[j][n - 1 - i] = temp;
		}
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (copy[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "5" << endl;
		return;
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			bool temp = copy[i][j];
			copy[i][j] = copy[n - 1 - j][i];
			copy[n - 1 - j][i] = copy[n - 1 - i][n - 1 - j];
			copy[n - 1 - i][n - 1 - j] = copy[j][n - 1 - i];
			copy[j][n - 1 - i] = temp;
		}
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (copy[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "5" << endl;
		return;
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - i - 1; j++)
		{
			bool temp = copy[i][j];
			copy[i][j] = copy[n - 1 - j][i];
			copy[n - 1 - j][i] = copy[n - 1 - i][n - 1 - j];
			copy[n - 1 - i][n - 1 - j] = copy[j][n - 1 - i];
			copy[j][n - 1 - i] = temp;
		}
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (copy[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "5" << endl;
		return;
	}
	same = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (in[i][j] != out[i][j])
			{
				same = false;
				break;
			}
		}
	}
	if (same)
	{
		fout << "6" << endl;
		return;
	}
	fout << "7" << endl;
}
void namethatnum()
{
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream dict("dict.txt");
	vector<int> brand;
	char a;
	while ((a = fin.get()) != '\n') brand.push_back(a - '0');
	string b;
	bool one = false;
	while (true)
	{
		dict >> b;
		if (dict.fail())
		{
			break;
		}
		if (b.length() != brand.size()) continue;
		bool valid = true;
		for (int i = 0; i < brand.size(); i++)
		{
			char c = b[i];
			if (brand[i] == 2 && 'A' <= c && c <= 'C') {}
			else if (brand[i] == 3 && 'D' <= c && c <= 'F') {}
			else if (brand[i] == 4 && 'G' <= c && c <= 'I') {}
			else if (brand[i] == 5 && 'J' <= c && c <= 'L') {}
			else if (brand[i] == 6 && 'M' <= c && c <= 'O') {}
			else if (brand[i] == 7 && 'P' <= c && c <= 'S' && c != 'Q') {}
			else if (brand[i] == 8 && 'T' <= c && c <= 'V') {}
			else if (brand[i] == 9 && 'W' <= c && c <= 'Y') {}
			else
			{
				valid = false;
				break;
			}
		}
		if (valid == true)
		{
			fout << b << endl;
			one = true;
		}
	}
	if (one == false)
	{
		fout << "NONE" << endl;
	}
}
void palindromicsquares()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int b;
	fin >> b;
	for (int i = 1; i <= 300; i++)
	{
		int j = i * i;
		string val = "";
		while (j > 0)
		{
			int num = j % b;
			if (num >= 0 && num <= 9)
			{
				val += (char)(num + '0');
			}
			else
			{
				val += (char)(num - 10 + 'A');
			}
			j /= b;
		}
		bool match = true;
		for (int i = 0; i < val.length() / 2; i++)
		{
			if (val[i] != val[val.length() - i - 1]) match = false;
		}
		if (match == false) continue;
		string first = "";
		j = i;
		while (j > 0)
		{
			int num = j % b;
			if (num >= 0 && num <= 9)
			{
				first += (char)(num + '0');
			}
			else
			{
				first += (char)(num - 10 + 'A');
			}
			j /= b;
		}
		for (int i = 0; i < first.length() / 2; i++)
		{
			char temp = first[i];
			first[i] = first[first.length() - i - 1];
			first[first.length() - i - 1] = temp;
		}
		fout << first << " " << val << endl;
	}
}
void dualpalindromes()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int n, s;
	fin >> n >> s;
	s++;
	while (n > 0)
	{
		int a = 2;
		bool right = false;
		for (int b = 2; b <= 10; b++)
		{
			int j = s;
			string val = "";
			while (j > 0)
			{
				int num = j % b;
				if (num >= 0 && num <= 9)
				{
					val += (char)(num + '0');
				}
				else
				{
					val += (char)(num - 10 + 'A');
				}
				j /= b;
			}
			bool match = true;
			for (int i = 0; i < val.length() / 2; i++)
			{
				if (val[i] != val[val.length() - i - 1]) match = false;
			}
			if (match == true)
			{
				a--;
			}
			if (a == 0)
			{
				right = true;
				break;
			}
		}
		if (right == true)
		{
			fout << s << endl;
			n--;
		}
		s++;
	}
}
void onepointthree()
{
	char funcNames[][100] =
	{
		"Milking Cows",
		"Transform",
		"Name That Number",
		"Palindromic Squares",
		"Dual Palindromes"
	};
	void (*funcs[])() =
	{
		milkingcows,
		transform,
		namethatnum,
		palindromicsquares,
		dualpalindromes
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