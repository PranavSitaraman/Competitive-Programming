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
#include<unordered_map>
using namespace std;
struct project
{
	int days;
	int score;
	int bestbefore;
	vector<pair<string, int>> roles;
};
unordered_map<string, unordered_map<string, int>> ppl;
vector<string> pplnames;
unordered_map<string, project> proj;
vector<string> projnames;
vector<vector<string>> chosen;
vector<vector<string>> answer;
vector<string> finalprojnames;
void hashcode2022()
{
	for (char i = 'a'; i <= 'a'; i++)
	{
		char word[60];
		sprintf(word, "Hash Code/2022/%c.txt", i);
		ifstream in(word);
		int contributors, projects;
		in >> contributors >> projects;
		for (int i = 0; i < contributors; i++)
		{
			unordered_map<string, int> tasks;
			string a; int b;
			in >> a >> b;
			for (int j = 0; j < b; j++)
			{
				string c; int d;
				in >> c >> d;
				tasks[c] = d;
			}
			ppl[a] = tasks;
			pplnames.push_back(a);
		}
		for (int i = 0; i < projects; i++)
		{
			string name; int a, b, c, d;
			in >> name >> a >> b >> c >> d;
			vector<pair<string, int>> roles;
			for (int j = 0; j < d; j++)
			{
				string e; int f;
				in >> e >> f;
				roles.push_back({ e, f });
			}
			project next = { a, b, c, roles};
			proj[name] = next;
			projnames.push_back(name);
		}
		in.close();
		int maxcount = 0;
		do
		{
			chosen.clear();
			finalprojnames.clear();
			int num = -1;
			for (auto i : projnames)
			{
				num++;
				chosen.push_back({});
				finalprojnames.push_back({});
				for (auto j : proj[i].roles)
				{
					for (auto k : pplnames)
					{
						if (ppl[k][j.first] >= j.second)
						{
							bool already = false;
							for (int q = 0; q < chosen[num].size(); q++)
							{
								if (chosen[num][q] == k)
								{
									already = true;
									break;
								}
							}
							if (!already)
							{
								chosen[num].push_back(k);
								if (ppl[k][j.first] == j.second)
								{
									ppl[k][j.first]++;
								}
								break;
							}
						}
					}
				}
			}
			int count = 0;
			for (int i = 0; i <= num; i++)
			{
				if (chosen[i].size() == proj[projnames[i]].roles.size())
				{
					count++;
				}
			}
			if (count > maxcount)
			{
				maxcount = count;
				answer.clear();
				for (int i = 0; i <= num; i++)
				{
					answer.push_back(chosen[i]);
					finalprojnames[i] = projnames[i];
				}
			}
		} while (next_permutation(projnames.begin(), projnames.end()));
		int count = 0;
		int num = -1;
		for (auto i : finalprojnames)
		{
			num++;
			if (answer[num].size() == proj[i].roles.size())
			{
				count++;
			}
		}
		sprintf(word, "Hash Code/2022/%c (out).txt", i);
		ofstream out(word);
		out << count << endl;
		num = -1;
		for (auto i : finalprojnames)
		{
			num++;
			if (answer[num].size() == proj[i].roles.size())
			{
				out << i << endl;
				for (int j = 0; j < answer[num].size(); j++)
				{
					if (j != 0) out << " ";
					out << answer[num][j];
				}
				out << endl;
			}
		}
		out.close();
		ppl.clear();
		pplnames.clear();
		proj.clear();
		projnames.clear();
		chosen.clear();
		answer.clear();
		finalprojnames.clear();
	}
}