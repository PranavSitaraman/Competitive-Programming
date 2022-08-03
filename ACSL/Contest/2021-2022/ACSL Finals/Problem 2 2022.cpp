#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string eval(string word, string guess)
{
	string out = "     ";
	for (int i = 0; i < guess.length(); i++)
	{
		if (guess[i] == word[i])
		{
			out[i] = 'G';
			word[i] = '-';
			continue;
		}
	}
	for (int i = 0; i < guess.length(); i++)
	{
		if (out[i] == 'G') continue;
		for (int j = 0; j < word.length(); j++)
		{
			if (guess[i] == word[j])
			{
				out[i] = 'Y';
				word[j] = '-';
				break;
			}
		}
		if (out[i] == ' ') out[i] = '-';
	}
	return out;
}
string target;
bool compare(string& a, string& b)
{
	string a1 = eval(target, a);
	string b1 = eval(target, b);
	if (count(a1.begin(), a1.end(), 'G') > count(b1.begin(), b1.end(), 'G')) return 0;
	else if (count(a1.begin(), a1.end(), 'G') < count(b1.begin(), b1.end(), 'G')) return 1;
	if (count(a1.begin(), a1.end(), 'Y') > count(b1.begin(), b1.end(), 'Y')) return 0;
	else if (count(a1.begin(), a1.end(), 'Y') < count(b1.begin(), b1.end(), 'Y')) return 1;
	if (a1[0] == 'G' && b1[0] != 'G') return 0;
	else if (a1[0] != 'G' && b1[0] == 'G') return 1;
	if (a1[a1.length() - 1] == 'G' && b1[b1.length() - 1] != 'G') return 0;
	else if (a1[a1.length() - 1] != 'G' && b1[b1.length() - 1] == 'G') return 1;
	int counta = 0;
	for (int i = 0; i < a.length(); i++) if (a1[i] == 'G' && (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')) counta++;
	int countb = 0;
	for (int i = 0; i < b.length(); i++) if (b1[i] == 'G' && (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')) countb++;
	if (counta > countb) return 0;
	else if (counta < countb) return 1;
	if (a < b) return 0;
	else return 1;
}
string findMatch(string word, string guesses)
{
	vector<string> guess;
	string next = "";
	target = word;
	for (int i = 0; i < guesses.length(); i++)
	{
		if (guesses[i] == ' ') { guess.push_back(next); next = ""; }
		else next += guesses[i];
	}
	guess.push_back(next);
	char letters[26] = { 0 };
	for (int i = 0; i < guess.size(); i++) for (int j = 0; j < guess[i].size(); j++) letters[guess[i][j] - 'a']++;
	for (int i = 0; i < guess.size(); i++) if (eval(word, guess[i]) == "-----") guess.erase(guess.begin() + (i--));
	sort(guess.begin(), guess.end(), compare);
	string out = "";
	if (guess.size() >= 6)
	{
		for (int i = 0; i < 6; i++)
		{
			if (i != 0) out += ' ';
			out += guess[guess.size() - 1 - i];
		}
		return out;
	}
	for (int i = 0; i < 26; i++) if (letters[i] == 0) out += ('a' + i);
	return out;
}
void acsl2022two()
{
	cout << findMatch("helps", "roads track fears sight jumps zones") << endl;
}