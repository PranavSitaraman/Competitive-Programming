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
void practiceround()
{
	for (char i = 'a'; i <= 'e'; i++)
	{
		vector<string> likes, dislikes, chosen;
		char word[60];
		sprintf(word, "%c.txt", i);
		ifstream in(word);
		sprintf(word, "%c (out).txt", i);
		ofstream out(word);
		int n;
		in >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			in >> a;
			for (int j = 0; j < a; j++)
			{
				string c;
				in >> c;
				likes.push_back(c);
			}
			in >> a;
			for (int j = 0; j < a; j++)
			{
				string c;
				in >> c;
				dislikes.push_back(c);
			}
		}
		in.close();
		sort(likes.begin(), likes.end());
		sort(dislikes.begin(), dislikes.end());
		do
		{
			while (dislikes.size() > 0 && dislikes[0] != likes[0]) dislikes.erase(dislikes.begin());
			int j = 0;
			for (; j < likes.size() && likes[j] == likes[0]; j++);
			int k = 0;
			for (; k < dislikes.size() && dislikes[k] == likes[0]; k++);
			if (j > k) chosen.push_back(likes[0]);
			while (j--) likes.erase(likes.begin());
			while (k--) dislikes.erase(dislikes.begin());
		} while (likes.size() > 0);
		out << chosen.size();
		for (int i = 0; i < chosen.size(); i++)
		{
			out << " " << chosen[i];
		}
		out.close();
	}
}