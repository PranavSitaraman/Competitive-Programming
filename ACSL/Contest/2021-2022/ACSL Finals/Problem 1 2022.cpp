#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int givenHour, givenMinute, givenSeconds;
vector<string> answer;
bool eval(string time)
{
    int hour = 0, minute = 0, seconds = 0;
    int fib[5] = { 1, 1, 2, 3, 5 };
    for (int i = 0; i < 5; i++)
    {
        switch (time[i])
        {
            case 'r': hour += fib[i]; break;
            case 'g': minute += fib[i]; break;
            case 'b': seconds += fib[i]; break;
            case 'y': hour += fib[i]; minute += fib[i]; break;
            case 'm': hour += fib[i]; seconds += fib[i]; break;
            case 'c': minute += fib[i]; seconds += fib[i]; break;
            case 'w': hour += fib[i]; seconds += fib[i]; minute += fib[i]; break;
            default: break;
        }
    }
    minute *= 5;
    seconds *= 5;
    return (hour == givenHour && minute == givenMinute && seconds == givenSeconds);
}
void dfs(string a)
{
    if (a.length() == 5)
    {
        if (eval(a)) answer.push_back(a);
        return;
    }
    dfs(a + 'r');
    dfs(a + 'g');
    dfs(a + 'b');
    dfs(a + 'y');
    dfs(a + 'm');
    dfs(a + 'c');
    dfs(a + 'w');
    dfs(a + 'k');
}
string displayTime(string time)
{
    givenHour = (time[0] - '0') * 10 + time[1] - '0';
    givenMinute = (time[3] - '0') * 10 + time[4] - '0';
    givenSeconds = (time[6] - '0') * 10 + time[7] - '0';
    dfs("");
    sort(answer.begin(), answer.end());
    string out = "";
    for (int i = 0; i < answer.size(); i++)
    {
        if (i != 0) out += " ";
        out += answer[i];
    }
    return out;
}
void acsl2022one()
{
	cout << displayTime("11:05:10") << endl;
}