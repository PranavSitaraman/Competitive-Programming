#include "USACO Rectangular Pasture.h"
using namespace std;
typedef std::pair<int, int> PointType;
int n, Psum[size3 + 1][size3 + 1];
PointType P[size3];
bool ycomp(PointType p, PointType q)
{
	return p.second < q.second;
}
long long rsum(int x1, int y1, int x2, int y2)
{
	return (long long) (Psum[x2 + 1][y2 + 1]) - (long long) (Psum[x2 + 1][y1]) - (long long)(Psum[x1][y2 + 1]) + (long long)(Psum[x1][y1]);
}
void usacorectpasturerun()
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		getchar();
		P[i].first = x;
		P[i].second = y;
	}
	std::sort(P, P + n);
	for (int i = 0; i < n; i++)
	{
		P[i].first = i + 1;
	}
	std::sort(P, P + n, ycomp);
	for (int i = 0; i < n; i++)
	{
		P[i].second = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		Psum[P[i].first][P[i].second] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			Psum[i][j] += Psum[i - 1][j] + Psum[i][j - 1] - Psum[i - 1][j - 1];
		}
	}
	long long answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int x1 = min(P[i].first, P[j].first) - 1;
			int x2 = max(P[i].first, P[j].first) - 1;
			answer += rsum(0, i, x1, j) * rsum(x2, i, n - 1, j);
		}
	}
	printf("%lld\n", ++answer);
}