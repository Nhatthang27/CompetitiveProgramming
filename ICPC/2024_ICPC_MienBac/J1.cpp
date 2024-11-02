
#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

const int R = 100;
const int INF = 1e9;

struct EdmondsKarp
{
    int n, src, sink;
    vector<vector<int>> adj;
    vector<vector<int>> cap;
    vector<int> parent;

    EdmondsKarp(int _n, int _src, int _sink) : n(_n), src(_src), sink(_sink)
    {
        adj.assign(n + 1, vector<int>());
        cap.assign(n + 1, vector<int>(n + 1, 0));
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += w;
    }

    int bfs()
    {
        fill(parent.begin(), parent.end(), -1);
        queue<pair<int, int>> q;
        q.push({src, INT_MAX});
        parent[src] = -2;

        while (!q.empty())
        {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int v : adj[u])
            {
                if (parent[v] == -1 && cap[u][v] > 0)
                {
                    parent[v] = u;
                    int new_flow = min(flow, cap[u][v]);
                    if (v == sink)
                        return new_flow;
                    q.push({v, new_flow});
                }
            }
        }
        return 0;
    }

    int max_flow()
    {
        int flow = 0, new_flow;
        parent.resize(n + 1);

        while (new_flow = bfs())
        {
            flow += new_flow;
            int cur = sink;
            while (cur != src)
            {
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
            }
        }
        return flow;
    }
};

void solve()
{
    int l, w, n;
    cin >> l >> w >> n;
    vector<pii> a(n + 1);
    fu(i, 1, n)
    {
        cin >> a[i].ff >> a[i].ss;
    }
    int src = 2 * n + 1, sink = 2 * n + 2;
    EdmondsKarp karp(2 * n + 2, 2 * n + 1, 2 * n + 2);

    // change vertex to edge
    //  each vertex to be an edge with weight 1

    fu(i, 1, n) karp.add_edge(i, n + i, 1);

    fu(i, 1, n)
    {
        if (a[i].ss <= R)
        {
            karp.add_edge(src, i, 1);
        }
        if (a[i].ss + R >= w && a[i].ss <= w)
        {
            karp.add_edge(n + i, sink, 1);
        }
    }

    fu(i, 1, n)
    {
        fu(j, i + 1, n)
        {
            if ((a[i].ff - a[j].ff) * (a[i].ff - a[j].ff) + (a[i].ss - a[j].ss) * (a[i].ss - a[j].ss) <= 4 * R * R)
            {
                karp.add_edge(n + i, j, 1);
                karp.add_edge(n + j, i, 1);
            }
        }
    }

    // how to removed minimun vertex to make max flow fron n + 1 to n + 2 is 0
    int maxFlow = karp.max_flow();
    cout << maxFlow << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    while (t-- > 0)
    {
        solve();
    }
}