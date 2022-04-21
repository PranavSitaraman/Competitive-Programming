#include "ACSL Fibonacci Clock.h"
using namespace std;
string findTime(char c1, char c2, char c3, char c4, char c5)
{
    int hour = 0, minute = 0;
    switch (c1)
    {
    case 'R': hour++; break;
    case 'B': hour++; minute++; break;
    case 'G': minute++; break;
    default: break;
    }
    switch (c2)
    {
    case 'R': hour++; break;
    case 'B': hour++; minute++; break;
    case 'G': minute++; break;
    default: break;
    }
    switch (c3)
    {
    case 'R': hour += 2; break;
    case 'B': hour += 2; minute += 2; break;
    case 'G': minute += 2; break;
    default: break;
    }
    switch (c4)
    {
    case 'R': hour += 3; break;
    case 'B': hour += 3; minute += 3; break;
    case 'G': minute += 3; break;
    default: break;
    }
    switch (c5)
    {
    case 'R': hour += 5; break;
    case 'B': hour += 5; minute += 5; break;
    case 'G': minute += 5; break;
    default: break;
    }
    minute *= 5;
    while (minute >= 60)
    {
        minute -= 60;
        hour++;
    }
    if (hour >= 12)
    {
        hour -= 12;
    }
    string a = "";
    if (hour < 10)
    {
        a += "0";
    }
    a += to_string(hour) + ":";
    if (minute < 10)
    {
        a += "0";
    }
    a += to_string(minute);
    return a;
}
void acslfibclock()
{
    char ch1, ch2, ch3, ch4, ch5;
    cin >> ch1 >> ch2 >> ch3 >> ch4 >> ch5;
    cout << findTime(ch1, ch2, ch3, ch4, ch5);
}