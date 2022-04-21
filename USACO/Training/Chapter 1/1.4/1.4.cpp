#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
void mixingmilk()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int n, m;
	fin >> n >> m;
	vector<pair<int, int>> farmers;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		fin >> a >> b;
		farmers.push_back({ a, b });
	}
	sort(farmers.begin(), farmers.end());
	int total = 0;
	int price = 0;
	int index = 0;
	while (total < n)
	{
		int next = min(farmers[index].second, n - total);;
		total += next;
		price += next * farmers[index].first;
		index++;
	}
	fout << price << endl;
}
void barnrepair()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int m, s, c;
	fin >> m >> s >> c;
	vector<int> num;
	for (int i = 0; i < c; i++)
	{
		int a;
		fin >> a;
		num.push_back(a);
	}
	if (m > c)
	{
		fout << c << endl;
		return;
	}
	sort(num.begin(), num.end());
	int min = num[0];
	int max = num[c - 1];
	vector<int> diff;
	for (int i = 0; i < c - 1; i++)
	{
		diff.push_back(num[i + 1] - num[i]);
	}
	sort(diff.begin(), diff.end());
	int total = 0;
	for (int b = 1; b <= m - 1; b++)
	{
		if (diff.size() - b >= 0) total += diff[diff.size() - b] - 1;
	}
	fout << (max - min + 1) - total << endl;
}
void primecryptarithm()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int n;
	fin >> n;
	vector<int> digits;
	for (int i = 0; i < n; i++)
	{
		int a;
		fin >> a;
		digits.push_back(a);
	}
	int length = digits.size();
	int total = 0;
	for (int a = 0; a < length; a++)
	{
		for (int b = 0; b < length; b++)
		{
			for (int c = 0; c < length; c++)
			{
				for (int d = 0; d < length; d++)
				{
					for (int e = 0; e < length; e++)
					{
						int first = 100 * digits[a] + 10 * digits[b] + digits[c];
						int second = 10 * digits[d] + digits[e];
						int one = first * digits[e];
						int two = first * digits[d];
						int product = first * second;
						if (one < 100 || one > 999 || two < 100 || two > 999 || product < 1000 || product > 9999)
						{
							continue;
						}
						bool works = true;
						while (one > 0)
						{
							int digit = one % 10;
							bool match = false;
							for (int i = 0; i < length; i++)
							{
								if (digits[i] == digit)
								{
									match = true;
									break;
								}
							}
							if (!match)
							{
								works = false;
								break;
							}
							one /= 10;
						}
						if (!works) continue;
						works = true;
						while (two > 0)
						{
							int digit = two % 10;
							bool match = false;
							for (int i = 0; i < length; i++)
							{
								if (digits[i] == digit)
								{
									match = true;
									break;
								}
							}
							if (!match)
							{
								works = false;
								break;
							}
							two /= 10;
						}
						if (!works) continue;
						works = true;
						works = true;
						while (product > 0)
						{
							int digit = product % 10;
							bool match = false;
							for (int i = 0; i < length; i++)
							{
								if (digits[i] == digit)
								{
									match = true;
									break;
								}
							}
							if (!match)
							{
								works = false;
								break;
							}
							product /= 10;
						}
						if (!works) continue;
						total++;
					}
				}
			}
		}
	}
	fout << total << endl;
}
void combinationlock()
{
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int farmera, farmerb, farmerc, mastera, masterb, masterc;
	int N;
	int count = 0;
	fin >> N >> farmera >> farmerb >> farmerc >> mastera >> masterb >> masterc;
	int farmergooda[5] = { farmera - 2, farmera - 1, farmera, farmera + 1, farmera + 2 };
	int farmergoodb[5] = { farmerb - 2, farmerb - 1, farmerb, farmerb + 1, farmerb + 2 };
	int farmergoodc[5] = { farmerc - 2, farmerc - 1, farmerc, farmerc + 1, farmerc + 2 };
	int mastergooda[5] = { mastera - 2, mastera - 1, mastera, mastera + 1, mastera + 2 };
	int mastergoodb[5] = { masterb - 2, masterb - 1, masterb, masterb + 1, masterb + 2 };
	int mastergoodc[5] = { masterc - 2, masterc - 1, masterc, masterc + 1, masterc + 2 };
	for (int i = 0; i < 5; i++)
	{
		if (farmergooda[i] <= 0)
		{
			farmergooda[i] += N;
		}
		if (farmergooda[i] > N)
		{
			farmergooda[i] -= N;
		}
		if (farmergoodb[i] <= 0)
		{
			farmergoodb[i] += N;
		}
		if (farmergoodb[i] > N)
		{
			farmergoodb[i] -= N;
		}
		if (farmergoodc[i] <= 0)
		{
			farmergoodc[i] += N;
		}
		if (farmergoodc[i] > N)
		{
			farmergoodc[i] -= N;
		}
		if (mastergooda[i] <= 0)
		{
			mastergooda[i] += N;
		}
		if (mastergooda[i] > N)
		{
			mastergooda[i] -= N;
		}
		if (mastergoodb[i] <= 0)
		{
			mastergoodb[i] += N;
		}
		if (mastergoodb[i] > N)
		{
			mastergoodb[i] -= N;
		}
		if (mastergoodc[i] <= 0)
		{
			mastergoodc[i] += N;
		}
		if (mastergoodc[i] > N)
		{
			mastergoodc[i] -= N;
		}
	}
	bool atrue, btrue, ctrue;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				atrue = false, btrue = false, ctrue = false;
				for (int a = 0; a < 5; a++)
				{
					if (i == farmergooda[a])
					{
						atrue = true;
						break;
					}
				}
				for (int b = 0; b < 5; b++)
				{
					if (j == farmergoodb[b])
					{
						btrue = true;
						break;
					}
				}
				for (int c = 0; c < 5; c++)
				{
					if (k == farmergoodc[c])
					{
						ctrue = true;
						break;
					}
				}
				if (atrue == true && btrue == true && ctrue == true)
				{
					count++;
				}
				else
				{
					atrue = false, btrue = false, ctrue = false;
					for (int a = 0; a < 5; a++)
					{
						if (i == mastergooda[a])
						{
							atrue = true;
							break;
						}
					}
					for (int b = 0; b < 5; b++)
					{
						if (j == mastergoodb[b])
						{
							btrue = true;
							break;
						}
					}
					for (int c = 0; c < 5; c++)
					{
						if (k == mastergoodc[c])
						{
							ctrue = true;
							break;
						}
					}
					if (atrue == true && btrue == true && ctrue == true)
					{
						count++;
					}
				}
			}
		}
	}
	fout << count << endl;
}
int total = 0;
int maxcoord = 0;
void wormholedfs(vector<int>& connect, vector<pair<int, int>>& coords)
{
	bool full = true;
	for (int i = 0; i < connect.size(); i++)
	{
		if (connect[i] == -1)
		{
			full = false;
			break;
		}
	}
	if (full)
	{
		for (int i = 0; i < coords.size(); i++)
		{
			int xcoord = coords[i].first;
			int ycoord = coords[i].second;
			bool works = false;
			while (true)
			{
				xcoord++;
				bool found = false;
				for (int j = 0; j < coords.size(); j++)
				{
					if (xcoord <= coords[j].first && ycoord == coords[j].second)
					{
						xcoord = coords[connect[j]].first;
						ycoord = coords[connect[j]].second;
						found = true;
						break;
					}
				}
				if (!found)
				{
					break;
				}
				if (xcoord == coords[i].first && ycoord == coords[i].second)
				{
					works = true;
					break;
				}
			}
			if (works)
			{
				total++;
				break;
			}
		}
		return;
	}
	for (int i = 0; i < connect.size(); i++)
	{
		if (connect[i] == -1)
		{
			for (int j = i + 1; j < connect.size(); j++)
			{
				if (connect[j] == -1)
				{
					connect[i] = j;
					connect[j] = i;
					wormholedfs(connect, coords);
					connect[i] = -1;
					connect[j] = -1;
				}
			}
			break;
		}
	}
}
int factorial(int n)
{
	if (n > 1) return n * factorial(n - 1);
	else return 1;
}
void wormholes()
{
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	int n;
	fin >> n;
	vector<pair<int, int>> coords;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		coords.push_back({ a, b });
		if (a > maxcoord)
		{
			maxcoord = a;
		}
	}
	sort(coords.begin(), coords.end());
	vector<int> connect(n);
	for (int i = 0; i < n; i++)
	{
		connect[i] = -1;
	}
	wormholedfs(connect, coords);
	fout << total << endl;
}
void skicoursedesign()
{
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	int N;
	vector<int> hills;
	fin >> N;
	int cost, least = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		int a;
		fin >> a;
		hills.push_back(a);
	}
	sort(hills.begin(), hills.end());
	for (int i = 0; i <= 83; i++)
	{
		cost = 0;
		for (int j = 0; j < N; j++)
		{
			if (hills[j] > i + 17)
			{
				cost += pow(hills[j] - i - 17.0, 2);
			}
			else if (hills[j] < i)
			{
				cost += pow(i - hills[j], 2);
			}
		}
		if (cost < least)
		{
			least = cost;
		}
	}
	fout << least << endl;
}
void onepointfour()
{
	char funcNames[][100] =
	{
		"Mixing Milk",
		"Barn Repair",
		"Prime Cryptarithm",
		"Combination Lock",
		"Wormholes",
		"Ski Course Design"
	};
	void (*funcs[])() =
	{
		mixingmilk,
		barnrepair,
		primecryptarithm,
		combinationlock,
		wormholes,
		skicoursedesign
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