#include "USACO Superbull.h"
#define maxn 2001
int team[maxn] = { 0 };
int max[maxn] = { 0 };
struct game
{
    int home, away;
    long long score;
} superbull[maxn * maxn];
bool compare(game x, game y)
{
    return x.score > y.score;
}
int find(int x)
{
    if (team[x] == x)
    {
        return x;
    }
    else
    {
        return team[x] = find(team[x]);
    }
}
void usacosuperbullrun()
{
    long long id[maxn] = { 0 };
    long long answer = 0;
    int num = 0;
    int count = 0;
    FILE* input = fopen("superbull.in", "r");
    FILE* output = fopen("superbull.out", "w");
    fscanf(input, "%d", &num);
    for (int i = 1; i <= num; i++)
    {
        char ch = fgetc(input);
        long long t = 0;
        while (ch < '0' || ch > '9')
        {
            ch = fgetc(input);
        }
        while (ch <= '9' && ch >= '0')
        {
            t = t * 10 + ch - '0';
            ch = fgetc(input);
        }
        id[i] = t;
        team[i] = i;
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            superbull[++count].away = i;
            superbull[count].home = j;
            superbull[count].score = id[i] ^ id[j];
        }
    }
    std::sort(superbull + 1, superbull + count + 1, compare);
    for (int i = 1; i <= count; i++)
    {
        int x = superbull[i].away;
        int y = superbull[i].home;
        if (find(x) != find(y))
        {
            x = find(x);
            y = find(y);
            if (max[x] > max[y])
            {
                int temp = x;
                x = y;
                y = temp;
            }
            if (x != y)
            {
                team[x] = y;
            }
            max[y] += max[x];
            max[x] = 0;
            answer += superbull[i].score;
        }
    }
    fprintf(output, "%lld", answer);
    fclose(input);
    fclose(output);
}