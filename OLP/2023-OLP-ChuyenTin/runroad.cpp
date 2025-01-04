
#include <bits/stdc++.h>
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const int MAX = 2e4 + 7;
const int MOD = 1e9 + 7;
int n, t;
vector<int> adj[MAX];
int h[MAX];

void enter()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void solve()
{
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> max_h(n + 1, vector<int>(n + 1, 0));
    for (int u = 1; u <= n; u++)
        max_h[u][u] = h[u];

    function<void(int, int, int)> dfs = [&](int start, int u, int par)
    {
        for (int v : adj[u])
        {
            if (v == par)
                continue;
            dis[start][v] = dis[start][u] + 1;
            max_h[start][v] = max(h[v], max_h[start][u]);
            dfs(start, v, u);
        }
    };

    for (int u = 1; u <= n; u++)
        dfs(u, u, -1);

    int sum = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = x + 1; y <= n; y++)
        {
            for (int z = y + 1; z <= n; z++)
            {
                if (max({max_h[x][y], max_h[y][z], max_h[z][x]}) == t)
                {
                    sum = (sum + dis[x][y] % MOD + dis[y][z] % MOD + dis[z][x] % MOD) % MOD;
                }
            }
        }
    }
    cout << sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    enter();
    solve();
}