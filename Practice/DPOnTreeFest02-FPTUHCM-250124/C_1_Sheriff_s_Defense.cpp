
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> values(n);
    for (int &v : values)
        cin >> v;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<array<int, 2>> dp(n, {0, 0});
    function<void(int, int)> dfs = [&](int u, int p)
    {
        if (p != -1 && adj[u].size() == 1)
        {
            dp[u] = {0, values[u]};
            return;
        }
        dp[u][1] = values[u];
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += max(dp[v][1] - 2 * c, dp[v][0]);
        }
    };
    dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}