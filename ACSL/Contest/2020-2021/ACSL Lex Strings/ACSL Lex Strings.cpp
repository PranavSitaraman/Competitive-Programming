#include "ACSL Lex Strings.h"
string rearrangedString(string s)
{
    string newstring;
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] < 'a' || s[i] > 'z')
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    while (s.length() > 0)
    {
        string current;
        int letter[26] = { 0 };
        for (int i = 0; i < s.length(); i++)
        {
            if (letter[s[i] - 'a'] == 0)
            {
                letter[s[i] - 'a'] = 1;
                current.append(s, i, 1);
                s.erase(s.begin() + i);
                i--;
            }
        }
        sort(current.begin(), current.end());
        newstring.append(current);
    }
    char prev = '\0';
    for (int i = 0; i < newstring.length(); i++)
    {
        if (newstring[i] == prev)
        {
            newstring.erase(newstring.begin() + i);
            i--;
        }
        prev = newstring[i];
    }
    return newstring;
}
void acsllexstringsrun()
{
    cout << rearrangedString("A good sorting algorithm.");
}