#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<numeric>
#include<list>
using namespace std;
struct value
{
	char ch;
	float num;
	bool type;
};
struct expression
{
	string math;
	int xmin;
	int xmax;
};
void longestprefix()
{
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	vector<string> primitives;
	while (true)
	{
		string a;
		fin >> a;
		if (a == ".")
		{
			break;
		}
		primitives.push_back(a);
	}
	string s = "";
	while (!fin.eof())
	{
		string a;
		fin >> a;
		fin.ignore();
		s += a;
	}
	vector<int> match(s.length() + 1, 0);
	match[0] = 1;
	int longest = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (match[i])
		{
			longest = i;
			for (int j = 0; j < primitives.size(); j++)
			{
				if (s.substr(i, primitives[j].length()) == primitives[j])
				{
					match[i + primitives[j].length()] = 1;
				}
			}
		}
	}
	if (match[s.length()]) longest = s.length();
	fout << longest << endl;
}
void cowpedigrees()
{
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	vector<vector<int>> trees;
	vector<vector<int>> smaller;
	int n, k;
	fin >> n >> k;
	for (int i = 0; i <= k; i++)
	{
		trees.push_back({});
		smaller.push_back({});
		for (int j = 0; j <= n; j++)
		{
			trees[i].push_back(0);
			smaller[i].push_back(0);
		}
	}
	trees[1][1] = 1;
	for (int i = 2; i <= k; i++)
	{
		for (int j = 1; j <= n; j += 2)
		{
			for (int k = 1; k <= j - 1 - k; k += 2)
			{
				int c;
				if (k != j - 1 - k) c = 2;
				else c = 1;
				trees[i][j] += c * (smaller[i - 2][k] * trees[i - 1][j - 1 - k] + trees[i - 1][k] * smaller[i - 2][j - 1 - k] + trees[i - 1][k] * trees[i - 1][j - 1 - k]);
				trees[i][j] %= 9901;
			}
		}
		for (int k = 0; k <= n; k++)
		{
			smaller[i - 1][k] += trees[i - 1][k] + smaller[i - 2][k];
			smaller[i - 1][k] %= 9901;
		}
	}
	fout << trees[k][n] << endl;
}
void expression(int depth, int n, string an, ofstream& fout)
{
	if (depth == n)
	{
		string ne = "";
		for (int i = 0; i < an.length(); i++)
		{
			if (an[i] != ' ')
			{
				ne += an[i];
			}
		}
		char ord[255] = { 0 }; ord['^'] = 3; ord['/'] = 2; ord['*'] = 2; ord['%'] = 2; ord['+'] = 1; ord['-'] = 1;
		list<value> in, top;
		for (int i = 0; i < ne.length(); i++)
		{
			char a = ne[i];
			if (a == ' ') continue;
			else if (a >= '0' && a <= '9')
			{
				string dec = "";
				while (ne[i] == '.' || (ne[i] >= '0' && ne[i] <= '9'))
				{
					dec += ne[i];
					i++;
				}
				i--;
				in.push_back({ NULL, stof(dec), false });
			}
			else if (a == ')')
			{
				value val = top.front();
				top.pop_front();
				while (val.type == true && val.ch != '(')
				{
					in.push_back(val);
					val = top.front();
					top.pop_front();
				}
			}
			else if (a != '(' && top.empty() == false && top.front().type == true && ord[top.front().ch] >= ord[a])
			{
				in.push_back(top.front());
				top.pop_front();
				top.push_front({ a, NULL, true });
			}
			else
			{
				top.push_front({ a, NULL, true });
			}
		}
		while (top.empty() == false)
		{
			in.push_back(top.front());
			top.pop_front();
		}
		while (in.empty() == false)
		{
			if (in.front().type == false)
			{
				top.push_front(in.front());
			}
			else
			{
				float val2 = top.front().num;
				top.pop_front();
				float val1 = top.front().num;
				top.pop_front();
				float result = 0;
				switch (in.front().ch)
				{
				case '+': result = val1 + val2; break;
				case '-': result = val1 - val2; break;
				case '*': result = val1 * val2; break;
				case '/': result = val1 / val2; break;
				case '%': result = int(val1) % int(val2); break;
				case '^': result = pow(val1, val2); break;
				}
				top.push_front({ NULL, result, false });
			}
			in.pop_front();
		}
		float answer = top.front().num;
		if (answer == 0)
		{
			fout << an << endl;
		}
		return;
	}
	expression(depth + 1, n, an + " " + string(1, depth + 1 + '0'), fout);
	expression(depth + 1, n, an + "+" + string(1, depth + 1 + '0'), fout);
	expression(depth + 1, n, an + "-" + string(1, depth + 1 + '0'), fout);
}
void zerosum()
{
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
	int n;
	fin >> n;
	expression(1, n, "1", fout);
}
void moneysystems()
{
	ifstream fin("money.in");
	ofstream fout("money.out");
	long long v, n;
	fin >> v >> n;
	vector<long long> arr;
	for (int i = 0; i < v; i++)
	{
		long long a;
		fin >> a;
		arr.push_back(a);
	}
	vector<long long> table(n + 1, 0);
	table[0] = 1;
	for (long long i = 0; i < v; i++)
		for (long long j = arr[i]; j <= n; j++)
			table[j] += table[j - arr[i]];
	fout << table[n] << endl;
}
void addcontroller(int i, int j, vector<vector<int>>& controls, vector<vector<int>>& owns)
{
	if (controls[i][j]) return;
	controls[i][j] = 1;
	for (int k = 0; k < owns.size(); k++) owns[i][k] += owns[j][k];
	for (int k = 0; k < owns.size(); k++) if (controls[k][i]) addcontroller(k, j, controls, owns);
	for (int k = 0; k < owns.size(); k++) if (owns[i][k] > 50) addcontroller(i, k, controls, owns);
}
void addowner(int i, int j, int p, vector<vector<int>>& controls, vector<vector<int>>& owns)
{
	for (int k = 0; k < owns.size(); k++) if (controls[k][i]) owns[k][j] += p;
	for (int k = 0; k < owns.size(); k++) if (owns[k][j] > 50) addcontroller(k, j, controls, owns);
}
void controllingcompanies()
{
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	int n; fin >> n;
	vector<vector<int>> controls(101);
	vector<vector<int>> owns(101);
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			controls[i].push_back(0);
			owns[i].push_back(0);
		}
	}
	for (int i = 0; i < 101; i++) controls[i][i] = 1;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		fin >> a >> b >> c;
		addowner(a, b, c, controls, owns);
	}
	for (int i = 0; i < controls.size(); i++)
	{
		for (int j = 0; j < controls[i].size(); j++)
		{
			if (i != j && controls[i][j]) fout << i << " " << j << endl;
		}
	}
}
void twopointthree()
{
	char funcNames[][100] =
	{
		"Longest Prefix",
		"Cow Pedigrees",
		"Zero Sum",
		"Money Systems",
		"Controlling Companies"
	};
	void (*funcs[])() =
	{
		longestprefix,
		cowpedigrees,
		zerosum,
		moneysystems,
		controllingcompanies
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