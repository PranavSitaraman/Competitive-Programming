#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
string generateSentences(vector<string> dictionary, string sentences)
{
	string a = "";
	vector<vector<string>> dict;
	vector<int> num(dictionary.size(), 0);
	for (int i = 0; i < dictionary.size(); i++)
	{
		vector<string> partial;
		stringstream split(dictionary[i]);
		string word;
		while (split >> word)
		{
			partial.push_back(word);
		}
		dict.push_back(partial);
	}
	int n, c, v, j, b, p;
	for (int i = 0; i < dict.size(); i++)
	{
		if (dict[i][0] == "N")
		{
			n = i;
		}
		if (dict[i][0] == "C")
		{
			c = i;
		}
		if (dict[i][0] == "V")
		{
			v = i;
		}
		if (dict[i][0] == "J")
		{
			j = i;
		}
		if (dict[i][0] == "B")
		{
			b = i;
		}
		if (dict[i][0] == "P")
		{
			p = i;
		}
	}
	vector<string> parts;
	stringstream multiple(sentences);
	string sent;
	while (multiple >> sent)
	{
		string flag = "";
		if (sent[0] == 'E')
		{
			flag = "!";
		}
		else if (sent[0] == 'Q')
		{
			flag = "?";
			a.append("What ");
		}
		else if (sent[0] == 'I' || sent[0] == 'D')
		{
			flag = ".";	
		}
		bool preva = false;
		if (sent[1] == 'B')
		{
			string add = dict[b][1 + num[b]];
			if (flag != "?")
			{
				add[0] = toupper(add[0]);
			}
			a.append(add);
			num[b]++;
			num[b] = num[b] % (dict[b].size() - 1);
		}
		if (sent[1] == 'P')
		{
			string add = dict[p][1 + num[p]];
			if (flag != "?")
			{
				add[0] = toupper(add[0]);
			}
			a.append(add);
			num[p]++;
			num[p] = num[p] % (dict[p].size() - 1);
		}
		if (sent[1] == 'J')
		{
			string add = dict[j][1 + num[j]];
			if (flag != "?")
			{
				add[0] = toupper(add[0]);
			}
			a.append(add);
			num[j]++;
			num[j] = num[j] % (dict[j].size() - 1);
		}
		if (sent[1] == 'V')
		{
			string add = dict[v][1 + num[v]];
			if (flag != "?")
			{
				add[0] = toupper(add[0]);
			}
			a.append(add);
			num[v]++;
			num[v] = num[v] % (dict[v].size() - 1);
		}
		if (sent[1] == 'C')
		{
			string add = dict[c][1 + num[c]];
			if (flag != "?")
			{
				add[0] = toupper(add[0]);
			}
			a.append(add);
			num[c]++;
			num[c] = num[c] % (dict[c].size() - 1);
		}
		if (sent[1] == 'N')
		{
			string add = dict[n][1 + num[n]];
			if (flag != "?")
			{
				add[0] = toupper(add[0]);
			}
			a.append(add);
			num[n]++;
			num[n] = num[n] % (dict[n].size() - 1);
		}
		if (sent[1] == 'T')
		{
			if (flag != "?")
			{
				a.append("The");
			}
			else
			{
				a.append("the");
			}
		}
		if (sent[1] == 'A')
		{
			if (flag != "?")
			{
				a.append("A");
			}
			else
			{
				a.append("a");
			}
			preva = true;
		}
		for (int q = 2; q < sent.size(); q++)
		{
			if (sent[q] == 'B')
			{
				if (preva == true)
				{
					char first = dict[b][1 + num[b]][0];
					if (first == 'a' || first == 'A' ||
						first == 'e' || first == 'E' ||
						first == 'i' || first == 'I' ||
						first == 'o' || first == 'O' ||
						first == 'u' || first == 'U')
					{
						a.append("n");
					}
				}
				a.append(" " + dict[b][1 + num[b]]);
				num[b]++;
				num[b] = num[b] % (dict[b].size() - 1);
			}
			if (sent[q] == 'P')
			{
				if (preva == true)
				{
					char first = dict[p][1 + num[p]][0];
					if (first == 'a' || first == 'A' ||
						first == 'e' || first == 'E' ||
						first == 'i' || first == 'I' ||
						first == 'o' || first == 'O' ||
						first == 'u' || first == 'U')
					{
						a.append("n");
					}
				}
				a.append(" " + dict[p][1 + num[p]]);
				num[p]++;
				num[p] = num[p] % (dict[p].size() - 1);
			}
			if (sent[q] == 'J')
			{
				if (preva == true)
				{
					char first = dict[j][1 + num[j]][0];
					if (first == 'a' || first == 'A' ||
						first == 'e' || first == 'E' ||
						first == 'i' || first == 'I' ||
						first == 'o' || first == 'O' ||
						first == 'u' || first == 'U')
					{
						a.append("n");
					}
				}
				a.append(" " + dict[j][1 + num[j]]);
				num[j]++;
				num[j] = num[j] % (dict[j].size() - 1);
			}
			if (sent[q] == 'V')
			{
				if (preva == true)
				{
					char first = dict[v][1 + num[v]][0];
					if (first == 'a' || first == 'A' ||
						first == 'e' || first == 'E' ||
						first == 'i' || first == 'I' ||
						first == 'o' || first == 'O' ||
						first == 'u' || first == 'U')
					{
						a.append("n");
					}
				}
				a.append(" " + dict[v][1 + num[v]]);
				num[v]++;
				num[v] = num[v] % (dict[v].size() - 1);
			}
			if (sent[q] == 'C')
			{
				if (preva == true)
				{
					char first = dict[c][1 + num[c]][0];
					if (first == 'a' || first == 'A' ||
						first == 'e' || first == 'E' ||
						first == 'i' || first == 'I' ||
						first == 'o' || first == 'O' ||
						first == 'u' || first == 'U')
					{
						a.append("n");
					}
				}
				a.append(" " + dict[c][1 + num[c]]);
				num[c]++;
				num[c] = num[c] % (dict[c].size() - 1);
			}
			if (sent[q] == 'N')
			{
				if (preva == true)
				{
					char first = dict[n][1 + num[n]][0];
					if (first == 'a' || first == 'A' ||
						first == 'e' || first == 'E' ||
						first == 'i' || first == 'I' ||
						first == 'o' || first == 'O' ||
						first == 'u' || first == 'U')
					{
						a.append("n");
					}
				}
				a.append(" " + dict[n][1 + num[n]]);
				num[n]++;
				num[n] = num[n] % (dict[n].size() - 1);
			}
			if (sent[q] == 'T')
			{
				a.append(" the");
			}
			if (sent[q] == 'A')
			{
				if (preva == true)
				{
					a.append("n");
				}
				a.append(" a");
				preva = true;
			}
			else
			{
				preva = false;
			}
		}
		a.append(flag + " ");
	}
	return a;
}
void acslfinalstworun()
{
	vector<string> word = { "N money tree sky", "C grow fall", "P on from" };
	cout << generateSentences(word, "ICNPTN ICPTN");
}