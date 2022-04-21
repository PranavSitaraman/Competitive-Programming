#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
using namespace std;
void spring2021easy5()
{
	int h, m;
	scanf("%d:%d", &h, &m);
	int t, s;
	cin >> t >> s;
	float change = float(s) / t;
	int cha = int(change);
	h += cha;
	m += floor((change - cha) * 60);
	while (h >= 24)
	{
		h -= 24;
	}
	if (m >= 60)
	{
		m -= 60;
		h += 1;
	}
	printf("%02d:%02d", h, m);
}