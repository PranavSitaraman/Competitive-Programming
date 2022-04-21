#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<numeric>
using namespace std;
struct cell
{
	bool w;
	bool n;
	bool e;
	bool s;
	int num;
};
int roomsize = 0;
int maxroomsize = 0;
void floodfill(int i, int j, vector<vector<cell>>& castle, int val)
{
	roomsize++;
	castle[i][j].num = val;
	if (!castle[i][j].n && castle[i - 1][j].num == 0)
	{
		floodfill(i - 1, j, castle, val);
	}
	if (!castle[i][j].s && castle[i + 1][j].num == 0)
	{
		floodfill(i + 1, j, castle, val);
	}
	if (!castle[i][j].w && castle[i][j - 1].num == 0)
	{
		floodfill(i, j - 1, castle, val);
	}
	if (!castle[i][j].e && castle[i][j + 1].num == 0)
	{
		floodfill(i, j + 1, castle, val);
	}
	return;
}
void castle()
{
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	int m, n;
	fin >> m >> n;
	vector<vector<cell>> castle;
	for (int i = 0; i < n; i++)
	{
		castle.push_back({});
		for (int j = 0; j < m; j++)
		{
			int a;
			fin >> a;
			castle[i].push_back({ bool(a & 1) , bool((a >> 1) & 1), bool((a >> 2) & 1), bool((a >> 3) & 1), 0 });
		}
	}
	int room = 0;
	vector<int> rooms;
	rooms.push_back(0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (castle[i][j].num == 0)
			{
				room++;
				roomsize = 0;
				floodfill(i, j, castle, room);
				rooms.push_back(roomsize);
				if (roomsize > maxroomsize)
				{
					maxroomsize = roomsize;
				}
			}
		}
	}
	int maxsize = 0;
	int wallx = 0;
	int wally = 0;
	char waldir = ' ';
	fout << room << endl << maxroomsize << endl;
	for (int j = 0; j < m; j++)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (i != 0)
			{
				if (castle[i][j].n)
				{
					int a;
					if (castle[i - 1][j].num != castle[i][j].num)
					{
						a = rooms[castle[i][j].num] + rooms[castle[i - 1][j].num];
					}
					else
					{
						a = rooms[castle[i][j].num];
					}
					if (a > maxsize)
					{
						maxsize = a;
						wallx = i;
						wally = j;
						waldir = 'N';
					}
				}
			}
			if (j != m - 1)
			{
				if (castle[i][j].e)
				{
					int a;
					if (castle[i][j + 1].num != castle[i][j].num)
					{
						a = rooms[castle[i][j].num] + rooms[castle[i][j + 1].num];
					}
					else
					{
						a = rooms[castle[i][j].num];
					}
					if (a > maxsize)
					{
						maxsize = a;
						wallx = i;
						wally = j;
						waldir = 'E';
					}
				}
			}
		}
	}
	fout << maxsize << endl << wallx + 1 << " " << wally + 1 << " " << waldir << endl;
}
int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else return gcd(a, b - a);
}
bool comp(pair<int, int> a, pair<int, int> b)
{
	if (double(a.first)/a.second > double(b.first)/b.second)
	{
		return false;
	}
	return true;
}
void orderedfractions()
{
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int n;
	fin >> n;
	vector<pair<int, int>> fractions;
	fractions.push_back({ 0, 1 });
	fractions.push_back({ 1, 1 });
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (gcd(i, j) == 1)
			{
				fractions.push_back({ j, i });
			}
		}
	}
	sort(fractions.begin(), fractions.end(), comp);
	for (int i = 0; i < fractions.size(); i++)
	{
		fout << fractions[i].first << "/" << fractions[i].second << endl;
	}
}
void sortingthreevalued()
{
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int length;
	fin >> length;
	vector<int> values;
	for (int i = 0; i < length; i++)
	{
		int a;
		fin >> a;
		values.push_back(a);
	}
	vector<vector<int>> swap;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	for (int i = 0; i < length; i++)
	{
		if (values[i] == 1)
		{
			num1++;
		}
		else if (values[i] == 2)
		{
			num2++;
		}
		else if (values[i] == 3)
		{
			num3++;
		}
	}
	for (int i = 0; i < num1; i++)
	{
		if (values[i] != 1)
		{
			int temp = -1;
			if (values[i] == 2)
			{
				for (int a = num1; a < num1 + num2; a++)
				{
					if (values[a] == 1)
					{
						temp = a;
					}
				}
			}
			else if (values[i] == 3)
			{
				for (int a = num1 + num2; a < num1 + num2 + num3; a++)
				{
					if (values[a] == 1)
					{
						temp = a;
					}
				}
			}
			if (temp != -1)
			{
				swap.push_back({ i, temp });
				int p = values[i];
				values[i] = values[temp];
				values[temp] = p;
			}
		}
	}
	for (int i = num1; i < num1 + num2; i++)
	{
		if (values[i] != 2)
		{
			int temp = -1;
			if (values[i] == 1)
			{
				for (int a = 0; a < num1; a++)
				{
					if (values[a] == 2)
					{
						temp = a;
					}
				}
			}
			else if (values[i] == 3)
			{
				for (int a = num1 + num2; a < num1 + num2 + num3; a++)
				{
					if (values[a] == 2)
					{
						temp = a;
					}
				}
			}
			if (temp != -1)
			{
				swap.push_back({ i, temp });
				int p = values[i];
				values[i] = values[temp];
				values[temp] = p;
			}
		}
	}
	for (int i = num1 + num2; i < num1 + num2 + num3; i++)
	{
		if (values[i] != 3)
		{
			int temp = -1;
			if (values[i] == 1)
			{
				for (int a = 0; a < num1; a++)
				{
					if (values[a] == 3)
					{
						temp = a;
					}
				}
			}
			else if (values[i] == 2)
			{
				for (int a = num1; a < num1 + num2; a++)
				{
					if (values[a] == 3)
					{
						temp = a;
					}
				}
			}
			if (temp != -1)
			{
				swap.push_back({ i, temp });
				int p = values[i];
				values[i] = values[temp];
				values[temp] = p;
			}
		}
	}
	for (int i = 0; i < num1; i++)
	{
		if (values[i] != 1)
		{
			int temp = -1;
			for (int a = num1; a < length; a++)
			{
				if (values[a] == 1)
				{
					temp = a;
				}
			}
			if (temp != -1)
			{
				swap.push_back({ i, temp });
				int p = values[i];
				values[i] = values[temp];
				values[temp] = p;
			}
		}
	}
	for (int i = num1; i < num1 + num2; i++)
	{
		if (values[i] != 2)
		{
			int temp = -1;
			for (int a = num1 + num2; a < length; a++)
			{
				if (values[a] == 2)
				{
					temp = a;
				}
			}
			if (temp != -1)
			{
				swap.push_back({ i, temp });
				int p = values[i];
				values[i] = values[temp];
				values[temp] = p;
			}
		}
	}
	fout << swap.size() << endl;
}
int best = INT_MAX;
vector<int> feed;
vector<int> feedtemp;
vector<vector<int>> vitamins;
bool valid()
{
	bool works = true;
	int totaldiff = 0;
	for (int i = 0; i < vitamins[0].size(); i++)
	{
		int sum = 0;
		for (int j = 1; j < vitamins.size(); j++)
		{
			sum += feedtemp[j - 1] * vitamins[j][i];
		}
		if (sum < vitamins[0][i])
		{
			works = false;
			break;
		}
	}
	return works;
}
void vitamindfs(int depth, int max, string current)
{
	if (depth == max)
	{
		int total = 0;
		for (int i = 0; i < depth; i++)
		{
			if (current[i] == '1')
			{
				total++;
				feedtemp[depth - 1 - i] = 1;
			}
			else
			{
				feedtemp[depth - 1 - i] = 0;
			}
		}
		if (total < best && valid())
		{
			best = total;
			for (int i = 0; i < depth; i++)
			{
				feed[i] = feedtemp[i];
			}
		}
		return;
	}
	else
	{
		vitamindfs(depth + 1, max, current + "0");
		vitamindfs(depth + 1, max, current + "1");
	}
}
void healthyholsteins()
{
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	int v;
	fin >> v;
	vitamins.push_back({});
	for (int i = 0; i < v; i++)
	{
		int a;
		fin >> a;
		vitamins[0].push_back(a);
	}
	int g;
	fin >> g;
	for (int i = 1; i <= g; i++)
	{
		vitamins.push_back({});
		feed.push_back(0);
		feedtemp.push_back(0);
		for (int j = 0; j < v; j++)
		{
			int a;
			fin >> a;
			vitamins[i].push_back(a);
		}
	}
	vitamindfs(0, g, "");
	fout << best;
	for (int i = 0; i < feed.size(); i++)
	{
		for (int j = 0; j < feed[i]; j++)
		{
			fout << " " << i + 1;
		}
	}
	fout << endl;
}
void numberdfs(vector<vector<int>>& distance, vector<int>& numbers, int n, int d, ofstream& fout)
{
	if (numbers.size() == n)
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i % 10) fout << " ";
			fout << numbers[i];
			if (i % 10 == 9 || i == numbers.size() - 1) fout << endl;
		}
		exit(0);
	}
	int i = numbers[numbers.size() - 1] + 1;
	while (true)
	{
		bool works = true;
		for (int j = 0; j < numbers.size(); j++)
		{
			if (distance[numbers[j]][i] < d)
			{
				works = false;
				break;
			}
		}
		if (works)
		{
			numbers.push_back(i);
			numberdfs(distance, numbers, n, d, fout);
		}
		i++;
	}
}
void hammingcodes()
{
	ifstream fin("hamming.in");
	ofstream fout("hamming.out"); 
	int n, b, d;
	fin >> n >> b >> d;
	vector<vector<int>> distance;
	vector<int> numbers;
	for (int i = 0; i < (1 << b); i++)
	{
		distance.push_back({});
		for (int j = 0; j < (1 << b); j++)
		{
			distance[i].push_back(0);
			for (int k = 0; k < b; k++)
			{
				if (((1 << k) & i) != ((1 << k) & j))
				{
					distance[i][j]++;
				}
			}
		}
	}
	numbers.push_back(0);
	numberdfs(distance, numbers, n, d, fout);
}
void twopointone()
{
	char funcNames[][100] =
	{
		"Castle",
		"Ordered Fractions",
		"Sorting Three-Valued",
		"Healthy Holsteins",
		"Hamming Codes"
	};
	void (*funcs[])() =
	{
		castle,
		orderedfractions,
		sortingthreevalued,
		healthyholsteins,
		hammingcodes
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