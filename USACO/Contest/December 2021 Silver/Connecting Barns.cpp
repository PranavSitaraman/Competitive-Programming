#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>
#include<cmath>
using namespace std;
void dfs(vector<vector<int>>& edges, vector<vector<int>>& connected, int currv, int index, vector<bool>& found)
{
    found[currv] = true;
    connected[index].push_back(currv);
    for (int child : edges[currv])
    {
        if (found[child] == false)
        {
            dfs(edges, connected, child, index, found);
        }
    }
}
void connectingbarns()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        vector<bool> found(n + 1, false);
        vector<vector<int>> connected;
        int index = 0;
        connected.push_back({});
        dfs(edges, connected, 1, index, found);
        sort(connected[index].begin(), connected[index].end());
        index++;
        for (int i = n; i > 1; i--)
        {
            if (found[i] == false)
            {
                connected.push_back({});
                dfs(edges, connected, i, index, found);
                sort(connected[index].begin(), connected[index].end());
                index++;
            }
        }
        bool same = false;
        for (int i = 0; i < connected[0].size(); i++)
        {
            if (connected[0][i] == n)
            {
                same = true;
                break;
            }
        }
        if (same == true)
        {
            cout << "0" << endl;
            continue;
        }
        int min = INT_MAX;
        for (int i = 0; i < connected[0].size(); i++)
        {
            int prev = INT_MAX;
            for (int j = 0; j < connected[1].size(); j++)
            {
                int val = pow(connected[0][i] - connected[1][j], 2);
                if (val > prev) break;
                if (val < min)
                {
                    min = val;
                }
                prev = val;
            }
        }
        for (int a = 2; a < connected.size(); a++)
        {
            int min1 = INT_MAX, min2 = INT_MAX;
            if (connected[a][connected[a].size() - 1] < connected[0][0])
            {
                min1 = pow(connected[a][connected[a].size() - 1] - connected[0][0], 2);
            }
            else if (connected[a][0] > connected[0][connected[0].size() - 1])
            {
                min1 = pow(connected[a][0] - connected[0][connected[0].size() - 1], 2);
            }
            else
            {
                for (int j = 0; j < connected[a].size(); j++)
                {
                    int prev = INT_MAX;
                    for (int i = 0; i < connected[0].size(); i++)
                    {
                        int val = pow(connected[0][i] - connected[a][j], 2);
                        if (val > prev) break;
                        if (val < min1)
                        {
                            min1 = val;
                        }
                        prev = val;
                    }
                }
            }
            if (connected[a][connected[a].size() - 1] < connected[1][0])
            {
                min2 = pow(connected[a][connected[a].size() - 1] - connected[1][0], 2);
            }
            else if (connected[a][0] > connected[1][connected[1].size() - 1])
            {
                min2 = pow(connected[a][0] - connected[1][connected[1].size() - 1], 2);
            }
            else
            {
                for (int j = 0; j < connected[a].size(); j++)
                {
                    int prev = INT_MAX;
                    for (int i = 0; i < connected[1].size(); i++)
                    {
                        int val = pow(connected[1][i] - connected[a][j], 2);
                        if (val > prev) break;
                        if (val < min2)
                        {
                            min2 = val;
                        }
                        prev = val;
                    }
                }
            }
            if (min1 + min2 < min) min = min1 + min2;
        }
        cout << min << endl;
    }
}