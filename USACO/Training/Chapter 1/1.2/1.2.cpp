#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void yourrideishere()
{
	ifstream fin ("ride.in");
	ofstream fout("ride.out");
	string first, second;
	fin >> first >> second;
	long long product1 = 1;
	for (int i = 0; i < first.length(); i++)
	{
		product1 *= (first[i] - 'A' + 1);
	}
	product1 %= 47;
	long long product2 = 1;
	for (int i = 0; i < second.length(); i++)
	{
		product2 *= (second[i] - 'A' + 1);
	}
	product2 %= 47;
	if (product1 == product2)
	{
		fout << "GO" << endl;
	}
	else
	{
		fout << "STAY" << endl;
	}
}
struct gift1account
{
	string name;
	int balance;
};
void greedygiftgivers()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	int np;
	fin >> np;
	vector<gift1account> people;
	for (int i = 0; i < np; i++)
	{
		string name;
		fin >> name;
		people.push_back({ name, 0 });
	}
	for (int i = 0; i < np; i++)
	{
		string name;
		int amount, num;
		fin >> name >> amount >> num;
		if (num == 0)
		{
			continue;
		}
		int give = amount / num;
		int save = amount - (amount / num) * num;
		for (int i = 0; i < np; i++)
		{
			if (people[i].name == name)
			{
				people[i].balance -= amount;
				people[i].balance += save;
				break;
			}
		}
		for (int i = 0; i < num; i++)
		{
			string name;
			fin >> name;
			for (int j = 0; j < np; j++)
			{
				if (people[j].name == name)
				{
					people[j].balance += give;
					break;
				}
			}
		}
	}
	for (int i = 0; i < np; i++)
	{
		fout << people[i].name << " " << people[i].balance << endl;
	}
}
void fridaythethirteenth()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int years;
	fin >> years;
	int monthsyear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysweek[7] = { 0 };
	for (int i = 0; i < 7; i++)
	{
		daysweek[i] = 0;
	}
	int day = 0;
	for (int i = 0; i < years; i++)
	{
		for (int month = 0; month < 12; month++)
		{
			daysweek[day]++;
			if (month == 1 && (i + 1900) % 4 == 0 && ((i + 1900) % 100 != 0 || (i + 1900) % 400 == 0))
			{
				day = (day + monthsyear[month] + 1) % 7;
			}
			else
			{
				day = (day + monthsyear[month]) % 7;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		fout << daysweek[i] << " ";
	}
	fout << daysweek[6] << endl;
}
void brokennecklace()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int num;
	string colors;
	fin >> num >> colors;
	int max = 0;
	for (int i = 0; i < num; i++)
	{
		int total = 0;
		int j = i;
		int increase = 0;
		while (colors[j] == 'w')
		{
			j++;
			if (j >= num)
			{
				j -= num;
			}
			increase++;
			if (increase > num)
			{
				break;
			}
		}
		char color = colors[j];
		while (colors[j] == color || colors[j] == 'w')
		{
			j++;
			if (j >= num)
			{
				j -= num;
			}
			increase++;
			if (increase > num)
			{
				break;
			}
		}
		total = increase;
		int decrease = 0;
		j = i - 1;
		if (j < 0)
		{
			j += num;
		}
		while (colors[j] == 'w')
		{
			j--;
			if (j < 0)
			{
				j += num;
			}
			decrease++;
			if (decrease > num)
			{
				break;
			}
		}
		color = colors[j];
		while (colors[j] == color || colors[j] == 'w')
		{
			j--;
			if (j < 0)
			{
				j += num;
			}
			decrease++;
			if (decrease > num)
			{
				break;
			}
		}
		total += decrease;
		if (total > max) max = total;
	}
	if (max > num)
	{
		max = num;
	}
	fout << max << endl;
}
void onepointtwo()
{
	char funcNames[][100] =
	{
		"Your Ride is Here",
		"Greedy Gift Givers",
		"Friday the Thirteenth",
		"Broken Necklace"
	};
	void (*funcs[])() =
	{
		yourrideishere,
		greedygiftgivers,
		fridaythethirteenth,
		brokennecklace
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