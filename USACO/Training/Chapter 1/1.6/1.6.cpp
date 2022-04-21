#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
void numbertriangles()
{
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	int n;
	fin >> n;
	vector<vector<int>> numbers;
	for (int i = 0; i < n; i++)
	{
		numbers.push_back({});
		for (int j = 0; j < i + 1; j++)
		{
			int a;
			fin >> a;
			numbers[i].push_back(a);
		}
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			numbers[i][j] += max(numbers[i + 1][j], numbers[i + 1][j + 1]);
		}
	}
	fout << numbers[0][0] << endl;
}
int a, b;
void isPrime(int n, ofstream& fout)
{
	for (int d = 3; d * d <= n; d += 2)
	{
		if (n % d == 0)
		{
			return;
		}
	}
	if (n >= a && n <= b) fout << n << endl;
}
void getPals(int i, int n, int isMid, char* str, ofstream& fout)
{
	int d = 1;
	int j = 0;
	char c[2];
	if (!isMid) {
		d = 2;
		j = 1;
	}
	if (n / 2 == i)
	{
		if (n % 2 == 1)
		{
			for (; j <= 9; j += d)
			{
				sprintf(c, "%d", j);
				str[i] = c[0];
				isPrime(atoi(str), fout);
			}
			return;
		}
		isPrime(atoi(str), fout);
		return;
	}
	for (; j <= 9; j += d)
	{
		sprintf(c, "%c", j);
		sprintf(c, "%d", j);
		str[i] = c[0];
		str[n - 1 - i] = c[0];
		getPals(i + 1, n, 1, str, fout);
	}
}
void primepalindromes()
{
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	int t;
	int an, bn;
	fin >> a >> b;
	an = bn = 0;
	t = a;
	while (t) { t /= 10; an += 1; }
	t = b;
	while (t) { t /= 10; bn += 1; }
	char* str;
	str = (char*)calloc(bn + 1, sizeof(char));
	for (int i = an; i <= bn; i++) { getPals(0, i, 0, str, fout); }
}
int prime(int num)
{
	bool flag = true;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}
void ribdfs(int depth, int maxdepth, int val, ofstream& fout)
{
	if (depth == maxdepth)
	{
		fout << val << endl;
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (i == 1 || i == 3 || i == 9 || i == 7)
		{
			int newval = val * 10 + i;
			if (prime(newval))
			{
				ribdfs(depth + 1, maxdepth, newval, fout);
			}
		}
	}
}
void superprimerib()
{
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	int n;
	fin >> n;
	for (int i = 1; i < 10; i++)
	{
		if (i == 2 || i == 3 || i == 5 || i == 7) ribdfs(1, n, i, fout);
	}
}
void onepointsix()
{
	char funcNames[][100] =
	{
		"Number Triangles",
		"Prime Palindromes",
		"Superprime Rib"
	};
	void (*funcs[])() =
	{
		numbertriangles,
		primepalindromes,
		superprimerib
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