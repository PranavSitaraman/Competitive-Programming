#include<iostream>
#include<vector>
#include<bitset>
#include<climits>
#include<stack>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
void searchingforsoulmates()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long start, end, answer = LLONG_MAX; cin >> start >> end;
		for (long long removed = 0, here = 0, prefix = end >> removed, cow = start; end >> removed > 0; removed++, here = 0, prefix = end >> removed, cow = start)
		{
			for (; cow > prefix; cow /= 2, here++) if (cow % 2 == 1) { cow++; here++; }
			answer = min(answer, here + prefix - cow + removed + (long long) bitset<32>(end & ((1 << removed) - 1)).count());
		}
		cout << answer << endl;
	}
}
void cowfrisbee()
{
	long long n, ans = 0, num = 2; cin >> n; vector<long long> h(n); for (long long& i : h) cin >> i;
	while (num--)
	{
		stack<long long> stk;
		for (long long i = n; --i >= 0;)
		{
			while (!stk.empty() && h[stk.top()] < h[i]) stk.pop();
			if (!stk.empty()) ans += stk.top() - i + 1;
			stk.push(i);
		}
		reverse(h.begin(), h.end());
	}
	cout << ans << endl;
}
struct edge
{
    int cow;
    int to;
    bool is_first;
    edge() {};
    edge(int cow, int to, bool is_first) : cow(cow), to(to), is_first(is_first) {};
};
int N, M;
vector<edge> adj[100001];
bool visited_cycle[100001];
bool visited[100001];
bool gets_cereal[100001];
int hungry_cows = 0;
queue<int> order;
int ignore_edge = -1;
int first_cereal = -1;
void find_cycle(int cur, int prev = -1)
{
    visited_cycle[cur] = true;
    for (edge next : adj[cur])
    {
        if (visited_cycle[next.to])
        {
            if (first_cereal == -1 && next.to != prev)
            {
                if (next.is_first) first_cereal = next.to;
                else first_cereal = cur;
                ignore_edge = next.cow;
                order.push(next.cow);
                gets_cereal[next.cow] = true;
            }
        }
        else
        {
            find_cycle(next.to, cur);
        }
    }
}
void dfs(int cur)
{
    visited[cur] = true;
    for (edge next : adj[cur])
    {
        if (!visited[next.to] && next.cow != ignore_edge)
        {
            gets_cereal[next.cow] = true;
            order.push(next.cow);
            dfs(next.to);
        }
    }
}
void cereal2()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(edge(i + 1, b, false));
        adj[b].push_back(edge(i + 1, a, true));
    }
    for (int i = 1; i <= M; ++i)
    {
        first_cereal = -1;
        ignore_edge = -1;
        if (!visited[i])
        {
            find_cycle(i);
            if (first_cereal > 0)
            {
                dfs(first_cereal);
            }
            else
            {
                dfs(i);
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!gets_cereal[i])
        {
            ++hungry_cows;
            order.push(i);
        }
    }
    cout << hungry_cows << endl;
    while (!order.empty())
    {
        cout << order.front() << endl;
        order.pop();
    }
}