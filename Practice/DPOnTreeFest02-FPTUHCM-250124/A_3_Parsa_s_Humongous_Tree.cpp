
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i].first >> val[i].second;
    }
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
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0] + abs(val[u].first - val[v].first), dp[v][1] + abs(val[u].first - val[v].second));
            dp[u][1] += max(dp[v][0] + abs(val[u].second - val[v].first), dp[v][1] + abs(val[u].second - val[v].second));
        }
    };
    dfs(0, -1);
    // cout << dp[0][0] << " " << dp[0][1] << "\n";
    // cout << dp[1][0] << " " << dp[1][1] << "\n";
    cout << max(dp[0][0], dp[0][1]) << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}