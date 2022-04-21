#include "USACO Stuck in a Rut.h"
void usacostuckinarutrun()
{
	long long n = 0;
	char ch = '\0';
	long long eastcount = 0;
	long long northcount = 0;
	cow2 temp;
	cow2 east[1000] = { 0 };
	cow2 north[1000] = { 0 };
	scanf("%lld", &n);
	getchar();
	for (long long i = 0; i < n; i++)
	{
		scanf("%c", &ch);
		if (ch == 'E')
		{
			east[eastcount].d = ch;
			scanf("%lld", &east[eastcount].x);
			scanf("%lld", &east[eastcount].y);
			east[eastcount].blame = 0;
			east[eastcount].stuck = false;
			east[eastcount++].num = i;
		}
		else if (ch == 'N')
		{
			north[northcount].d = ch;
			scanf("%lld", &north[northcount].x);
			scanf("%lld", &north[northcount].y);
			north[northcount].blame = 0;
			north[northcount].stuck = false;
			north[northcount++].num = i;
		}
		getchar();
	}
	for (long long i = 0; i < eastcount; i++)
	{
		for (long long j = i + 1; j < eastcount; j++)
		{
			if (east[i].y > east[j].y)
			{
				temp = east[i];
				east[i] = east[j];
				east[j] = temp;
			}
		}
	}
	for (long long i = 0; i < northcount; i++)
	{
		for (long long j = i + 1; j < northcount; j++)
		{
			if (north[i].x > north[j].x)
			{
				temp = north[i];
				north[i] = north[j];
				north[j] = temp;
			}
		}
	}
	for (long long i = 0; i < eastcount; i++)
	{
		for (long long j = 0; j < northcount; j++)
		{
			if (east[i].stuck == false && north[j].stuck == false && north[j].x > east[i].x && east[i].y > north[j].y)
			{
				if (north[j].x - east[i].x > east[i].y - north[j].y)
				{
					east[i].stuck = true;
					north[j].blame += 1 + east[i].blame;
				}
				else if (east[i].y - north[j].y > north[j].x - east[i].x)
				{
					north[j].stuck = true;
					east[i].blame += 1 + north[j].blame;
				}
			}
		}
	}
	for (long long i = 0; i < n; i++)
	{
		for (long long j = 0; j < eastcount; j++)
		{
			if (east[j].num == i)
			{
				printf("%lld\n", east[j].blame);
				goto cool;
			}
		}
		for (long long j = 0; j < northcount; j++)
		{
			if (north[j].num == i)
			{
				printf("%lld\n", north[j].blame);
				goto cool;
			}
		}
	cool:printf("");
	}
}