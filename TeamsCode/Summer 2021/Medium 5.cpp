#include <cstdio>
#include <cstdlib>
#include <iostream>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
char findmax(int* appear, char prevmax)
{
	char max;
	if (appear[1] > appear[0] && appear[1] > appear[2])
	{
		max = 'B';
	}
	else if (appear[2] > appear[0] && appear[2] > appear[1])
	{
		max = 'C';
	}
	else if (appear[0] > appear[1] && appear[0] > appear[2])
	{
		max = 'A';
	}
	else if (appear[0] == appear[1] && appear[0] > appear[2])
	{
		if (prevmax == 'B')
		{
			max = 'A';
		}
		else
		{
			max = 'B';
		}
	}
	else if (appear[1] == appear[2] && appear[1] > appear[0])
	{
		if (prevmax == 'B')
		{
			max = 'C';
		}
		else
		{
			max = 'B';
		}
	}
	else if (appear[0] == appear[2] && appear[0] > appear[1])
	{
		if (prevmax == 'C')
		{
			max = 'A';
		}
		else
		{
			max = 'C';
		}
	}
	else if (appear[0] == appear[2] && appear[2] == appear[1])
	{
		if (prevmax == 'B')
		{
			max = 'A';
		}
		else if (prevmax == 'A')
		{
			max = 'C';
		}
		else if (prevmax == 'C')
		{
			max = 'B';
		}
	}
	return max;
}
char findmax(int* appear)
{
	char max;
	if (appear[1] > appear[0] && appear[1] > appear[2])
	{
		max = 'B';
	}
	else if (appear[2] > appear[0] && appear[2] > appear[1])
	{
		max = 'C';
	}
	else if (appear[0] > appear[1] && appear[0] > appear[2])
	{
		max = 'A';
	}
	else if (appear[0] == appear[1] && appear[0] > appear[2])
	{
		max = 'A';
	}
	else if (appear[1] == appear[2] && appear[1] > appear[0])
	{
		max = 'B';
	}
	else if (appear[0] == appear[2] && appear[0] > appear[1])
	{
		max = 'A';
	}
	else if (appear[0] == appear[2] && appear[2] == appear[1])
	{
		max = 'A';
	}
	return max;
}
void summer2021medium5()
{
	int n, k;
	cin >> n >> k;
	char* word = (char*)malloc(sizeof(char) * n);
	char* answer = (char*)malloc(sizeof(char) * n);
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> word[i];
	}
	int appear[3] = { 0 };
	for (int i = 0; i < k; i++)
	{
		appear[word[i] - 'A']++;
	}
	char max = findmax(appear);
	for (int i = 0; i < k; i++)
	{
		answer[counter] = max;
		counter++;
	}
	for (int i = k; i < n; i++)
	{
		appear[word[i] - 'A']++;
		char newmax = findmax(appear, max);
		if (newmax == max)
		{
			answer[counter] = newmax;
			counter++;
		}
		else
		{
			int b = 1;
			for (int j = i + 1; j < n && j < i + k; j++)
			{
				appear[word[j] - 'A']++;
				b++;
			}
			i += b - 1;
			newmax = findmax(appear, max);
			for (int a = 0; a < b; a++)
			{
				answer[counter] = newmax;
				counter++;
			}
		}
		max = newmax;
	}
	appear[0] = 0;
	appear[1] = 0;
	appear[2] = 0;
	int score = 0;
	for (int i = 0; i < counter; i++)
	{
		appear[word[i] - 'A']++;
		if (appear[answer[i] - 'A'] == max(appear[0], max(appear[1], appear[2])))
		{
			score++;
		}
	}
	cout << score;
}