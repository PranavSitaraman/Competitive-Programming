/*
NAME: Pranav Sitaraman
SCHOOL: Middlesex County Academy for Science, Mathematics, and Engineering Technologies
GRADE: 10
DIVISION: Intermediate - 5
ROUND: Practice Test #1
PROGRAM NAME: Quine-McCluskyAlgorithm
LANGUAGE: CPP
Pledge: I have neither given nor received help, nor will I give help on this program or any other
program.
*/
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
void solve(vector<char>& a, vector<char>& b)
{
	int numdiff = 0;
	int val = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i])
		{
			numdiff++;
			val = i;
		}
	}
	if (numdiff == 1)
	{
		a[val] = 'x';
	}
	else
	{
		a[0] = 'N';
	}
}
void acslquinemcclusky()
{
	int a;
	cin >> a;
	while(a != -1)
	{
		cin.ignore();
		cin >> a;
	}
	for (int i = 0; i < 2; i++)
	{
		int a, b;
		cin >> a;
		cin.ignore();
		cin >> b;
		vector<char> first, second;
		for (int i = 0; i < 4; i++)
		{
			first.push_back((a % 2) + '0');
			second.push_back((b % 2) + '0');
			a = a / 2;
			b = b / 2;
		}
		solve(first, second);
		if (first[0] == 'N')
		{
			cout << "NONE" << endl;
		}
		else
		{
			vector<char> answer;
			for (int i = 3; i >= 0; i--)
			{
				cout << first[i];
				if (first[i] == '1')
				{
					answer.push_back('A' + 3 - i);
				}
				else if (first[i] == '0')
				{
					answer.push_back('a' + 3 - i);
				}
			}
			cout << " ";
			for (int i = 0; i < answer.size(); i++)
				cout << answer[i];
			cout << endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		int a, b, c, d;
		cin >> a;
		cin.ignore();
		cin >> b;
		cin.ignore();
		cin >> c;
		cin.ignore();
		cin >> d;
		vector<char> first, second, third, fourth;
		for (int i = 0; i < 4; i++)
		{
			first.push_back(a % 2 + '0');
			second.push_back(b % 2 + '0');
			third.push_back(c % 2 + '0');
			fourth.push_back(d % 2 + '0');
			a = a / 2;
			b = b / 2;
			c = c / 2;
			d = d / 2;
		}
		solve(first, second);
		solve(third, fourth);
		if (first[0] == 'N' || third[0] == 'N')
		{
			cout << "NONE" << endl;
		}
		else
		{
			solve(first, third);
			if (first[0] == 'N')
			{
				cout << "NONE" << endl;
			}
			else
			{
				vector<char> answer;
				for (int i = 3; i >= 0; i--)
				{
					cout << first[i];
					if (first[i] == '1')
					{
						answer.push_back('A' + 3 - i);
					}
					else if (first[i] == '0')
					{
						answer.push_back('a' + 3 - i);
					}
				}
				cout << " ";
				for (int i = 0; i < answer.size(); i++)
					cout << answer[i];
				cout << endl;
			}
		}
	}
}