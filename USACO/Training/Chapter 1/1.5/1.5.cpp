#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
void arithmeticprogressions()
{
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int n, m;
	fin >> n >> m;
	vector<pair<int, int>> sequences;
	vector<bool> bisquares(m * m * 2 + 1, false);
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			bisquares[i * i + j * j] = true;
		}
	}
	for (int i = 0; i < bisquares.size(); i++)
	{
		if (!bisquares[i]) continue;
		int max = (m * m * 2 - i) / (n - 1);
		for (int j = 1; j <= max; j++)
		{
			bool works = true;
			for (int p = 1; p < n; p++)
			{
				if (!bisquares[i + p * j])
				{
					works = false;
					break;
				}
			}
			if (works)
			{
				sequences.push_back({ j, i });
			}
		}
	}
	sort(sequences.begin(), sequences.end());
	if (sequences.size() == 0)
	{
		fout << "NONE" << endl;
	}
	else
	{
		for (int i = 0; i < sequences.size(); i++)
		{
			fout << sequences[i].second << " " << sequences[i].first << endl;
		}
	}
}
int states[21][21];
void search(int newC, int newB, int maxA, int maxB, int maxC)
{
	int newA;
	if (states[newC][newB] == 1) return;
	states[newC][newB] = 1;
	newA = maxC - newB - newC;
	if (maxB < newC + newB) search(newC - (maxB - newB), maxB, maxA, maxB, maxC);
	else search(0, newC + newB, maxA, maxB, maxC);
	if (maxC < newC + newB) search(maxC, newB - (maxC - newC), maxA, maxB, maxC);
	else search(newC + newB, 0, maxA, maxB, maxC);
	if (maxA < newC + newA) search(newC - (maxA - newA), newB, maxA, maxB, maxC);
	else search(0, newB, maxA, maxB, maxC);
	if (maxC < newC + newA) search(maxC, newB, maxA, maxB, maxC);
	else search(newC + newA, newB, maxA, maxB, maxC);
	if (maxA < newB + newA) search(newC, newB - (maxA - newA), maxA, maxB, maxC);
	else search(newC, 0, maxA, maxB, maxC);
	if (maxB < newB + newA) search(newC, maxB, maxA, maxB, maxC);
	else search(newC, newB + newA, maxA, maxB, maxC);
}
void mothersmilk()
{
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	int A, B, C;
	fin >> A >> B >> C;
	search(C, 0, A, B, C);
	for (int i = 0; i <= C; i++)
	{
		if (states[i][C - i] == 1)
		{
			if ((i != C - B) && (i != 0)) fout << " ";
			fout << i;
		}
	}
	fout << endl;
}
void onepointfive()
{
	char funcNames[][100] =
	{
		"Arithmetic Progressions",
		"Mother's Milk"
	};
	void (*funcs[])() =
	{
		arithmeticprogressions,
		mothersmilk
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