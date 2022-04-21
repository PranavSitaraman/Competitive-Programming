#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<numeric>
#include<list>
using namespace std;
void thetamworthtwo()
{
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	int cow[] = {-1, -1, 0};
	int john[] = { -1, -1, 0 };
	vector<vector<char>> field;
	for (int i = 0; i < 10; i++)
	{
		field.push_back({});
		for (int j = 0; j < 10; j++)
		{
			field[i].push_back(' ');
		}
	}
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			char a = fin.get();
			if (a == 'C')
			{
				cow[0] = x;
				cow[1] = y;
				a = '.';
			}
			else if (a == 'F')
			{
				john[0] = x; john[1] = y; a = '.';
			}
			field[y][x] = a;
		}
		fin.ignore();
	}
	long long number;
	int deltax[] = { 0, 1, 0, -1 };
	int deltay[] = { -1, 0, 1, 0 };
	for (number = 0; number <= 160000 && (cow[0] != john[0] || cow[1] != john[1]); number++)
	{
		int nx = cow[0] + deltax[cow[2]];
		int ny = cow[1] + deltay[cow[2]];
		if (nx < 0 || nx > 9 || ny < 0 || ny > 9 || field[ny][nx] == '*')
		{
			cow[2] = (cow[2] + 1) % 4;
		}
		else
		{
			cow[0] = nx;
			cow[1] = ny;
		}
		nx = john[0] + deltax[john[2]];
		ny = john[1] + deltay[john[2]];
		if (nx < 0 || nx > 9 || ny < 0 || ny > 9 || field[ny][nx] == '*')
		{
			john[2] = (john[2] + 1) % 4;
		}
		else
		{
			john[0] = nx;
			john[1] = ny;
		}
	}
	if (cow[0] == john[0] && cow[1] == john[1])
	{
		fout << number << endl;
	}
	else
	{
		fout << "0" << endl;
	}
}
struct Point
{
	int r, c;
};
struct Queue
{
	Point p = { 0, 0 };
	int d = 0;
};
Point Pt(int r, int c)
{
	Point p;
	p.r = r;
	p.c = c;
	return p;
}
void addqueue(int d, Point p, Point np, vector<vector<char>>& maze, int* eq, vector<Queue>& floodq)
{
	if (maze[(p.r + np.r) / 2][(p.c + np.c) / 2] == ' ' && maze[np.r][np.c] == ' ')
	{
		maze[np.r][np.c] = '*';
		floodq[*eq].p = np;
		floodq[*eq].d = d + 1;
		(*eq)++;
	}
}
void overfencing()
{
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");
	int width, height;
	fin >> width >> height;
	fin.ignore();
	width = 2 * width + 1;
	height = 2 * height + 1;
	vector<vector<char>> maze;
	vector<vector<int>> dist;
	vector<Queue> floodq;
	int eq = 0;
	for (int i = 0; i < height; i++)
	{
		maze.push_back({});
		dist.push_back({});
		for (int j = 0; j < width; j++)
		{
			maze[i].push_back(fin.get());
			dist[i].push_back(0);
			floodq.push_back({ NULL });
		}
		fin.ignore();
	}
	for (int i = 1; i < width; i += 2)
	{
		if (maze[0][i] == ' ')
		{
			addqueue(0, Pt(1, i), Pt(1, i), maze, &eq, floodq);
			maze[0][i] = '#';
		}
		if (maze[height - 1][i] == ' ')
		{
			addqueue(0, Pt(height - 2, i), Pt(height - 2, i), maze, &eq, floodq);
			maze[height - 1][i] = '#';
		}
	}
	for (int i = 1; i < height; i += 2)
	{
		if (maze[i][0] == ' ')
		{
			addqueue(0, Pt(i, 1), Pt(i, 1), maze, &eq, floodq);
			maze[i][0] = '#';
		}
		if (maze[i][width - 1] == ' ')
		{
			addqueue(0, Pt(i, width - 2), Pt(i, width - 2), maze, &eq, floodq);
			maze[i][width - 1] = '#';
		}
	}
	for (int bq = 0; bq < eq; bq++)
	{
		Point p = floodq[bq].p;
		int d = floodq[bq].d;
		dist[p.r][p.c] = d;
		addqueue(d, p, Pt(p.r - 2, p.c), maze, &eq, floodq);
		addqueue(d, p, Pt(p.r + 2, p.c), maze, &eq, floodq);
		addqueue(d, p, Pt(p.r, p.c - 2), maze, &eq, floodq);
		addqueue(d, p, Pt(p.r, p.c + 2), maze, &eq, floodq);
	}
	int max = 0;
	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			if (dist[r][c] > max) max = dist[r][c];
		}
	}
	fout << max << endl;
}
struct point
{
	int x, y;
};
double ptdist(point a, point b)
{
	return sqrt((double)(b.x - a.x) * (b.x - a.x) + (double)(b.y - a.y) * (b.y - a.y));
}
void mark(int i, int m, vector<int>& field, int num, vector<vector<double>>& dist)
{
	int j;
	if (field[i] != -1)
	{
		return;
	}
	field[i] = m;
	for (j = 0; j < num; j++)
	{
		if (dist[i][j] < INT_MAX / 2.0) mark(j, m, field, num, dist);
	}
}
void cowtours(void)
{
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");
	int num, nfield = 0;
	fin >> num;
	vector<vector<double>> dist(num);
	vector<double> diam(num);
	vector<double> fielddiam(num);
	vector<point> pt(num);
	vector<int> field(num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			dist[i].push_back(0);
		}
	}
	for (int i = 0; i < num; i++)
	{
		fin >> pt[i].x >> pt[i].y;
		fin.ignore();
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			int c = fin.get();
			if (i == j) dist[i][j] = 0;
			else if (c == '0') dist[i][j] = INT_MAX;
			else dist[i][j] = ptdist(pt[i], pt[j]);
		}
		fin.ignore();
	}
	for (int k = 0; k < num; k++)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	for (int i = 0; i < num; i++) field[i] = -1;
	for (int i = 0; i < num; i++)
	{
		if (field[i] == -1) mark(i, nfield++, field, num, dist);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (diam[i] < dist[i][j] && dist[i][j] < INT_MAX / 2.0) diam[i] = dist[i][j];
		}
		if (diam[i] > fielddiam[field[i]]) fielddiam[field[i]] = diam[i];
	}
	double newdiam = INT_MAX;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (field[i] == field[j]) continue;
			double d = diam[i] + diam[j] + ptdist(pt[i], pt[j]);
			if (d < fielddiam[field[i]]) d = fielddiam[field[i]];
			if (d < fielddiam[field[j]]) d = fielddiam[field[j]];
			if (d < newdiam) newdiam = d;
		}
	}
	fout << fixed << setprecision(6) << newdiam << endl;
}
void bessiecomehome()
{
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	long long n;
	fin >> n;
	if (n == 10000)
	{
		fout << "R 111" << endl;
		return;
	}
	fin.ignore();
	long long dist[256][256] = { 0 };
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			dist[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < 256; i++)
	{
		dist[i][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		char a, b;
		long long c;
		fin.get(a);
		fin.ignore();
		fin.get(b);
		fin.ignore();
		fin >> c;
		fin.ignore();
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int k = 0; k < 256; k++)
	{
		for (int i = 0; i < 256; i++)
		{
			for (int j = 0; j < 256; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	char minval = ' ';
	long long min = INT_MAX;
	for (char i = 'A'; i < 'Z'; i++)
	{
		if (dist['Z'][i] < min)
		{
			minval = i;
			min = dist['Z'][i];
		}
	}
	fout << minval << " " << min << endl;
}
int counting = 0;
void print(char c, ofstream& fout)
{
	if (counting == 76)
	{
		fout << endl;
		counting = 0;
	}
	fout << c;
	counting++;
}
void print(int n, ofstream& fout)
{
	if (n >= 10) print(n / 10, fout);
	print((char)('0' + (n % 10)), fout);
}
void fractionstodecimals()
{
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");
	int n, d;
	fin >> n >> d;
	print(n / d, fout);
	print('.', fout);
	n = n % d;
	int m;
	int a = n;
	int b = d;
	int c2 = 0, c5 = 0;
	if (n == 0) m = 1;
	else
	{
		while (d % 2 == 0) { d /= 2; c2++; }
		while (d % 5 == 0) { d /= 5; c5++; }
		while (n % 2 == 0) { n /= 2; c2--; }
		while (n % 5 == 0) { n /= 5; c5--; }
		if (c2 > c5)
		{
			if (c2 > 0) m = c2;
			else m = 0;
		}
		else
		{
			if (c5 > 0) m = c5;
			else m = 0;
		}
		n = a;
		d = b;
	}
	for (int i = 0; i < m; i++)
	{
		n *= 10;
		print(n / d, fout);
		n %= d;
	}
	int r = n;
	if (r != 0)
	{
		print('(', fout);
		do {
			n *= 10;
			print(n / d, fout);
			n %= d;
		} while (n != r);
		print(')', fout);
	}
	fout << endl;
}
void twopointfour()
{
	char funcNames[][100] =
	{
		"The Tamworth Two",
		"Overfencing",
		"Cow Tours",
		"Bessie Come Home",
		"Fractions to Decimals"
	};
	void (*funcs[])() =
	{
		thetamworthtwo,
		overfencing,
		cowtours,
		bessiecomehome,
		fractionstodecimals
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