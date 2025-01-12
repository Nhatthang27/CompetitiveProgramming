
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d(n, 0);
    vector<int> dx(n, 0);
    function<void(int, int, vector<int> &d)> dfs = [&](int u, int p, vector<int> &d)
    {
        for (int v : adj[u])
        {
            if (v != p)
            {
                d[v] = d[u] + 1;
                dfs(v, u, d);
            }
        }
    };
    dfs(0, -1, d);
    dfs(x, -1, dx);
    int res = 0;
    for (int i = 0; i < n; i++);l
    {
        if (dx[i] < d[i])
        {
            res = max(res, 2 * d[i]);
        }
    }
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    solve();
}