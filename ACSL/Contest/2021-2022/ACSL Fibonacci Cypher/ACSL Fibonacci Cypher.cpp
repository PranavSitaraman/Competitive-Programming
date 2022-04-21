#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;
int fib[20] = { 0 };
int fibonacci(int n)
{
    if (fib[n - 1] == -1)
    {
        fib[n - 1] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return fib[n - 1];
}
string fibCypher(int num1, int num2, char key, string msg)
{
    for (int i = 0; i < 20; i++)
    {
        fib[i] = -1;
    }
    fib[0] = num1;
    fib[1] = num2;
    fibonacci(20);
    string out = "";
    for (int i = 0; i < int(msg.length()); i++)
    {
        int offset = fib[i % 20];
        int n = key + offset;
        while (n > 'z')
        {
            n -= 26;
        }
        int answer = msg[i] + 3 * n;
        if (i != 0)
        {
            out += " ";
        }
        out += to_string(answer);
    }
    return out;
}
void acslfibcypher()
{
    cout << fibCypher(3, 7, 'h', "ACSL c2");
}